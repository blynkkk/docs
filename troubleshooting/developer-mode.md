# Developer Mode

## I can't enable Developer Mode

**What could be the reason:**

* Organization can have only one developer account. That is done to avoid sync issues.

**What’s the solution:**

* Contact other users with admin role and ask them to disable Developer Mode on their side so you could enable it on yours.
* This limit can be changed in the future.

## Changes made to Device Template are not applied

**What could be the reason:**

* there was no Save action confirmation
* Save command was sent during the server disconnect

**What’s the solution:**

* be sure to click Save button on the top right after you made changes that you want to keep
* check your internet connection please.
* keep the page open, click Save once you'll get "Connection has been restored" 

## **My API request doesn't work**

**What could be the reason:**

* request with incorrect parameters  
* the device token is specified incorrectly  
* wrong pin format input  
* value doesn't match the datastream type  
* requested datastream doesn't exist in the product  
* event code is not provided  
* there's no event with code provided in the product

**What’s the solution:**

* follow [HTTPS guides](https://docs.blynk.io/en/blynk.cloud/update-datastream-value) attentively  
* be sure to send the requests to the correct server  
* check all the inputs to be corrent in the request and to be present in the template _(also there's a hint on what exactly went wrong in a result field of Postman or web page body)_

## I can't see enumerable datastreams in Blynk.Apps

**What could be the reason:**

* not supported by every widget at the moment

**What’s the solution:**

* view full metadata list in Blynk.Console
* wait for Blynk.Apps list of widgets that support enumerable datastreams to expand 
* keep Blynk.Apps up to date

## I can't add an image to Blynk.Apps widget

**What could be the reason:**

* limited access to the image source
* image extension is not supported

**What’s the solution:**

* be sure to use the link open to public
* images should have .png, .jpg, jpeg or .gif extension

## I've created dashboard in web and don't see it in mobile app (or reverse)

**What could be the reason:**

* there's no option to convert templates between Blynk.Apps and Blynk.Console now.

**What’s the solution:**

* set up dashboards in both Blynk.Apps and Blynk.Console

## I've set up Map widgets in web and mobile app but they show different data

**What could be the reason:**

* web and mobile apps Map widgets use different datastreams in their sets now

**What’s the solution:**

* wait for Blynk.Console and Blynk.Apps to become unified
* keep Blynk.Apps up to date

## Flood Error

**What could be the reason:**

* Your code frequently sends a lot of requests to our server, your hardware will be disconnected. Blynk.App may show “Your hardware is offline”\
  When `Blynk.virtualWrite` is in the `void loop`, it generates hundreds of “writes” per second

Here is an example of what may cause flood. _**DON’T DO THAT:**_

```
void loop()
{
  Blynk.virtualWrite(1, value); // This line sends hundreds of messages to Blynk server
  Blynk.run();
}
```

**What’s the solution:**

* If you need to perform actions in time intervals - use timers, for example [BlynkTimer.](../blynk.edgent/api/blynk-timer.md)\
  \
  **Note:** using `delay()` will not solve the problem either. It may cause [Delay issue](https://docs.blynk.io/en/troubleshooting/developer-mode#delay). Use timers!

If sending hundreds of requests is what you need for your product you may increase flood limit on local server and within Blynk.Library. For local server you need to change `user.message.quota.limit` property within `server.properties` file :

```
    #100 Req/sec rate limit per user.
    user.message.quota.limit=100
```

For library you need to change `BLYNK_MSG_LIMIT` property within `BlynkConfig.h` file :

```
    //Limit the amount of outgoing commands.
    #define BLYNK_MSG_LIMIT 20
```

## Delay

**What could be the reason:**

* If you use long `delay()` or send your hardware to sleep inside of the `loop()` expect connection drops and downgraded performance.

_**DON’T DO THAT:**_

```
void loop()
{
  ...
  delay(1000); // this is long delay, that should be avoided
  other_long_operation();
  ...
  Blynk.run();
}
```

_**Note:**_ This also applies to the BLYNK_READ & BLYNK_WRITE handlers!

**What’s the solution:**

* If you need to perform actions in time intervals - use timers, for example [BlynkTimer](../blynk.edgent/api/blynk-timer.md)
