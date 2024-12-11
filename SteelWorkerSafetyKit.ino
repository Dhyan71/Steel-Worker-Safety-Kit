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
   Serial.begin(115200);

  // Initialize sensors and LEDs
  dht.begin();
  pinMode(TEMP_LED, OUTPUT);
  pinMode(GAS_LED, OUTPUT);
  pinMode(SOUND_LED, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start Web Server
  server.on("/", HTTP_GET, []() {
    server.send_P(200, "text/html", index_html);
  });

  server.on("/data", HTTP_GET, []() {
    String json = String("{\"temperature\":") + temperature +
                  ",\"gas\":" + mq2Value +
                  ",\"sound\":" + soundValue +
                  ",\"tempAlert\":" + (temperature > TEMP_THRESHOLD) +
                  ",\"gasAlert\":" + (mq2Value > MQ2_THRESHOLD) +
                  ",\"soundAlert\":" + (soundValue > SOUND_THRESHOLD) + "}";
    server.send(200, "application/json", json);
  });

  server.begin();
  Serial.println("Web Server started");
}


void loop() {
  // Read sensors
  temperature = dht.readTemperature();
  mq2Value = analogRead(MQ2PIN);
  soundValue = analogRead(SOUND_SENSOR_PIN);

  // Handle LED blinking for alerts
  unsigned long currentMillis = millis();

  if (temperature > TEMP_THRESHOLD) {
    if (currentMillis - previousMillisTemp >= blinkInterval) {
      previousMillisTemp = currentMillis;
      tempLedState = !tempLedState;
      digitalWrite(TEMP_LED, tempLedState);
    }
  } else {
    digitalWrite(TEMP_LED, LOW);
  }

  if (mq2Value > MQ2_THRESHOLD) {
    if (currentMillis - previousMillisGas >= blinkInterval) {
      previousMillisGas = currentMillis;
      gasLedState = !gasLedState;
      digitalWrite(GAS_LED, gasLedState);
    }
  } else {
    digitalWrite(GAS_LED, LOW);
  }

  if (soundValue > SOUND_THRESHOLD) {
    if (currentMillis - previousMillisSound >= blinkInterval) {
      previousMillisSound = currentMillis;
      soundLedState = !soundLedState;
      digitalWrite(SOUND_LED, soundLedState);
    }
  } else {
    digitalWrite(SOUND_LED, LOW);
  }

  // Handle web server client requests
  server.handleClient();
}

