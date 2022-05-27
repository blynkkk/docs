# Set Up Mobile App Dashboard

Now let's set up the mobile UI for our device.

In Blynk you can build different dashboards for the web and for the mobile app. Because screen sizes are different, you can adapt the interface to make it user-friendly.

You would need Blynk mobile app for iOS or Android to continue. Make sure Developer mode is turned On in your Profile.

## Select the Template

Click on the Wrench Icon to get to the list of templates.&#x20;

![Devices tab](https://user-images.githubusercontent.com/72790181/119994637-7235cd80-bfd5-11eb-9ad5-b932d1bfc1a6.png)

Tap on the template you would like to work with. If you are new to Blynk and used the Quickstart flow to get your device online, there will be just one template named Quickstart Template. Now you can configure how your devices should work in the mobile app.

![List of templates](https://user-images.githubusercontent.com/72790181/119501811-e2dcb000-bd71-11eb-8d15-23889cdc4176.png)

## Choose the Tile Design

You can choose how a device tile will look in the list of devices when added using this template.

There are currently 6 Device Tile presets with different interactions:

* **Key Value (default)** – shows Datastream value in real-time (e.g.: temperature, volume, percentage, etc.)
* **Button** – tap on the Device Tile will trigger an action or toggle ON/OFF state. Tap on the name to open the device dashboard
* **Level** – visualizes a certain level (brightness, power, etc.) based on selected Datastream value
* **Color** – indicates color, brightness, etc., and can quickly turn the device ON/OFF. Tap on the name to open the device dashboard
* **Image** – shows device image or icon. Tap anywhere will=/. open the device dashboard&#x20;
* **3 Labels** – you can display up to 3 important values plus a switch control

To choose the Device Tile preset tap on Gear Icon and after that on three dots in the top right corner. Tap Change tile type and you'll see the full list of options.

![Choose tile design preset](https://user-images.githubusercontent.com/72790181/119505413-9a26f600-bd75-11eb-9a73-986f5ab3dce0.png)

Let's select Button for this demonstration (you can edit it later). On choosing the preset, tile settings will open. Select the datastream that will be linked to the tile action.

Select the Tap Interaction - Button and the Button Mode - Switch. It will allow toggling the device ON/OFF when tapping on the device tile. Press OK.

![Tile settings](https://user-images.githubusercontent.com/72790181/119505758-f427bb80-bd75-11eb-8a7a-175df903c363.png)

## Create Mobile Dashboard

![Empty dashboard editing](https://user-images.githubusercontent.com/72790181/119505806-00ac1400-bd76-11eb-9881-42b8daf4c4fb.png)

Now you can start building a mobile UI for your device. Tap anywhere on the canvas and add these widgets:

* Button
* Labeled Value
* SuperChart

### Button Widget Settings

Give it a title (optional), select the datastream.

![Button settings](https://user-images.githubusercontent.com/72790181/119505855-0bff3f80-bd76-11eb-9169-c2a641f49592.png)

### Labeled Value Settings

For example, you want to show a temperature in the labeled value widget.\
Pick a datastream for temperature, also you can choose to use Title filed to place the label above the value or Label filed to configure the message of your choice, placing the text before and/or after the value.

![Labeled value settings](https://user-images.githubusercontent.com/72790181/119505877-10c3f380-bd76-11eb-8a83-e12979866280.png)

### SuperChart Widget Settings

Now choose a SuperChart widget, set up 2 datastreams for example for power and temperature.

![SuperChart settings](https://user-images.githubusercontent.com/72790181/119505920-1ae5f200-bd76-11eb-9d9c-911602789f53.png)

Now your template is ready. Let's finish with the sketch and make it work.

![Dashboard editing](https://user-images.githubusercontent.com/72790181/119506005-2c2efe80-bd76-11eb-8f44-e6181d3b3c38.png)
