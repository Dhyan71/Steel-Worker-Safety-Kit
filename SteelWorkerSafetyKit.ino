#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

// Wi-Fi Credentials
const char* ssid = "Your_SSID";       // Replace with your Wi-Fi SSID
const char* password = "Your_Password"; // Replace with your Wi-Fi Password

// Pin Definitions
#define DHTPIN 5         // GPIO pin for DHT22
#define DHTTYPE DHT22    // DHT22 sensor type
#define MQ2PIN 34        // Analog pin for MQ2 gas sensor
#define SOUND_SENSOR_PIN 35 // Analog pin for sound sensor
#define TEMP_LED 4      // GPIO pin for Temperature/Humidity LED
#define GAS_LED 18       // GPIO pin for Gas LED
#define SOUND_LED 19     // GPIO pin for Sound LED

// Thresholds
const float TEMP_THRESHOLD = 32.7;   // Temperature threshold in °C
const int MQ2_THRESHOLD = 380;       // Gas level threshold
const int SOUND_THRESHOLD = 1850;    // Sound level threshold

// Initialize DHT Sensor
DHT dht(DHTPIN, DHTTYPE);

// Web Server Object
WebServer server(80);

// Sensor Data Variables
float temperature = 0.0;
int mq2Value = 0;
int soundValue = 0;

// LED Blinking Variables
unsigned long previousMillisTemp = 0;
unsigned long previousMillisGas = 0;
unsigned long previousMillisSound = 0;
const long blinkInterval = 500; // Blink interval in milliseconds
bool tempLedState = LOW;
bool gasLedState = LOW;
bool soundLedState = LOW;

#include "htmlContent.h"

void setup() {
  // Initialization code...
}

void loop() {
  // Sensor reading and LED handling code...
}
