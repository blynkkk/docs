# Changelog

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

## August 4, 2025

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
