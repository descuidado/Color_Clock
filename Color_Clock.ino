#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#define dataline 2
#define output 3
#define rst 4
#define input 5
#define Ymin 11
#define Dmin 6


tmElements_t tm;

void setup() {
  for (int i = 2; i <= 16; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  RTC.read(tm);
  showNumMin(tm.Minute / 10, Dmin);
  showNumMin(tm.Minute % 10, Ymin);
  showNumHour(tm.Hour);
  if (analogRead(A2) < 960 && analogRead(A2) > 860) {
    delay(110);
    if (analogRead(A2) < 960 && analogRead(A2) > 860) {
      minUpPressed();
    }
  }
  if (analogRead(A3) < 960 && analogRead(A3) > 860) {
    delay(110);
    if (analogRead(A3) < 960 && analogRead(A3) > 860) {
      HourUpPressed();
    }
  }
  if (analogRead(A2) < 550 && analogRead(A2) > 450) {
    delay(110);
    if (analogRead(A2) < 550 && analogRead(A2) > 450) {
      minDownPressed();
    }
  }
  if (analogRead(A3) < 550 && analogRead(A3) > 450) {
    delay(110);
    if (analogRead(A3) < 550 && analogRead(A3) > 450) {
      HourDownPressed();
    }
  }
}

void minUpPressed() {
  short int minutetowrite = tm.Minute;
  minutetowrite++;
  if (minutetowrite > 59) {
    minutetowrite = 0;
  }
  tm.Minute = minutetowrite;
  RTC.write(tm);
}

void minDownPressed() {
  short int minutetowrite = tm.Minute;
  minutetowrite--;
  if (minutetowrite < 0) {
    minutetowrite = 59;
  }
  tm.Minute = minutetowrite;
  RTC.write(tm);
}
void HourUpPressed() {
  short int hourtowrite = tm.Hour;
  hourtowrite++;
  if (hourtowrite > 23) {
    hourtowrite = 0;
  }
  tm.Hour = hourtowrite;
  RTC.write(tm);
}
void HourDownPressed() {
  short int hourtowrite = tm.Hour;
  hourtowrite--;
  if (hourtowrite < 0) {
    hourtowrite = 23;
  }
  tm.Hour = hourtowrite;
  RTC.write(tm);
}

void showNumMin(int number, int pin) {
  if (number == 0) {
    digitalWrite(pin, LOW);
    digitalWrite(pin + 1, LOW);
    digitalWrite(pin + 2, LOW);
    digitalWrite(pin + 3, LOW);
    digitalWrite(pin + 4, LOW);
  }
  if (number == 1) {
    digitalWrite(pin, HIGH);
    digitalWrite(pin + 1, LOW);
    digitalWrite(pin + 2, LOW);
    digitalWrite(pin + 3, LOW);
    digitalWrite(pin + 4, LOW);
  }
  if (number == 2) {
    digitalWrite(pin, HIGH);
    digitalWrite(pin + 1, HIGH);
    digitalWrite(pin + 2, LOW);
    digitalWrite(pin + 3, LOW);
    digitalWrite(pin + 4, LOW);
  }
  if (number == 3) {
    digitalWrite(pin, HIGH);
    digitalWrite(pin + 1, HIGH);
    digitalWrite(pin + 2, HIGH);
    digitalWrite(pin + 3, LOW);
    digitalWrite(pin + 4, LOW);
  }
  if (number == 4) {
    digitalWrite(pin, HIGH);
    digitalWrite(pin + 1, HIGH);
    digitalWrite(pin + 2, HIGH);
    digitalWrite(pin + 3, HIGH);
    digitalWrite(pin + 4, LOW);
  }
  if (number == 5) {
    digitalWrite(pin, LOW);
    digitalWrite(pin + 1, LOW);
    digitalWrite(pin + 2, LOW);
    digitalWrite(pin + 3, LOW);
    digitalWrite(pin + 4, HIGH);
  }
  if (number == 6) {
    digitalWrite(pin, HIGH);
    digitalWrite(pin + 1, LOW);
    digitalWrite(pin + 2, LOW);
    digitalWrite(pin + 3, LOW);
    digitalWrite(pin + 4, HIGH);
  }
  if (number == 7) {
    digitalWrite(pin, HIGH);
    digitalWrite(pin + 1, HIGH);
    digitalWrite(pin + 2, LOW);
    digitalWrite(pin + 3, LOW);
    digitalWrite(pin + 4, HIGH);
  }
  if (number == 8) {
    digitalWrite(pin, HIGH);
    digitalWrite(pin + 1, HIGH);
    digitalWrite(pin + 2, HIGH);
    digitalWrite(pin + 3, LOW);
    digitalWrite(pin + 4, HIGH);
  }
  if (number == 9) {
    digitalWrite(pin, HIGH);
    digitalWrite(pin + 1, HIGH);
    digitalWrite(pin + 2, HIGH);
    digitalWrite(pin + 3, HIGH);
    digitalWrite(pin + 4, HIGH);
  }
}

void showNumHour(int number) {
  digitalWrite(rst, LOW);
  delay(5);
  digitalWrite(rst, HIGH);
  digitalWrite(dataline, LOW);
  if (number == 1) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
  }
  if (number == 2) {
    digitalWrite(dataline, HIGH);
    next();
    next();
    digitalWrite(dataline, LOW);
    next();
  }
  if (number == 3) {
    digitalWrite(dataline, HIGH);
    next();
    next();
    next();
    digitalWrite(dataline, LOW);
    next();
  }
  if (number == 4) {
    digitalWrite(dataline, HIGH);
    next();
    next();
    next();
    next();
    digitalWrite(dataline, LOW);
    next();
  }
  if (number == 5) {
    next();
    next();
    next();
    next();
    digitalWrite(dataline, HIGH);
    next();
  }
  if (number == 6) {
    next();
    next();
    next();
    //next();
    digitalWrite(dataline, HIGH);
    next();
    next();
  }
  if (number == 7) {
    next();
    next();
    digitalWrite(dataline, HIGH);
    next();
    next();
    next();
  }
  if (number == 8) {
    next();
    digitalWrite(dataline, HIGH);
    next();
    next();
    next();
    next();
  }
  if (number == 9) {
    digitalWrite(dataline, HIGH);
    next();
    next();
    next();
    next();
    next();
  }
  if (number == 10) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    next();
    next();
    next();
    next();
  }
  if (number == 11) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    next();
    next();
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
  }
  if (number == 12) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    next();
    digitalWrite(dataline, HIGH);
    next();
    next();
    digitalWrite(dataline, LOW);
    next();
  }
  if (number == 13) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    digitalWrite(dataline, HIGH);
    next();
    next();
    next();
    digitalWrite(dataline, LOW);
    next();
  }
  if (number == 14) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, HIGH);
    next();
    next();
    next();
    next();
    digitalWrite(dataline, LOW);
    next();
  }
  if (number == 15) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    next();
    next();
    next();
    digitalWrite(dataline, HIGH);
    next();
  }
  if (number == 16) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    next();
    next();
    digitalWrite(dataline, HIGH);
    next();
    next();
  }
  if (number == 17) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    next();
    digitalWrite(dataline, HIGH);
    next();
    next();
    next();
  }
  if (number == 18) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    digitalWrite(dataline, HIGH);
    next();
    next();
    next();
    next();
  }
  if (number == 19) {
    digitalWrite(dataline, HIGH);
    next();
    next();
    next();
    next();
    digitalWrite(dataline, HIGH);
    next();
    next();
  }
  if (number == 20) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    next();
    next();
    next();
    next();
    next();
  }
  if (number == 21) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    next();
    next();
    next();
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
  }
  if (number == 22) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    next();
    next();
    digitalWrite(dataline, HIGH);
    next();
    next();
    digitalWrite(dataline, LOW);
    next();
  }
  if (number == 23) {
    digitalWrite(dataline, HIGH);
    next();
    digitalWrite(dataline, LOW);
    next();
    next();
    digitalWrite(dataline, HIGH);
    next();
    next();
    next();
    digitalWrite(dataline, LOW);
    next();
  }
  digitalWrite(output, HIGH);
  delay(5);
  digitalWrite(output, LOW);
}

void next() {
  digitalWrite(input, HIGH);
  delay(5);
  digitalWrite(input, LOW);
}
