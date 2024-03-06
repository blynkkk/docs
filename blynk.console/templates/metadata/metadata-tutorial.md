# Metadata Tutorial

Metadata is a table of `key:value` data attached to every device. `Keys` are static, and `values` are related for each device.

For example, a Serial Number Metadata field can be attached to every device, but the actual value is different.

### **1.** [Create a Template](../../../getting-started/template-quick-setup/) or use an existing one

### **2. Create Metadata**

1. Open Template
2. Click **Edit** at the top right
3. Switch to Metadata tab

![](https://user-images.githubusercontent.com/72824404/120795827-aa439000-c542-11eb-8aec-660d8000baea.png)

4. Click **Add Metadata**.

Choose the most relevant [type](../datastreams/datastreams-common-settings/data-type.md) for every metadata input. For example, if you would need to associate Serial Number with every product, add the “Number” metadata field.

5. Set it up and click **Create** button once you've finished with this characteristic

![](https://user-images.githubusercontent.com/72824404/120796929-15da2d00-c544-11eb-8ed2-52ae0fdd94f7.png)

6. Repeat steps 4 and 5 untill you create Metadata list you need &#x20;
7. Click **Save** Template at the top right &#x20;
8. Choose Apply Changes option (let's select Save Changes. Don't update active device this time) and click **Continue**

![](https://user-images.githubusercontent.com/72824404/120797093-3efabd80-c544-11eb-81bb-24344b16717b.png)

{% hint style="info" %}
You can edit Product's Metadata settings any time you need it by following the steps above.
{% endhint %}

### 3. [Add Device](../../../blynk.apps/device-management/add-new-device.md) and provide it's Metadata

During the provision there will be prompts to input Device Metadata:

![Device profiling](https://user-images.githubusercontent.com/72790181/119658205-8a6ee680-be35-11eb-8825-6bc47971ef98.png)

1. Change default value to actual one by tapping step buttons or direct input to the field. &#x20;
2. Follow provision flow till it's end.

### 4. View Metadata

#### View metadata in Blynk.Apps

1. Tap Device tile
2. Tap top right Menu button
3. Scroll through Information tab untill you see Metadata you need

![Device profile](https://user-images.githubusercontent.com/72790181/119658437-d1f57280-be35-11eb-881f-8346abdd42ec.png)

#### View metadata in Blynk.Console

1. Find your Device
2. Click on it's name or row in the table
3. Switch to Metadata tab

![](https://user-images.githubusercontent.com/72824404/120797332-90a34800-c544-11eb-8337-2127e665b330.png)

### 5. Edit Device Metadata

#### Edit device metadata in Blynk.Apps

1. Tap Device tile
2. Tap top right Menu button
3. Scroll through Information tab untill you see Metadata you need
4. Tap Metadata value field
5. Change the value
6. Return to the previous screen

#### Edit device metadata in Blynk.Console

1. Find your Device
2. Click on it's name or row in the table
3. Switch to Metadata tab
4. Hover Metadata value you want to change
5. Click **Edit**
6. Change the value
7. Click **Save**

![](https://user-images.githubusercontent.com/72824404/120797432-b4ff2480-c544-11eb-92b7-681fed6f0262.png)
