const int LDR = A0;		// LDR sur AnalogPin 0
int LDRValue = 0;		// valeur en sortie de la LDR
int value = 0;			// valeur après mapping

void setup()
{
	Serial.begin(9600);	// Lancement communication série
}

void loop()
{
	LDRValue = analogRead (LDR);	// Lecture sur analog pin 0
	value = map (LDRValue, 0, 1023, 0, 255) //mapping
	Serial.println(value);		// Affichage de la valeur sur le port série
	Delay(1000);				// Temporisation de 1s
}