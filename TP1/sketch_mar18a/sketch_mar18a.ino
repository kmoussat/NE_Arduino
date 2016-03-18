#include <SoftwareSerial.h>
#include <Bridge.h>
#include <HttpClient.h>
#include <Console.h>


void setup() {
  Bridge.begin();
  Serial.begin(9600);

  while (!Serial);

client();
 
}


 
void loop() {
  

}


void client() {

  // Initialize the client library
  HttpClient client;

  // Make a HTTP request:
  client.get("http://www.arduino.cc/asciilogo.txt");

  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();
    Serial.println(c);
  }
  Serial.flush();

  delay(5000);
 
}
