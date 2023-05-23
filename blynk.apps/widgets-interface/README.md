---
description: >-
  Elements used to organize other widgets and/or improve the UI of the app.
  Tabs, Menus, etc.
---

# Widgets Interface

### Tabs

The only purpose of the Tabs widget is to extend your project space. In order to edit the tabs widget - just tap on the selected tab. You can drag widgets between tabs. Only the last tab can be removed: to remove it swipe left on its name in the Settings screen.

The maximum number of tabs on iOS is 4 The maximum number of tabs on Android is 10

### Menu

The menu widget allows you to send commands to your hardware based on the selection you made on UI. The menu sends the index of the element you selected and not the label string. Sending index starts from 0. It works the same way as the usual ComboBox element.

Example code:

```
BLYNK_WRITE {
  switch (param.asInt()) {
    case 0: { // Item 1
      Serial.println("Item 1 selected");
      break;
    }
    case 1: { // Item 2
      Serial.println("Item 2 selected");
      break;
    }    
  }
}
```

You can also set Menu items from hardware side with :

```
Blynk.setProperty(V1, "labels", "label 1", "label 2", "label 3");
```

**Sketch:** [Menu](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/Menu/Menu.ino)

### Map

The map widget allows you to set a point/pin on the map from the hardware side.

You can send a point to map with regular virtual write command :

```
Blynk.virtualWrite(V1, lon, lat);
```

### Text Input

Text Input displays and lets you directly alter a string value. You can limit the maximum number of characters in widget settings.

### Numeric Input

Numeric Input displays and lets you directly alter a number value. Similar to the Step widget, it has incrementing and decrementing buttons for quicker value changes, which you can set up (step, looping) in widget settings.

### Segmented Switch

The Segmented Switch widget allows you to send commands to your hardware based on the selection you made on UI. Segmented Switch sends the index of the element you selected and not the label string. Sending index starts from 0. It works the same way as the usual ComboBox or Menu element.

Example code:

```
BLYNK_WRITE {
  switch (param.asInt()) {
    case 0: { // Item 1
      Serial.println("Item 1 selected");
      break;
    }
    case 1: { // Item 2
      Serial.println("Item 2 selected");
      break;
    }    
  }
}
```

You can also set Menu items from the hardware side with :

```
Blynk.setProperty(V1, "labels", "label 1", "label 2", "label 3");
```

**Sketch:** [Menu](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/Menu/Menu.ino)

### Icon Segmented Switch

### Text
