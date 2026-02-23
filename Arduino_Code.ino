#include <Servo.h>

// Motor driver pins
#define LM1 2
#define LM2 3
#define RM1 4
#define RM2 5
#define ENAM A5
#define ENBM A4

// Water Pump pin
#define IN1 6
#define IN2 7
#define ENA 12

// Flame sensor pins
#define FLAME_LEFT 9
#define FLAME_FRONT 8
#define FLAME_RIGHT 10

// servo pin
#define SERVO_PIN 11

// Servo object
Servo servo;

void setup() {
  // Motor setup
  pinMode(ENA, OUTPUT);
  pinMode(ENAM, OUTPUT);
  pinMode(ENBM, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  // Flame sensor setup
  pinMode(FLAME_LEFT, INPUT);
  pinMode(FLAME_FRONT, INPUT);
  pinMode(FLAME_RIGHT, INPUT);

  // pump, Motor driver and servo setup
  analogWrite(ENAM, 0);
  analogWrite(ENBM, 0);
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW); 
  analogWrite(ENA, 255); // Turn off water pump
  servo.attach(SERVO_PIN);
  servo.write(55); // Center position
}

void loop() {
  // Read flame sensor values
  int flameLeft = digitalRead(FLAME_LEFT);
  int flameFront = digitalRead(FLAME_FRONT);
  int flameRight = digitalRead(FLAME_RIGHT);

  // Flame detection logic
  if (flameFront == LOW){   //Fire detected on front side  
    //moveForward();
    //delay(500);
    //stopMotors();
    digitalWrite(IN1, HIGH);  // Set IN1 HIGH
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 255); 
    for(int angle = 55;angle <= 110;angle+=2){
      servo.write(angle);
      delay(20);
    }
     for(int angle = 110;angle >= 0;angle-=2){
      servo.write(angle);
      delay(20);
    }
     for(int angle = 0;angle <= 110;angle+=2){
      servo.write(angle);
      delay(20);
    }
     for(int angle = 110;angle >= 55; angle-=2){
      servo.write(angle);
      delay(20);
    }
    
  // Turn off the pump
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
  delay(1000);
  } else if (flameLeft == LOW) { // Fire on the left
    turnLeft();
  } else if (flameRight == LOW) { // Fire on the right
    turnRight();
  } else {
    stopMotors(); // No fire detected, stop
  }

  delay(100);
}

// Motion functions
void moveForward() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(ENAM, 150);
  analogWrite(ENBM, 150);
}

void turnLeft() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(ENAM, 150);
  analogWrite(ENBM, 150);
  
}

void turnRight() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
  analogWrite(ENAM, 150);
  analogWrite(ENBM, 150);
 
}

void stopMotors() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);

}
