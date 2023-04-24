/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_SERVER ""

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <BlynkSimpleEsp32_SSL.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "shanti";
char pass[] = "TimeIsNotImport@nt";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN,ssid, pass, BLYNK_SERVER);
}

void loop()
{
  Blynk.run();
}
