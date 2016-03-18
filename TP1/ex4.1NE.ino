// initializes and declares the pin as contant variable 
const int led1 = 13;

void setup()
{
// sets the pin as output
pinMode(led1, OUTPUT); 
}

void loop()
{
//ex1();
ex2();
}

void ex1()
{
 digitalWrite(led1, HIGH); //sets the pin up
  delay(1000); // for a duration of 1 second
  digitalWrite(led1, LOW);//sets the pin down
  delay(500);// for a duration of 0.5 second
}

void ex2()
{
/*Morse code for NE: -. .
1s for a dash, 0.5s for a dot, 0.05s for interval timeouts 
*/
 digitalWrite(led1, HIGH); //sets the pin up
  delay(3000); // for a duration of 3 seconds DASH (DOT length x3)
  digitalWrite(led1, LOW);//sets the pin down
  delay(1000);// time between elements DOT length
   digitalWrite(led1, HIGH); //sets the pin up DOT
  delay(1000); // for a duration of 1 second
    digitalWrite(led1, LOW);//sets the pin down
  delay(3000);// time between characters DOT length x3
   digitalWrite(led1, HIGH); //sets the pin up DOT
  delay(1000); // for a duration of 1 second
   digitalWrite(led1, LOW);//sets the pin down
  delay(7000);// time between words DOT length x7
}