---
description: >-
  Easily upload and manage all your assets in one central location, ready for
  use in both the App and Console dashboards.
---

# Assets

{% hint style="info" %}
**Note:** This feature is currently available only for Enterprise customers.
{% endhint %}

<figure><img src="../../.gitbook/assets/template-assets.png" alt=""><figcaption><p>Assets tab in your Device Template</p></figcaption></figure>

### Uploading Files

1. Navigate to the **Assets** tab in your Template.
2. Click the **Upload Files** button.
3. Drag and drop files or click on the file upload area to browse and select files.
4. Adjust file names if needed.
5. Click **Save** to upload the files.

{% hint style="success" %}
**Pro Tip:** Use `_light`/`_dark` postfixes in your file names, and the app will automatically detect the appropriate image for opposite themes.
{% endhint %}

{% hint style="warning" %}
**Note:** Uploading a file with the same name replaces the existing one.
{% endhint %}

***

### Creating Folders

You can create folders to organize your assets:

* Add a slash (`/`) to the file name to create subfolders.\
  Example: `buttons/play.png` creates a folder named `buttons` containing the file `play.png`.

{% hint style="success" %}
**Tip:** You can pre-name your files with slashes before uploading to speed up the folder creation process.
{% endhint %}

***

### Managing Files

#### Actions Available

* **Copy Link:** Get a direct link to the file for use anywhere in the app.
* **Rename:** Rename the file (folders cannot be created during renaming).

{% hint style="info" %}
Renaming a file does not change its link or ID.
{% endhint %}

* **Replace:** Replace the file while keeping the same ID.

{% hint style="info" %}
Ideal during prototyping to swap images without breaking the UI.\
When replacing an asset, the URL changes but the ID remains the same.
{% endhint %}

* **Delete:** Permanently delete the selected file(s).

***

### Limitations

| Limitation                 | Details                         |
| -------------------------- | ------------------------------- |
| **Supported formats**      | `.png`, `.jpg`, `.jpeg`, `.ico` |
| **Max files per upload**   | 50 files                        |
| **Max file size**          | 5 MB per file                   |
| **Storage per template**   | 200 MB                          |
| **Max files per template** | 1,000 files                     |
| **Max file name length**   | 1,000 characters                |

***

### Using Assets

#### 1. Add an Asset Using the Asset Picker (Recommended)

The Asset Picker is available in both the App and Console for convenient asset selection:

1. Click **Add Image** (in the App) or the image URL input (on mobile) to open the Asset Picker.
2. Search for an asset by name, or switch to "list view" for easier navigation.
3. Use sorting and grouping options to find assets quickly.

{% hint style="success" %}
**Pro Tip:** Use the **Add All** button to add all images from a folder at once.\
This feature is supported in the Image Gallery and Header Image widgets, with images sorted by their IDs.
{% endhint %}

<figure><img src="../../.gitbook/assets/asset-picker.png" alt=""><figcaption><p>Asset picker on iOS and Android</p></figcaption></figure>

#### 2. Add an Asset Using the URL

You can also manually copy an asset URL and paste it into the URL field where needed.

{% hint style="info" %}
**Important:** Replacing a file updates its link. To avoid broken links, use the Asset Picker or the file ID (`template_asset://ID`).
{% endhint %}

#### 3. Add Images Using Device Storage Placeholders

Replace placeholders with actual images stored on the device:

* **Supported Placeholder:** `device_storage://filename`

For more details on uploading files from your device, see the [Device HTTPS API Documentation](https://docs.blynk.io/en/blynk.cloud/device-https-api/upload-a-file).

***