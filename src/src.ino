#include <Keyboard.h>

int encoderA = 7;
int encoderB = 6;
int encoderPos = 0;
int encoderALast = LOW;
int encoderRead = LOW;
int right = 12;
int left = 11;
int profile1 = 9;
int profile2 = 8;
int profile3 = 2;
int key1 = 5;
int key2 = 4;
int key3 = 3;
int key4 = 10;
int profile1LED = 15; //A1
int profile2LED = 16; //A2
int profile3LED = 17; //A3
int key1LED = 18; //A4
int key2LED = 19; //A5
int key3LED = 20; //A6
int key4LED = 21; //A7

int profile1State = HIGH;
int profile2State = LOW;
int profile3State = LOW;
int key1State = LOW;
int key2State = LOW;
int key3State = LOW;
int key4State = LOW;

void setup() {
  pinMode (encoderA, INPUT);
  pinMode (encoderB, INPUT);
  pinMode(profile1, INPUT_PULLUP);
  pinMode(profile2, INPUT_PULLUP);
  pinMode(profile3, INPUT_PULLUP);
  pinMode(key1, INPUT_PULLDOWN);
  pinMode(key2, INPUT_PULLDOWN);
  pinMode(key3, INPUT_PULLDOWN);
  pinMode(key4, INPUT_PULLDOWN);
  pinMode(profile1LED, OUTPUT);
  pinMode(profile2LED, OUTPUT);
  pinMode(profile3LED, OUTPUT);
  pinMode(key1LED, OUTPUT);
  pinMode(key2LED, OUTPUT);
  pinMode(key3LED, OUTPUT);
  pinMode(key4LED, OUTPUT);
  Keyboard.begin();
//  Serial.begin(9600);
}

void up() {
  if (isNavegation()) {
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.release(KEY_UP_ARROW);
  }
}

void down() {
  if (isNavegation()) {
    Keyboard.press(KEY_DOWN_ARROW);
    Keyboard.release(KEY_DOWN_ARROW);
  }
}
bool isNavegation() {
  if (key1State == LOW && key2State == LOW && key3State == LOW && key4State == LOW) {
    return true;
  } else {
    return false;
  }
}

void pushProfile1() {
    profile1State = HIGH;
    profile2State = LOW;
    profile3State = LOW;
    updateLED();
}
void pushProfile2() {
    profile1State = LOW;
    profile2State = HIGH;
    profile3State = LOW;
    updateLED();
}
void pushProfile3() {
    profile1State = LOW;
    profile2State = LOW;
    profile3State = HIGH;
    updateLED();
}
void pushKey1() {
  if (key1State == LOW) {
    key1State == HIGH;
  } else {
    key1State == LOW;
  }
  updateLED();
  delay(100);
}
void pushKey2() {
  if (key2State == LOW) {
    key2State == HIGH;
  } else {
    key2State == LOW;
  }
  updateLED();
  delay(100);
}
void pushKey3() {
  if (key3State == LOW) {
    key3State == HIGH;
  } else {
    key3State == LOW;
  }
  updateLED();
  delay(100);
}
void pushKey4() {
  if (key4State == LOW) {
    key4State == HIGH;
  } else {
    key4State == LOW;
  }
  updateLED();
  delay(100);
}

void updateLED() {
  digitalWrite(profile1LED, profile1State);
  digitalWrite(profile2LED, profile2State);
  digitalWrite(profile3LED, profile3State);
  digitalWrite(key1LED, key1State);
  digitalWrite(key2LED, key2State);
  digitalWrite(key3LED, key3State);
  digitalWrite(key4LED, key4State);
}

void loopp() {
//  digitalWrite(profile1LED, HIGH);
//  delay(1000);
//  digitalWrite(profile1LED, LOW);
//  delay(1000);
  profile1State = HIGH;
  profile2State = LOW;
  profile3State = LOW;
  updateLED();
  delay(1000);
  profile1State = LOW;
  profile2State = HIGH;
  profile3State = LOW;
  updateLED();
  delay(1000);
  profile1State = LOW;
  profile2State = LOW;
  profile3State = HIGH;
  updateLED();
  delay(1000);
}

void loop() {
  encoderRead = digitalRead(encoderA);
  if ((encoderALast == LOW) && (encoderRead == HIGH)) {
    if (digitalRead(encoderB) == LOW) {
      up();
    } else {
      down();
    }
  }
  encoderALast = encoderRead;

  if (digitalRead(profile1) == LOW) {
    pushProfile1();
  }
  if (digitalRead(profile2) == LOW) {
    pushProfile2();
  }
  if (digitalRead(profile3) == LOW) {
    pushProfile3();
  }
  if (digitalRead(key1) == HIGH) {
    pushKey1();
  }
  if (digitalRead(key2) == HIGH) {
    pushKey2();
  }
  if (digitalRead(key3) == HIGH) {
    pushKey3();
  }
  if (digitalRead(key4) == HIGH) {
    pushKey4();
  }
}
