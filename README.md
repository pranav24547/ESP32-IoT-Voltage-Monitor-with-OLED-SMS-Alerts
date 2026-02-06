# ⚡ ESP32 IoT Voltage Monitor with OLED & SMS Alerts

An IoT-based smart voltage monitoring system built using **ESP32**, featuring real-time voltage status display on an **OLED screen** and instant fault alerts via **Cloud SMS API** — without requiring a GSM module.

---

## 🚀 Features

* 📟 0.96" OLED live voltage display
* ⚠️ High Voltage detection
* ⚠️ Low Voltage detection
* ✅ Normal voltage status
* 📩 Instant SMS alerts via Cloud API
* 🌐 Works over Wi-Fi (no SIM required)
* 🔁 Cooldown logic to prevent SMS spam
* 🧪 Simulation supported (Wokwi)

---

## 🧠 System Architecture

ESP32 reads voltage conditions →
Displays status on OLED →
Triggers Cloud API →
SMS sent to registered phone.

---

## 🔧 Hardware Required

* ESP32 Dev Board
* SSD1306 OLED Display (I2C)
* Wi-Fi Internet Connection
* USB Power Supply

---

## 🔌 OLED Wiring

| OLED | ESP32   |
| ---- | ------- |
| VCC  | 3.3V    |
| GND  | GND     |
| SDA  | GPIO 21 |
| SCL  | GPIO 22 |

---

🔌 Schematic Diagram

<img src="https://github.com/pranav24547/ESP32-IoT-Voltage-Monitor-with-OLED-SMS-Alerts/blob/main/esp sms.png">

---

## 📡 SMS API Used

CircuitDigest Cloud SMS API enables ESP32 to send SMS alerts over HTTPS without GSM hardware.

---

## 📊 Voltage Logic

| Voltage Range | Status          |
| ------------- | --------------- |
| < 200V        | Low Voltage ⚠️  |
| 200–250V      | Perfect ✅       |
| > 250V        | High Voltage ⚠️ |

---

🖥️ Serial Monitor Output

<img src="https://github.com/pranav24547/ESP32-IoT-Voltage-Monitor-with-OLED-SMS-Alerts/blob/main/serial esp.png">

---

## 📁 Libraries Used

* Adafruit GFX
* Adafruit SSD1306
* WiFi
* HTTPClient
* WiFiClientSecure

---

## 📸 Project Output

<img src="https://github.com/pranav24547/ESP32-IoT-Voltage-Monitor-with-OLED-SMS-Alerts/blob/main/sms.jpeg">

---

## 🏷️ Keywords (SEO)

ESP32 IoT, Voltage Monitor, OLED Display, SMS Alert System, Smart Energy Monitoring, Cloud SMS API, CircuitDigest, IoT Fault Detection.

---

## 📜 License

Developed by **Pranav Thanavel**  
For academic and educational purposes.

---

⭐ If you find this project helpful, consider giving it a star on GitHub!
