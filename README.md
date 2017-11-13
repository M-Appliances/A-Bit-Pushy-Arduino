# A-Bit-Pushy
*AKA the PB01*

This repo contains the code for the first Pantri device.  How cool is that eh?!

If you want to find out exactly what its about, then take a look here:

[https://www.hackster.io/pantri/a-bit-pushy-6e7222](https://www.hackster.io/pantri/a-bit-pushy-6e7222)

On the above link you'll find out everything you need to know about what ***A Bit Pushy*** is all about.

Theres also a shopping list for you to find out how to build one & instructions.

#Help You

If you need any support, chat to us on [Facebook](https://www.facebook.com/groups/545153832488441/).  Note that we're only in alpha & so you'll need to be in our alpha club to join.  If you think you have something worth contributing, then ask to join by dropping us a line (contact details at [pantri.net](http://www.pantri.net)).

#Help Us

We're makers & we're learning all the time.  If you think we're doing something in an overly complex manner that could be improved, or we're just doing something outright wrong, then please tell us (ideally with a repo push)?  We want this to be a community.

#Schematics

The latest Schematics are available within this Repo.  Mainly because we hope that you will alter, improve & iterate on our design before pushing any improvements to us.

#3D Printed Case

You can get hold of a case for A Bit Pushy by either buying your own here:

[https://www.shapeways.com/shops/pantri-devices](https://www.shapeways.com/shops/pantri-devices)

Or making your own by downloading the repo here:

[https://github.com/pantri/A-Bit-Pushy-Case](https://github.com/pantri/A-Bit-Pushy-Case)

As with the schematics, you can download the 3D Printed Case.  Modify it as you like.  Just make sure you send us a Push if its really cool as others might want to build one like yours too. :)

#Arduino Software

The software here is written in the Arduino IDE.  If you don't know what you're doing with this, we suggest you start by getting an Arduino Uno ([https://store.arduino.cc/arduino-uno-rev3](https://store.arduino.cc/arduino-uno-rev3)) & a copy of a book like this ([https://www.makershed.com/products/make-getting-started-with-arduino-3rd-edition](https://www.makershed.com/products/make-getting-started-with-arduino-3rd-edition)) - note that both of these products are widely available from a range of outlets around the globe.

You don't need to be an expert to build this device, but you should be able to make an LED or two flash on a breadboard before you start getting stuck into this.

The code is split up into numerous .ino files.  This is explained in more depth in the Hackster.io article, but to programme the board you need to be aware of the following:

You add your personal configuration to the *pb01_sketch.ino* onlu.

`const char* ssid     = "`insert your WiFi name here`";`

`const char* password = "`insert your WiFi password here`";`

`const char* objectID = "`insert the object ID provided when registering the device here`";`

Regarding the last point, you obtain your objectID by registering the device as follows:

[INSERT LINK HERE TO GETTING A DEVICE OBJECT ID]

You might also want to edit the pins that the various LED's & buzzer are attached toto match your setup.

Once you've done that, flash it to your Adafruit Huzzah Feather as instructed in the [Hackster.io](www.hackster.io/pantri/a-bit-pushy-6e7222) guide above & you should be in business!

# Alerts

You will receieve alerts from A Bit Pushy in two forms; an **audible beep** & one of **3 LED Colours**.

The three LED colours are configured as follows:

* Blue (Operation in progress)
* Green (Success)
* Red (Failure)

Each of the LED's will usually be accompanied by a corresponding beep.  The LED flashes will be either short or long (a bit like Morse Code).

A short beep ( .  ) will be 100 milliseconds long.

A long beep ( _ ) will be 300 milliseconds long.

### Alert Types

The alerts & errors available are as follows:

* Low Battery Alert
* WIFI Connection
* Server Connection
* Sleep

### Test It Out

We've built some sample code to test things out here: [https://github.com/pantri/A-Bit-Pushy-Output-Test](https://github.com/pantri/A-Bit-Pushy-Output-Test)

Might be worth loading this to check everythings performing as it should.

## Low Battery Alert

When A Bit Pushy wakes up, the first thing it will do is check its remaining battery power.  One of two alerts will be displayed:

1. Battery Less Than 10% (flat)
2. Battery More Than 98% (full)

### Battery Less Than 10%

When the battery is less than 10%, the device LED & Buzzer flashes Red, Green, Blue 3 times followed by a long red light:

`.(r) .(g) .(b)`
`.(r) .(g) .(b)`
`.(r) .(g) .(b)`
`_ (r)`

_The device will then go back to sleep **WITHOUT SENDING ANY DATA TO THE SERVER**._

This is to prevent a power up when putting the device on charge sending through API calls.  This issue needs designing out using capacitors & the EN pin at a later date (work in progress).

### Battery More Than 98%

When the device is fully charged it will output a single long green alert.

`_ (g)`

## WIFI Connection Alerts

Once the battery has been checked & assuming the battery is not flat, the system will then attempt to connect to the WIFI network.  The device will output one of the following statuses:

* Connecting
* Connected
* Cannot connect to network specified [Likely password error]
* Cannot find the network specified [SSID]
* Another unspecified connection error
* Failure to connect - powering down

### Connecting

Whilst the device is connecting, it will beep a blue short light & corresponding beep.

`.(b) .(b) .(b) .(b) etc.`

This will last for up to 30 beeps as A Bit Pushy tries to connect to the WIFI signal (using the details you specified in the sketch page).

Once it has unsuccessfully tried to connect once, it will do so again 3 more times silently.

`(b)  (b)  (b)  (b)  (b) etc.`

### Successfully Connected

Once the device connects, it will emit two long green beeps:

`_ (g) _ (g)`

### Cannot connect to network specified [likely password error]

In the event that the WiFi connection cannot be established to the specified ID (likely due to a password error), the device will emit two long red beeps.

`_ (r) _ (r)`

### Cannot find the network specified [SSID]

Similarly, if the device can't find the specified network, then it will emit three long red beeps.

`_ (r) _ (r) _ (r)`

### Another Unspeicified Error

In the event that there is another reason the device can't connect, then it will emit four red beeps.

`_ (r) _ (r) _ (r) _ (r)`

### Giving Up Connecting & Going Back To Sleep

A Bit Pushy will try to connect to the specified WiFi silently three times.  In the event that it doesn't get anywhere, then it will go back to sleep.  It will signify this with an extra long red beeps.  It will remain audible for 4 seconds, with the red LED showing for a further 16 seconds

`_____ (r)`

## Server Connection

Once A Bit Pushy has connected to the web, it can then talk to the all important Pantri API (Oooohhh!).  The device will send through a REST API Post via HTTPS & await a response, which will be one of the following:

* Sent data to server successfully
* Cannot connect to server
* No response from the server
* SSL Fingerprint doesn't match
* Device has a different MAC Address
* Device is not registered on the system (Check object ID)
* Unknown Server Error		

### Sent Data To Server Successfully

In the event that all is well, the device will display 3 green beeps as follows:

`_ (g) . (g) _ (g)`

*(Long, Short, Long)*

The green light will then stay on for another three seconds before going back to sleep.

### Cannot Connect To Server

In the event that A Bit Pushy cannot connect to the server due to an internet (not WiFi connection) issue or a problem with the availability of our servers, the device will emit the following beeps:

`_ (r) . (r) _ (r) . (r) _ (r) . (r) _ (r)`

### No Reponse From The Server

If the Pantri Server Minions have decided to head out to lunch, on strike, or are messing about in the corner rather than getting on with sorting out your request, then you won't get a response.  Aside from apologising for the poor customer service, the device will provide the following output:

`_ (r) _ (r) . (r)  . (r) _ (r) _ (r) . (r) . (r)`

### SSL Fingerprint Mismatch

If the SSL fingerprint is mismatched, then the data won't transfer due to the security hole. In such an event, the following alert will be displayed:

`_ (r) _ (r) _ (r) _ (r) _ (r)`

### Device Has A Different MAC Address

Your device will report its MAC address to the API when it makes its call.  If this MAC address isn't as registered with the associated objectID, then the API Post will be rejected.  This is to stop someone obtaining an objectID & wreaking havoc on another device, or someone accidentally putting the wrong objectID on the wrong device.

In any case, you'll be alerted as follows:

`_ (r) _ (r) _ (r) _ (r) _ (r) _ (r)` (7)

### Device Is Not Registered On System

Similarly to the above error, if you type an objectID that doesn't exist on our system, then you'll end up recieving the following error returned.

`_ (r) _ (r) _ (r) _ (r) _ (r) _ (r) _ (r)` (8)

Check with your control panel to make sure you've not got a typo.

### Unspecified Error Communicating With The Pantri API

In the event that there is another error, the following output will be displayed:

`_ (r) . (b) _ (r) . (b) _ (r) . (b) _ (r)`

## Night Night (Sleep)

When the device goes to sleep it will emit a single silent long blue light.

`_ (b)`

## Alerts Summary

`.` means short beep

`_` means long beep

`(g)`means colour (in this instance green - red, green or blue are available)

Battery Less Than 10%

`.(r) .(g) .(b)`
`.(r) .(g) .(b)`
`.(r) .(g) .(b)`
`_ (r)`

Battery More Than 98%

`_ (g)`

Connecting To WiFi

`.(b) .(b) .(b) .(b) etc.`

Successfully Connected To WiFi

`_ (g) _ (g)`

WiFi Password Error

`_ (r) _ (r)` (2)

Cannot Find Network Specified

`_ (r) _ (r) _ (r)` (3)

Unspecified WiFi Connection Error

`_ (r) _ (r) _ (r) _ (r)` (4)

Giving Up Trying To Connect & Going Back To Sleep

`_____ (r)`

API Send Success

`_ (g) . (g) _ (g)`

API Not Accessible

`_ (r) . (r) _ (r) . (r) _ (r) . (r) _ (r)`

API No Response

`_ (r) _ (r) . (r)  . (r) _ (r) _ (r) . (r) . (r)`

SSL Fingerprint Mismatch

`_ (r) _ (r) _ (r) _ (r) _ (r)` (5)

Device Has A Different MAC Address Than Registered With Pantri

`_ (r) _ (r) _ (r) _ (r) _ (r) _ (r)` (6)

Device Is Not Registered On Pantri

`_ (r) _ (r) _ (r) _ (r) _ (r) _ (r) _ (r)` (7)

Unspecified Error Communicating With The Pantri Server

`_ (r) . (b) _ (r) . (b) _ (r) . (b) _ (r)`

Sleep

`_ (b)`