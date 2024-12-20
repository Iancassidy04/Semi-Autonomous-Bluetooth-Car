
void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  pinMode(1, INPUT);
  Serial.begin(9600);
}
 


void loop(){
   byte data = 0;

   // - check for new serial data - and respond accordingly
   if (Serial.available() > 0) {
      int x = Serial.read();    // The "Serial.read" command returns integer-type
      data = x;                 //             
     // - now: do something with "data"
     if (data == 0) { 
       Serial.println("Backing up");
        digitalWrite(13, LOW); //Establishes forward direction of Channel B
        digitalWrite(8, LOW);   //Disengage the Brake for Channel B
        analogWrite(11, 238);   //Spins the motor on Channel B at no speed

    //Motor A forward @ full speed
        digitalWrite(12, LOW); //Establishes forward direction of Channel A
        digitalWrite(9, LOW);   //Disengage the Brake for Channel A
        analogWrite(3, 255);   //Spins the motor on Channel A at no speed

     } else if (data == 1) {
       Serial.println("Staying still");
        //digitalWrite(13, HIGH); //Establishes forward direction of Channel B
        //digitalWrite(8, LOW);   //Disengage the Brake for Channel B
        analogWrite(11, 0);   //Spins the motor on Channel B at no speed

    //Motor A forward @ full speed
        //digitalWrite(12, HIGH); //Establishes forward direction of Channel A
        //digitalWrite(9, LOW);   //Disengage the Brake for Channel A
        analogWrite(3, 0);   //Spins the motor on Channel A at no speed

     } else if (data == 2) {
       Serial.println("Moving forward");
         //Motor B forward @ full speed
       digitalWrite(13, HIGH); //Establishes forward direction of Channel B
        digitalWrite(8, LOW);   //Disengage the Brake for Channel B
        analogWrite(11, 238);   //Spins the motor on Channel B at full speed

    //Motor A forward @ full speed
        digitalWrite(12, HIGH); //Establishes forward direction of Channel A
        digitalWrite(9, LOW);   //Disengage the Brake for Channel A
          analogWrite(3, 255);   //Spins the motor on Channel A at full speed
     } 
     else if (data == 3) {
       Serial.println("Moving back and to the left");
        digitalWrite(13, LOW); //Establishes forward direction of Channel B
        digitalWrite(8, LOW);   //Disengage the Brake for Channel B
        analogWrite(11, 255);   //Spins the motor on Channel B at no speed

    //Motor A forward @ full speed
        digitalWrite(12, LOW); //Establishes forward direction of Channel A
        digitalWrite(9, LOW);   //Disengage the Brake for Channel A
        analogWrite(3, 150);   //Spins the motor on Channel A at no speed
        
     }
       else if (data == 4) {
       Serial.println("Moving left");
        digitalWrite(13, HIGH); //Establishes forward direction of Channel B
        digitalWrite(8, LOW);   //Disengage the Brake for Channel B
        analogWrite(11, 225);   //Spins the motor on Channel B at no speed

    //Motor A forward @ full speed
        digitalWrite(12, LOW); //Establishes forward direction of Channel A
        digitalWrite(9, LOW);   //Disengage the Brake for Channel A
        analogWrite(3, 0);   //Spins the motor on Channel A at no speed
       }
       else if (data == 5) {
       Serial.println("Moving forward and to the left");
        digitalWrite(13, HIGH); //Establishes forward direction of Channel B
        digitalWrite(8, LOW);   //Disengage the Brake for Channel B
        analogWrite(11, 255);   //Spins the motor on Channel B at no speed

    //Motor A forward @ full speed
        digitalWrite(12, HIGH); //Establishes forward direction of Channel A
        digitalWrite(9, LOW);   //Disengage the Brake for Channel A
        analogWrite(3, 150);   //Spins the motor on Channel A at no speed
       }
       else if (data == 6) {
       Serial.println("Moving back and to the right");
        digitalWrite(13, LOW); //Establishes forward direction of Channel B
        digitalWrite(8, LOW);   //Disengage the Brake for Channel B
        analogWrite(11, 125);   //Spins the motor on Channel B at no speed

    //Motor A forward @ full speed
        digitalWrite(12, LOW); //Establishes forward direction of Channel A
        digitalWrite(9, LOW);   //Disengage the Brake for Channel A
        analogWrite(3, 255);   //Spins the motor on Channel A at no speed
        
       }
       else if (data == 7) {
       Serial.println("Moving right");
        digitalWrite(13, HIGH); //Establishes forward direction of Channel B
        digitalWrite(8, LOW);   //Disengage the Brake for Channel B
        analogWrite(11, 0);   //Spins the motor on Channel B at no speed

    //Motor A forward @ full speed
        digitalWrite(12, HIGH); //Establishes forward direction of Channel A
        digitalWrite(9, LOW);   //Disengage the Brake for Channel A
        analogWrite(3, 210);   //Spins the motor on Channel A at no speed
       }
       else if (data == 8) {
       Serial.println("Moving forward and to the right");
        digitalWrite(13, HIGH); //Establishes forward direction of Channel B
        digitalWrite(8, LOW);   //Disengage the Brake for Channel B
        analogWrite(11, 125);   //Spins the motor on Channel B at no speed

    //Motor A forward @ full speed
        digitalWrite(12, HIGH); //Establishes forward direction of Channel A
        digitalWrite(9, LOW);   //Disengage the Brake for Channel A
        analogWrite(3, 255);   //Spins the motor on Channel A at no speed
       }

   
   }

   // ... do other tasks

}



    
  //Motor A forward @ full speed
  //digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  //digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  //analogWrite(3, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ half speed
  //digitalWrite(13, LOW);  //Establishes backward direction of Channel B
  //digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  //analogWrite(11, 123);    //Spins the motor on Channel B at half speed

//  digitalWrite(9, HIGH);  //Engage the Brake for Channel A
//  digitalWrite(9, HIGH);  //Engage the Brake for Channel B

  //Motor A forward @ full speed
//  digitalWrite(12, LOW);  //Establishes backward direction of Channel A
//  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
//  analogWrite(3, 123);    //Spins the motor on Channel A at half speed
  
  //Motor B forward @ full speed
//  digitalWrite(13, HIGH); //Establishes forward direction of Channel B
//  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
//  analogWrite(11, 255);   //Spins the motor on Channel B at full speed
  
//  digitalWrite(9, HIGH);  //Engage the Brake for Channel A
//  digitalWrite(9, HIGH);  //Engage the Brake for Channel B
  
  

