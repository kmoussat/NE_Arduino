#include <Console.h> // appel de  la console

void setup()
 {   
 // fonction de parametrage 
  	Bridge.begin();   		// com entre le AVR et le linux processor
  	Serial.begin(115200);  // début communication série + baud rate
}

void loop()
 {
  	Serial.println("Hello Arduino World!");	 //affichage du texte	
  	delay(2000); 		 // delais de 2s sans aucune execution
 }