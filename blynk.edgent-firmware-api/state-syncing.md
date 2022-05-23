# State Syncing

### For hardware

If your hardware looses Internet connection or resets, you can restore all the values from Widgets in the Blynk app.

```cpp
BLYNK_CONNECTED() {
    Blynk.syncAll();
}

//here handlers for sync command
BLYNK_WRITE(V0) {
   ....
}
```

The `Blynk.syncAll()` command restores all the Widget's values based on the last saved values on the server. All analog and digital pin states will be restored. Every Virtual Pin will perform `BLYNK_WRITE` event.

**NOTE**: if pin value is empty and wasn't initialized, hardware will not get any response for those pin during sync.

[Sync Hardware with App state](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/HardwareSyncStateFromApp/HardwareSyncStateFromApp.ino)

You can also update a single Virtual Pin value by calling `Blynk.syncVirtual(V0)` or you can update several pins with `Blynk.syncVirtual(V0, V1, V2, ...)`.

You can also use server to store any value without widget. Just call `Blynk.virtualWrite(V0, value)`.

[Storing single value on server](https://github.com/blynkkk/blynk-library/blob/master/examples/More/ServerAsDataStorage/ServerAsDataStorage_SingleValue/ServerAsDataStorage_SingleValue.ino)

[Storing multiple values on server](https://github.com/blynkkk/blynk-library/blob/master/examples/More/ServerAsDataStorage/ServerAsDataStorage_MultiValue/ServerAsDataStorage_MultiValue.ino)

### For app

If you need to keep your hardware in sync with Widgets' state even if app is offline use `Blynk.virtualWrite`.

Imagine you have a LED Widget connected to the Virtual Pin V1 in the app, and a physical button attached to your hardware. When you press a physical button, you would expect to see updated state of the LED Widget in the app. To achieve that you need to send `Blynk.virtualWrite(V1, 255)` when a physical button gets pressed.

[Represent physical button state via LED widget with interrupts](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)

[Represent physical button state via LED widget with polling](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonPoll/ButtonPoll.ino)

[Represent physical button state via Button widget with polling](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/SyncPhysicalButton/SyncPhysicalButton.ino)

