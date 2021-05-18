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

// #define FORWARD 166 * 2
// #define BACKWARD 150 * 2
#define FORWARD 600
#define BACKWARD FORWARD
#define START 4
#define END START + 3

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(OUT1, HIGH);
  digitalWrite(OUT2, LOW);

  for (int i = START; i <= END; i++)
  {
    analogWrite(PWM, i * 25);
    delay(FORWARD);
  }
  delay(50);
  for (int i = END; i >= START; i--)
  {
    analogWrite(PWM, i * 25);
    delay(FORWARD);
  }

  digitalWrite(OUT1, LOW);
  delay(7000);
  digitalWrite(OUT2, HIGH);

  for (int i = START; i <= END; i++)
  {
    analogWrite(PWM, i * 25);
    delay(BACKWARD);
  }
  delay(50);
  for (int i = END; i >= START; i--)
  {
    analogWrite(PWM, i * 25);
    delay(BACKWARD);
  }

  digitalWrite(OUT2, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(10000);
}
