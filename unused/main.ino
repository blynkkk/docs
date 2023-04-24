/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_SERVER "fra.blynk-qa.com"

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <BlynkSimpleEsp32_SSL.h>

BlynkTimer timer;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";
int alertStatus = 0;

void myTimerEvent()
{
  int value = random (0, 100);
  alertStatus = map(value, 0, 100, 0, 2);
  Blynk.virtualWrite(V2, value);

  switch (alertStatus)
  {
  case 0:
    Blynk.setProperty(V0, "url", "https://raw.githubusercontent.com/blynkkk/docs/main/unused/astronaut.json");
    Blynk.setProperty(V0, "loop", "true");
    break;

  case 1:
    Blynk.setProperty(V0, "url", "https://raw.githubusercontent.com/blynkkk/docs/main/unused/orangealert.json");
    Blynk.setProperty(V0, "loop", "true");
    break;

  case 2:
    Blynk.setProperty(V0, "url", "https://raw.githubusercontent.com/blynkkk/docs/main/unused/redalert.json");
    Blynk.setProperty(V0, "loop", "true");
    break;

  default:
    Blynk.setProperty(V0, "url", "https://raw.githubusercontent.com/blynkkk/docs/main/unused/astronaut.json");
    Blynk.setProperty(V0, "loop", "true");
    break;
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, BLYNK_SERVER);
  timer.setInterval(5000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
}
