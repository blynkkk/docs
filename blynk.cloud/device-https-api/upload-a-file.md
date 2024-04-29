# Upload a File

```http
POST https://{server_address}/external/api/upload?token={token}
Content-Type: multipart/form-data; boundary=someboundary

--someboundary
Content-Disposition: form-data; name="upfile"; filename="poem.txt"
Content-Type: application/octet-stream

*My awesome poem*
--someboundary--
```

### Responses

{% tabs %}
{% tab title="Successfully uploaded" %}
Status code: `200 OK`\
Body consists of a URL, that is pointing to the uploaded file.

Example:

```
https://fra1.blynk.cloud/device_uploads/35587/8vPs4QSrfKOXyxZnXJhz0lA6cax7WQe8.xml
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

https://fra1.blynk.cloud/device_uploads/35587/8vPs4QSrfKOXyxZnXJhz0lA6cax7WQe8.xml
```

### Limitations

* Each device may hold up to 10 files. If the limit is exceeded - the oldest file will be deleted.
* Each file should be up to 5MB.
* Each device can upload up to 1,000. The limit is configurable for White-Label customers.
* Uploading a file with the same specified name, that was uploaded before, would override the existing file.
* This API is currently available only for White-Label customers.
