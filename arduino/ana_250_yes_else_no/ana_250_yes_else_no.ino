//int pinAnalog = A0;
//int anaValue;
//
//void setup() {
//  pinMode(pinAnalog, INPUT);
//  Serial.begin(9600);
//}
//
//void loop() {
//  anaValue = analogRead(pinAnalog);
//  Serial.println("------Original Value------");
//  Serial.println(anaValue);
//  int mapped = map(anaValue, 0, 1023, 0, 255);
//  Serial.println("------Converted------");
//  Serial.println(mapped);
//  delay(500);
//}





int pinAnalog = A0;
int anaValue;

void setup() {
  pinMode(pinAnalog, INPUT);
  Serial.begin(9600);
}

void loop() {
  anaValue = analogRead(pinAnalog);
//  Serial.println("------Original Value------");
  Serial.println(anaValue);
  if(anaValue > 250){
    Serial.println("Yes");
  }else{
    Serial.println("No");
  }
}
