#include <Servo.h>		

//Rappel : Vars globales, on y a accès depuis toutes les fonctions
Servo petitServo;	
int servoPos = 0;	// Position du servo	
const int LDR = A0;	// On fait pareil que précédemment
int LDRValue = 0;
int value = 0;

void setup()
{
petitServo.attach(9);	
petitServo.write(servoPos);	
}

void loop()
{
	LDRValue = analogRead(LDR);
	value = map(LDRValue, 0, 1023, 0, 100)
	if (value>20)		//Au-dessus de 20%, on fait bouger le servomoteur
	{
		servoAct();	// Appel fonction
	}
	delay(1000);
}

//fonction permettant de faire tourner le servo en fonction de sa position actuelle
void servoAct()
{
	if (servoPos==0) servoPos=180;	// La position passe d’un extrême à un autre
	else servoPos=0;

	petitServo.write(servoPos);	// Activation du servomoteur petitServo
} 
