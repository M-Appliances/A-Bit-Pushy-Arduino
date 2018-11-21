# A Bit Pushy
**Where it all began!**

This repo contains the code for our first device, 'A Bit Pushy'. A IoT based button device that connects directly to the Pantri Dashboard.

If you want to know what its about, then take a look at our original hackster blog post here:

[https://www.hackster.io/pantri/a-bit-pushy-6e7222](https://www.hackster.io/pantri/a-bit-pushy-6e7222)


#Help Us

We're makers & we're learning all the time.  If you think we're doing something in an overly complex manner that could be improved, or we're just doing something outright wrong, then please tell us (ideally with a repo push)?  We want this to be a community.

#Schematics

The  Schematics are available in this Repo.  Mainly because we love sharing, and hope that you will alter, improve & iterate on our design!

#3D Printed Case

You can get hold of the original case for A Bit Pushy by either buying your own here:

[https://www.shapeways.com/shops/pantri-devices](https://www.shapeways.com/shops/pantri-devices)

Or making your own by downloading the repo here:

[https://github.com/Maker-Appliances/LEGACY-BitPushy-Case](https://github.com/Maker-Appliances/LEGACY-BitPushy-Case)

As with the schematics, you can download the 3D Printed Case.  Modify it as you like.  Just make sure you send us a push if its really cool as others might want to build one like yours too. :)
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
