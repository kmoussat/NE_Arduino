int compteur = 0;
int const inter = 2;

void setup() 
{
  	Serial.begin(9600);
  	pinMode(13, OUTPUT);
  	pinMode(2, INPUT);
  	//Exercice 4.3.2.2: (à mettre en commentaire pour faire fonctionner le 4.3.2.1)
  	attachInterrupt(digitalPinToInterrupt(inter), clignoter, RISING);
}

void loop() 
{

  	//Exercice 4.3.2.1:
 	 if(digitalRead(inter))
  	{
    		while(digitalRead(inter))
   		 {
      			//Tant que le bouton n'est pas relâché on ne fait rien
   		 }	//bouton relaché
    		compteur++;	//on incrémente
    		Serial.print(compteur);
 	 }

}

void clignoter()	// Fonction pour le 4.3.2.2
{
  	digitalWrite(13,HIGH);
  	delay(500);
  	digitalWrite(13,LOW);
  	delay(10);
}
