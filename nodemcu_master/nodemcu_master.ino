#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"
int c=0;
ESP8266WebServer server(80);

 void handleRootPath() {      //Handler for the root path
  server.send(200, "text/plain", "Test Successful");
}
void handleProject(){         //Handler for /project
  server.send(200,"text/plain",(String)c);
}
void handleNotFound(){        //Handler for unknown request
  server.send(200,"text/plain","No incoming data");
}
void setup() {
 
  Serial.begin(115200);
  WiFi.begin("VIT2.4G", "");  //Connect to the WiFi network
  Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
  while (WiFi.status() != WL_CONNECTED) {  //Wait for connection
  delay(500);
  Serial.println("Waiting to connect…");
  }
  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP
  server.on("/", handleRootPath);    //Associate the handler function to the path
  server.on("/project",HTTP_GET, handleProject); //when project handle is requested
  server.onNotFound(handleNotFound); //when unknown uri is requested
  server.begin();                    //Start the server
  Serial.println("Server listening");
 
}
 
void loop() {
  
  server.handleClient();         //Handling of incoming requests
  Wire.requestFrom(8, 1); // request & read data of size 13 from slave
  while(Wire.available()){
    int k=c;
    c = Wire.read();
    if(c!=k)
    Serial.println(c);
    k=0;
    delay(200);
  }
}
