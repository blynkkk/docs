# Limitations and Recommendations

* Don't put `Blynk.virtualWrite` and any other `Blynk.*` command directly inside `void loop()`- it will cause lot's of outgoing messages to our server and your connection will be terminated;
* We recommend calling functions with intervals. For example, use [BlynkTimer](https://github.com/blynkkk/docs/tree/b7e1f17dc099ba9cebae3461a13ca2fe69b767a8/blynk.edgent/README.md#blynk-firmware-blynktimer)
* Avoid using long delays with `delay()` – it may cause connection breaks;
* If you send more than 100 values per second - you may cause [Flood Error](https://github.com/blynkkk/docs/tree/b7e1f17dc099ba9cebae3461a13ca2fe69b767a8/blynk.edgent/README.md#troubleshooting-flood-error) and your hardware will be automatically disconnected from the server;
* Be careful sending a lot of `Blynk.virtualWrite` commands as most hardware is not very powerful so it may not handle many requests.

