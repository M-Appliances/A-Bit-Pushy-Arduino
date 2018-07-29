# A-Bit-Pushy
**AKA the PB01**

This repo contains the code for the first Pantri device.  How cool is that eh?!

If you want to find out exactly what its about, then take a look here:

[https://www.hackster.io/pantri/a-bit-pushy-6e7222](https://www.hackster.io/pantri/a-bit-pushy-6e7222)

On the above link you'll find out everything you need to know about what ***A Bit Pushy*** is all about.

Theres also a shopping list for you to find out how to build one & instructions.

#Help You

If you need any support, chat to us on [Slack](https://pantri-developers.slack.com/join/shared_invite/enQtMzQ2MTQ2NjI5Mzk3LWE1NDc5OGQ1MDBhNWJhMDE5NTFjNzU1YThmOWJjZThiZGQzNjc5NWY4YWQ5YjFkNWY3NjljZGI4MmE4NTM3NmE).  Note that we're only in alpha & so you'll need to be in our alpha club to join.  If you think you have something worth contributing, then ask to join by dropping us a line (contact details at [pantri.net](http://www.pantri.net)).

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

[http://help.pantri.net/pantri-dashboard/device/add-new/](http://help.pantri.net/pantri-dashboard/device/add-new/)

You might also want to edit the pins that the various LED's & buzzer are attached toto match your setup.

Once you've done that, flash it to your Adafruit Huzzah Feather as instructed in the [Hackster.io](www.hackster.io/pantri/a-bit-pushy-6e7222) guide above & you should be in business!

# Alerts

Want to know what the "A Bit Pushy" is telling you?  Check out our help site for necessary info:

[http://help.pantri.net/a-bit-pushy/a-bit-pushy-device-alerts/](http://help.pantri.net/a-bit-pushy/a-bit-pushy-device-alerts/)
