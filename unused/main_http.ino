/* Fill in information from Blynk Device Info here */
//#define BLYNK_TEMPLATE_ID           ""
//#define BLYNK_TEMPLATE_NAME         ""
//#define BLYNK_AUTH_TOKEN            ""

// Network settings
const char ssid[] = "";
const char pass[] = "";

// Blynk cloud server
const char* host = "fra.blynk-qa.com";
unsigned int port = 80;

WiFiClient client;

// Start the WiFi connection
void connectNetwork()
{
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
}

bool httpRequest(const String& method,
                 const String& url,
                 const String& request,
                 String&       response)
{
  Serial.print(F("Connecting to "));
  Serial.print(host);
  Serial.print(":");
  Serial.print(port);
  Serial.print("... ");
  if (client.connect(host, port)) {
    Serial.println("OK");
  } else {
    Serial.println("failed");
    return false;
  }

  Serial.print(method); Serial.print(" "); Serial.println(url);

  client.print(method); client.print(" ");
  client.print(url); client.println(F(" HTTP/1.1"));
  client.print(F("Host: ")); client.println(host);
  client.println(F("Connection: close"));
  if (request.length()) {
    client.println(F("Content-Type: application/json"));
    client.print(F("Content-Length: ")); client.println(request.length());
    client.println();
    client.print(request);
  } else {
    client.println();
  }

  //Serial.println("Waiting response");
  int timeout = millis() + 5000;
  while (client.available() == 0) {
    if (timeout - millis() < 0) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return false;
    }
  }

  //Serial.println("Reading response");
  int contentLength = -1;
  while (client.available()) {
    String line = client.readStringUntil('\n');
    line.trim();
    line.toLowerCase();
    if (line.startsWith("content-length:")) {
      contentLength = line.substring(line.lastIndexOf(':') + 1).toInt();
    } else if (line.length() == 0) {
      break;
    }
  }

  //Serial.println("Reading response body");
  response = "";
  response.reserve(contentLength + 1);
  while (response.length() < contentLength) {
    if (client.available()) {
      char c = client.read();
      response += c;
    } else if (!client.connected()) {
      break;
    }
  }
  client.stop();
  return true;
}

void setup()
{
  Serial.begin(9600);
  delay(10);
  Serial.println();
  Serial.println();

  connectNetwork();
}

void loop() {
  String response;
  
  int value = random(0, 100);
  alertStatus = map(value, 0, 100, 0, 2);
  //Blynk.virtualWrite(V2, value);

  //unsigned long value = millis();

  // Send value to the cloud
  // similar to Blynk.virtualWrite()

  Serial.print("Sending value: ");
  Serial.println(value);

  if (httpRequest("GET", String("/external/api/update?token=") + BLYNK_AUTH_TOKEN + "&pin=V2&value=" + value, "", response)) {
    if (response.length() != 0) {
      Serial.print("WARNING: ");
      Serial.println(response);
    }
  }

  // Read the value back
  // similar to Blynk.syncVirtual()

  Serial.println("Reading value");

  if (httpRequest("GET", String("/external/api/get?token=") + BLYNK_AUTH_TOKEN + "&pin=V2", "", response)) {
    Serial.print("Value from server: ");
    Serial.println(response);
  }

  // Wait
  delay(8000L);
}
