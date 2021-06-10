# Template ID

Product's Template ID is used to check if new Device is allowed to work with the Product's settings.

Follow these steps to allow the Device to use Product's Template you need:

* select the Product, open Info tab and copy it's Template ID
* in Arduino IDE Sketch find a string that contains "\#define BOARD\_TEMPLATE\_ID", change "TMPL0000" by pasting Template ID from the previous step

**Note: the Device will be refused by the app if it's and Product's Template ID don't match**

