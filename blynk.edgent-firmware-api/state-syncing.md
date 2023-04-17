# State Syncing

### For hardware

If your hardware loses an Internet connection or resets, you can restore all the values from Datastreams in the Blynk app.

```cpp
BLYNK_CONNECTED() {
   Blynk.syncAll();
}

//here are handlers for the sync command
BLYNK_WRITE(V0) {
   ....
}
```

The `Blynk.syncAll()` command restores all Dastatstream's values based on the last saved values on the server. All analog and digital pin states will be restored. Every Virtual Pin will perform `BLYNK_WRITE` call.

**NOTE**: if the datastream value is empty (doesn't have a default value,) and wasn't initialized, hardware will not get any response for those datastreams during sync.

**NOTE**: `Blynk.syncAll()` returns data only for the datastreams marked as "Sync with latest server value" in your template setup:

![Sync datastream for Blynk.syncAll() command](../.gitbook/assets/screenshot-blynk-qa.com-2023.04.17-19\_19\_57.png)

[Sync Hardware with App state](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/HardwareSyncStateFromApp/HardwareSyncStateFromApp.ino)

You can also request a single Virtual Pin value by calling `Blynk.syncVirtual(V0)` or you can request several datastreams with `Blynk.syncVirtual(V0, V1, V2, ...)`. In case of the `Blynk.syncVirtual()` command you don't need to mark your datastream as "Sync with latest server value" in your template settings.



[Storing a single value on the server](https://github.com/blynkkk/blynk-library/blob/master/examples/More/ServerAsDataStorage/ServerAsDataStorage\_SingleValue/ServerAsDataStorage\_SingleValue.ino)

[Storing multiple values on the server](https://github.com/blynkkk/blynk-library/blob/master/examples/More/ServerAsDataStorage/ServerAsDataStorage\_MultiValue/ServerAsDataStorage\_MultiValue.ino)

### For app

If you need to keep your hardware in sync with the Datastreams state even if the app is offline use `Blynk.virtualWrite`.

Imagine you have a LED Widget connected to the Virtual Pin V1 in the app, and a physical button attached to your hardware. When you press a physical button, you would expect to see the updated state of the LED Widget in the app. To achieve that you need to send `Blynk.virtualWrite(V1, 255)` when a physical button gets pressed.

[Represent physical button state via LED widget with interrupts](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)

[Represent physical button state via LED widget with polling](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonPoll/ButtonPoll.ino)

[Represent physical button state via Button widget with polling](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/SyncPhysicalButton/SyncPhysicalButton.ino)
