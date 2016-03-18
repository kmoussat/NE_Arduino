Code:
#include <Servo.h>		// Ajout de la librairie pour servos

Servo petitServo;		// Création objet de classe Servo grâce à la librairie

void setup()
{
petitServo.attach(9);	// servo sur digital pin 9 ( PWM bien sûr)
petitServo.write(0);		// Initialisation à la position extrême 0°
delay(500);			// Temporisation avant démo
petitServo.write(180);	// Demi-tour complet dans un sens ->180°
delay(1000);			// Temporisation pour bien voir
petitServo.write(0);		// Demi-tour dans l’autre sens -> retour à 0°
}

void loop()
{
}