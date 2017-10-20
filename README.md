# A-Bit-Pushy
*AKA the PB01*

This is the first Pantri device.  How cool is that eh?!

Whats it do?

...well, nothing until you've built it.  Once you have put everything together, then you'll end up with a swanky push button that you can press to connect to the Pantri service.

Once there you can do loads of cool stuff with groceries automatically.  Visit [pantri.net](http://pantri.net) to find out more.

> The idea is that you can:
> 
1. get a shopping list of bits
2. download schematic drawings
3. build the electronic circuits
4. download the 3D case CAD files
5. Edit them if you like
6. Print a case
7. Download the Arduino code
8. Flash it onto your Arduino
9. Assemble it all
10. Have a kick ass product that you put together yourself that automatically reorders grocery items for you!  MEGA!
>
> The hope is that you'll then go off & make even cooler products that will find new cool ways to track grocery inventory usage!

# Shopping List

Heres the list of bits that you need to purchase to build the device:

[Insert content here]

#Schematics

[Insert content here]

#3D Printed Case

[Insert content here]

#Arduino Software

[Insert content here]

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