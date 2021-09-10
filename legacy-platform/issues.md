---
description: >-
  This article will help you to correctly report the issue you might have and
  share the minimum necessary information needed to review it.
---

# Issues

### What information about the issue we need <a id="what-information-about-the-issue-we-need"></a>

In order to fix issue as soon as possible we need to understand it and have all the information about the environment in which it was observed. If you found a bug, incorrect behavior of application/hardware or you have any other difficulties please send us:

- **issue name**

- **the detailed description of the issue** \(including the summary, the OS version, phone / board model, IDE / Blynk library version / Core version of your board\)

- **steps to reproduce this issue**

- **actual and expected results**

- **Logs / Serial Monitor Output / Screenshots / Video / Sketch / Credentials** \(depending on a type of issue, we may need [additional information](https://app.intercom.com/a/apps/hhaxrs9k/articles/articles/4558902) to better understand it\)

**Without this information there is no viable way for us to investigate and fix any issue.**

It will also be extremely useful if you can add information like whether the issue is reproducible in another OS / board / Internet environment, etc. This will narrow down the issue, reduce communication and speed up the fix by times.

### Example: <a id="example"></a>

**The detailed description of the issue:** Android application does not send value "255" after clicking on the "Styled Button" widget.

**Steps to reproduce:**

1. Open Blynk app

2. Log in to account: [**test@email.com**](mailto:test@email.com) \[**blynk-cloud.com** server\]

3. Open and run the project \[[QR-code](https://docs.blynk.cc/#sharing-share-your-project-configuration)\]

4. Click on the Styled Button widget \[**Vpin5**\]

**Actual Result:** LED\[**Vpin5**\] does not change its state.

**Expected Result:** LED in the project should turn ON.

App logs and bare-minimum sketch are attached to the email.

