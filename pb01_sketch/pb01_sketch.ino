/*

  Pantri PB01 a.k.a:

  --- A Bit Pushy ---

  ALPHA RELEASE V 0.1.1

  Distributed under GNU General Public License V3

  This sketch comprises of the following tabs:
 - pb01sketch
 - pb01a_operables    - The priniple declarations, setup & loop functions operate here.
 - pb01b_buttonPress  - The functions actioned upon button press operate here.
 - pb01c_battery      - The functions monitoring the battery voltage are located here.

*/

// Insert your personal WLAN device (home router, etc) credentials inside the speach marks.

const char* ssid     = "BTHub5-3M2M";    //  This is the name or your wireless network
//BTHub5-3M2M
//PLUSNET-7ZMW
const char* password = "846c6c8924";      //  This is your wireless network password
//846c6c8924
//38fcb463c9
const char* objectID = "1yF2myRKhe";      //  This is the objectID issued to your device (on the Pantri device dashboard)

const char* fingerprint = "08:3B:71:72:02:43:6E:CA:ED:42:86:93:BA:7E:DF:81:C4:BC:62:30";

//  This section defines pins that link your Adafruit Arduino Huzzah ESP8266 Feather board to your button, buzzer & LED.

int button = 4;      // This is the pin that connects from the output of your switch
int buzzer = 14;     // This is the pin output leading to your Buzzer
int LED = 13;        // This is the pin output leading to your LED
int alertLED = 12;   // This is the pin output leading to the red alert LED

/***************************************************

  LICENSES

  This section declares any legal obligations with relation to elements of code obtained from other repositories:

  BATTERY SCRIPT
  Adafruit IO Trigger Example
  Must use ESP8266 Arduino from:
    https://github.com/esp8266/Arduino

  Works great with Adafruit's Huzzah ESP board:
  ----> https://www.adafruit.com/product/2471

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Todd Treece for Adafruit Industries.

  MIT license, all text above must be included in any redistribution
  
****************************************************/
