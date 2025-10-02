# Security Overview

Security is at the core of Blynk’s mission to reduce complexity and help organizations confidently scale IoT solutions. We apply industry best practices across every layer of our platform — from devices and firmware to mobile apps and cloud infrastructure — to ensure data integrity, privacy, and resilience.

***

### Security by Design Principles

* Encryption in transit – All communication between devices, cloud, and applications is secured with Transport Layer Security (TLS). By default, Blynk enforces TLS v1.2 or v1.3; older versions are blocked as insecure.
* Granular access control – Organizations can define fine-grained permissions to control who can view or manage devices and data.
* Strong authentication – Each user must have a verified email address. Blynk provides built-in verification and login protections.
* Device-level security – Every device is provisioned with a unique OAuth token and Product ID. This pairing ensures device authentication and prevents unauthorized access.
* Secure architecture – Our system design prevents any user outside your organization’s hierarchy from accessing your devices or data.

***

### Platform Security

#### Blynk.Edgent (Device Layer)

* By default, Blynk.Edgent uses TLS (v1.2) for communication between supported hardware (ESP32, ESP8266, MKR 1000, etc.) and the cloud.
* If a device does not support TLS, connections fall back to plain HTTP. We strongly recommend using TLS-capable hardware.
* Each device authenticates with a unique OAuth-secured token generated during provisioning.

#### Blynk.Console and Blynk.Apps (User Layer)

* Console and mobile apps communicate over secured WebSockets using TLS v1.2/1.3.
* Passwords are encrypted client-side and never stored or transmitted in plain text. Only salted and hashed values are stored on servers.
* Accounts are protected by login throttling (temporary IP block after multiple failed attempts).

#### Blynk.Cloud (Infrastructure Layer)

* All data transfers between services are encrypted.
* Databases are fully isolated in a private network with no direct internet access.
* Encryption at rest is available as part of enterprise and white-label deployments.
* TLS connections use standard ports (443 / 9443). Non-TLS connections (80 / 8080) are supported only for legacy or limited hardware.
* Certificates are issued via Let’s Encrypt and automatically renewed every two months.

***

### Compliance & Certifications

* SOC 2 Type II – Blynk has successfully completed a SOC 2 Type II audit conducted by an independent third-party auditor. This validates that our internal controls meet the highest standards for security, availability, and confidentiality as defined by the AICPA.
* GDPR compliance – Blynk is fully compliant with the General Data Protection Regulation (GDPR). We ensure personal data is processed lawfully, transparently, and with the highest levels of protection for EU users.
* Cloud provider certifications – Blynk leverages infrastructure partners that maintain SOC 2, ISO 27001, and GDPR/CCPA compliance.
* Documentation – SOC 2 reports are available under NDA upon request.

***

### Operational Security

* 24/7 monitoring – Our infrastructure and services are continuously monitored to detect and respond to anomalies or threats in real time.
* Penetration testing – Regular penetration testing and vulnerability assessments are conducted by external security firms to validate and strengthen our defenses.
* Continuous improvement – Security patches and updates are applied proactively to address emerging threats.

***

### Data Security & Privacy

* Encryption in transit – TLS ensures that data exchanged between devices, cloud, and apps cannot be intercepted.
* Encryption at rest – Available for enterprise / white-label deployments where additional regulatory or contractual obligations require it (add-on service).
* Isolation – Production databases are segmented and protected within private networks.
* Certificates & key management – Certificates are automatically rotated and managed according to best practices.
* Data privacy – Blynk adheres to GDPR requirements, including user consent management, right to be forgotten, and data portability for EU-based users.

***

### Customer Controls

* Role-based access and org-level hierarchies provide visibility and governance over who can access which resources.
* Customers using enterprise or white-label solutions can configure additional security measures, such as encryption at rest and extended access policies.

***

### Commitment to Security

At Blynk, we view security as an ongoing commitment, not a one-time certification. We continually invest in improving our security posture so that developers and enterprises can focus on innovation, confident that their connected products are built on a safe, resilient, and trusted IoT platform.



{% hint style="info" %}
For more details or to request our SOC 2 report, please contact your Blynk representative.
{% endhint %}
