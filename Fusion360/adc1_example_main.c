/* ADC1 Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

#define DEFAULT_VREF    1100        //Use adc2_vref_to_gpio() to obtain a better estimate
#define NO_OF_SAMPLES   32          //Multisampling
//---------------------------------------------------------------------------------------------
#define NUM_OF_RECV 8           // there are 8 receivers in total
//---------------------------------------------------------------------------------------------
#define pinA GPIO_NUM_5
#define pinB GPIO_NUM_18
#define pinC GPIO_NUM_19

static esp_adc_cal_characteristics_t *adc_chars;
static const adc_channel_t channel = ADC_CHANNEL_6;     //GPIO34 if ADC1, GPIO14 if ADC2
static const adc_atten_t atten = ADC_ATTEN_DB_11;
static const adc_unit_t unit = ADC_UNIT_1;
int voltage_converged[8];
int intArr[3];


static void check_efuse()
{
    //Check TP is burned into eFuse
    if (esp_adc_cal_check_efuse(ESP_ADC_CAL_VAL_EFUSE_TP) == ESP_OK) {
        printf("eFuse Two Point: Supported\n");
    } else {
        printf("eFuse Two Point: NOT supported\n");
    }

    //Check Vref is burned into eFuse
    if (esp_adc_cal_check_efuse(ESP_ADC_CAL_VAL_EFUSE_VREF) == ESP_OK) {
        printf("eFuse Vref: Supported\n");
    } else {
        printf("eFuse Vref: NOT supported\n");
    }
}

static void print_char_val_type(esp_adc_cal_value_t val_type)
{
    if (val_type == ESP_ADC_CAL_VAL_EFUSE_TP) {
        printf("Characterized using Two Point Value\n");
    } else if (val_type == ESP_ADC_CAL_VAL_EFUSE_VREF) {
        printf("Characterized using eFuse Vref\n");
    } else {
        printf("Characterized using Default Vref\n");
    }
}

void task_ir()
{
    while (1) {
//---------------------------------------------------------------------------------------------
        for(int k = 0; k < NUM_OF_RECV; k++){
//---------------------------------------------------------------------------------------------
            // Decimal binary conversion

            int l = k;
            intArr[2] = l & 0x01;
            intArr[1] = (l >> 1) & 0x01;
            intArr[0] = (l >> 2) & 0x01;

            // int l= k;
            // int bin[32], i = 0;
            // while (l>0)
            // {
            //     bin[i]=l%2;
            //     i ++;
            //     l=l/2;
            // }
            // for (int i = 0; i < 3; i ++){
            //     intArr[i] = bin[3 - i];
            //     printf("%d", intArr[i]);
            // }
            // printf("\n");




            // Sending values to mux
            gpio_set_level(pinA, intArr[0]);
            gpio_set_level(pinB, intArr[1]);
            gpio_set_level(pinC, intArr[2]);
            uint32_t adc_reading = 0;
            //Multisampling
            for (int i = 0; i < NO_OF_SAMPLES; i++) {
                if (unit == ADC_UNIT_1) {
                    adc_reading += adc1_get_raw((adc1_channel_t)channel);
                } else {
                    int raw;
                    adc2_get_raw((adc2_channel_t)channel, ADC_WIDTH_BIT_12, &raw);
                    adc_reading += raw;
                }
            }
            adc_reading /= NO_OF_SAMPLES;
            //Convert adc_reading to voltage in mV
            uint32_t voltage = esp_adc_cal_raw_to_voltage(adc_reading, adc_chars);
            // printf("Voltage Converted.\n");
//---------------------------------------------------------------------------------------------
            // adc_reading_raw[k] = adc_reading;
            voltage_converged[k] = voltage;

//---------------------------------------------------------------------------------------------
            // printf("Raw: %d\tVoltage: %dmV\n", adc_reading, voltage);
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }
//---------------------------------------------------------------------------------------------
        printf("----------------------------------------------------------------\n");
        printf("RECV1\tRECV2\tRECV3\tRECV4\tRECV5\tRECV6\tRECV7\tRECV8\n");
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", \
        voltage_converged[0], voltage_converged[1], voltage_converged[2], voltage_converged[3], \
        voltage_converged[4], voltage_converged[5], voltage_converged[6], voltage_converged[7]);
//---------------------------------------------------------------------------------------------
        printf("finished\n");
    }
}

void app_main()
{
    // define two arrays
    // int adc_reading_raw[8];

    //Check if Two Point or Vref are burned into eFuse
    check_efuse();

    //Configure ADC
    if (unit == ADC_UNIT_1) {
        adc1_config_width(ADC_WIDTH_BIT_12);
        adc1_config_channel_atten(channel, atten);
    } else {
        adc2_config_channel_atten((adc2_channel_t)channel, atten);
    }

    //Characterize ADC
    adc_chars = calloc(1, sizeof(esp_adc_cal_characteristics_t));
    esp_adc_cal_value_t val_type = esp_adc_cal_characterize(unit, atten, ADC_WIDTH_BIT_12, DEFAULT_VREF, adc_chars);
    print_char_val_type(val_type);
    intArr[0] = 0;
    intArr[1] = 0;
    intArr[2] = 0;
    // Setting up the pins

    gpio_set_direction(pinA, GPIO_MODE_OUTPUT);
    gpio_set_direction(pinB, GPIO_MODE_OUTPUT);
    gpio_set_direction(pinC, GPIO_MODE_OUTPUT);
    //Continuously sample ADC1
    printf("Task Initialize\n");
    xTaskCreate(&task_ir, "task_ir", 2048, NULL, 5, NULL);
    
}

