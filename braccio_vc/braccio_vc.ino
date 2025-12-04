#include <Braccio.h>
#include <Servo.h>

// Servo objects
#include <SoftwareSerial.h>

SoftwareSerial vcSerial(2, 3);
String command ;
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_ver;
Servo wrist_rot;
Servo gripper;

void setup() {
  Braccio.begin();
  Serial.begin(115200); 
  vcSerial.begin(115200);
 
}

void pick() {
  Braccio.ServoMovement(20, 100, 90, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 100, 90, 0, 45, 180, 30);
  delay(100);
  Braccio.ServoMovement(20, 100, 58, 0, 45, 180, 30);
  delay(100);
  Braccio.ServoMovement(20, 100, 58, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 100, 90, 0, 45, 180, 73);
  delay(100);
  ///////
}
void place() {
  Braccio.ServoMovement(20, 100, 90, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 100, 58, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 100, 58, 0, 45, 180, 30);
  delay(100);
  Braccio.ServoMovement(20, 100, 90, 0, 45, 180, 73);
  delay(100);
  ///////
}
void say_hi() {
  Braccio.ServoMovement(20, 100, 90, 90, 0, 180, 73);
  delay(500);
  Braccio.ServoMovement(10, 100, 90, 90, 0, 0, 73);
  delay(100);
  Braccio.ServoMovement(10, 100, 90, 90, 0, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 100, 45, 180, 0, 180, 73);
}
void give() {
  Braccio.ServoMovement(20, 100, 75, 90, 0, 180, 65);
  delay(1000);
  Braccio.ServoMovement(15, 100, 75, 90, 0, 180, 30);
  delay(2000);
  Braccio.ServoMovement(20, 100, 75, 90, 0, 180, 73);
}
void hold() {
  Braccio.ServoMovement(20, 100, 75, 90, 0, 180, 73);
  delay(1000);
  Braccio.ServoMovement(15, 100, 75, 90, 0, 180, 30);
  delay(1000);
  Braccio.ServoMovement(15, 100, 75, 90, 0, 180, 65);
}
void pick_on_right() {
  Braccio.ServoMovement(20, 180, 90, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 180, 90, 0, 45, 180, 30);
  delay(100);
  Braccio.ServoMovement(20, 180, 58, 0, 45, 180, 30);
  delay(100);
  Braccio.ServoMovement(20, 180, 58, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 180, 90, 0, 45, 180, 73);
  delay(100);

  
}
void pick_on_left() {
  Braccio.ServoMovement(20, 0, 90, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 0, 90, 0, 45, 180, 30);
  delay(100);
  Braccio.ServoMovement(20, 0, 58, 0, 45, 180, 30);
  delay(100);
  Braccio.ServoMovement(20, 0, 58, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 0, 90, 0, 45, 180, 73);
  delay(100); 
  /////
}
void place_on_left() {
  Braccio.ServoMovement(20, 0, 90, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 0, 58, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 0, 58, 0, 45, 180, 30);
  delay(100);
  Braccio.ServoMovement(20, 0, 90, 0, 45, 180, 30);
  delay(100);
  Braccio.ServoMovement(20, 0, 90, 0, 45, 180, 73);
  delay(100);
  /////
}
void place_on_right() {
  Braccio.ServoMovement(20, 180, 90, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 180, 58, 0, 45, 180, 73);
  delay(100);
  Braccio.ServoMovement(20, 180, 58, 0, 45, 180, 30);
  delay(100);
  Braccio.ServoMovement(20, 180, 90, 0, 45, 180, 30);
  delay(100);
  Braccio.ServoMovement(20, 180, 90, 0, 45, 180, 73);
  delay(100);
  /////
}
void home_position() {
  Braccio.ServoMovement(20, 90, 45, 180, 0, 180, 73);
}



void loop() {



  if (vcSerial.available()) {
    int command = vcSerial.read(); 
    Serial.println(command);
    // command.trim();
    if (command == 183){
      pick();
    }
    else if (command == 168){
      place();
    }
    else if (command ==  167){
      say_hi();
    }
    else if (command == 210){
      give();
    }
    else if (command == 209){
      hold();
    }
    else if (command == 194){
      pick_on_right();
    }
    else if (command == 193){
      pick_on_left();
    }
    else if (command == 211){
      place_on_left();
    }
    else if (command == 212){
      place_on_right();
    }
    else if (command == 160){
      home_position();
    }
  }
}

 