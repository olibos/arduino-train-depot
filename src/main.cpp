#include <Arduino.h>

#define PWM 6
#define OUT1 5
#define OUT2 7

void setup()
{
  pinMode(PWM, OUTPUT);
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  digitalWrite(OUT1, HIGH);
  digitalWrite(OUT2, HIGH);
  analogWrite(PWM, 0);
  pinMode(LED_BUILTIN, OUTPUT);
}

#define FORWARD 166
#define BACKWARD 150

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(OUT1, HIGH);
  digitalWrite(OUT2, LOW);

  for (int i = 0; i <= 10; i++)
  {
    analogWrite(PWM, i * 25);
    delay(FORWARD);
  }
  delay(50);
  for (int i = 10; i >= 0; i--)
  {
    analogWrite(PWM, i * 25);
    delay(FORWARD);
  }

  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, HIGH);
  delay(5000);
  for (int i = 0; i <= 10; i++)
  {
    analogWrite(PWM, i * 25);
    delay(BACKWARD);
  }
  delay(50);
  for (int i = 10; i >= 0; i--)
  {
    analogWrite(PWM, i * 25);
    delay(BACKWARD);
  }

  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
}
