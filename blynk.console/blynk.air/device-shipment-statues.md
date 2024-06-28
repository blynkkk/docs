---
description: This page explains the meaning of Blynk device shipment statuses
---

# Device shipment statues

When the shipment is started, the server assigns shipment progress status for every device. The meaning of every status is described below:

* **Started**
  * This status indicates that the OTA update process has been initiated and the device is online. The system has begun the necessary preparations to send the firmware update to the designated devices.
* **Request sent**
  * A request with a firmware download URL for the OTA update has been sent to the device. The system has communicated with the device, notifying it that an update is available and requesting it to prepare for the firmware download. This step ensures that the correct firmware version is identified.
* **Firmware requested**
  * The device has acknowledged the update request and has asked the server for the specific firmware file.&#x20;
* **Firmware uploaded**
  * The firmware file has been successfully uploaded to the device. This status indicates that the transfer process has finished, and the firmware is now on the device, ready to be installed.
* **Success**
  * The OTA update has been successfully completed. The device has received the firmware, installed it, and reconnected to the server with a new firmware version.
* **Upload failure**
  * There was a failure during the upload process. This status indicates that the firmware file could not be uploaded to the device, possibly due to network issues, device errors, or file corruption.
* **Download limit reached**
  * The device has reached its download limit for the firmware update. Usually, it indicates that devices made multiple download attempts and all of them failed. The default limit is 3 downloads per 24 hours.
* **Rollback**
  * The OTA update process has been reversed, and the device has reverted to its previous firmware version. This might happen if the new firmware caused issues or if the update process failed after the firmware was installed.
* **Firmware type mismatch**
  * The device firmware type does not match the shipment requirements. This status indicates that the firmware file intended for another type of device was mistakenly sent to this device. If you see this status, it means shipment firmware has a different template than a destination device.
* **Firmware version mismatch**
  * The device firmware version does not match the expected shipment version. This might occur if the device is already running a newer version of the firmware or if there was an error in selecting the correct firmware version for the update.
* **Firmware uploaded to mobile**
  * The firmware has been uploaded to a mobile device as part of the update process. This status is relevant if the OTA update involves transferring the firmware via a mobile device before reaching the target IoT device.
* **Awaiting user action**
  * The update process is on hold, waiting for the user to take a specific action. This could involve approving the update, connecting the device to a power source, or any other necessary step that requires user intervention.
