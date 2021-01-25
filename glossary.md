---
description: Terminology used in Blynk
---

# Glossary

## 0..9

`Blynk.360` - a complex of `Blynk` services. Our web portal is the main entry point to Blynk.360.

## A

`API` - an application programming interface is a computing interface that defines interactions between multiple software intermediaries

`Auth Token` - a unique identifier that is assigned to each `Device` that is activated in the system.

`Automation` - condition-to-action sets allowing electronic `Devices` to complete various tasks with the minimal amount of human interaction.

## B

`Blynk.Air` - subsystem for management of over-the-air updates.

`Blynk.Inject` - implementation of `provisioning` for WiFi devices. See `Provisioning`.

`Blynk.Edgent` - Blynk `Firmware` implementation.

`Blynk.Library` - Blynk `Library` implementation for integration with `Blynk.360`

`Blynk.Marketplace` - a registry of `Products`, that are available globally to all `Blynk` `Users`.

`BlynkR` - subsystem for `User` registration and management

`Board` - microcontroller hardware that is used as a core of `Device`. List of supported hardware.

## C

`Category` - `Devices` group by their type that allows to control all of them by giving single commands to voice assistants (Alexa, Google Assistant).

`Claiming` - process of associating the device with it's digital twin. I.e. when working with cellular devices, `Provisioning` is usually not required, so we use `claiming` to register each device in the system.

## D

`Dashboard` - a collection of `Widgets`.

`Device` - physical or virtual appliance, `Users` can get telemetry from, configure, interact with, etc. Each device needs to be registered in the system.

`Device Owner`- basically displays the `User` who added a `Device` to an `Organization`. Can be assigned to another `User` via `Transfer`

`Datastream` - is a set of digital signals used for different kinds of content transmission.

`Dynamic Auth Token` - a unique identifier that is activated in the system and is assigned to each `Device` automatically during Wi-Fi `Provision`

## E

`Event` - an item in the device `Timeline` . On Apps, events are also displayed in the `Alerts` tab.

## F

`Firmware` - `Device's` low-level software that allows data exchange and commands execution inside a `Device` and between it and `Blynk.360`

## G

## H

`HTTP API` - a service that allows inter-operating with devices using a simple HTTP client. Devices can report their data using `HTTP` protocol.

## I

## J

## K

## L

`Library` - a bunch of files embedded to the arduino (or any other) integrated development environment (IDE) that add more functionality and ease to the use the `Board`.

## M

`Metadata` - a set of characteristics \(or configurations\) applied to every Product and associated with every Device

## N

`Notification` - a message sent by Email, SMS or Push after an `Event` occured

## O

`Offline Ignore Period` - a user defined amount of time to pass before `Device` is displayed offline in `Blynk.360` after it's being actually offline

`Organization` - `Blynk.360` instance containing interconnected `Templates`, `Products`, `Devices` and Users used by a group of people.

`OTA` - over-the-air `Firmware` updates without accessing the `Device` physically.

## P

`Pin` - GPIO (general-purpose input/output) pin on your `Board` used to interface hardware (Servo, LCD and others) of your `Device`

`Product` - a `Template`, that is successfully published to `Blynk.Marketplace`

`Provisioning` - a process of assigning `Auth Token` to a `Device` while adding it to an `Organization`

`Profiling` -

## Q

## R

`Rule Engine` -

## S

`Shipment` - `OTA` `Firmware `loading to a single or multiple `Devices` 

`Static Auth Token` - a unique identifier that is activated in the system and is assigned to each `Device` manually by editting the `Sketch`

## T

`Tag` - a keyword or term that can be used to give short descriptions of a `User` or a `Device` 

`Template` - a set of elements and configurations, used to display all `Devices` of a particular type. `Templates` are created by `Developers`, and can be published to be accessible globally as `Products`.

`Template ID` - a unique identifier that is automatically assigned to each `Template`.

`Timeline` - a list of `Events` in chronological order. Represents `Device` status changes and warnings.

`Transfer` - move operation applied to 'Organizations', 'Devices' and Users, such as `Organization` or `Device Owner` changes.

## U

`User` - an account assigned to a person and is a member of group of people accessing an `Organization`

## V

`Virtual Pin -` think of them as channels for sending any data used to interface with other libraries and implement custom logic. Has have no physical representation.

## W

`Widget` - interface module that eases digital and analog data reading.

## Y

## Z

