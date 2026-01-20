# MCP Server

Blynk provides a hosted Model Context Protocol (MCP) server, designed to enable clients to interact with their hardware through AI interfaces. This implementation streamlines development and allows AI agents to manage your fleet, enabling tasks like checking device status, metadata, and datastream values through natural language or automated workflows.

Endpoint: `https://blynk.cloud/mcp`&#x20;

### Authentication

The Blynk MCP server implements the OAuth 2.0 specification in full accordance with the MCP standard. All requests require a valid access token. To facilitate seamless integration across different AI platforms and services, the server also supports Dynamic Client Registration.

### Tools

Blynk’s MCP server provides a suite of tools that allow AI agents to perform administrative and operational tasks directly within your organization.

{% hint style="warning" %}
Each tool requires specific permissions associated with the user's role (e.g., _View Devices_, _Edit Templates_).

For tools that modify the structure of your project (like creating templates or datastreams), [Developer Mode](../concepts/developer-mode.md) must be enabled in your User Profile.
{% endhint %}

#### Search Devices

`search_devices`

Finds and lists devices, optionally filtered by name.\
Example AI request: "Find all devices that have 'Pump' in their name."

#### Create a Device

`create_device`

Creates a new device under a template and generates an Auth Token.\
Example AI request: "Create a new device named 'Living Room Sensor' using template 'Room Sensor'."

#### Get all Templates

`get_all_templates`

Retrieves information of all templates, including their name, description and template ID.\
Example AI request: "List all my available templates."

#### Get Template

`get_template`

Retrieves a detailed information of a specific template, including its datastream, event, lifecycle settings.\
Example AI request: "Show the template 'Living Room Sensor' datastream settings."

#### Create a Template

`create_template`

Creates a new template, specifying it's name, description, connection type and other information.\
Example AI request: "Set up a new template for an ESP32 board connected via Wi-Fi."

#### Create a DataStream

`create_datastream`

Adds a new virtual data channel (V1–V255) to a specific template.\
Example AI request: "Add a new datastream to template TMPL123 for temperature tracking."

#### Edit a DataStream

`edit_datastream`

Updates the configuration of an existing data channel within a template.\
Example AI request: "Change the unit of the datastream on V1 in template TMPL123 to Celsius."

#### Create an Event

`create_event`

Adds a new event to a specific template.\
Example AI request: "Create a 'Low Battery' event for my sensor template."

#### Edit an Event

`edit_event`

Modifies the parameters or notification settings of an existing event.\
Example AI request: "Update the 'Overheat' event to be a high-priority notification."

### Resources

Beyond active tools, the MCP server exposes Device and Template entities as persistent resources.

Resources offer a standardized method for AI to interpret the state of your Blynk ecosystem, providing models with the long-term context needed for accurate analysis and troubleshooting.
