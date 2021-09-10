---
description: How to set up custom "from" email address for transactional emails in Blynk
---

# Set up custom email address for transactional emails in Blynk

Commercial version of Blynk instance includes sending out transactional emails.

Transactional email is a type of automated email between a sender and a recipient. It differs from marketing email in that transactional email is triggered by events, interactions, or preferences within your application rather than by a your company’s marketing campaign.

#### **A list of all transactional emails Blynk can send on your behalf:** <a id="a-list-of-all-transactional-emails-blynk-can-send-on-your-behalf-"></a>

* Invitation email \( a link to create new account in your app and dashboard\)
* Confirmation of account creation and app download instructions
* Password reset link
* Succesful password reset
* Email when new Event is logged \(on a timeline\)
* Scheduled and one-shot reports
* Email with a link to download Report for device\(s\)
* Email with a link to download OTA report
* Email with user actions report

Transactional emails are included in every commercial installation of Blynk and by default all the emails are sent from `dispatcher@blynk.io`

#### Changing FROM email address <a id="changing-from-email-address"></a>

If you need to use another **FROM** address, for example: `noreply@mycompany.com`, you would need to next:

1. Get in touch with Blynk team and let them know that you would need custom email address.
2. Provide the **domain** you would like to use in "**from**" email address, for example: `mycompany.com` and email address you would like to use for transactional emails. For example `no-reply@mycompany.com`
3. Blynk engineer will set up the mail client for you.
4. Blynk engineer will provide you with new DNS and TXT records which should be created by you in your DNS management system \(e.g. GoDaddy\). You will get instructions on what should be done.
5. You will get an email to specified address \(e.g. `no-reply@mycompany.com` \) with a verification link. You would need to click on this link.

After the verification is done, all transactional emails will be from the address you specified.

