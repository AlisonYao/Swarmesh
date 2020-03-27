import processing.serial.*;
import java.util.Arrays;
String myString = null;
Serial myPort;
int[] recv4 = {0, 0, 0, 0, 0};
int[] recv3 = {0, 0, 0, 0, 0};
int[] recv2 = {0, 0, 0, 0, 0};
int[] recv1 = {0, 0, 0, 0, 0};


int NUM_OF_VALUES = 4;   /** YOU MUST CHANGE THIS ACCORDING TO YOUR PROJECT **/
int[] sensorValues;      /** this array stores values from Arduino **/
int count = 0;
// setup the size of the screen
void setup(){
  size(800, 800);
  setupSerial();
  colorMode(RGB, 1000);
}

// draw the coordinate
void draw(){
  updateSerial();
  background(1000);
  textSize(20);
  // calculate the average received value of each receiver
  recv4 = arrayReplacement(recv4, sensorValues[3]);
  recv3 = arrayReplacement(recv3, sensorValues[2]);
  recv2 = arrayReplacement(recv2, sensorValues[1]);
  recv1 = arrayReplacement(recv1, sensorValues[0]);

  int avg4 = avgCalc(recv4);
  int avg3 = avgCalc(recv3);
  int avg2 = avgCalc(recv2);
  int avg1 = avgCalc(recv1);
  
  println("------------------RESULTS------------------");
  println(avg4);
  println(avg3);
  println(avg2);
  println(avg1);
  fill(0);
  text(avg4, 10, 20);
  text(avg3, 10, 40);
  text(avg2, 10, 60);
  text(avg1, 10, 80);
  
  fill(sensorValues[3]);
  arc(width / 2, height / 2, width / 2, height / 2, 0, PI / 2);
  fill(sensorValues[2]);
  arc(width / 2, height / 2, width / 2, height / 2, PI / 2, PI);
  fill(sensorValues[1]);
  arc(width / 2, height / 2, width / 2, height / 2, PI, PI * 3 / 2);
  fill(sensorValues[0]);
  arc(width / 2, height / 2, width / 2, height / 2, PI * 3 / 2, PI * 2);
}

// fill the arc with different degree of shade with regard to the distance of the mouse

int avgCalc(int[] Arr){
  int sum = Arrays.stream(Arr).sum();
  int avg = sum / Arr.length;
  return avg;
}

int[] arrayReplacement(int[] Arr, int recv){
  for (int i = 0; i < 5; i ++){
    if (i != 4){
      Arr[i] = Arr[i + 1];
    } else {
      Arr[i] = recv;  
    }
  }
  return Arr;
}

void setupSerial() {
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[ 2 ], 9600);
  // WARNING!
  // You will definitely get an error here.
  // Change the PORT_INDEX to 0 and try running it again.
  // And then, check the list of the ports,
  // find the port "/dev/cu.usbmodem----" or "/dev/tty.usbmodem----" 
  // and replace PORT_INDEX above with the index number of the port.

  myPort.clear();
  // Throw out the first reading,
  // in case we started reading in the middle of a string from the sender.
  myString = myPort.readStringUntil( 10 );  // 10 = '\n'  Linefeed in ASCII
  myString = null;

  sensorValues = new int[NUM_OF_VALUES];
}



void updateSerial() {
  while (myPort.available() > 0) {
    myString = myPort.readStringUntil( 10 ); // 10 = '\n'  Linefeed in ASCII
    if (myString != null) {
      String[] serialInArray = split(trim(myString), ",");
      if (serialInArray.length == NUM_OF_VALUES) {
        for (int i=0; i<serialInArray.length; i++) {
          sensorValues[i] = int(serialInArray[i]);
        }
      }
    }
  }
}
