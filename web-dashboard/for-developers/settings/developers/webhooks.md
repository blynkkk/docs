# !Webhooks

![](../../../../.gitbook/assets/webhooks.png)

## Table contents

5 specific columns, table view order can be sorted by any of them.

* **Webhook name**
* **Status** _–_ webhooks can be enabled or disabled for execution
* **Trigger event** – displays the action that causes the webhook to run
* **Last triggered** – displays last execution time in hh:mm:ss M D, Y format \(current year is hidden\)
* **Attempts** – counter of all \(_successful, failed, test, real action_\) attempts to execute the webhook

## !New Webhook

## Actions

* **Click on row area** – opens Webhook view screen
* **Actions Menu**
  * **Edit** – \(also available from Webhook view screen\)
  * **Test** – triggers test execution with success/error return from the server on the top of the screen \(this execution is not saved to Webhook  Log\)
  * **Disable** – turns off the execution of the webhook without deleting it
  * **Delete** – opens delete modal window. Follow the steps described there 

## Webhook view

### Information

![Information tab](../../../../.gitbook/assets/webhook_view.png)

* **URL** – webhook requests destination 
* **Trigger events** – displays the action that causes the webhook to run
* **Webhook ID** 
* **Creation date** – hh:mm M D, Y format
* **Version**

### Logs table

This table stores and displays all trigger results that was caused by rel actions \(not test webhook runs\)  
It can be sorted by switching Timeline tabs and each column value.

![](../../../../.gitbook/assets/webhook_log.png)

* **Status** – `OK`_,_ `Waiting`_,_ `Failed` are possible with [`server response code`](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status)\`\`
* **Date** – webhook trigger time in hh:mm:ss M D, Y format 
* **Request to** – webhook request destination URL
* **Trigger ID** – hover on so the hint appears, click Copy pictogram to put it to your clipboard

