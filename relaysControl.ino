#define BLYNK_TEMPLATE_ID "TEMPLATE ID"
#define BLYNK_TEMPLATE_NAME "TEMPLATE NAME"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_ESP32_DEV_MODULE

#include "BlynkEdgent.h"
// Define GPIO pins connected to the relays
#define RELAY1_PIN 15   // First relay (e.g., GPIO 15)
#define RELAY2_PIN 4   // Second relay (e.g., GPIO 4)

void setup()
{
  Serial.begin(115200); // Start serial communication for debugging
  delay(100);

  // Set relay pins as output
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  // Turn off both relays initially
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);

  // Initialize Blynk connection
  BlynkEdgent.begin();
}

void loop() {
  // Run Blynk connection and tasks
  BlynkEdgent.run();
}

// Handle virtual pin V0 to control Relay 1
BLYNK_WRITE(V0)
{
  int value = param.asInt(); // Read value from Blynk (0 or 1)
  digitalWrite(RELAY1_PIN, value); // Turn relay on or off
}

// Handle virtual pin V1 to control Relay 2
BLYNK_WRITE(V1)
{
  int value = param.asInt(); // Read value from Blynk (0 or 1)
  digitalWrite(RELAY2_PIN, value); // Turn relay on or off
}