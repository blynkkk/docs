# Timezone / Location

Device can request advanced timezone / location information:

```text
Timezone:        Europe/Kiev
ISO-8601 time:   2020-10-06T10:16:26+03:00
Unix time (UTC): 1601968586694
TZ offset:       120 minutes
DST offset:      60 minutes
POSIX TZ rule:   EET-2EEST,M3.5.0/3,M10.5.0/4
Next offset changes: 120min. on 1603587600, 180min. on 1616893200
Location:        41.941692,-88.390674
```

Example:

```cpp
BLYNK_CONNECTED() {
    // Send requests for different internal data
    // Request what is actually needed for your use-case
    Blynk.sendInternal("utc", "tz_name");   // Name of timezone
    Blynk.sendInternal("utc", "iso");       // ISO-8601 formatted time
    Blynk.sendInternal("utc", "time");      // Unix timestamp (with msecs)
    Blynk.sendInternal("utc", "tz");        // Timezone and DST offsets
    Blynk.sendInternal("utc", "tz_rule");   // POSIX TZ rule
    Blynk.sendInternal("utc", "dst_next");  // Up to 2 next time offset changes (due to DST)
}

// Receive UTC data
BLYNK_WRITE(InternalPinUTC) {
    String cmd = param[0].asStr();
    if (cmd == "time") {
        uint64_t utc_time = param[1].asLongLong();
        Serial.print("Unix time (UTC): "); Serial.println(utc_time);
        
    } else if (cmd == "iso") {
        String iso_time = param[1].asStr();
        Serial.print("ISO-8601 time:   "); Serial.println(iso_time);
        
    } else if (cmd == "tz") {
        long tz_offset = param[1].asInt();
        long dst_offset = param[2].asInt();
        Serial.print("TZ offset:       "); Serial.print(tz_offset);  Serial.println(" minutes");
        Serial.print("DST offset:      "); Serial.print(dst_offset); Serial.println(" minutes");
    
    } else if (cmd == "tz_name") {
        String tz_name = param[1].asStr();
        Serial.print("Timezone:        "); Serial.println(tz_name);
    
    } else if (cmd == "tz_rule") {
        String tz_rule = param[1].asStr(); 
        Serial.print("POSIX TZ rule:   "); Serial.println(tz_rule);
   
    } else if (cmd == "dst_next") {
        uint32_t next1_ts  = param[1].asLong();
        int next1_off       = param[2].asInt();

        uint32_t next2_ts  = param[3].asLong();
        int next2_off       = param[4].asInt();
        
        Serial.print("Next offset changes: ");
        Serial.print(next1_off); Serial.print("min. on "); Serial.print(next1_ts);
        Serial.print(", ");
        Serial.print(next2_off); Serial.print("min. on "); Serial.print(next2_ts);
        Serial.println();
    }
}
```



