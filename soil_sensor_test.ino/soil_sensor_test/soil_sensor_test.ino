// Include Sensirion library
#include "SHT1x.h"

// Sensor pins
#define dataPin  D6
#define clockPin D7

// Variables for the temperature & humidity sensor
float temperature;
float humidity;
float dewpoint;

// Create sensor instance
SHT1x sht1x(dataPin, clockPin);


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(9600);              // Open serial connection to report values to host
  Serial.println("Starting up");  
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  //delay(1000);                      // Wait for a second
  //digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  //delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)



  float temp_c;
  float temp_f;
  float humidity;
 
  // Read values from the sensor
  temp_c = sht1x.readTemperatureC();
  temp_f = sht1x.readTemperatureF();
  humidity = sht1x.readHumidity();
 
  // Print the values to the serial port
  Serial.print("Temperature: ");
  Serial.print(temp_c, DEC);
  Serial.print("C / ");
  Serial.print(temp_f, DEC);
  Serial.print("F. Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
 
  delay(2000); 
}






 


