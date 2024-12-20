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
 
#include <AltSoftSerial.h>
AltSoftSerial BTserial; 
// https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html
 
 
char c=' ';
boolean NL = true;
int LED = 3; //LED pin
String numStore = " "; //Stores characters as integer
int finalNum = 0; //numStore converted into an integer
float conv = 0.24926; //Converts analog signal range to PWM transmission range


void setup() 
{
    pinMode(3, OUTPUT);
    Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" ");
 
    BTserial.begin(9600);  
    Serial.println("BTserial started at 9600");
}
 
void loop()
{

    // Read from the Bluetooth module and send to the Arduino Serial Monitor
   
    
    if (BTserial.available())
    {
        c = BTserial.read();
        Serial.write(c);

        std::string s = c;
        std::string delimiter = ",";

        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
          token = s.substr(0, pos);
          std::cout << token << std::endl;
          s.erase(0, pos + delimiter.length());
        }
        std::cout << s << std::endl;
    }
}
    

