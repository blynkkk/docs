---
description: Terminology used in Blynk
---

# Glossary

## A

`API` - an Application Programming Interface – computing interface that defines interactions between multiple software intermediaries

`Auth Token` - a unique identifier that is assigned to each `Device` that is activated in the system.

`Automation` - condition-to-action sets allowing `Devices` to complete tasks without user interaction.

## B

`Blynk.360` - a web application to configure devices, manage users, organizations.... [Link]()

`Blynk.App` - a  mobile app available for iOS and Android

`Blynk.Air` - a Blynk Service that manages firmware-over-the-air updates. 

`Blynk.Edgent` - a Blynk hardware agent library that manages device connection and communication with the cloud

`Blynk.Inject` - Blynk Service that gets hardware connected to the Internet. In short - a wifi connection manager.  

`Blynk.R` - Blynk Service  for `User` registration and management

`Board` - microcontroller hardware that is used as a core of `Device`. List of supported hardware.

`Blynk 0.1` - First version of the Blynk IoT platform. No longer developed and supported.

`Blynk Library` - first version of the hardware agent library . Now`Blynk.Edgent`

## C

`Category` - `Devices` group by their type that allows controlling all of them with voice assistants \(Alexa, Google Assistant\).

`Claiming` - a process of associating the device with the User \(device owner\). Usually used with devices that connect to the Internet using cellular or wired connection. WiFI `Provisioning` 

## D

`Dashboard` - a collection of `Widgets`

`Device` - physical or virtual appliance, `Users` can get telemetry from, configure, interact with, etc. Each device needs to be registered in the system.

`Device Owner`-  a user considered to be a primary owner of the physical device. 

`Datastream` - is a set of digital signals used for different kinds of content transmission.

`Dynamic Auth Token` - a unique identifier that is activated in the system and is assigned to each `Device` automatically during Wi-Fi `Provisioning`

## E

`Event` - a recorded occurrence of an application-important event on the device

## F

`Firmware` -  a low-level software application that controls electronics and peripherials

## H

`HTTP API` - a service that allows inter-operating with devices using a simple HTTP client. Devices can report their data using `HTTP` protocol.

## L

`Library` - a set of files embedded to the arduino \(or any other\) integrated development environment \(IDE\) that add more functionality and ease to the use the `Board`.

## M

`Metadata` -  a `{key: value}` data associated with every device of a certain  `Template`

## N

`Notification` - a short message triggered by a certain `Event` and delivered to the specified recipient as an Email, SMS or `Push Notification`

## O

`Organization` - a collection of users, devices, and locations

`OTA` \(also `FOTA`\) – **O**ver-**T**he-**A**ir `Firmware` updates without accessing the `Device` physically.

## P

`Pin` - GPIO \(general-purpose input/output\) pin on your `Board` used to interface with external hardware components  \(sensors, servo motors, LCDs, etc\) of your `Device`.

`Product` - a `Template` published to `Blynk.Marketplace` and available for public use

`Provisioning (also WiFI provisioning)` - a process where the Blynk app sends parameters required to establish a WiFi connection to the `device`. 

`Profiling` - a process of filling-out  of Device `Matadata` after `Claiming` or `Provisioning` a device

`Push Notification` - a type of notification sent directly to the app on the smartphone  

## S

`Shipment` - `OTA` `Firmware`loading to a single or multiple `Devices`

`Static Auth Token` - a unique identifier that is activated in the system and is assigned to each `Device` manually by editting the `Sketch`

## T

`Tag` - a keyword or term that can be used to give a short description to a `User` or a `Device`

`Template` - a set of elements and configurations, used to display all `Devices` of a particular type. `Templates` are created by `Developers`, and can be published to be accessible globally as `Products`.

`Template ID` - a unique identifier that is automatically assigned to each `Template`.

`Timeline` - a list of `Events` in chronological order. Represents `Device` status changes and warnings.

`Transfer` - move operation applied to 'Organizations', 'Devices' and Users, such as `Organization` or `Device Owner` changes.

## U

`User` - an account assigned to a person and is a member of group of people accessing an `Organization`

## V

`Virtual Pin` - a "channel" used to send processed data from/to cloud . Virtual pins have no physical representation on the hardware. 

## W

`Widget` - a self-contained graphical user interface \(GUI\) element used to visualize data or get user input.

