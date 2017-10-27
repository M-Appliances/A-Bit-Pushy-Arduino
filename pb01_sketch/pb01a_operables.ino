//ALPHA RELEASE V 0.1.1

// Do not alter anything within this TAB (unless you want to)!


/***************************************************

  // Libraries

***************************************************/

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

/***************************************************

  // Definitions

***************************************************/

int buttonStatus = 0;
int oldButtonStatus = 0;
int blevel;
float bvolt;
float xbvolt;
int level;
int xlevel;
int levelUnMod;
int var;
int connectionCount;
int timeoutAlertCount;
int errorCount;
int errorButtonCount;

/***************************************************

  // Global Functions

***************************************************/

void Flash() {
  digitalWrite(LED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay (100);
  digitalWrite(LED, LOW);
  digitalWrite(buzzer, LOW);
  delay (100);
}
void FlashLong() {
  digitalWrite(alertLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay (800);
  digitalWrite(alertLED, LOW);
  digitalWrite(buzzer, LOW);
  delay (200);
}
void errorFlash() {
  digitalWrite(buzzer, HIGH);
  delay (50);
  digitalWrite(buzzer, LOW);
  delay (50);
}

// use the ssid and password to connect to the customer's WiFi
void connectToWifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Disable AP_SSID publication in Client mode
  WiFi.mode(WIFI_STA);

  // Starts WiFi Connection
  WiFi.begin(ssid, password);

  connectionCount = 30;
  Serial.println("");

  Serial.println("Connection timeout in: ");

  // loop to check if connected to the wi fi network
  while (WiFi.status() != WL_CONNECTED && connectionCount > 0) {
    delay(450);
    digitalWrite(LED, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW);
    connectionCount--;
    Serial.print(connectionCount);
    Serial.print(" Current WiFi Status = ");
    Serial.print(WiFi.status());
    Serial.println(", ");
  }

  // we're connected to the wi fi network
  if (WiFi.status() == WL_CONNECTED) {

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("Setup Complete");

    digitalWrite(LED, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(750);
    digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW);
  }
  else { // else we never connected to the network, inform the user of the error using the buzzer and LED

    Serial.println("");
    Serial.println("Not Connected To WiFi");
    timeoutAlertCount = 0;

    while (timeoutAlertCount <= 3) {

      digitalWrite(alertLED, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(750);
      digitalWrite(buzzer, LOW);
      delay(1000);
      digitalWrite(alertLED, LOW);
      timeoutAlertCount++;
    }
  }
}

void connectToWifiSilent() {

  Serial.print("Connecting to ");
  Serial.println(ssid);
  // Disconnects from previous WiFi session
  WiFi.disconnect();
  // Disable AP_SSID publication in Client mode
  WiFi.mode(WIFI_STA);
  // Starts WiFi Connection
  WiFi.begin(ssid, password);
  connectionCount = 30;
  Serial.println("");
  Serial.println("Connection timeout in: ");
  while (WiFi.status() != WL_CONNECTED && connectionCount > 0) {
    delay(450);
    digitalWrite(LED, HIGH);
    delay(50);
    digitalWrite(LED, LOW);
    connectionCount--;
    Serial.print(connectionCount);
    Serial.print(" Current WiFi Status = ");
    Serial.print(WiFi.status());
    Serial.println(", ");
  }

  if (WiFi.status() == WL_CONNECTED) {

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("Setup Complete");
    digitalWrite(LED, HIGH);
    delay(750);
    digitalWrite(LED, LOW);

  }
  else {

    Serial.println("");
    Serial.println("Not Connected To WiFi");
    timeoutAlertCount = 0;

    digitalWrite(alertLED, HIGH);
    delay(3000);
    digitalWrite(alertLED, LOW);

  }
}

void myMacAddress() {
  Serial.print("MAC address from WiFi.macAddress() is: ");
  Serial.println(WiFi.macAddress());
}
