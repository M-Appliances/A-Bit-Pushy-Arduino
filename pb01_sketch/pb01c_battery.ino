//ALPHA RELEASE V 0.1.1

void battery_level() {

  // read the battery level from the ESP8266 analog in pin.
  // analog read level is 10 bit 0-1023 (0V-1V).
  // our 1M & 220K voltage divider takes the max
  // lipo value of 4.2V and drops it to 0.758V max.
  // this means our min analog read value should be 580 (3.14V)
  // and the max analog read value should be 774 (4.2V).

  level = analogRead(A0);
  levelUnMod = analogRead(A0);
  // convert battery level to percent
  blevel = map(level, 580, 774, 0, 100);
  xlevel = level*100;
  xbvolt = map(xlevel, 58000, 77400, 314, 420);
  bvolt = xbvolt/100;
}

void battery_alert() {
  // Low Battery
  if (blevel < 10) {
    digitalWrite(alertLED, HIGH);
    delay (850);
    digitalWrite(buzzer, HIGH);
    delay (150);
    digitalWrite(alertLED, LOW);
    digitalWrite(buzzer, LOW);
    Serial.println("Low Battery");
  }
  // Fully Charged Battery
  else if (blevel > 98) {
    digitalWrite(LED, HIGH);
    delay (100);
    digitalWrite(LED, LOW);
    Serial.println("Battery Is Charged");
  }
  else {
    // Do nothing if battery is neither fully charged or low!
  }
  Serial.print("Battery level: "); Serial.print(blevel); Serial.print("%"); Serial.print(" / "); Serial.print(bvolt); Serial.println(" v");
  Serial.print("A0 pin reading: "); Serial.println(levelUnMod);
  Serial.println("");
  var = 0;
};
