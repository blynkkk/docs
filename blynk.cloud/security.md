# Security

- Every message sent through Blynk is encrypted and secure (unless you're using hardware that doesn't support TLS)
- Granular permissions allow you to manage who and how can see your devices and their data
- Server system design doesn't allow any other user than allowed by you to view the devices within your organization hierarchy
- Each device has own unique OAuth token and Product Id. Combination of both these fields grants access of the device only for your organization
- Constant monitoring allows us to react quickly on any possible incidents   

Blynk mostly relies on industry standards - transport layer security protocol, known as TLS. 
Blynk server by default tries to use the latest available protocol TLSv1.3 
(or TLSv1.2 in case TLSv1.3 version is not supported).

Lower versions of TLS protocols TLSv1 and TLSv1.1 [are not supported](https://en.wikipedia.org/wiki/Transport_Layer_Security#TLS_1.0)
as they are considered as not secure.

The server will automatically close connections with not supported TLS versions.

Blynk uses 443 port for TLS connections and 80 port for plain connections (in case your hardware doesn't support it).
We recommend you to start using the hardware with TLS support right away, if you not yet using it yet.

When we talk about the security of Blynk cloud, we need to consider three different components:

- Hardware
- Web and Mobile App
- Server

## Hardware

By default, Blynk.Edgent library tries to use TLS (v1.2) connection between the hardware and server. 
This is true for the popular hardware like ESP32, ESP8266, NodeMCU, MKR 1000, etc. However, some boards don't support TLS,
in that case plain (non encrypted) connection is used. You can check that in the serial console output of your board. 
Typical TLS connection port would be 443.
For the plain connections port 80 is used.

Default authentication for the hardware is OAuth secured token, it looks like this `xw7ITVneg1DifRRQuPGcA7fJvV8-FAVl` and 
represent 24 bytes in base 64 encoding.
The token could be changed with the re-provision flow.

## Web and Mobile apps

Blynk uses secured web sockets (TLSv1.3 in case you browser supports it, TLSv1.2 otherwise) for web dashboard 
and mobile apps connections and basic authentication (email/password).

All passwords are encrypted on the client side before the transfer to the server and never stored or transferred in the plain form. 
Only encrypted password hash is used and stored on the server.

After multiple (5) failed login attempts from the same IP - IP is not allowed to login for the next 10 minutes.

## Server

- All data transfer between server and database is encrypted
- Database is fully isolated within the private network
- Database doesn't have access from the internet and available only from the private network
- Database itself is not encrypted. Could be done for the clients on Enterprise plan ($).

### Certificates

Blynk uses Let's Encrypt certificates for the TLS connections. Certificates are renewed every 2 months. 

### Ports

Blynk doesn't require any non-standard ports.

- 443 port is used for TLS connections
- 80 port is used for plain connections