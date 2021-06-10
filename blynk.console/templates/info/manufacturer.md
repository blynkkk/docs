# Manufacturer

It's the name of a Manufacturer that makes your Product. This field used in multiple places on the UI and is required to work with Voice Assistance \(Alexa, Google Home\).  
  
Follow these steps to set Product's Manufacturer:

* select the Product, open Info tab and copy it's Manufacturer \(single Manufacturer can be assigned to one Product\);
* in Arduino IDE Sketch find a string that contains "\#define BOARD\_VENDOR", change "Company Name" by pasting Manufacturer from the previous step;

This field is mandatory. Max length - 128 characters. Only letters, digits and space are allowed.

