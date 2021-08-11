#include <Keyboard.h>

int encoderA = 7;
int encoderB = 6;
int encoderPos = 0;
int encoderALast = LOW;
int encoderRead = LOW;
int right = 11;
int left = 12;
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
  pinMode(key1, INPUT_PULLUP);
  pinMode(key2, INPUT_PULLUP);
  pinMode(key3, INPUT_PULLUP);
  pinMode(key4, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  pinMode(profile1LED, OUTPUT);
  pinMode(profile2LED, OUTPUT);
  pinMode(profile3LED, OUTPUT);
  pinMode(key1LED, OUTPUT);
  pinMode(key2LED, OUTPUT);
  pinMode(key3LED, OUTPUT);
  pinMode(key4LED, OUTPUT);
  Keyboard.begin();
//  Serial.begin(9600);
  updateLED();
}

void up() {
  if (isNavegation() || isSelection()) {
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.release(KEY_UP_ARROW);
  } else if (isMove()) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_UP_ARROW);
  } else if (isHorizontal()) {
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.release(KEY_LEFT_ARROW);    
  }
}

void down() {
  if (isNavegation() || isSelection()) {
    Keyboard.press(KEY_DOWN_ARROW);
    Keyboard.release(KEY_DOWN_ARROW);
  } else if (isMove()) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_DOWN_ARROW);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_DOWN_ARROW);
  } else if (isHorizontal()) {
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.release(KEY_RIGHT_ARROW);    
  }
}
void pushLeft() {
  if (isNavegation()) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('a');
    Keyboard.release(KEY_LEFT_CTRL);
  } else if (isSelection()) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('A');
    Keyboard.release(KEY_LEFT_CTRL);
  } else if (isMove()) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.write('[');
    Keyboard.release(KEY_LEFT_GUI);
  }
  delay(200);
}
void pushRight() {
  if (isNavegation()) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('e');
    Keyboard.release(KEY_LEFT_CTRL);
  } else if (isSelection()) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('E');
    Keyboard.release(KEY_LEFT_CTRL);
  } else if (isMove()) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.write(']');
    Keyboard.release(KEY_LEFT_GUI);
  }
  delay(200);
}
bool isNavegation() {
  if (key1State == LOW && key2State == LOW && key3State == LOW && key4State == LOW) {
    return true;
  } else {
    return false;
  }
}
bool isSelection() {
  if (key1State == HIGH) {
    return true;
  } else {
    return false;
  }
}
bool isMove() {
  if (key2State == HIGH) {
    return true;
  } else {
    return false;
  }
}
bool isHorizontal() {
  if (key4State == HIGH) {
    return true;
  } else {
    return false;
  }
}
void releaseModKeys() {
  Keyboard.release(KEY_LEFT_SHIFT);
  Keyboard.release(KEY_LEFT_CTRL);
  Keyboard.release(KEY_LEFT_GUI);
  Keyboard.release(KEY_LEFT_ALT);

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
    releaseModKeys();
    updateLED();
}
void pushKey1() {
  if (key1State == LOW) {
    key1State = HIGH;
    Keyboard.press(KEY_LEFT_SHIFT);
  } else {
    key1State = LOW;
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  updateLED();
  delay(300);
}
void pushKey2() {
  if (key2State == LOW) {
    key2State = HIGH;
    key1State = LOW;
    Keyboard.release(KEY_LEFT_SHIFT);
  } else {
    key2State = LOW;
  }
  updateLED();
  delay(300);
}
void pushKey3() {
  if (key3State == LOW) {
    releaseModKeys();
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.write('b');
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_ALT);
//    key3State = HIGH;
  } else {
    key3State = LOW;
  }
  updateLED();
  delay(300);
}
void pushKey4() {
  Serial.println(key4State);
  if (key4State == LOW) {
    key4State = HIGH;
  } else {
    key4State = LOW;
  }
  updateLED();
  delay(300);
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
      down();
    } else {
      up();
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
  if (digitalRead(key1) == LOW) {
    pushKey1();
  }
  if (digitalRead(key2) == LOW) {
    pushKey2();
  }
  if (digitalRead(key3) == LOW) {
    pushKey3();
  }
  if (digitalRead(key4) == LOW) {
    pushKey4();
  }
  if (digitalRead(left) == LOW) {
    pushLeft();
  }
  if (digitalRead(right) == LOW) {
    pushRight();
  }
}
