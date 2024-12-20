//  SerialIn_SerialOut_HM-10_01
//
//  Uses hardware serial to talk to the host computer and AltSoftSerial for communication with the bluetooth module
//
//  What ever is entered in the serial monitor is sent to the connected device
//  Anything received from the connected device is copied to the serial monitor
//  Does not send line endings to the HM-10
//
//  Pins
//  BT VCC to Arduino 5V out.
//  BT GND to GND
//  Arduino D8 (SS RX) - BT TX no need voltage divider
//  Arduino D9 (SS TX) - BT RX through a voltage divider (5v to 3.3v)
//
//#include "Adafruit_Sensor.h"
//#include "Adafruit_AM2320.h"
//Adafruit_AM2320 am2320 = Adafruit_AM2320();
#include <AltSoftSerial.h>
AltSoftSerial BTserial;
// https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html
char c=' ';
const int ledPin = 13;    // the number of the LED pin
boolean NL = true;
int x = A0;
int y = A1;
int joystickx = 0;
int joysticky = 0;
 //Holds joystick value for transmission
String intHold = " ";
int finalTemp = 0;
void setup()
{
    pinMode(ledPin, OUTPUT);    
    pinMode(x, INPUT);
    pinMode(y, INPUT);
    Serial.begin(9600);
    //Serial.print("Sketch:   ");   Serial.println(__FILE__);
    //Serial.print("Uploaded: ");   Serial.println(__DATE__);
    //Serial.println(" ");
    BTserial.begin(9600);
    //Serial.println("BTserial started at 9600");
    //Initialization protocol version 1
    BTserial.print("AT");
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(1000);
    BTserial.print("AT+ROLE1");
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(1000);
    BTserial.print("AT+CO0B0D27832FC29");
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(1000);
    BTserial.print("AT+CO0B0D27832FC29");
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(1000);
    BTserial.print("AT+CO0B0D27832FC29");
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    while (!Serial) {
      delay(10); // hang out until serial port opens
    
    }
}
void loop()
{
    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available())
    {
        c = BTserial.read();
        digitalWrite(ledPin, HIGH);
        Serial.write(c);
    }
    // Read from the Serial Monitor and send to the Bluetooth module
    if (Serial.available())
    {
        c = Serial.read();
        // do not send line end characters to the HM-10
        if (c!=10 & c!=13 )
        {
             BTserial.write(c);
        }
        // Echo the user input to the main window.
        // If there is a new line print the ">" character.
        if (NL) { Serial.print("\r\n>");  NL = false; }
        Serial.write(c);
        if (c==10) { NL = true; }
    }
        //BTserial.write(Serial.read());
        delay(40);
    
    joystickx = analogRead(x);
    BTserial.print("{");
    BTserial.print(joystickx);
    //delay(1000);
    Serial.println(joystickx);
    BTserial.print(",");
    joysticky = analogRead(y);
    BTserial.print(joysticky);
    //delay(1000);
    Serial.println(joysticky);
    BTserial.print("}\n");
    delay(35);
    
}