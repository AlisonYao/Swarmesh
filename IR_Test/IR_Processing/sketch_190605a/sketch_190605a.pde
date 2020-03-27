import processing.serial.*;
import java.util.Arrays;
String myString = null;
PrintWriter output;
Serial myPort;
int[] recv4 = {0, 0, 0, 0, 0};
int[] recv3 = {0, 0, 0, 0, 0};
int[] recv2 = {0, 0, 0, 0, 0};
int[] recv1 = {0, 0, 0, 0, 0};


int NUM_OF_VALUES = 4;   /** YOU MUST CHANGE THIS ACCORDING TO YOUR PROJECT **/
int[] sensorValues;      /** this array stores values from Arduino **/
int count = 0;
// s`etup the size of the screen
void setup(){
  size(800, 800);
  setupSerial();
  colorMode(RGB, 1000);
  output = createWriter("data.txt");
}

// draw the coordinate
void draw(){
  updateSerial();
  background(1000);
  textSize(20);
  // calculate the average received value of each receiver
  //recv4 = arrayReplacement(recv4, sensorValues[3]);
  //recv3 = arrayReplacement(recv3, sensorValues[2]);
  //recv2 = arrayReplacement(recv2, sensorValues[1]);
  //recv1 = arrayReplacement(recv1, sensorValues[0]);

  //int avg4 = avgCalc(recv4);
  //int avg3 = avgCalc(recv3);
  //int avg2 = avgCalc(recv2);
  //int avg1 = avgCalc(recv1);
  output.println(sensorValues[3] + " " + sensorValues[2] + " " + sensorValues[1] + " " + sensorValues[0]);
  println("------------------RESULTS------------------");

  fill(0);
  text(sensorValues[3], 10, 20);
  text(sensorValues[2], 10, 40);
  text(sensorValues[1], 10, 60);
  text(sensorValues[0], 10, 80);
  
  rect(250, 100, 300, sensorValues[3] / 4);
  rect(200, 100, 250, sensorValues[2] / 4);
  rect(150, 100, 200, sensorValues[1] / 4);
  rect(100, 100, 150, sensorValues[0] / 4);
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
