# Update Device Metadata Value

You can update the value of any single-value (text, number, hotspot, device name, list, int, imei, iccid) device meta field using its identifier.



<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/device/meta/update?token={token}&metaFieldId={metaFieldId}&value={metaFieldValue}`

or by metafield name (**param and value are case sensitive, should be properly encoded**):

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/device/meta/update?token={token}&metaFieldName={metaFieldId}&value={metaFieldValue}`

###

### Example

`https://fra1.blynk.cloud/external/api/device/meta/update?token=EzHOlVG4dOdkPozcZutxK0AlkrsJAVff&metaFieldId=3&value=Sample+value`

`https://fra1.blynk.cloud/external/api/device/meta/update?token=EzHOlVG4dOdkPozcZutxK0AlkrsJAVff&metaFieldName=Meta%20Name&value=Sample%20value`

### Response

#### **Success**

**200 OK**

#### **Invalid token error**

**400 Bad Requets**

```
{"error":{"message":"Invalid token."}}
```

#### **Wrong metafield identifier format**

**400 Bad Requets**

```
{"error":{"message":"Wrong metaField format"}}
```

#### **Metafield is not found**

**400 Bad Requets**

```
{"error":{"message":"MetaField doesn't exist"}}
```

#### **Wrong metafield value**

**400 Bad Requets**

```
{"error":{"message":"Wrong value"}}
```

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}
