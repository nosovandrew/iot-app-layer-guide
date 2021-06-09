// CoAP-сервер
#include <ESP8266WiFi.h>
#include <coap_server.h>

// CoAP server endpoint url callback
void callback_light(coapPacket &packet, IPAddress ip, int port, int obs);
void callback_temp(coapPacket &packet, IPAddress ip, int port, int obs);

coapServer coap;

//WiFi connection info
const char* ssid = "nvv_kt";
const char* password = "f226717226717";

// LED STATE
bool LEDSTATE;

// CoAP server endpoint URL
void callback_light(coapPacket *packet, IPAddress ip, int port,int obs) {
  Serial.println("light");

  // send response
  char p[packet->payloadlen + 1];
  memcpy(p, packet->payload, packet->payloadlen);
  p[packet->payloadlen] = NULL;
  Serial.println(p);

  String message(p);

  if (message.equals("0"))
  {
    digitalWrite(16,LOW);
    Serial.println("0 received");
  }
  else if (message.equals("1"))
  {
    digitalWrite(16,HIGH);
    Serial.println("1 received");
  } 
  char *light = (digitalRead(16) > 0)? ((char *) "1") :((char *) "0");
  
   //coap.sendResponse(packet, ip, port, light);
   if(obs==1)
    coap.sendResponse(light);
   else
    coap.sendResponse(ip,port,light);
 
}

void callback_temp(coapPacket *packet, IPAddress ip, int port,int obs) {
  char *temp = ((char *) "28");
  if(obs==1)
    coap.sendResponse(temp);
   else
    coap.sendResponse(ip,port,temp);
}

void setup() {
  yield();
  //serial begin
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println(" ");

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    //delay(500);
    yield();
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());

  // LED State
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  LEDSTATE = false;

  // add server url endpoints.
  // can add multiple endpoint urls.

  coap.server(callback_light, "light");
  coap.server(callback_temp,"temperature");

  // start coap server/client
  coap.start();
  // coap.start(5683);
}

void loop() {
  coap.loop();
  delay(2000);
}
