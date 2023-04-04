# Blynk Protocol

Blynk Library uses proprietary binary protocol.&#x20;

Every message consists of 2 parts.

1. Header :

Protocol command (1 byte);

* MessageId (2 bytes);
* Body message length (2 bytes);

2\. Body : string (could be up to 2^15 bytes).

Blynk transfers binary messages with the following structure:

| Command | Message Id | Length/Status |   Body   |
| :-----: | :--------: | :-----------: | :------: |
|  1 byte |   2 bytes  |    2 bytes    | Variable |

Message size is 1 byte + 2 bytes + 2 bytes + messageBody.length
