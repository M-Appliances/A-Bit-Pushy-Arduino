//ALPHA RELEASE V 0.1.1

void httpPost() {
  HTTPClient http;

  //
  // Step 1: Declare the URL, headers & JSON body
  //

  myMacAddress();
  http.begin("http://pantri-api.herokuapp.com/classes/DeviceActivity/");  //Specify Request Destinations

  http.addHeader("Content-Type", "application/json");
  http.addHeader("X-Parse-Application-Id", "pantri_api");

  char json[115 + 17 + 1] = "{\"ReceiptBoolean\":true,\"Device\":{\"__type\":\"Pointer\",\"className\":\"Device\",\"objectId\":\"";
  strcat(json, objectID);
  strcat(json,"\"},\"MAC_Address\":\"");
  uint8_t MAC[6];
  WiFi.macAddress(MAC);
  char MACstr[17 + 1];
  sprintf(MACstr, "%02X:%02X:%02X:%02X:%02X:%02X", MAC[5], MAC[4], MAC[3], MAC[2], MAC[1], MAC[0]);
  strcat(json, MACstr);
  strcat(json, "\"}");

  Serial.print("Submitted JSON is: ");
  Serial.println(json);


  //
  // Step 2: Post JSON to server
  //
  int httpCode = http.POST(json); // Send the request

  //
  // Step 3: Receive server response
  //
  String payload = http.getString();  // Get the response
  Serial.print("httpCode = ");
  Serial.println(httpCode);  // Print HTTP return code
  Serial.print("Payload = ");
  Serial.println(payload);   // Print request response payload
  http.end();  // Close connection

  //
  // Step 4: Create output depending on response
  //

  if (httpCode == 201) {
    Serial.println("SUCCESS BABY...");
    digitalWrite(LED, HIGH);
    int count = 0; // This is to be replaced with "while waiting for a response from the API..."
    while (count < 4) {
      Flash();
      count++;
    };
    digitalWrite(LED, HIGH);
    delay (2000);
  } else {
    int count = 0;
    Serial.println("HOUSTON WE HAVE A PROBLEM...");
    while (count < 4) {
      FlashLong();
      count++;
    };
    digitalWrite(LED, LOW);
  }
}
/*
    A big thankyou to Youtube user tutorialsx for his guide getting the above up & running - https://youtu.be/nmzt-a-WtWw
*/
