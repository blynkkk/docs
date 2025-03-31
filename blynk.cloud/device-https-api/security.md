# Security

Blynk.Cloud has multiple layers of security:

* Every message sent through Blynk is encrypted and secure (unless you're using hardware that doesn't support TLS)
* Granular permissions allow you to manage who and how can see your devices and their data
* Every user should have a valid email address. Blynk offers a built-in verification process
* Server system design doesn't allow any other user than allowed by you to view the devices within your organization's hierarchy
* Each device has its own unique OAuth token and Product ID. A combination of both these fields grants access to the device only for your organization
* Constant monitoring allows us to react quickly to any possible incidents  &#x20;

Blynk mostly relies on industry standards - transport layer security protocol, known as TLS. Blynk server by default tries to use the latest available protocol TLSv1.3 (or TLSv1.2 in case the TLSv1.3 version is not supported).

Lower versions of TLS protocols TLSv1 and TLSv1.1 [are not supported](https://en.wikipedia.org/wiki/Transport_Layer_Security#TLS_1.0) as they are considered being not secure.

The server will automatically close connections with not supported TLS versions.

Blynk uses 443 port (or 9443 if 443 is not available) for TLS connections and 80 port (or 8080 if 80 is not available) for plain connections (in case your hardware doesn't support it). We highly recommend using hardware that supports TLS.&#x20;

When we are talking about the security of Blynk cloud, we take into account these Blynk Products and components:

* Blynk.Edgent that runs on the device
* Blynk.Console and Blynk.App for iOS and Android
* Blynk.Cloud (or private servers for white-label solutions)

### SOC2 Compliance

Blynk has successfully completed a SOC 2 Type II audit, conducted by an independent third-party auditor. This validates that our internal controls and processes meet the highest industry standards for security, availability, and confidentiality—as defined by the American Institute of Certified Public Accountants (AICPA).

#### What This Means for You:

* **Stronger Data Protection** – Ensures your IoT data is managed in accordance with rigorous security standards.
* **Faster Vendor Approvals** – Helps reduce friction during security reviews in enterprise environments.
* **Trusted Infrastructure** – Confirms that Blynk follows structured processes to secure systems and data continuously.
* **Scalable & Secure Deployments** – Allows you to confidently build and scale IoT applications on a platform with enterprise-grade security practices.

Blynk's SOC 2 report is not publicly available but can be shared under NDA upon request. Contact your Blynk representative for more details.

Read the [full announcement](https://blynk.io/blog/blynk-soc2-compliance-secure-scalable-iot).

### Blynk.Edgent (hardware library)

By default, Blynk.Edgent library tries to use TLS (v1.2) connection between the hardware and server. This is true for popular hardware like ESP32, ESP8266, NodeMCU, MKR 1000, etc ([full list](../../blynk.edgent/overview.md)). However, some boards don't support TLS, in that case, a plain (non-encrypted) connection is used. You can check that in the serial console output of your board. A typical TLS connection port would be 443. For the plain connections, port 80 is used.

Default authentication for the hardware is OAuth secured token, it looks like this `xw7ITVneg1DifRRQuPGcA7fJvV8-FAVl` and represents 24 bytes in base 64 encoding. The token could be changed with the re-provision flow.

## Blynk.Apps for iOS and Android

Blynk uses secured web sockets (TLSv1.3 in case your browser supports it, TLSv1.2 otherwise) for communication and basic authentication (email/password). for Blynk.Console and mobile apps&#x20;

Passwords are encrypted on the client side before transferring to the cloud server and are never stored or transferred in plain format. Only encrypted password hash is stored and used on the server.

After 5  failed login attempts from the same IP - the IP is not allowed to log in for the next 10 minutes.

## Blynk.Cloud

* All data transferred between the cloud and the database is always encrypted
* The database is fully isolated within the private network
* The database doesn't have access to the internet and can be accessed from the private network only
* The database itself is not encrypted. Encryption is available for white-label solution as a paid add-on

### Certificates

Blynk uses Let's Encrypt certificates for TLS connections. Certificates are renewed every 2 months.

### Ports

Blynk doesn't require any non-standard ports.

* 443 port is used for TLS connections (9443 if 443 is not available)
* 80 port is used for plain connections (8080 if 80 is not available)
