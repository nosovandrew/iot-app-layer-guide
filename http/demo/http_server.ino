// HTTP-сервер
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "nvv_kt"
#define STAPSK  "f226717226717"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

uint8_t temperature = 28;
char str_temp[10];

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/controlpanel", []() {
    server.send(200, "text/html", SendHTML(temperature));
  });

  server.on("/rawtemperature", []() {
    sprintf(str_temp, "%d", temperature);
    server.send(200, "text/plain", str_temp);
  });
  
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}

String SendHTML(uint8_t temperature)
{
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>Smart Home: Control Panel</title>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";

  ptr += "<h1>Smart Home App (HTTP + IoT)</h1>";
  ptr += "<p>Current temperature:\n";
  ptr += temperature;
  ptr += " C\n";
  ptr +="<p>\n";

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
