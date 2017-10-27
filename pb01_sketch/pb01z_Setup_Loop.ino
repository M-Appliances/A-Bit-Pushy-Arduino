//ALPHA RELEASE V 0.1.1

void setup() {

  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(alertLED, OUTPUT);
  Serial.begin(115200);
  delay(2000);
  connectToWifi();
}

void loop() {

  // Check battery every 10 seconds with var
  var = 0;
  while (var < 15000) {
    delay (1);
    buttonStatus = digitalRead(button);
    // Check Online Status
    if (WiFi.status () == WL_CONNECTED) {
      button_press();
    } 
    else {
      // Insert WIFI error function here
      errorCount = 120000;
      Serial.println("Retry connecting after 2 minutes");
      battery_level();
      battery_alert();

      while (errorCount >= 0) {
        button_press_no_connection();
        delay(1);
        errorCount--;
      }

      if (errorCount <= 0) {
        connectToWifiSilent();
      }

    }
    var++;
  };
  
  if (var >= 15000) {
    //
    // Battery Voltage Check
    //
    battery_level();
    battery_alert();
  }
}
