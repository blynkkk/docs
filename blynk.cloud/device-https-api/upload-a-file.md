# Upload a File

{% hint style="info" %}
This API is currently available only for Enterprise customers.
{% endhint %}

```http
POST https://{server_address}/external/api/upload?token={token}
Content-Type: multipart/form-data; boundary=someboundary

--someboundary
Content-Disposition: form-data; name="upfile"; filename="file.png"
Content-Type: application/octet-stream

*My awesome poem*
--someboundary--
```

### Responses

{% tabs %}
{% tab title="Successfully uploaded" %}
Status code: `200 OK`\
The body consists of a URL, that is pointing to the uploaded file.

Example:

```
https://fra1.blynk.cloud/device_uploads/35587/8vPs4QSrfKOXyxZnXJhz0lA6cax7WQe8.png
```
{% endtab %}

{% tab title="Invalid Device Token" %}
Status code: `400 Bad Request`\
Example body:

```json
{"error":{"message":"Invalid token."}}
```
{% endtab %}

{% tab title="File uploads limit has been reached" %}
Status code: `403 Forbidden`\
Example body:

```json
{"error":{"message":"File uploads limit has been reached."}}
```
{% endtab %}
{% endtabs %}

cURL example:

```bash
$ curl -X POST -F upfile=@image.png https://{server_address}/external/api/upload?token={token}
```

cURL example with real data:

```bash
$ curl -X POST -F upfile=@image.png https://fra1.blynk.cloud/external/api/upload?token=jO3u7d6qkjWncxw91D1glSHIe5hJ7bSk

https://fra1.blynk.cloud/device_uploads/35587/8vPs4QSrfKOXyxZnXJhz0lA6cax7WQe8.png
```

### Limitations

* Each device may hold up to 10 files. If the limit is exceeded - the oldest file will be deleted.
* Each file should be up to 5MB.
* Each device can upload up to 1,000
* Uploading a file with the same specified name, that was uploaded before, would override the existing file.

All the above limits could be changed based on the Enterprise client's needs.

The uploaded images could be previewed in the "Developer Tools" section:

<figure><img src="../../.gitbook/assets/upload.jpg" alt=""><figcaption><p>File Storage for the uploaded images</p></figcaption></figure>
