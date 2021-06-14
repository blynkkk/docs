# Metadata

### Read device metadata

```text
BLYNK_CONNECTED() {
  // Send requests for different metadata
  Blynk.sendInternal("meta", "get", "Spa Size");
  Blynk.sendInternal("meta", "get", "Pool Size");
}

BLYNK_WRITE(InternalPinMETA) {
    String field = param[0].asStr();
    if (field == "Pool Size") {
        String value = param[1].asStr();
        // Do something with pool size
    } else if (field == "Spa Size") {
        String value = param[1].asStr();
        // Do something with spa size
    }
}
```

### Write device metadata

```text
Blynk.sendInternal("meta", "set", "Serial Number", sn_value);
Blynk.sendInternal("meta", "set", "Model", model_value);
```

