//ALPHA RELEASE V 0.1.1

void button_press() {

  if ((buttonStatus == LOW) && (oldButtonStatus == LOW)) {

    // Code runs here when the button isn't pressed
    digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(alertLED, LOW);
  }
  if ((buttonStatus == HIGH) && (oldButtonStatus == LOW)) {
    // Code runs here immediately after the button has been pressed
    Serial.println("Button has been pressed");
    digitalWrite(LED, HIGH);
    digitalWrite(buzzer, HIGH);
    delay (500);
    oldButtonStatus = buttonStatus;
  }
  if ((buttonStatus == LOW) && (oldButtonStatus == HIGH)) {
    // Code runs here when button is released

    // SEND REST PUSH TO API
    httpPost();
    digitalWrite(buzzer, LOW);
    delay(250);
    oldButtonStatus = 0;
  }
}
void button_press_no_connection() {
  buttonStatus = digitalRead(button);
  if (buttonStatus == HIGH) {
    digitalWrite(alertLED, HIGH);
    Serial.println("BUTTON WON'T WORK WHILST NOT CONNECTED TO THE INTERNET!");
    errorButtonCount = 0;
    while (errorButtonCount <= 20) {
      digitalWrite(buzzer, HIGH);
      delay (50);
      digitalWrite(buzzer, LOW);
      delay (50);
      errorButtonCount++;
    }
    delay(3000);
    digitalWrite(alertLED, LOW);
    connectToWifiSilent();
  }
}
