#include <reroSensor_US.h>                                        //Libary Of Ultrasonic Sensor
#include <SoftwareSerial.h>
reroSensor_US US(2, 3, 8);                                        //define class of reroSensor_US=US (rxpin,txpin,ctrlpin)
void setup() {
  Serial.begin(9600);               
  US.begin(19200);                                                //Standard baudrate 19200.
  pinMode(8, OUTPUT);                                             //Set Pin Mode
  delay(1000);
}
void loop() {
 
  word distance=US.pingUS(102);                                  //define distance as function to find out the reading of the distance of ultrasonic sensor.
  Serial.print("Check Ultrasonic Ping:");
  Serial.println(US.errStatus);                                  //the standart of the value is 0, if got error the value will be 255.
  if(US.errStatus>0){
    Serial.println("Ultrasonic Ping ERROR!");               
  }
  else
  {
    Serial.print("Distance(cm):");
    Serial.println(distance);                                   //The value will be in centimeter
  }
  delay(1000);
}
