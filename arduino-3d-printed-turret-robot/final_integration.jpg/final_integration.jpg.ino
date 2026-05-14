// Define the control output
#include <Servo.h>
#define MOT_A1_PIN 9
#define MOT_A2_PIN 6
#define MOT_B1_PIN 5
#define MOT_B2_PIN 3

// Define the angle and pin
Servo servo_1;
Servo servo_2;
Servo servo_3;

char selected_motor = 'A';

int angle_1 = 90;
int angle_2 = 90;
int direction = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo_1.attach(10);
  servo_2.attach(11);
  servo_3.attach(12);

  servo_1.write(angle_1);
  servo_2.write(angle_2);
  servo_3.write(angle_2);

  // setup pin for DC motor:
  pinMode(MOT_A1_PIN, OUTPUT);
  pinMode(MOT_A2_PIN, OUTPUT);
  pinMode(MOT_B1_PIN, OUTPUT);
  pinMode(MOT_B2_PIN, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(MOT_A1_PIN, LOW);
  digitalWrite(MOT_A2_PIN, LOW);
  digitalWrite(MOT_B1_PIN, LOW);
  digitalWrite(MOT_B2_PIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  readDirection();
  if (direction ==1){
    CW();
  } else if (direction ==2){
    CCW();
  } else if (direction ==0){
    stop();
  } else if (direction == 3){
    stop_DC();
  } else if (direction == 4){
    run();
  } else if (direction == 5){
    curve_ball();
  }
}

void readDirection() {
  if (Serial.available()>0){
    char ch = Serial.read(); // 첫 번째 문자(알맹이)를 읽음

        if (ch == 'A' || ch == 'B') {
        selected_motor = ch;
        direction = 0;

        Serial.print(">> Selected motor: ");
        Serial.println(selected_motor);
      } else if (ch >= '0' && ch <= '2') {
          direction = ch - '0'; // ASCII 문자 '1' -> 정수 1로 변환
          
          Serial.print(">> Received Command: ");
          Serial.println(direction);

          while (Serial.available() > 0) { // 버퍼 비우기
            Serial.read(); 
          }
          
          Serial.println("Enter next command:");
        } else if (ch >= '3' && ch <= '4') {
          direction = ch - '0'; // ASCII 문자 '1' -> 정수 1로 변환
          
          Serial.print(">> Received Command: ");
          Serial.println(direction);

          while (Serial.available() > 0) { // 버퍼 비우기
            Serial.read(); 
          }
          
          Serial.println("Enter next command:");
        } else if (ch >= '5' && ch < '6') {
          direction = ch - '0'; // ASCII 문자 '1' -> 정수 1로 변환
          
          Serial.print(">> Received Command: ");
          Serial.println(direction);

          while (Serial.available() > 0) { // 버퍼 비우기
            Serial.read(); 
          }
          
          Serial.println("Enter next command:");
        }
  }
}

void CCW(){
  if (selected_motor == 'A') {
    if (angle_1 < 180) {
      angle_1++;
      servo_1.write(angle_1);
      delay(15);
    }
    else servo_1.write(angle_1);
  }

  else if (selected_motor == 'B') {
    if (angle_2 < 180) {
      angle_2++;
      servo_2.write(angle_2);
      servo_3.write(angle_2);
      delay(15);
    }
    else servo_2.write(angle_2);
         servo_3.write(angle_2);
  }
}

void CW() {
  if (selected_motor == 'A') {
    if (angle_1 > 0) {
      angle_1--;
      servo_1.write(angle_1);
      delay(15);
    }
    else servo_1.write(angle_1);
  }

  else if (selected_motor == 'B') {
    if (angle_2 > 0) {
      angle_2--;
      servo_2.write(angle_2);
      servo_3.write(angle_2);
      delay(15);
    }
    else servo_2.write(angle_2);
         servo_3.write(angle_2);
  }
}

void stop(){
  if (selected_motor == 'A') {
    servo_1.write(angle_1);
  }
  else if (selected_motor == 'B') {
    servo_2.write(angle_2);
    servo_3.write(angle_2);
  }
}

// run DC motor
void run(){
  analogWrite(MOT_A1_PIN, 255);
  analogWrite(MOT_A2_PIN, LOW);
  analogWrite(MOT_B2_PIN, LOW);
  analogWrite(MOT_B1_PIN, 255);

}

void stop_DC(){
    analogWrite(MOT_A1_PIN, LOW);
    analogWrite(MOT_A2_PIN, LOW);
    analogWrite(MOT_B1_PIN, LOW);
    analogWrite(MOT_B2_PIN, LOW);
}

void curve_ball(){
    analogWrite(MOT_A1_PIN, 255);
  analogWrite(MOT_A2_PIN, LOW);
  analogWrite(MOT_B2_PIN, LOW);
  analogWrite(MOT_B1_PIN, 200);
}