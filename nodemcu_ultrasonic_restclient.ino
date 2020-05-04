#include "ESP8266WiFi.h"
#include "RestClient.h"
//RestClient clients = RestClient("if.unila.ac.id");

String response;
#define LED     D0        // Led in NodeMCU at pin GPIO16 (D0).

const char server[] = "if.unila.ac.id"; 
const char* MY_SSID = "UPT.TIK";
const char* MY_PWD =  "UNILAJAYA2020";
WiFiClient client;


#define triggerPin  D1
#define echoPin     D2

void setup() {

  Serial.print("Connecting to "+*MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  Serial.println("going into wl connect");

  while (WiFi.status() != WL_CONNECTED) //not connected,  ...waiting to connect
    {
      delay(1000);
      Serial.print(".");
    }
  Serial.println("wl connected");
  Serial.println("");
  Serial.println("Credentials accepted! Connected to wifi\n ");
  Serial.println("");
  
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600); 
}

void loop() {

  long duration, jarak;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  jarak = (duration/2) / 29.1;
  Serial.print("Jarak Sensor: ");
  Serial.println(jarak);

  Serial.println("\nStart koneksi ke server..."); 
  // Apabila terhubung, akan ada laporan via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected to server");
    WiFi.printDiag(Serial);

  client.print("GET /iot/load.php?jarak=");
  client.print(jarak);
  client.println(" HTTP/1.1");
  client.println("Host: 192.168.1.9");
  client.println();

   if (jarak < 20 ){
    digitalWrite(LED, HIGH); 
    }
   else {
    digitalWrite(LED, LOW); 
    }
  
  delay(1000);
}
}
