# Image Button

The image button widget allows you to not only control your device by switching between two states (e.g. on/off) but also display any image making your dashboard more visually engaging.&#x20;

For the image, you need to provide http/s url to it. The URL should be a valid endpoint to the binary data of the image. URL shortener will not work.

The widget has two images representing on/off state.

[![image](https://user-images.githubusercontent.com/24506752/171159657-bddb6373-1cc5-4fa1-8a58-db10c3727f08.png)](https://user-images.githubusercontent.com/24506752/171159657-bddb6373-1cc5-4fa1-8a58-db10c3727f08.png)

The main use case for this widget is similar to that of the on/off Switch widget but enriched with images.

### Datastream

Only Integer Datastream can be used here.

### Mode

The image button widget can operate in these modes:

* Push: on finger release, the device will switch off but the button will return to its original state
* Switch: on finger release, the device and the button will toggle between the on and off states

### Images

[![image](https://user-images.githubusercontent.com/24506752/171161912-d15f26bf-e4e6-4df6-930f-4cfb6fe29505.png)](https://user-images.githubusercontent.com/24506752/171161912-d15f26bf-e4e6-4df6-930f-4cfb6fe29505.png)

**Off Image** - for the minimum datastream value\
**On Image** - for the maximum datastream value

### Display options

As of now, the image button widget supports 2 display options:

* **Fit:** The image will be scaled to fit the height or width of the widget size
* **Fill:** The image will be scaled to fill the widget area. Cropping may occur

### How to send data from the device

The widget works in push or switch modes. It allows sending any number value on button click and button release events. By default, the widget uses 0/1 (LOW/HIGH) values. It sends 1 (HIGH) on press and sends 0 (LOW) on release.\
You can change the button state on the hardware side. For example, turn on the button assigned to virtual pin V1 on sending 1 :

```
Blynk.virtualWrite(V1, 0); // show off image
Blynk.virtualWrite(V1, 1); // show on image
```

Don't put `Blynk.virtualWrite()` into the `void loop()` as it can cause a flood of messages and your hardware will be disconnected from the server for spam. Send such updates only when necessary.

### Get data using Blynk library

You can also get the button state from the server in case your hardware was disconnected with the Blynk Sync feature :

```
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
}

BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
}
```

### Send data using HTTP API

Please check this article [https://docs.blynk.io/en/blynk.cloud/update-datastream-value](https://docs.blynk.io/en/blynk.cloud/update-datastream-value)

### Set image URLs via setProperty function

You can set \*\* onImageUrl\*\* via setProperty function:

```
Blynk.setProperty(V1, "onImageUrl", "https://blynk.cloud/static/icon.png");
```

You can set \*\* offImageUrl\*\* via setProperty function:

```
Blynk.setProperty(V1, "offImageUrl", "https://blynk.cloud/static/icon.png");
```
