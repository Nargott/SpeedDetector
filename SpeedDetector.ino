#include "MatrixDisplay.h"

#define LASER0 6
#define LASER1 7

#define WAIT_TO_ERROR 5000000 //micros
#define SHOW_DELAY 10000000 //micros

float dist = 1.00;

boolean is_sleep, is_show;
volatile unsigned long gap1, gap2;
unsigned long sleep_timer;
float velocity, velocity_km;

void start() {
  Serial.println("START");
  if (gap1==0) {
    gap1=micros();
  } 
}


void finish() {
  Serial.println("END");
  if (gap2==0) {
    gap2=micros();
  }
  is_sleep=false;
  sleep_timer=micros();
}

void setup() {
  pinMode(LASER0, OUTPUT);
  pinMode(LASER1, OUTPUT);
  Serial.begin(9600);
  initMatrix();
  attachInterrupt(0, start, RISING);
  attachInterrupt(1, finish, RISING);
}

void loop() {
  digitalWrite(LASER0, HIGH);
  digitalWrite(LASER1, HIGH);
  if (gap1!=0 && gap2!=0 && gap2>gap1) {
    velocity=(1000000*(dist)/(gap2-gap1));
    velocity_km = velocity*3.6;
    Serial.print("Speed = ");
    Serial.println(velocity);
    gap1=0;
    gap2=0;
    is_show=true;
  }

  if (is_show) {
    int v = round(velocity);
    Serial.print("Speed rounded = ");
    Serial.println(v);
    showNumber(v);
    is_show=false;
  }

  if (micros()-gap1>WAIT_TO_ERROR && gap1!=0) {
    Serial.println("FAIL");
    gap1=0;
    gap2=0;
    is_sleep=false;
    showChar(45);
    is_show=false;
    sleep_timer=millis();
  }

  if ( (micros()-sleep_timer) > SHOW_DELAY && !is_sleep) {
    is_sleep=true;
    clear();
  }

  delay(5);
}
