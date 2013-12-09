#include <Arduino.h>
#include "Ardumoto.h"

Ardumoto::Ardumoto(){
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void Ardumoto::forward(int l, int r, int t)
{
  analogWrite(10,l);
  analogWrite(11,r);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  delay(t);
}

void Ardumoto::reverse(int l, int r, int t)
{
  analogWrite(10,l);
  analogWrite(11,r);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(t);
}

void Ardumoto::brake(int t)
{
  analogWrite(10,0);
  analogWrite(11,0);
  delay(t);
}

void Ardumoto::rotate(int t)
{
  analogWrite(10,100);
  analogWrite(11,100);
  if (t>0) {
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  delay(abs(t));
}
