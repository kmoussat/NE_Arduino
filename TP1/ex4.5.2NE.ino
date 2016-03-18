#include <Servo.h>		

//Rappel : Vars globales, on y a accès depuis toutes les fonctions
Servo petitServo;	
int servoPos = 0;	// Position du servo	s	
const int LDR = A0;	// On fait pareil que précédemment
int LDRValue = 0;
int value = 0;

void setup()
{
petitServo.Attach(9);	
petitServo.Write(servoPos);	
}

void loop()
{
	LDRValue = analogRead(LDR);
	value = map(LDRValue, 0, 1023, 0, 100)
	if (value>20)		//Au-dessus de 20%, on fait bouger le servomoteur
	{
		servoAct(*servoPos);	// Appel fonction avec en argument l’adresse de servoPos
	}
	Delay(100);
}

//fonction permettant de faire tourner le servo en fonction de sa position actuelle
void servoAct(*int pos)	//On prend en argument l’adresse de la var de position
{
	if (pos==0) pos=180;	// La position passe d’un extrême à un autre
	else pos=0;

	petitServo.Write(pos);	// Activation du servomoteur petitServo
} 