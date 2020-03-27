int recv1 = A0;
int recv2 = A1;
int recv3 = A2;
int recv4 = A3;
int recv5 = A4;
int recv6 = A5;
int recv7 = A6;
int recv8 = A7;

int val;
int rotation = 0;
#include <Servo.h>
Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode(recv1, INPUT);
  pinMode(recv2, INPUT);
  pinMode(recv3, INPUT);
  pinMode(recv4, INPUT);
  pinMode(recv5, INPUT);
  pinMode(recv6, INPUT);
  pinMode(recv7, INPUT);
  pinMode(recv8, INPUT);
  myservo.attach(9);
  val = 0;
}

void loop() {
  // read the analog value from the receiver
  int recv1 = map(analogRead(A0), 0, 1023, 0, 1000);
  int recv2 = map(analogRead(A1), 0, 1023, 0, 1000);
  int recv3 = map(analogRead(A2), 0, 1023, 0, 1000);
  int recv4 = map(analogRead(A3), 0, 1023, 0, 1000);
  int recv5 = map(analogRead(A4), 0, 1023, 0, 1000);
  int recv6 = map(analogRead(A5), 0, 1023, 0, 1000);
  int recv7 = map(analogRead(A6), 0, 1023, 0, 1000);
  int recv8 = map(analogRead(A7), 0, 1023, 0, 1000);
  
  myservo.write(val);
  if (val < 180){
    val += 1;
  } else {
    val = 0;
  }
  // send the analog value to processing
  // start sending
  Serial.print(recv1);
  Serial.print(",");
  Serial.print(recv2);
  Serial.print(",");
  Serial.print(recv3);
  Serial.print(",");
  Serial.print(recv4);
  Serial.print(",");
  Serial.print(recv5);
  Serial.print(",");
  Serial.print(recv6);
  Serial.print(",");
  Serial.print(recv7);
  Serial.print(",");
  Serial.print(recv8);
  Serial.println();
  
  // communication stops
  // too fast communication might cause some latency in Processing
  // this delay resolves the issue.

  delay(100);
}
