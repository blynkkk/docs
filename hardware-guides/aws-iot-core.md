---
description: The integration details with AWS IoT Core service.
---

# AWS IoT Core

[AWS IoT Core](https://aws.amazon.com/iot-core/) is a managed cloud service that allows connected devices to interact easily and securely with cloud applications and other devices. The integration with AWS IoT Core is facilitated through [Device Shadow](https://docs.aws.amazon.com/iot/latest/developerguide/iot-device-shadows.html).

* **Uplink Support**: Blynk supports uplinks through Device Shadow updates, allowing seamless data communication.
* **Downlink Support**: Downlinks are managed by updating the shadow's desired state, ensuring synchronized device operation.
* **Device Importing**: Efficiently import devices, simplifying asset management.

### Connecting the integration

To connect the AWS IoT Core integration, you need to complete several fields and actions in AWS to enable Blynk to connect to your AWS IoT Core server and access your devices.

First, open your **Blynk Console** and go to **Developer Zone** → **Integrations** → **AWS IoT Core Integration**.

<figure><img src="../.gitbook/assets/AWS integration page.png" alt=""><figcaption></figcaption></figure>

Fill in all the required fields:

#### **1. Region**

Begin by selecting your AWS Region. You can locate this in the top-right corner of the AWS Management Console, near your account name.

#### **2. AWS IoT Core Domain**

Provide the AWS IoT Core Domain. To find it:

* Navigate to **AWS IoT Core** in the AWS Console.
* Go to **Connect** → **Domain Configurations** and copy the domain name.

<figure><img src="../.gitbook/assets/AWS domain configuration.png" alt=""><figcaption></figcaption></figure>

#### **3. AWS IoT Credentials Provider Domain**

If you have the AWS CLI tool installed and authorized to your account, execute the following command to retrieve the Credentials Provider Domain:

```bash
aws iot describe-endpoint --endpoint-type iot:CredentialProvider
```

Alternatively, you can run this command in the AWS Console using the CloudShell tool.

#### **4. AWS Account ID**

Find your AWS Account ID by clicking on your account name (top-right corner) in the AWS Console and copying the **Account ID** displayed.

#### **5. Create a Policy for Blynk Connection**

1. Copy the Policy JSON provided on Blynk's integration page.
2. In the AWS Console, go to **AWS IoT Core** → **Security** → **Policies** → **Create New**.
3. Assign a name to the policy (e.g., `BlynkPolicy`).
4. Select the **JSON Policy Editor**, paste the copied JSON policy, and click **Create**.

<figure><img src="../.gitbook/assets/AWS policy creation.png" alt=""><figcaption></figcaption></figure>

#### **6. Create Certificates for the Blynk Connection**

1. In the AWS Console, navigate to **AWS IoT Core** → **Security** → **Certificates**.
2. Click **Add certificate** → **Create certificate**.
3. Change its status to **Active** and click **Create**.
4.  Download the **Device Certificate** and **Private Key** files, then upload them to the corresponding section on the Blynk integration page.\


    <figure><img src="../.gitbook/assets/AWS certificate download screen.png" alt="" width="309"><figcaption></figcaption></figure>
5. Click **Continue** in the Blynk interface.
6. In the AWS Console, open the newly created certificate.
7. Click **Attach policies**, select the previously created policy (e.g., `BlynkPolicy`), and click **Attach policies**.

<figure><img src="../.gitbook/assets/AWS attach certificate policy screen.png" alt=""><figcaption></figcaption></figure>

#### **7. Create a Blynk Role**

1. On the Blynk integration page, copy the **Role JSON**.
2. In the AWS Console, navigate to the **IAM** service:
   * Go to **Roles** → **Create Role**.
   * Select **Custom Trust Policy** and paste the copied JSON.
   * Click **Next**, then **Next** again, and name the role **BlynkRole**.
3.  Click **Create Role** to finalize.\


    <figure><img src="../.gitbook/assets/AWS create role.png" alt=""><figcaption></figcaption></figure>
4. Next, on the Blynk integration page, copy the **Role Permission JSON**.
5. In the AWS Console, open the created **BlynkRole**, and:
   * Click **Add Permissions** → **Create Inline Policy**.
   * Choose the **JSON Policy Editor** and paste the copied JSON.
   * Enter a name for the policy and click **Create**.

<div><figure><img src="../.gitbook/assets/AWS role create policy (1).png" alt=""><figcaption></figcaption></figure> <figure><img src="../.gitbook/assets/AWS role policy creation.png" alt=""><figcaption></figcaption></figure></div>

#### **8. Create a Role Alias**

1. In the AWS Console, navigate to the **IoT Core** service.
2. Go to **Security** → **Role Aliases** → **Create Role Alias**.
3. Enter **BlynkRole** as the role alias name.
4. Select the previously created **BlynkRole** as the associated role.
5. Click **Create** to finalize.

<figure><img src="../.gitbook/assets/AWS role alias creation.png" alt=""><figcaption></figcaption></figure>

Now, in Blynk Console on the integration page click **Connect** and you should see the successful connection message.

<figure><img src="../.gitbook/assets/Blynk connected AWS integration.png" alt=""><figcaption></figcaption></figure>

### Configuring the integration

Once the integration is connected, you need to configure it:

1. **Create a Blynk Template**
   * If you haven’t already, [create the Blynk Template](../getting-started/template-quick-setup/) that will be used for your devices.
2. **Map the AWS Thing Type to the Blynk Template**
   * Blynk uses the AWS [Thing Type](https://docs.aws.amazon.com/iot/latest/developerguide/thing-types.html) to map devices of the same template to a corresponding set of devices on AWS.
   * Scroll to the bottom of the AWS Integration page, select the **Thing Type** you want to use, and its corresponding **Blynk Template**.
   * Click **Link** to save the selection.

<figure><img src="../.gitbook/assets/AWS Thing Type mapping.png" alt=""><figcaption></figcaption></figure>

### Importing device

After mapping the Thing Type, you can import devices of this type from AWS into Blynk:

1. Click the **Import** button.
2. Select the specific devices you want to import. Alternatively, you can click **Import All** to import all devices of the specified Thing Type from AWS.

<figure><img src="../.gitbook/assets/AWS device importing.png" alt=""><figcaption></figcaption></figure>

You can also manually create a device in Blynk by editing its **"Thing Name"** meta field. Ensure the value matches the exact **Thing Name** used in AWS IoT Core and include the device's region.

### Receiving uplinks

Once the integration is successfully connected and the Thing Type is mapped to the corresponding Blynk Template, the system is ready to receive uplink data.

**Configure Datastreams**\
Begin by setting up the datastreams within the Blynk Template. Ensure the names of the datastreams align with the JSON key names in the AWS IoT Device Shadow, and that their types match the JSON value types. Use Virtual Pins, Enum, and Location datastream types.

Below is an example of datastream configurations:\


<figure><img src="../.gitbook/assets/Blynk template datastreams settings (1).png" alt=""><figcaption></figcaption></figure>

Sample AWS IoT Device Shadow:

```json
{
    "state": {
        "reported": {
            "Temperature": 21.2,
            "Humidity": 43,
            "Location": [-73.935242, 40.730610]
        }
    }
}
```

### Receiving downlinks

To send a downlink to your device, first ensure that the necessary datastream is created. Then, add a control widget to the Web Dashboard or Mobile App.

When the widget is triggered, Blynk will update the device's unnamed shadow desired state with the value provided by the user.

### Next Steps

With a configured Blynk template and a working device, you can now start creating a [Web Dashboard](../blynk.console/templates/dashboard/) and [Mobile application](../blynk.apps/constructor.md).

Additionally, take advantage of other powerful Blynk features, such as [Automations](../concepts/automations.md), [WebHooks](../blynk.console/settings/developers/webhooks.md), [Device Connection Lifecycle](../concepts/connection-lifecycle-management/), and the [Device HTTPS API](../blynk.cloud/device-https-api/), to build more advanced workflows.
