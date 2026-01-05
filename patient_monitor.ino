#include <WiFi.h>
#include <HTTPClient.h>

// Replace with your WiFi credentials
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

// Server URL for sending data
const char* serverName = "http://YOUR_PC_IP:5000/update";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
  // Simulated sensor data
  float heartRate = random(60, 100);
  float temperature = random(360, 380)/10.0; // 36.0 to 38.0 C
  float oxygen = random(94, 100);

  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String serverPath = serverName + "?heart=" + String(heartRate) + "&temp=" + String(temperature) + "&oxygen=" + String(oxygen);
    
    http.begin(serverPath);
    int httpResponseCode = http.GET();
    if(httpResponseCode>0){
      String response = http.getString();
      Serial.println(response);
    }
    else{
      Serial.println("Error sending data");
    }
    http.end();
  }
  delay(5000); // send every 5 seconds
}
