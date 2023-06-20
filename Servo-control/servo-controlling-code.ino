#include <Servo.h>
#define up 3
#define down 4
#define left 5
#define right 6
#define center 7

Servo servo1;
Servo servo2;

int pos1 = 90;
int pos2 = 90;

void setup() {
  //Serial.begin(9600);
  pinMode(center,INPUT);
  pinMode(up,INPUT);
  pinMode(down,INPUT);
  pinMode(left,INPUT);
  pinMode(right,INPUT);

  servo1.attach(9);
  servo2.attach(10);
  servo1.write(pos1);
  delay(200);
  servo2.write(pos2);
  delay(200);

}

void loop() {
  // put your main code here, to run repeatedly:
  byte upstate = digitalRead(up);
  if ((upstate == HIGH) && (pos1 <= 160)){
    //Serial.println("Button up is pressed");
    pos1+=10;
    servo1.write(pos1);
    //Serial.println(pos1);
    //Serial.println(pos2);
    
    delay(250);
    }
  byte downstate = digitalRead(down);
  if ((downstate == HIGH) && (pos1 >= 20)){
    //Serial.println("Button down is pressed");
    pos1-=10;
    servo1.write(pos1);
    
    delay(250);
    }
  byte leftstate = digitalRead(left);
  if ((leftstate == HIGH) && (pos2 <= 160)){
    //Serial.println("Button left is pressed");
    pos2+=10;
    servo2.write(pos2);
    
    delay(250);
    }
  byte rightstate = digitalRead(right);
  if ((rightstate == HIGH) && (pos2 >= 20)){
    //Serial.println("Button right is pressed");
    pos2-=10;
    servo2.write(pos2);
    
    delay(250);
    }
  byte centerstate = digitalRead(center);
  if (centerstate == HIGH){
    //Serial.println("Button center is pressed");
    pos1=90;
    pos2=90;
    servo1.write(pos1);
    delay(200);
    servo2.write(pos1);
    delay(200);
    }  
}
