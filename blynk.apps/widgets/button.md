# Button

With Button you can  send any number value to the hardware. on button click and button release events. By default  
button uses 0/1 \(LOW/HIGH\) values. Button sends 1 \(HIGH\) on press and sends 0 \(LOW\) on release.

You can change button state from hardware side. For example, turn on button assigned to virtual pin V1 :

```cpp
Blynk.virtualWrite(V1, HIGH);
```

You can change button labels from hardware with :

```text
Blynk.setProperty(V1, "onLabel", "ON");
```

```text
Blynk.setProperty(V1, "offLabel", "OFF");
```

or change color :

```cpp
//#D3435C - Blynk RED 
Blynk.setProperty(V1, "color", "#D3435C");
```

You can also get button state from server in case your hardware was disconnected with Blynk Sync feature :

```text
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
}

BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
}
```

