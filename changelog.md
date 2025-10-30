# Changelog

## October 30, 2025&#x20;

### New features

* New Blynk firmware API to get device owner locale

### Improvements

* Free plan hardware messages limit increased 30k -> 200k

### Cleanup & Fixes

* **AI Chat:**
  * Fixed metadata addition issue on request.
  * Corrected suggestions for `int` datastream with invalid min/max values.
  * Ensured widget creation requires a relevant datastream.
  * Corrected Vpin format to prevent product crashes.
  * Prevented changes to datastream type (e.g., Enum to Int, GPS to String) during settings modification.
  * Stopped duplication of datastreams when edits are made.
  * Fixed coordinate parsing and non-existent parameter usage.
  * Resolved the mode switch issue when already in Edit mode.
  * Ensured user confirmation before reporting successful changes.
  * Restricted User Notes to one per user.
  * Addressed missing SMS notification recipients in event creation.
* **Dashboards:**
  * Improved GeoMap widget performance with large datasets.
  * Reinforced the limit of 5 Image Map widgets per dashboard.
  * Resolved indefinite dashboard loading due to filters (QuotaExceededError).
  * Corrected pop-up placement when images are zoomed.
  * Prevented Image Map markers from being placed outside visible image areas.
  * Fixed console errors during long editing sessions.
* **Artifacts:**
  * Corrected the "Edit Template" button to switch to edit mode successfully.
* **Device Reports:**
  * Addressed discrepancies between device reports and Service Charts caused by timezone issues.
* **UI:**
  * Corrected font weight for column headings in all tables.
* **Server:**
  * Stopped duplicate replacements of the heartbeat handler on device connection.
  * Fixed memory leaks in the MQTT encoder.
  * Added internal worker for system resources monitoring for self-hosted environments

## October 13, 2025&#x20;

### **New Features**

#### AI Chat Features

* **Availability:** AI Chat is now accessible for Free and Plus users with a 100-message limit. Pro users can use up to 1000 messages.
* **Expanded View:** The AI Chat interface can now be expanded to 40rem (640px) width, with preferences saved for user convenience.

#### MQTT Converter

* **Downlinks:** Added downlink functionality in MQTT converters to trigger device actions.

#### SQL Widget

* **Download Confirmation:** A download confirmation popup is now available for CSV report exports in SQL widgets, aligning with device reports.

### **Improvements**

* **AI Chat Interface:** Enhanced code block display for improved readability.
* **AI Chat UX:** Replaced the "New Chat" icon with a broom icon for better clarity.
* **AI Chat Performance:** Optimized database queries for quicker AI message history retrieval.
* **Converter UI:** "Create" buttons are auto-hidden when datastream/event limits are reached.
* **Device Interface:** Resolved no-device screen issue for non-developer users.
* **Modules Widget:** Made "Create more datastreams" text non-interactive when no datastreams match.
* **Email Validation:** Improved registration email validation to support special characters.
* **OpenWeather Optimization:** Reduced API call frequency for better performance.

### **Cleanup & Fixes**

#### AI Chat

* Resolved crash issues during product edit mode.
* Fixed server message content errors after restarts.
* Corrected datastream spec artifacts.
* Adjusted single backtick wrapping in code blocks.
* Fixed crash due to "undefined is not an object" error.

#### Automation

* Fixed editing window closure issue when deselecting datastreams.
* Resolved marking issues for datastreams in automation.
* Hide "Duplicate" button when only one action exists.

#### Control Segments

* Fixed name cropping issues in the automation interface.

#### Converter UI

* Resolved template name overflow hiding additional action buttons.

#### Device Customization

* Fixed non-functional search in the "Customize View" tab.

#### Device Map

* Fixed map button visibility on "My Devices" page after refresh.
* Fixed map not displaying when adding a new location in device info.

#### Geographic Map Widget

* Prevented devices from displaying on the Design tab without available devices.
* Fixed double map loading on the Design tab.
* Resolved widget name cropping with "Upgrade" button visible.

#### Icon Alignment

* Corrected misaligned icons.

#### Webhook Parameters

* Fixed missing timestamp and tag values in webhook calls.

#### Product Validation

* Resolved "Datastream should have unique ID" error for AI-generated datastreams.

## September 30, 2025&#x20;

> ### **New Features**
>
> * **Customize View Accessibility**: The "Customize View" button for the device list is now available to all plans, broadening its previous accessibility from just Plus/Pro users.
> * **New Column in Customize View**: We've added a "Last Connected At" column to enhance the "Customize View" options.
> * **New Webhooks for Enterprise Plans**:
>   * "New Organization Created"
>   * "Product Log Event"
> * **Rule Engine Update**: Introduced a new Rule Engine flow to cater to "Plan Changed" triggers for Enterprise end-user billing.
> * **AI Helper Chat**: A new AI helper chat feature is now available to make template editing and configuration easier.
> * **Automations for Segments**: Our automation now supports device segments, allowing for dynamic device list generation.
> * **GeoMap Widget**: A new GeoMap widget has been introduced.
> *   **CSV Download Features**:
>
>     * Button added for downloading uploaded CSV files for In-App campaigns.
>     * Organizations list can now be downloaded as CSV files.
>
>
>
> ### **Cleanup & Fixes**&#x20;
>
> * Reformatted datastream values in the devices table.
> * Enhanced error messages for data converters.
> * Fixed memory leak in rare cases during data converter usage.
> * Corrected incorrect counters in running shipments.
> * Added a link to documentation in the Data Converter view.
> * Boosted performance for ARM servers in self-hosted environments.

## September 12, 2025&#x20;

> ### **New Features**
>
> * **Data Converters**: A user-defined JavaScript for HTTPS/MQTT messages that can decode/encode messages on the fly and perform other Blynk operations like sending log events, changing multiple data streams at a time, data filtering, and conversion, etc. Available for Enterprise and PRO users.
> * **Root Org Level Webhook**: With "Organization Created" trigger. Available for Enterprise users.
> * **Image Map Widget**: Upload your image of a building, floor, room, etc., and pin devices on it. Available for Enterprise and PRO users.
>
>
>
> ### **Cleanup & Fixes**&#x20;
>
> * The maximum number of data streams for Enterprise clients is now 256 instead of 255 as it was before.
> * Fixed broken percentage counters in dashboard widgets "Active Devices" / "Total Devices."

## August 18, 2025&#x20;

> ### **Enterprise features** &#x20;
>
> * Event and push messages are now translated based on each receiver’s locale, ensuring notifications are delivered in the user’s preferred language.
>
> ### **Improvements**  &#x20;
>
> * Added the “Download all” button in Assets to easily export all files with assets JSON as a ZIP archive.&#x20;
> * **OTA:** status now displays only the actual state per device, simplifying managing multiple devices
> * Added a download popup for SQL widget reports, giving users clearer control over exporting data
>
> ### **Cleanup & Fixes**&#x20;
>
> Ongoing stability improvements and resolution of various UI, logic, and performance issues.

## August 4, 2025&#x20;

> ### **New Features**&#x20;
>
> * **Dashboards:** New Bitmask Table widget that visualizes binary states as LED indicators in a table, supporting customizable rows, endianness, and per-bit inversion for efficient status monitoring.&#x20;
> * **Dashboards:** Added support for entering decimal values in the slider widget to enable precise control, e.g., setting temperature thresholds.
> * **Datastreams:** When saving with invalid fields, the editor now automatically opens the tab containing the errors to improve visibility and user feedback.
> * **Platform API:** Added Get Base Device Info endpoint with minimized response for faster device lookup and improved performance.
>
>
>
> ### **Improvements**
>
> * **OTA:** Implemented gradual shipment rollout for over 100k devices to prevent system overload by staggering firmware delivery when targeting fleets over 10k devices.&#x20;
> * **Intercom Integration:** Improved security by implementing JWT-based user authentication for the Intercom messenger across platforms.
>
>
>
> ### **Enterprise Features**
>
> * **Datastreams**: Added support for storing string datastream values, including integration into device reports and history data export.
> * **Platform:** Implemented support for HTTP range requests in the static file handler to enable partial downloads, such as segmented firmware retrieval.
>
>
>
> ### **Cleanup & Fixes**&#x20;
>
> Ongoing stability improvements and resolution of various UI, logic, and performance issues.

\


## July 7, 2025

> ### New Features
>
> * **Blynk.Apps**: Stop Automation allowing users to halt running automation directly from the automation settings or card.
>
>
>
> ### Enterprise Features
>
> * **Custom Data:** allows users to view, create, edit, and manage custom database records with proper validation, nested relations, and access control—supporting both structured data management and field operations. It is available in Blynk.Console and Blynk.Apps.
>
>
>
> ### Cleanup & Fixes
>
> Ongoing stability improvements and resolution of various UI, logic, and performance issues.

## June 23, 2025

> ### New Features
>
> * **Blynk.Console**: more dashboard features are now available to users on the Free plan.
>
>
>
> ### Improvements
>
> * **Blynk.Apps**: Android – Developer Mode UX Improvements for theme sync and editing flow.
> * **Enterprise**: Enhanced email notifications.
>
>
>
> ### Cleanup & Fixes
>
> Ongoing stability improvements and resolution of various UI, logic, and performance issues.



## June 9th, 2025&#x20;

> ### New Features
>
> * **Get Started With Blynk**: New first-month experience with streamlined onboarding and a unified device connection flow covering all supported connection methods.
>
>
>
> ### Enterprise features
>
> * **Intercom Integration**: platform-wide support for Intercom chat with configurable settings and user activity sync.&#x20;
> * **Custom Roles**: enabled support for the creation, modification, and management of custom roles, featuring hierarchical synchronization, limit enforcement, and granular permission control across organizations
>
>
>
> ### Cleanup & Fixes
>
> Ongoing stability improvements and resolution of various UI, logic, and performance issues.

\
