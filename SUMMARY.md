# Table of contents

* [Introduction](Introduction.md)

## Getting Started

* [Supported Hardware](getting-started/supported-boards.md)
* [Quickstart](getting-started/what-do-i-need-to-blynk/README.md)
  * [Next Steps After Quickstart](getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made.md)
  * [Quickstart Device: Code Overview](getting-started/what-do-i-need-to-blynk/quickstart-device-code-overview.md)
  * [Troubleshooting](getting-started/what-do-i-need-to-blynk/troubleshooting.md)
* [Device Activation Methods](getting-started/activating-devices/README.md)
  * [Manual Device Activation](getting-started/activating-devices/manual-device-activation.md)
  * [WiFi provisioning](getting-started/activating-devices/blynk-edgent-wifi-provisioning.md)
  * [Static Token](getting-started/activating-devices/blynk-edgent-static-authtoken.md)
* [Template Quick Setup](getting-started/template-quick-setup/README.md)
  * [Set Up Datastreams](getting-started/template-quick-setup/set-up-datastreams.md)
  * [Set Up Web Dashboard](getting-started/template-quick-setup/set-up-web-dashboard.md)
  * [Set Up Mobile App Dashboard](getting-started/template-quick-setup/set-up-mobile-app-dashboard.md)
  * [Prepare Your Code](getting-started/template-quick-setup/prepare-code.md)
  * [Test your Template](getting-started/template-quick-setup/test-your-template.md)
* [Send Data From Hardware To Blynk](getting-started/how-to-display-any-sensor-data-in-blynk-app.md)
* [Control Devices (GPIOs and beyond)](getting-started/using-virtual-pins-to-control-physical-devices.md)
* [Events](getting-started/events-tutorial.md)
* [Notifications (Alerts)](getting-started/notification-management.md)
* [Sign Up / Sign In](getting-started/signup.md)

***

* [Changelog](changelog.md)

## General Concepts <a href="#concepts" id="concepts"></a>

* [Developer Mode](concepts/developer-mode.md)
* [Device](concepts/device.md)
* [Device Template](concepts/device-template.md)
* [Connection Lifecycle](concepts/connection-lifecycle-management/README.md)
  * [Disconnections And Heartbeat](concepts/connection-lifecycle-management/disconnections-and-heartbeat.md)
* [Users](concepts/users/README.md)
  * [Multi-tenancy](concepts/users/multi-tenant-tree-structure.md)
* [Organizations](concepts/organizations.md)
* [Automations](concepts/automations.md)
  * [Forward Device Data](concepts/automations/forward-device-data.md)

***

* [Message Usage](message-usage.md)

## Integration Guides <a href="#hardware-guides" id="hardware-guides"></a>

* [Node-RED](hardware-guides/node-red.md)
* [The Things Stack](hardware-guides/the-things-stack/README.md)
  * [Getting Started](hardware-guides/the-things-stack/getting-started.md)
  * [Device Grouping](hardware-guides/the-things-stack/device-grouping.md)
  * [Automated Device Onboarding](hardware-guides/the-things-stack/automated-device-onboarding.md)
  * [System DataStreams](hardware-guides/the-things-stack/system-datastreams.md)
* [Blues](hardware-guides/blues.md)
* [NCD Industrial Vibration Sensor](hardware-guides/ncd-industrial-vibration-sensor.md)
* [Particle - monitor with Blynk](hardware-guides/particle.md)
* [Particle - control with Blynk](hardware-guides/particle-part-ii.md)
* [AWS IoT Core](hardware-guides/aws-iot-core.md)

***

* [Myriota](myriota.md)
* [OpenWeather](openweather.md)

## Blynk.Console

* [Overview](blynk.console/console-overview.md)
* [Dashboards](blynk.console/dashboards/README.md)
  * [Dashboard Widgets](blynk.console/dashboards/dashboard-widgets.md)
* [Devices](blynk.console/devices/README.md)
  * [Device profile](blynk.console/devices/device-profile/README.md)
    * [Dashboard](blynk.console/devices/device-profile/dashboard.md)
    * [Device Info & Metadata](blynk.console/devices/device-profile/device-info.md)
    * [Notifications & Events](blynk.console/devices/device-profile/timeline.md)
    * [Developer tools](blynk.console/devices/device-profile/developer-tools/README.md)
      * [General](blynk.console/devices/device-profile/developer-tools/general.md)
      * [Datastreams](blynk.console/devices/device-profile/developer-tools/datastreams.md)
      * [Testing](blynk.console/devices/device-profile/developer-tools/testing.md)
      * [Actions Log](blynk.console/devices/device-profile/developer-tools/actions-log.md)
  * [Actions with devices](blynk.console/devices/actions-with-devices.md)
  * [Segments](blynk.console/devices/segments.md)
  * [Filters](blynk.console/devices/filters.md)
  * [Notifications Settings](blynk.console/devices/notifications-settings.md)
  * [Device Sharing](blynk.console/devices/device-sharing.md)
* [Locations](blynk.console/locations/README.md)
  * [Location Profile](blynk.console/locations/location-profile.md)
  * [Assigning Devices to the Locations](blynk.console/locations/locations.md)
* [Organizations](blynk.console/organizations.md)
  * [Create a Sub-Organization](blynk.console/organizations/create-a-sub-organization.md)
  * [Working with Sub-Organizations](blynk.console/organizations/browse-and-edit-a-sub-organization.md)
* [Users](blynk.console/users/README.md)
  * [User Profile](blynk.console/users/user-view.md)
* [Device Templates](blynk.console/templates/README.md)
  * [Working With Templates](blynk.console/templates/working-with-templates.md)
  * [Info](blynk.console/templates/info/README.md)
    * [Offline Ignore Period](blynk.console/templates/info/offline-ignore-period.md)
    * [Manufacturer](blynk.console/templates/info/manufacturer.md)
    * [Template ID](blynk.console/templates/info/template-ids.md)
    * [Categories](blynk.console/templates/info/categories.md)
    * [Hotspot Prefix](blynk.console/templates/info/hotspot-prefix.md)
  * [Datastreams](blynk.console/templates/datastreams/README.md)
    * [Datastream Settings](blynk.console/templates/datastreams/datastreams-common-settings/README.md)
      * [Name](blynk.console/templates/datastreams/datastreams-common-settings/datastream_name.md)
      * [Alias](blynk.console/templates/datastreams/datastreams-common-settings/alias.md)
      * [Virtual Pin](blynk.console/templates/datastreams/datastreams-common-settings/virtual-pin.md)
      * [Color](blynk.console/templates/datastreams/datastreams-common-settings/color.md)
      * [Data Type](blynk.console/templates/datastreams/datastreams-common-settings/data-type.md)
      * [Min Value](blynk.console/templates/datastreams/datastreams-common-settings/min-value.md)
      * [Max Value](blynk.console/templates/datastreams/datastreams-common-settings/max-value.md)
      * [Default Value](blynk.console/templates/datastreams/datastreams-common-settings/default-value.md)
      * [Save RAW Data](blynk.console/templates/datastreams/datastreams-common-settings/save-raw-data.md)
      * [Invalidate Value](blynk.console/templates/datastreams/datastreams-common-settings/invalidate-value.md)
      * [Wait for confirmation from device](blynk.console/templates/datastreams/datastreams-common-settings/wait-for-confirmation-from-device.md)
      * [Sync with latest server value every time device connects to the cloud](blynk.console/templates/datastreams/datastreams-common-settings/sync-with-latest-server-value-every-time-device-connects-to-the-cloud.md)
      * [Expose to Voice Assistants](blynk.console/templates/datastreams/datastreams-common-settings/expose-to-voice-assistants.md)
    * [Virtual Pin](blynk.console/templates/datastreams/virtual-pin.md)
    * [Location](blynk.console/templates/datastreams/location.md)
    * [Enumerable](blynk.console/templates/datastreams/enumerable.md)
  * [Web Dashboard](blynk.console/templates/dashboard/README.md)
    * [Multiple Dashboard Tabs](blynk.console/templates/dashboard/multiple-dashboard-tabs.md)
  * [Metadata](blynk.console/templates/metadata/README.md)
    * [Metadata Tutorial](blynk.console/templates/metadata/metadata-tutorial.md)
  * [Connection Lifecycle](blynk.console/templates/connection-lifecycle.md)
  * [Events](blynk.console/templates/events/README.md)
    * [Custom Events](blynk.console/templates/events/custom-events/README.md)
      * [Event Settings](blynk.console/templates/events/custom-events/events-general-setting.md)
      * [How to Send/Log Events](blynk.console/templates/events/custom-events/events--how-to-log-events.md)
      * [Content Events](blynk.console/templates/events/custom-events/events-content-events.md)
    * [Notifications Settings](blynk.console/templates/events/events-notification-settings/README.md)
      * [Custom Sounds and Critical Notifications](blynk.console/templates/events/events-notification-settings/custom-sounds-and-critical-notifications.md)
  * [User Guides](blynk.console/templates/user-guides.md)
  * [Assets](blynk.console/templates/assets.md)
* [Widgets (Console)](blynk.console/widgets-console/README.md)
  * [Switch](blynk.console/widgets-console/switch.md)
  * [Slider](blynk.console/widgets-console/slider.md)
  * [Number Input](blynk.console/widgets-console/number-input.md)
  * [Image Button](blynk.console/widgets-console/image-button.md)
  * [Web Page Image Button](blynk.console/widgets-console/web-page-image-button.md)
  * [LED](blynk.console/widgets-console/led.md)
  * [Label](blynk.console/widgets-console/label.md)
  * [Gauge](blynk.console/widgets-console/gauge.md)
  * [Chart](blynk.console/widgets-console/chart.md)
  * [Map](blynk.console/widgets-console/map.md)
  * [Image Gallery](blynk.console/widgets-console/image-gallery.md)
  * [Custom Chart](blynk.console/widgets-console/custom-chart.md)
  * [Heatmap Chart](blynk.console/widgets-console/heatmap-chart.md)
  * [Video](blynk.console/widgets-console/video.md)
  * [Bitmask Table](blynk.console/widgets-console/bitmask-table.md)
  * [Gradient Ramp](blynk.console/widgets-console/gradient-ramp.md)
  * [Terminal](blynk.console/widgets-console/terminal.md)
  * [Segmented Switch](blynk.console/widgets-console/segmented-switch.md)
  * [Alarm & Sound Widget](blynk.console/widgets-console/alarm-and-sound-widget.md)
  * [Modules](blynk.console/widgets-console/modules.md)
* [Blynk.Air](blynk.console/blynk.air/README.md)
  * [Shipment Details](blynk.console/blynk.air/shipment-details.md)
  * [Shipment Management](blynk.console/blynk.air/shipment-management/README.md)
    * [New Shipping](blynk.console/blynk.air/shipment-management/new-shipping.md)
  * [Device shipment statuses](blynk.console/blynk.air/device-shipment-statues.md)
  * [User-Controlled Shipments](blynk.console/blynk.air/user-controlled-shipments.md)
* [Settings](blynk.console/settings/README.md)
  * [Organization Settings](blynk.console/settings/organization-settings/README.md)
    * [General](blynk.console/settings/organization-settings/general.md)
    * [Users](blynk.console/settings/organization-settings/users.md)
    * [Locations (Job Site or Facilities)](blynk.console/settings/organization-settings/locations.md)
    * [Tags](blynk.console/settings/organization-settings/tags.md)
  * [Roles and Permissions](blynk.console/settings/access.md)
  * [Developers](blynk.console/settings/developers/README.md)
    * [OAuth2](blynk.console/settings/developers/oauth2.md)
    * [Webhooks](blynk.console/settings/developers/webhooks.md)
    * [Create New Webhook](blynk.console/settings/developers/create-new-webhook.md)
  * [Integrations](blynk.console/settings/integrations.md)
* [User Profile Menu](blynk.console/user-profile.md)
* [Limits](blynk.console/limits.md)

## Blynk.Apps

* [Overview](blynk.apps/overview.md)
* [Mobile Dashboard Editor](blynk.apps/constructor.md)
* [Device Header Constructor](blynk.apps/device-header-constructor/README.md)
  * [Header Design](blynk.apps/device-header-constructor/header-design.md)
  * [Header Mini Widgets](blynk.apps/device-header-constructor/header-mini-widgets/README.md)
    * [Connection Status Widget](blynk.apps/device-header-constructor/header-mini-widgets/connection-status-widget.md)
    * [Last Reported Widget](blynk.apps/device-header-constructor/header-mini-widgets/last-reported-widget.md)
    * [Tabs Widget](blynk.apps/device-header-constructor/header-mini-widgets/tabs-widget.md)
    * [Datastream Value Widget](blynk.apps/device-header-constructor/header-mini-widgets/datastream-value-widget.md)
    * [Image Widget](blynk.apps/device-header-constructor/header-mini-widgets/image-widget.md)
    * [Battery Level Widget](blynk.apps/device-header-constructor/header-mini-widgets/battery-level-widget.md)
    * [Signal Level Widget](blynk.apps/device-header-constructor/header-mini-widgets/signal-level.md)
    * [Tags Widget](blynk.apps/device-header-constructor/header-mini-widgets/tags-widget.md)
  * [Header Buttons](blynk.apps/device-header-constructor/header-buttons.md)
* [Pages](blynk.apps/pages.md)
* [Widgets (app)](blynk.apps/widgets-app/README.md)
  * [Common Widget Settings](blynk.apps/widgets-app/common-widget-settings.md)
  * [List of Datastreams types supported by Widgets](blynk.apps/widgets-app/list-of-datastreams-types-supported-by-widgets.md)
* [Widgets Controllers](blynk.apps/widgets-controllers/README.md)
  * [Button](blynk.apps/widgets-controllers/button.md)
  * [Styled Button](blynk.apps/widgets-controllers/styled-button.md)
  * [Icon Button](blynk.apps/widgets-controllers/icon-button.md)
  * [Image Button](blynk.apps/widgets-controllers/image-button.md)
  * [Slider](blynk.apps/widgets-controllers/slider.md)
  * [Vertical Slider](blynk.apps/widgets-controllers/vertical-slider.md)
  * [Step Slider](blynk.apps/widgets-controllers/step-slider.md)
  * [Vertical Step Slider](blynk.apps/widgets-controllers/vertical-step-slider.md)
  * [Joystick](blynk.apps/widgets-controllers/joystick.md)
  * [zeRGBa](blynk.apps/widgets-controllers/zergba.md)
  * [RGB Light Control](blynk.apps/widgets-controllers/rgb-light-control.md)
  * [Step H](blynk.apps/widgets-controllers/step-h.md)
  * [Step V](blynk.apps/widgets-controllers/step-v.md)
  * [Slope Control](blynk.apps/widgets-controllers/slope-control.md)
  * [Switch](blynk.apps/widgets-controllers/switch.md)
  * [Level Slider](blynk.apps/widgets-controllers/level-slider.md)
  * [Level Slider with Switch](blynk.apps/widgets-controllers/level-slider-with-switch.md)
* [Widgets Displays](blynk.apps/widgets-displays/README.md)
  * [Value Display](blynk.apps/widgets-displays/value-display.md)
  * [Labeled Value](blynk.apps/widgets-displays/labeled-value.md)
  * [LED](blynk.apps/widgets-displays/led.md)
  * [Gauge](blynk.apps/widgets-displays/gauge.md)
  * [Radial Gauge](blynk.apps/widgets-displays/radial-gauge.md)
  * [Enhanced Gauge](blynk.apps/widgets-displays/enhanced-gauge.md)
  * [LCD](blynk.apps/widgets-displays/lcd.md)
  * [Simple Chart](blynk.apps/widgets-displays/simple-chart.md)
  * [SuperChart](blynk.apps/widgets-displays/superchart.md)
  * [Terminal](blynk.apps/widgets-displays/terminal.md)
  * [Video Stream](blynk.apps/widgets-displays/video-stream.md)
  * [Level H](blynk.apps/widgets-displays/level-h.md)
  * [Level V](blynk.apps/widgets-displays/level-v.md)
  * [Image Gallery](blynk.apps/widgets-displays/image-gallery.md)
  * [Gradient Ramp](blynk.apps/widgets-displays/gradient-ramp.md)
  * [Icon](blynk.apps/widgets-displays/icon.md)
  * [Image Animation](blynk.apps/widgets-displays/image-animation.md)
  * [Lottie Animation](blynk.apps/widgets-displays/lottie-animation.md)
* [Widgets Interface](blynk.apps/widgets-interface/README.md)
  * [Tabs](blynk.apps/widgets-interface/tabs.md)
  * [Menu](blynk.apps/widgets-interface/menu.md)
  * [Map](blynk.apps/widgets-interface/map.md)
  * [Text Input](blynk.apps/widgets-interface/text-input.md)
  * [Numeric Input](blynk.apps/widgets-interface/numeric-input.md)
  * [Time input](blynk.apps/widgets-interface/time-input.md)
  * [Segmented Switch](blynk.apps/widgets-interface/segmented-switch.md)
  * [Icon Segmented Switch](blynk.apps/widgets-interface/icon-segmented-switch.md)
  * [Text](blynk.apps/widgets-interface/text.md)
  * [Formatted Text](blynk.apps/widgets-interface/formatted-text.md)
  * [Dynamic Spacer](blynk.apps/widgets-interface/dynamic-spacer.md)
* [Widgets Other](blynk.apps/widgets-other/README.md)
  * [Music Player](blynk.apps/widgets-other/music-player.md)
  * [WebPage Button](blynk.apps/widgets-other/webpage-button.md)
  * [WebPage Image Button](blynk.apps/widgets-other/webpage-image-button.md)
  * [Alias Name](blynk.apps/widgets-other/alias-name.md)
* [Main Menu](blynk.apps/profile-management/README.md)
  * [My Profile](blynk.apps/profile-management/my-profile.md)
  * [Organization](blynk.apps/profile-management/organization-management.md)
  * [Settings](blynk.apps/profile-management/settings.md)
  * [Help](blynk.apps/profile-management/help.md)
  * [About](blynk.apps/profile-management/about.md)
  * [Log Out](blynk.apps/profile-management/log-out.md)
* [Devices](blynk.apps/device-management/README.md)
  * [Add New Device](blynk.apps/device-management/add-new-device.md)
* [Automations](blynk.apps/automations.md)
* [Notifications & Events](blynk.apps/notifications.md)

## Blynk.Edgent

* [Blynk.Edgent overview](blynk.edgent/overview.md)
* [Blynk.Inject and Blynk.Air](platform-overview/services.md)
* [OTA: Firmware Over-The-Air updates](blynk.edgent/updating-devices-firmwares-ota.md)

## Blynk.NCP

* [Blynk.NCP overview](blynk.ncp/overview.md)
* [Supported Connectivity Modules](blynk.ncp/supported-connectivity-modules.md)
* [OTA: Firmware Over-The-Air updates](blynk.ncp/updating-devices-firmwares-ota.md)

## Blynk Library - firmware API

* [Installation](blynk-library-firmware-api/installation/README.md)
  * [Install Blynk Library in Arduino IDE](blynk-library-firmware-api/installation/install-blynk-library-in-arduino-ide.md)
  * [Install Blynk Library for Platformio.org](blynk-library-firmware-api/installation/install-blynk-library-for-platformio.org.md)
  * [Install ESP8266 core for Arduino IDE](blynk-library-firmware-api/installation/install-esp8266-core-for-arduino-ide.md)
* [Configuration](blynk-library-firmware-api/configuration.md)
* [Connection Management](blynk.edgent-firmware-api/connection-management.md)
* [Device Online/Offline Status](blynk-library-firmware-api/devices-online-status.md)
* [Digital/Analog Pins](blynk-library-firmware-api/digital-analog-pins.md)
* [Virtual Pins](blynk-library-firmware-api/virtual-pins.md)
* [Widget Properties](blynk.edgent-firmware-api/widget-properties.md)
* [State Syncing](blynk.edgent-firmware-api/state-syncing.md)
* [Timers](blynk.edgent-firmware-api/blynk-timer.md)
* [Time (RTC clock)](blynk.edgent-firmware-api/rtc-clock.md)
* [Timezone / Location](blynk-library-firmware-api/timezone-location.md)
* [Log Event](blynk-library-firmware-api/log-event.md)
* [Metadata](blynk-library-firmware-api/metadata.md)
* [Debug](blynk-library-firmware-api/debug.md)
* [Reboot](blynk-library-firmware-api/reboot.md)
* [Over-The-Air Firmware Updates (OTA)](blynk-library-firmware-api/ota-updates.md)
* [Other](blynk-library-firmware-api/other.md)
* [Limitations and Recommendations](blynk-library-firmware-api/limitations-and-recommendations.md)
* [Blynk Protocol](blynk-library-firmware-api/blynk-protocol.md)

## BLYNK.CLOUD MQTT API

* [Device MQTT API](blynk.cloud/device-mqtt-api/README.md)
  * [Authentication](blynk.cloud/device-mqtt-api/authentication.md)
  * [Topic Structure](blynk.cloud/device-mqtt-api/topic-structure.md)
  * [Datastreams](blynk.cloud/device-mqtt-api/datastreams.md)
  * [Widget Properties](blynk.cloud/device-mqtt-api/widget-properties.md)
  * [Events](blynk.cloud/device-mqtt-api/events.md)
  * [Metadata](blynk.cloud/device-mqtt-api/metadata.md)
  * [Timezone/Location](blynk.cloud/device-mqtt-api/timezone-location.md)
  * [OTA](blynk.cloud/device-mqtt-api/ota.md)
  * [Miscelaneous](blynk.cloud/device-mqtt-api/miscelaneous.md)
  * [Code Examples](blynk.cloud-mqtt-api/device-mqtt-api/code-examples.md)

## BLYNK.CLOUD HTTPS API <a href="#blynk.cloud" id="blynk.cloud"></a>

* [Device HTTPS API](blynk.cloud/device-https-api/README.md)
  * [Get Datastream Value](blynk.cloud/device-https-api/get-datastream-value.md)
  * [Get Multiple Datastream Values](blynk.cloud/device-https-api/get-multiple-datastream-values.md)
  * [Get Historical Data From Device](blynk.cloud/device-https-api/get-device-report.md)
  * [Update Datastream Value](blynk.cloud/device-https-api/update-datastream-value.md)
  * [Update Multiple Datastreams Simultaneously](blynk.cloud/device-https-api/update-multiple-datastreams-api.md)
  * [Upload a Set of Timestamped Data](blynk.cloud/device-https-api/upload-set-of-data-with-timestamps-api.md)
  * [Update Widget/Datastream Property](blynk.cloud/device-https-api/update-property.md)
  * [Send/Log An Event](blynk.cloud/device-https-api/trigger-events-api.md)
  * [Get Device Metadata Value](blynk.cloud/device-https-api/get-device-metafield-value.md)
  * [Update Device Metadata Value](blynk.cloud/device-https-api/get-device-metafield-value-1.md)
  * [Is Device Connected](blynk.cloud/device-https-api/is-device-connected.md)
  * [Upload a File](blynk.cloud/device-https-api/upload-a-file.md)
  * [HTTPS API Troubleshooting](blynk.cloud/device-https-api/troubleshooting.md)
* [Platform API](blynk.cloud/platform-https-api/README.md)
  * [Authentication](blynk.cloud/platform-https-api/authentication.md)
  * [Ogranization API](blynk.cloud/platform-https-api/ogranization-api/README.md)
    * [Get Own Organization Info](blynk.cloud/platform-https-api/ogranization-api/get-organization-info.md)
    * [Get Organization Info](blynk.cloud/platform-https-api/ogranization-api/get-organization-info-1.md)
    * [Search Organizations](blynk.cloud/platform-https-api/ogranization-api/get-organization-info-2.md)
    * [Create Organization](blynk.cloud/platform-https-api/ogranization-api/create-organization.md)
    * [Get Static Tokens](blynk.cloud/platform-https-api/ogranization-api/get-static-tokens.md)
    * [Get Organization Tags](blynk.cloud/platform-https-api/ogranization-api/get-organization-tags.md)
    * [Get Organization Automations](blynk.cloud/platform-https-api/ogranization-api/get-organization-automations.md)
  * [Devices API](blynk.cloud/platform-https-api/devices-api/README.md)
    * [Get All Devices](blynk.cloud/platform-https-api/devices-api/get-all-devices.md)
    * [Search Devices](blynk.cloud/platform-https-api/devices-api/search-devices.md)
    * [Get Devices by Owner Email](blynk.cloud/platform-https-api/devices-api/search-devices-1.md)
    * [Get Devices in user organization](blynk.cloud/platform-https-api/devices-api/search-devices-2.md)
    * [Get Recently Activated Devices](blynk.cloud/platform-https-api/devices-api/get-recently-activated-devices.md)
    * [Get Device Info](blynk.cloud/platform-https-api/devices-api/get-device-info.md)
    * [Get Base Device Info](blynk.cloud/platform-https-api/devices-api/get-device-info-1.md)
    * [Get Connection Status](blynk.cloud/platform-https-api/devices-api/get-connection-status.md)
    * [Create Device](blynk.cloud/platform-https-api/devices-api/create-device.md)
    * [Edit Device](blynk.cloud/platform-https-api/devices-api/edit-device.md)
    * [Get Datastream Values](blynk.cloud/platform-https-api/devices-api/get-datastream-values.md)
    * [Update Datastream Value](blynk.cloud/platform-https-api/devices-api/update-datastream-value.md)
    * [Update Multiple Datastreams Values](blynk.cloud/platform-https-api/devices-api/update-multiple-datastreams-values.md)
    * [Import Datastream Values](blynk.cloud/platform-https-api/devices-api/import-datastream-values.md)
    * [Update Datastream Property](blynk.cloud/platform-https-api/devices-api/update-datastream-property.md)
    * [Get Datastream Historical Data](blynk.cloud/platform-https-api/devices-api/get-datastream-historical-data.md)
    * [Get Device Metadata](blynk.cloud/platform-https-api/devices-api/get-device-metadata.md)
    * [Update Device Metadata](blynk.cloud/platform-https-api/devices-api/update-device-metadata.md)
    * [Get Device Tags](blynk.cloud/platform-https-api/devices-api/get-device-tags.md)
    * [Get Device Timeline Log](blynk.cloud/platform-https-api/devices-api/get-device-timeline-log.md)
    * [Log a Device Event](blynk.cloud/platform-https-api/devices-api/log-a-device-event.md)
    * [Get Actions Log](blynk.cloud/platform-https-api/devices-api/get-actions-log.md)
    * [Erase All Data](blynk.cloud/platform-https-api/devices-api/erase-all-data.md)
    * [Remove Device Owner](blynk.cloud/platform-https-api/devices-api/remove-device-owner.md)
    * [Transfer Device](blynk.cloud/platform-https-api/devices-api/transfer-device.md)
    * [Delete Device](blynk.cloud/platform-https-api/devices-api/delete-device.md)
  * [Users API](blynk.cloud/platform-https-api/users-api/README.md)
    * [Get All Users](blynk.cloud/platform-https-api/users-api/get-all-users.md)
    * [Search Users](blynk.cloud/platform-https-api/users-api/search-users.md)
    * [Create New User](blynk.cloud/platform-https-api/users-api/create-new-user.md)
    * [Invite User](blynk.cloud/platform-https-api/users-api/invite-user.md)
    * [Get User Info](blynk.cloud/platform-https-api/users-api/get-user-info.md)
    * [Update User Role](blynk.cloud/platform-https-api/users-api/get-user-info-1.md)
  * [Templates API](blynk.cloud/platform-https-api/templates-api/README.md)
    * [Get All Templates](blynk.cloud/platform-https-api/templates-api/get-all-templates.md)
    * [Get Template Info](blynk.cloud/platform-https-api/templates-api/get-template-info.md)
    * [Get Template Metadata](blynk.cloud/platform-https-api/templates-api/get-template-metadata.md)
    * [Get Template Datastreams](blynk.cloud/platform-https-api/templates-api/get-template-datastreams.md)
    * [Get Template Events](blynk.cloud/platform-https-api/templates-api/get-template-events.md)
* [Security](blynk.cloud/device-https-api/security.md)

## Downloads

* [Blynk Mobile Apps](downloads/blynk-apps-for-ios-and-android.md)
* [Blynk Library](downloads/blynk-library.md)

## Troubleshooting

* [General Issues](troubleshooting/general-issues.md)
* [Developer Mode](troubleshooting/developer-mode.md)
* [Changes from Blynk 0.1](troubleshooting/blynk-1.0-and-2.0-comparison/README.md)
  * [Migrating to the new Blynk - Full Guide](troubleshooting/blynk-1.0-and-2.0-comparison/migrate-from-1.0-to-2.0.md)
* [Glossary](troubleshooting/glossary.md)
* [Links](troubleshooting/links.md)

## Commercial Use

* [Deploying Products With Dynamic AuthTokens](commercial-use/deploying-products-with-dynamic-authtokens.md)
* [Deploying Products With Static Tokens](commercial-use/deploying-products-with-static-authtokens.md)
* [Working With Clients](commercial-use/working-with-clients-pro-business-plan.md)
* [Supported topologies](commercial-use/supported-topologies.md)
* [Business Plan (White Label Solution)](commercial-use/business-plan-white-label-assets/README.md)
  * [App Publishing Process And Timeline](commercial-use/business-plan-white-label-assets/app-publishing-process-and-timeline.md)
  * [What's Needed To Publish Your Apps And Go Live](commercial-use/business-plan-white-label-assets/publishing-materials.md)
  * [Branding Materials](commercial-use/business-plan-white-label-assets/branding-materials.md)
  * [Custom Email Address For Transactional Emails](commercial-use/business-plan-white-label-assets/set-up-custom-email-address-for-transactional-emails-in-blynk.md)
  * [Application Settings](commercial-use/business-plan-white-label-assets/application-settings/README.md)
    * [General](commercial-use/business-plan-white-label-assets/application-settings/general.md)
    * [Design](commercial-use/business-plan-white-label-assets/application-settings/design.md)
    * [Mobile Apps](commercial-use/business-plan-white-label-assets/application-settings/mobile-apps.md)
    * [Sign Up](commercial-use/business-plan-white-label-assets/application-settings/sign-up.md)

## Add-Ons

* [Add-on list](add-ons/add-on-list.md)
* [Amazon Alexa](add-ons/amazon-alexa.md)
* [Google Assistant](add-ons/google-assistant.md)
* [Localization](add-ons/localization.md)
* [Database Access](add-ons/database-access.md)
* [Marketing](add-ons/marketing.md)

## Legacy Platform Help Articles <a href="#legacy-platform" id="legacy-platform"></a>

* [Legacy articles](legacy-platform/legacy-articles/README.md)
  * [What is Virtual Pins](legacy-platform/legacy-articles/what-is-virtual-pins.md)
  * [Keep your void loop() clean](legacy-platform/legacy-articles/keep-your-void-loop-clean.md)
  * [How to control anything with Blynk app](legacy-platform/legacy-articles/how-to-control-anything-with-blynk-app.md)
  * [NodeMCU](legacy-platform/legacy-articles/nodemcu.md)
  * [ESP8266 standalone](legacy-platform/legacy-articles/esp8266-standalone.md)
  * [Particle Electron](legacy-platform/legacy-articles/particle-electron.md)
  * [ESP8266 with AT firmware](legacy-platform/legacy-articles/esp8266-with-at-firmware.md)
  * [Bluetooth (2.0 SPP, 4.0 LE)](legacy-platform/legacy-articles/bluetooth-2.0-spp-4.0-le.md)
  * [USB Serial](legacy-platform/legacy-articles/usb-serial.md)
  * [Raspberry Pi and Blynk](legacy-platform/legacy-articles/raspberry-pi-and-blynk.md)
  * [BBC micro:bit + Arduino IDE](legacy-platform/legacy-articles/bbc-micro-bit-+-arduino-ide.md)
  * [Blynk and Raspberry Pi: Tips & Tricks](legacy-platform/legacy-articles/blynk-and-raspberry-pi-tips-and-tricks.md)
  * [How to install Node.js library on Linux](legacy-platform/legacy-articles/how-to-install-node.js-library-on-linux.md)
  * [Node.js vs. C++ library](legacy-platform/legacy-articles/node.js-vs.-c++-library.md)
  * [Implementing a Blynk client (library)](legacy-platform/legacy-articles/implementing-a-blynk-client-library.md)
  * [App and board logs. How to send application and board logs correctly](legacy-platform/legacy-articles/app-and-board-logs.-how-to-send-application-and-board-logs-correctly.md)
  * [Blynk Android permissions explained](legacy-platform/legacy-articles/blynk-android-permissions-explained.md)
  * [How to find code for my hardware?](legacy-platform/legacy-articles/getting-started.md)
