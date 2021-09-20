// Adafruit Unified Sensor - Version: Latest
#include <Adafruit_Sensor.h>

// DHT sensor library - Version: Latest
#include <DHT.h>
#include <DHT_U.h>

/*
  Sketch generated by the Arduino IoT Cloud Thing "Aditya Chanan"
  https://create.arduino.cc/cloud/things/3251df02-ea80-4fd8-a7ca-4a84ae6be870

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float readHum;
  CloudSwitch led_state;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/
#define DHTTYPE DHT22
#include "thingProperties.h"
#define DHTPIN A7 // Pin connected to the DHT 22 sensor

DHT dht(A7, DHT22);

int checkStartTime = 0;
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  dht.begin();
  pinMode(LED_BUILTIN, OUTPUT);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here
  readHum = dht.readHumidity();
  if (readHum >= 63)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.println(readHum);
}

void onTestVarChange() {
  // Do something
}








void onLedStateChange()
{
  // Do something
  if (digitalRead(LED_BUILTIN) == HIGH)
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  else
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
