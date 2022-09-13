#include<Servo.h>
Servo SM;

#define LA 7
#define LB 8
#define RA 10
#define RB 11
#define ENA 6
#define ENB 5

#define trigpin 2
#define echo 4

void setup() {
  // put your setup code here, to run once:
  pinMode(LA, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RA, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(trigpin, OUTPUT);
  pinMode(echo, INPUT);

  analogWrite(ENA, 100);
  analogWrite(ENB, 100);

  SM.attach(9);
  SM.write(53);
  delay(3000);


}
int distance;
void loop() {
  // put your main code here, to run repeatedly:
  findDistance() ;

  if (distance > 35)
   {
    forward();
  } else
  {
    delay(60);
    findDistance();
    if (distance > 35) {
      forward();
    } else {
      Stop();
      SM.write(10);
      delay(500);
      findDistance();
      if (distance>35)
      {
        SM.write(53);
        delay(1000);
        rightward();
        delay(500);
        Stop();
      }
      else
      {
        SM.write(100);
        delay(1000);
        findDistance();
        if (distance>35){
          SM.write(53);
          delay(1000);
          leftward();
          delay(500);
          Stop();
        }else{
          SM.write(53);
          delay(1000);
          backward();
          delay(1500);
          Stop();
          
        }
      }
    }
  }
}
void forward() {
  digitalWrite(LA, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
}
void backward() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RA, LOW);
  digitalWrite(RB, HIGH);
}
void leftward() {
  digitalWrite(LA, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(RB, HIGH);
}
void rightward() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
}
void Stop() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(RB, LOW);
}

void findDistance() {
  int duration;
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (1 / 29.1) * (duration / 2);
  delay(60);

}
