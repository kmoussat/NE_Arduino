#include <Servo.h>
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

Servo servo;
YunServer server;

int LDR1 = A0;
int LDR2 = A1;
int L1 = 0;
int L2 = 0;
int diff = 0;

int angleServo = 90;
int seuil = 90;


void setup()
{
  Serial.begin(9600);
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
  Serial.println("Begin");

  servo.attach(9);
  servo.write(angleServo);
}

void loop()
{
  Serial.println("lecture capteur");
  L1 = analogRead(LDR1);
  L2 = analogRead(LDR2);
  diff = L1 - L2;

  YunClient client = server.accept();
  if (client)
  {
    Serial.println("Reception commande");
    String command = client.readString();
    Serial.println(command);
    switch(command.toInt())
    {
      case 1000:
        Serial.print("L1 = ");
        Serial.println(L1);
        Serial.print("L2 = ");
        Serial.println(L2);
        break;

      case 2000:
        if (diff < 0)
          client.println("rotation sens horaire");
        else
          client.println("rotation sens anti-horaire");
        break;

      case 9999:
        Serial.print("L1 = ");
        Serial.println(L1);
        Serial.print("L2 = ");
        Serial.println(L2);
        if (diff < 0)
          client.println("rotation sens horaire");
        else
          client.println("rotation sens anti-horaire");
        break;

      default:
        command.trim();
        seuil = command.toInt();
        break;
    }
    client.stop();
  }

  //Reprise du code initial
  if (diff > seuil)
  {
    angleServo = angleServo + 1;
    if (angleServo > 180)
    {
      angleServo = 180;
    }
    else {}
    servo.write(angleServo);
  }

  else if (diff < -seuil)
  {
    angleServo = angleServo - 1;
    if (angleServo < 0)
    {
      angleServo = 0;
    }
    else {}
    servo.write(angleServo);
  }

  delay(15);
}
