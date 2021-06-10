# Set Up Mobile App Dashboard

Now let's set up the mobile UI for our device.

In Blynk you can build different dashboards for the web and for the mobile app. Because screen sizes are different, you can adapt the interface to make it user-friendly.

You would need Blynk mobile app for iOS or Android to continue.

## Switch to Developer Mode

Click on the Wrench Icon to switch to Developer mode. There you should see your template\(s\). Now you can configure how your devices should work in the mobile app.

![Devices tab](https://user-images.githubusercontent.com/72790181/119994637-7235cd80-bfd5-11eb-9ad5-b932d1bfc1a6.png)

Tap on the template you would like to work with.

![Developer mode](https://user-images.githubusercontent.com/72790181/119501811-e2dcb000-bd71-11eb-8d15-23889cdc4176.png)

## Choose the Tile Design

When you are working with the Mobile Dashboard for the first time you can choose how devices will be shown in the list of devices when it's added.

There are currently 6 Tiles presets with different interactions:

* **Default** – shows Datastream value in the tile \(e.g.: temperature, volume, percentage, etc.\)
* **Icon Button** – tap on the Device Tile will trigger an action or switch ON/OFF state
* **Icon Level** – displays a certain level \(brightness, power, etc.\) based on selected Datastream value
* **Color Brightness** – allows to view and edit Color, Power status, and Brightness level of the Device
* **Image** – shows Icon or Image on the Tile. No quick actions. 
* **3 Labels** – it's a hybrid of Default and Icon Button. You can display up to 3 important values.

Choose the Icon Button Template

![Choose tile design](https://user-images.githubusercontent.com/72790181/119505413-9a26f600-bd75-11eb-9a73-986f5ab3dce0.png)

The template settings will open. Select the datastream that will be linked to the button action.

Select the Button mode - Switch. It will allow switching controlling the state of the datastream when tapping the device tile. Press OK.

![Template settings](https://user-images.githubusercontent.com/72790181/119505758-f427bb80-bd75-11eb-8a7a-175df903c363.png)

## Create Mobile Dashboard

![Empty dashboard editing](https://user-images.githubusercontent.com/72790181/119505806-00ac1400-bd76-11eb-9881-42b8daf4c4fb.png)

Now you can start building a mobile UI for your device. Tap anywhere on the canvas and add these widgets:

* Switch
* Labeled Value
* Chart

### Switch Widget Settings

Give it a title, select the datastream

![Switch settings](https://user-images.githubusercontent.com/72790181/119505855-0bff3f80-bd76-11eb-9169-c2a641f49592.png)

### Labeled Value Settings

For example, you want to show a temperature in the labeled value widget.  
Pick a datastream for temperature, also you can define a text before or after the value

![Labeled value settings](https://user-images.githubusercontent.com/72790181/119505877-10c3f380-bd76-11eb-8a83-e12979866280.png)

### Chart Widget Settings

Now choose a SuperChart widget, set up 2 datastreams for example for power and temperature.

![Super chart settings](https://user-images.githubusercontent.com/72790181/119505920-1ae5f200-bd76-11eb-9d9c-911602789f53.png)

Now your template is ready. Let's finish with the sketch and make it work.

![Dashboard editing](https://user-images.githubusercontent.com/72790181/119506005-2c2efe80-bd76-11eb-8f44-e6181d3b3c38.png)

