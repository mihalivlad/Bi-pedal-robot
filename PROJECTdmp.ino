#include <Servo.h>
#include <LiquidCrystal.h>
#include <pt.h>
Servo rightfoot;
Servo rightthigh;
Servo leftfoot;
Servo leftthigh;
int speakerPin = 14;
int interruptPin = 2;
int interruptPin2 = 3;
volatile int nr = 5;

//LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
int pos = 0;
int pos1 = 0;

#include "pitches.h"

#define melodyPin 14

// Jingle Bells

int melody[] = {
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
    NOTE_E5,
    NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
    NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
    NOTE_D5, NOTE_G5,
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
    NOTE_E5,
    NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
    NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
    NOTE_D5, NOTE_G5};

int tempo[] = {
    8, 8, 4,
    8, 8, 4,
    8, 8, 8, 8,
    2,
    8, 8, 8, 8,
    8, 8, 8, 16, 16,
    8, 8, 8, 8,
    4, 4,
    8, 8, 4,
    8, 8, 4,
    8, 8, 8, 8,
    2,
    8, 8, 8, 8,
    8, 8, 8, 16, 16,
    8, 8, 8, 8,
    4, 4};

// We wish you a merry Christmas

int wish_melody[] = {
    NOTE_B3,
    NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
    NOTE_D4, NOTE_D4, NOTE_D4,
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_E4, NOTE_E4, NOTE_E4,
    NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
    NOTE_D4, NOTE_G4, NOTE_E4,
    NOTE_F4,
    NOTE_B3,
    NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
    NOTE_D4, NOTE_D4, NOTE_D4,
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_E4, NOTE_E4, NOTE_E4,
    NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
    NOTE_D4, NOTE_G4, NOTE_E4,
    NOTE_F4};

int wish_tempo[] = {
    4,
    4, 8, 8, 8, 8,
    4, 4, 4,
    4, 8, 8, 8, 8,
    4, 4, 4,
    4, 8, 8, 8, 8,
    4, 4, 8, 8,
    4, 4, 4,
    2,
    4,
    4, 8, 8, 8, 8,
    4, 4, 4,
    4, 8, 8, 8, 8,
    4, 4, 4,
    4, 8, 8, 8, 8,
    4, 4, 8, 8,
    4, 4, 4,
    2};

// Santa Claus is coming to town

int santa_melody[] = {
    NOTE_G4,
    NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
    NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
    NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
    NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
    NOTE_D4, NOTE_F4, NOTE_B3,
    NOTE_C4,
    NOTE_G4,
    NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
    NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
    NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
    NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
    NOTE_D4, NOTE_F4, NOTE_B3,
    NOTE_C4};

int santa_tempo[] = {
    8,
    8, 8, 4, 4, 4,
    8, 8, 4, 4, 4,
    8, 8, 4, 4, 4,
    8, 8, 4, 2,
    4, 4, 4, 4,
    4, 2, 4,
    1,
    8,
    8, 8, 4, 4, 4,
    8, 8, 4, 4, 4,
    8, 8, 4, 4, 4,
    8, 8, 4, 2,
    4, 4, 4, 4,
    4, 2, 4,
    1};

void setup()
{
    rightfoot.attach(12);
    rightthigh.attach(13);
    leftfoot.attach(10);
    leftthigh.attach(11);
    leftfoot.write(10);
    leftthigh.write(90);
    rightthigh.write(105);
    rightfoot.write(180);
    pinMode(14, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    pinMode(interruptPin2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), inter1, RISING);
    attachInterrupt(digitalPinToInterrupt(interruptPin2), inter2, RISING);
}
void loop()
{
startloop:
    switch (nr)
    {
    case 0:
        robotStop();
        break;
    case 1:
        robot();
        break;
    case 2:
        robot1();
        break;
    case 3:
        robot2();
        break;
    case 4:
        robot3();
        break;
    case 5:
        robot4();
        break;
    }
}

void robot()
{
    int i = 0;
    if (nr == 1)
    {
        rightfoot.write(172);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        rightfoot.write(164);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        rightfoot.write(156);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        rightfoot.write(148);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        rightfoot.write(140);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        rightfoot.write(132);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(16);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(22);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(28);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(34);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(40);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(46);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        rightfoot.write(172);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        rightfoot.write(164);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        rightfoot.write(156);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        rightfoot.write(148);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        rightfoot.write(140);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        rightfoot.write(132);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(16);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(22);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(28);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(34);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(40);
        music2(i);
        i++;
    }
    if (nr == 1)
    {
        leftfoot.write(46);
        music2(i);
        i++;
    }
}

void robot1()
{
    for (pos = 85; pos < 130; pos += 1)
    {
        if (nr == 2)
        {
            rightthigh.write(pos);

            delay(15);
        }
    }
    for (pos = 130; pos >= 85; pos -= 1)
    {
        if (nr == 2)
        {
            rightthigh.write(pos);

            delay(15);
        }
    }

    for (pos1 = 50; pos1 < 95; pos1 += 1)
    {
        if (nr == 2)
        {
            leftthigh.write(pos1);

            delay(15);
        }
    }
    for (pos1 = 95; pos1 >= 50; pos1 -= 1)
    {
        if (nr == 2)
        {
            leftthigh.write(pos1);

            delay(15);
        }
    }
}

void robot2()
{
    leftfoot.write(10);
    leftthigh.write(90);
    rightthigh.write(105);
    rightfoot.write(180);
    //delay(1000);
    int i = 0;
    leftfoot.write(17);
    if (nr == 3)
    {
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftthigh.write(95);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        rightthigh.write(107.5);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftfoot.write(24);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftthigh.write(100);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        rightthigh.write(110);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftfoot.write(31);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftthigh.write(105);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        rightthigh.write(112.5);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftfoot.write(38);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftthigh.write(110);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        rightthigh.write(115);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftfoot.write(45);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftthigh.write(115);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        rightthigh.write(117.5);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftfoot.write(52);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftthigh.write(120);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        rightthigh.write(120);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftfoot.write(59);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftthigh.write(125);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        rightthigh.write(122.5);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftfoot.write(66);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftthigh.write(130);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        rightthigh.write(125);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftfoot.write(73);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftthigh.write(135);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        rightthigh.write(127.5);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftfoot.write(80);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        leftthigh.write(140);
        music3(i);
        i++;
    }
    if (nr == 3)
    {
        rightthigh.write(130);
        delay(100);
    }
}

void robot3()
{
    int i = 0;
    if (nr == 4)
    {
        rightthigh.write(98);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(78);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(96);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(76);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(94);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(74);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(92);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(72);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(90);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(70);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(88);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(68);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(86);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(66);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(84);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(64);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(82);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(62);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(80);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(60);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(103);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(92);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(106);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(94);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(109);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(96);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(112);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(98);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(115);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(100);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(118);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(102);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(121);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(104);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(124);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(106);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(127);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(108);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        rightthigh.write(130);
        music4(i);
        i++;
    }
    if (nr == 4)
    {
        leftthigh.write(110);
        music4(i);
        i++;
    }
}

void robot4()
{
    if (nr == 5)
    {
        delay(700);
        leftfoot.write(20);
    }
    if (nr == 5)
    {
        delay(300);
        leftfoot.write(30);
    }
    if (nr == 5)
    {
        delay(300);
        leftfoot.write(40);
    }
    if (nr == 5)
    {
        delay(300);
        leftfoot.write(50);
    }
    if (nr == 5)
    {
        delay(300);
        leftfoot.write(60);
    }
    if (nr == 5)
    {
        delay(700);
        rightfoot.write(160);
    }
    if (nr == 5)
    {
        delay(700);
        rightfoot.write(150);
    }
    if (nr == 5)
    {
        delay(700);
        rightfoot.write(140);
    }
    if (nr == 5)
    {
        delay(700);
        rightfoot.write(130);
    }
    if (nr == 5)
    {
        delay(1000);
        leftfoot.write(35);
    }
    if (nr == 5)
    {
        delay(500);
        leftfoot.write(10);
    }
    if (nr == 5)
    {
        delay(700);
        rightthigh.write(90);
    }
    if (nr == 5)
    {
        delay(700);
        rightthigh.write(80);
    }
    if (nr == 5)
    {
        delay(700);
        leftthigh.write(65);
    }
    if (nr == 5)
    {
        delay(700);
        rightthigh.write(70);
    }
    if (nr == 5)
    {
        delay(700);
        rightfoot.write(140);
    }
    if (nr == 5)
    {
        delay(500);
        rightfoot.write(150);
    }
    if (nr == 5)
    {
        delay(500);
        rightfoot.write(160);
    }
    if (nr == 5)
    {
        delay(500);
        rightfoot.write(170);
    }
    if (nr == 5)
    {
        delay(500);
        rightfoot.write(180);
    }
    if (nr == 5)
    {
        delay(700);
        rightthigh.write(100);
    }
    if (nr == 5)
    {
        delay(700);
        rightfoot.write(150);
    }
    if (nr == 5)
    {
        delay(300);
        rightfoot.write(140);
    }
    if (nr == 5)
    {
        delay(300);
        rightfoot.write(130);
    }
    if (nr == 5)
    {
        delay(300);
        rightfoot.write(120);
    }
    if (nr == 5)
    {
        delay(700);
        leftfoot.write(20);
    }
    if (nr == 5)
    {
        delay(300);
        leftfoot.write(30);
    }
    if (nr == 5)
    {
        delay(300);
        leftfoot.write(40);
    }
    if (nr == 5)
    {
        delay(300);
        leftfoot.write(50);
    }
    if (nr == 5)
    {
        delay(1200);
        leftthigh.write(80);
    }
    if (nr == 5)
    {
        delay(700);
        leftthigh.write(90);
    }
    if (nr == 5)
    {
        delay(700);
        leftthigh.write(100);
    }
    if (nr == 5)
    {
        delay(700);
        rightfoot.write(150);
    }
    if (nr == 5)
    {
        delay(700);
        rightfoot.write(180);
    }
    if (nr == 5)
    {
        delay(700);
        leftfoot.write(40);
    }
    if (nr == 5)
    {
        delay(300);
        leftfoot.write(30);
    }
    if (nr == 5)
    {
        delay(300);
        leftfoot.write(20);
    }
    if (nr == 5)
    {
        delay(300);
        leftfoot.write(10);
    }
    if (nr == 5)
    {
        delay(300);
        leftfoot.write(10);
    }
    if (nr == 5)
    {
        delay(300);
        leftthigh.write(90);
    }
    if (nr == 5)
    {
        delay(300);
        rightthigh.write(100);
    }
    if (nr == 5)
    {
        delay(300);
        rightfoot.write(180);
    }
}

void robotStop()
{
    leftfoot.write(10);
    leftthigh.write(90);
    rightthigh.write(105);
    rightfoot.write(180);
}

void inter1()
{
    nr = nr + 1;
    if(nr == 6){
      nr = 0;
    }
    delayMicroseconds(1000);
    robotStop();
}

void inter2()
{
    nr = 0;
    robotStop();
}

void music2(int i)
{
    int noteDuration = 1000 / tempo[i];

    buzz(melodyPin, melody[i], noteDuration);
    delay(20);
}

void music3(int i)
{
    int noteDuration = 1000 / wish_tempo[i];

    buzz(melodyPin, wish_melody[i], noteDuration);
    delay(20);
}

void music4(int i)
{
    int noteDuration = 900 / santa_tempo[i];

    buzz(melodyPin, santa_melody[i], noteDuration);
    delay(20);
}

void buzz(int targetPin, long frequency, long length)
{
    long delayValue = 1000000 / frequency / 2; 
    long numCycles = frequency * length / 1000;
    for (long i = 0; i < numCycles; i++)
    {                                 
        digitalWrite(targetPin, HIGH);
        delayMicroseconds(delayValue); 
        digitalWrite(targetPin, LOW); 
        delayMicroseconds(delayValue); 
    }
}
