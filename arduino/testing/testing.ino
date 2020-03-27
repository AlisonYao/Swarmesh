const int ledPin = 13; //global variable

//setup the serial
void setup() {
  Serial.begin(9600);      //setup serial
  pinMode(ledPin,OUTPUT);    // let the LED blink

  countDown(5);

  int j = 3;
  while(j > 0){
    Serial.print(j);
    Serial.print(", ");
    j--;
  }
  Serial.println("Go...\n");
  Serial.print("3.11111111 + 4.11111111 = ");
//  Serial.println(addFloats(3.11111111, 4.11111111), 8);
//  Serial.println(addDoubles(3.11111111, 4.11111111), 8);

  bool canVote = true;

  Serial.print("Can I vote? ");
  Serial.println(((canVote == true) ? "Yes" : "No"));

  //chat letD = "D";
  //Serial.println(letD);
}



// it is a for loop
// unless you write while(1)
void loop() {
  static int delayPeriod = 100;  // it pretty much means global ...
  static int countDir = 1;
  
  digitalWrite(ledPin,HIGH);
  delay(delayPeriod);
  digitalWrite(ledPin,LOW);
  delay(delayPeriod);

  countDir = checkDirChange(delayPeriod, countDir);

  delayPeriod += 100 * countDir ; 
  Serial.print("New Wait Time: ");
  Serial.println(delayPeriod);
}

int checkDirChange(int delayPeriod, int countDir){
  if((delayPeriod == 1000 ) || (delayPeriod == 0)){    //&& is and 
      countDir *= -1; 
       
      if(countDir < 0){
        Serial.println("Going Down");
      } else {
        Serial.println("Going Up");
           
    }
  }
  return countDir;
}


void countDown(int max){
  for(int i = max ; i > 0; i--){ //this means i += 1 
    
    
  }
}




//float addFloats(float num1, float num2){
//  return num1 + num2;
//}
//
//
//
//double addDoubles(double num1, double num2){
//  return num1 + num2;
//}
