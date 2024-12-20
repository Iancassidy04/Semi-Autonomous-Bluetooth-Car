#include <AltSoftSerial.h>
AltSoftSerial BTserial; 
// https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html
#include <NewPing.h>

#define TRIGGER_PIN  11
#define ECHO_PIN     10
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
char c=' ';
boolean NL = true;
int LED = 3; //LED pin
String numStore = " "; //Stores characters as integer
int finalNum = 0; //numStore converted into an integer
float conv = 0.24926; //Converts analog signal range to PWM transmission range
int ind1, ind2, ind3;
String strX;
String strY;
float x;
float y;
String dx = " ";
String dy = " ";
String state = " ";

void setup() {
  // put your setup code here, to run once:
    pinMode(3, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);    
    Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" ");
 
    BTserial.begin(9600);  
    Serial.println("BTserial started at 9600");
}
 


void loop() {
  // put your main code here, to run repeatedly:

    
  if (BTserial.available())
    {
        c = BTserial.read();
        //Serial.write(c);
        numStore += String(c);
        //Serial.println(numStore);

  delay(4);
    }
  else if (c = "}") {
    long distance = sonar.ping_cm();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    ind1 = numStore.indexOf("{");
    ind2 = numStore.indexOf(",");
    ind3 = numStore.indexOf("}");
    strX = numStore.substring(ind1 + 1, ind2);
    strY = numStore.substring(ind2 + 1, ind3);
    //Serial.print(strX.toInt());
    //Serial.println("\t");
    //Serial.print(strY.toInt());
    //Serial.println("\t");
    numStore = "";
    dx = "";
    dy = "";
    //state = "";    
    Serial.println(numStore);


  if (strX.toInt() > 900){
    dx += 2;
  }
  else if (strX.toInt() < 100){
    dx += 0;
  }
  else{
    dx += 1;
  }  
  
  if (strY.toInt() > 900){
    dy += 2;
  }
  else if (strY.toInt() < 100){
    dy += 0;
  }
  else{
    dy += 1;
  }
  
  Serial.println(dx);
  Serial.println(dy);
  

 
  if (distance <= 20 && distance != 0){
    state += 0; //backwards
    }
  //state = "";
  
  else if (dx.toInt() == 1){
    if (dy.toInt() == 0){
      state += 0; //backwards
    }
    if (dy.toInt() == 1){
      state += 1; //nuetral
    }
    if (dy.toInt() == 2){
      state += 2; //forwards
    }
  //state = "";
  }
  else if (dx.toInt() == 0){
    if (dy.toInt() == 0){
      state += 3; //left and backward
    }
    else if (dy.toInt() == 1){
      state += 4; //direct left         
    }
    else if (dy.toInt() == 2){
      state += 5; //left and forward
    }
  //Serial.println(state.toInt());
  //state = "";
  }
  else if (dx.toInt() == 2){
    if (dy.toInt() == 0){
      state += 6; //right and backward
    }
    else if (dy.toInt() == 1){
      state += 7; //direct right         
    }
    else if (dy.toInt() == 2){
      state += 8; //right and forward
    }
  //Serial.println(state.toInt());
  //state = "";
  } 
  Serial.println(state.toInt());
  Serial.write(state.toInt());
  state = "";
  // declare the variable "color"            // set the variable to any value in the range [0-255]
  
  //Serial.println(state.toInt());
      // transmit the byte-variable "color"
  //Serial.println(dx.toInt());

  //Serial.println(dy.toInt());


delay(75);

}}
