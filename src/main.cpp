#include <Arduino.h>

#define segA 2
#define segB 3
#define segC 4
#define segD 5
#define segE 6
#define segF 7
#define segG 8

void apaga();
void mostra_numero(int n);

int num[10][7] = {
    {segA, segB, segC, segD, segE, segF},         // zero
    {segB, segC},                                 // um
    {segA, segB, segD, segE, segG},               // dois
    {segA, segB, segC, segD, segG},               // tres
    {segB, segC, segF, segG},                     // quatro
    {segA, segC, segD, segF, segG},               // cinco
    {segA, segC, segD, segE, segF, segG},         // seis
    {segA, segB, segC},                           // sete
    {segA, segB, segC, segD, segE, segF, segG},   // oito
    {segA, segB, segC, segD, segF, segG}          // nove
};

void setup()
{
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  Serial.begin(9600);
}

void loop()
{

  delay(1000);
  apaga();
  int valor_potenciometro = analogRead(A0);
  Serial.println(valor_potenciometro);
  int numero_a_apresentar = map(valor_potenciometro, 0, 1023, 0, 9);
  mostra_numero(numero_a_apresentar);
  
}

void apaga()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void mostra_numero(int n)
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(num[n][i], LOW);
  }
}