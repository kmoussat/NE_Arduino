/*
  Yún HTTP Client

 This example for the Arduino Yún shows how create a basic
 HTTP client that connects to the internet and downloads
 content. In this case, you'll connect to the Arduino
 website and download a version of the logo as ASCII text.

 created by Tom igoe
 May 2013

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/HttpClient

 */

#include <Bridge.h>
#include <HttpClient.h>

const int led1 = 13;

void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  Bridge.begin();
  digitalWrite(led1, HIGH);

  Serial.begin(9600);

  while (!Serial); // wait for a serial connection
}

void loop() {
  // Initialize the client library
  HttpClient client;

  // Make a HTTP request:
  client.get("http://arduino.cc/asciilogo.txt");


  // if there are incoming bytes available
  // from the server, read them and print them:
  String str = "";
    char c;
    int count=0;
  while (client.available()) {  
    c = client.read();
        Serial.print(c);  
    str += String(c);
    count = int(str.length());

  
    blink(count);
    
  
  }
  Serial.println("Nombre de caracteres en string");
  Serial.println(str.length());

  /*int count = int(str.length());
  Serial.println("Nombre de caracteres en Int ");
  Serial.println(count);


  digitalWrite(led1, HIGH);
  digitalWrite(led1, LOW);

 blink(count);
  */
  Serial.flush();


  
  delay(10000);
}


void blink(int count)
{
 int  n = 100;
double  timer=n/count;

  for (int i = 0; i < count; i++)
  {
    digitalWrite(led1,HIGH);
    delay(timer);
    digitalWrite(led1,LOW);
    delay(timer);
    
  }
}

