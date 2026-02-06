#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

// =====================================================
// 🔐 USER CONFIGURATION (ADD YOUR CREDENTIALS HERE)
// =====================================================

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Cloud SMS API Credentials
const char* apiKey = "YOUR_API_KEY_HERE";
const char* templateID = "101";
const char* mobileNumber = "91XXXXXXXXXX";

// =====================================================
// OLED SETUP
// =====================================================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// =====================================================
// SYSTEM VARIABLES
// =====================================================

float voltage;
unsigned long lastSMS = 0;
const unsigned long cooldown = 20000;

// =====================================================
// SEND SMS FUNCTION
// =====================================================

void sendSMS(String statusMsg) {

  if (millis() - lastSMS < cooldown) return;

  Serial.println("Sending SMS...");

  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;

  String url =
    "https://www.circuitdigest.cloud/api/v1/send_sms?ID=" +
    String(templateID);

  http.begin(client, url);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");

  String payload =
    "{\"mobiles\":\"" + String(mobileNumber) +
    "\",\"var1\":\"Voltage\"" +
    ",\"var2\":\"" + statusMsg + "\"}";

  int httpCode = http.POST(payload);

  Serial.print("HTTP Code: ");
  Serial.println(httpCode);

  String response = http.getString();
  Serial.println(response);

  http.end();
  lastSMS = millis();
}

// =====================================================
// SETUP
// =====================================================

void setup() {

  Serial.begin(115200);

  Serial.print("Connecting WiFi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");

  Wire.begin(21,22);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while(1);
  }

  display.clearDisplay();
  display.display();
}

// =====================================================
// LOOP
// =====================================================

void loop() {

  voltage = random(180, 270);

  String status;

  if (voltage > 250) {
    status = "High Voltage";
    sendSMS(status);
  }
  else if (voltage < 200) {
    status = "Low Voltage";
    sendSMS(status);
  }
  else {
    status = "Perfect";
  }

  // OLED UI
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Volt:");

  display.setCursor(0,25);
  display.print(voltage);

  display.setTextSize(1);
  display.setCursor(0,50);
  display.print("Status:");
  display.print(status);

  display.display();

  delay(3000);
}
