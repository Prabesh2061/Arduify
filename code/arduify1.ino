#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define BUZZER_PIN 10
#define REST     0

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32, 16, 2);
int changeButton = 2;
int pauseButton = 3;
int song = 1;
bool pause = false;
int red = 10;
int yellow = 7;
int blue = 5;
int white = 4;
int green = 6;
int orange = 8;
int lighting, size;

int mario[] = {
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5, NOTE_G5, REST,
  NOTE_G4, REST, NOTE_C5, NOTE_G4, REST, NOTE_E4, NOTE_A4, NOTE_B4, NOTE_AS4,
  NOTE_A4, NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5, REST, NOTE_E5,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_G4, REST, NOTE_E4, NOTE_A4, NOTE_B4,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5, REST,
  NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4, REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5,
  NOTE_E5, REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  REST, NOTE_DS5, REST, NOTE_D5, NOTE_C5, REST, REST, NOTE_G5, NOTE_FS5, NOTE_F5,
  NOTE_DS5, NOTE_E5, REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5,
  NOTE_D5, REST, NOTE_DS5, REST, NOTE_D5, NOTE_C5, REST, NOTE_C5, NOTE_C5,
  NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_C5,
  NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5, REST, NOTE_C5, NOTE_C5,
  NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_E5,
  NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5, NOTE_G5, REST, NOTE_G4, REST,
  NOTE_C5, NOTE_G4, REST, NOTE_E4
};

int mariodurations[] = {
  8, 8, 8, 8, 8, 8, 8, 4, 4, 8, 4, 4, 8, 4, 4, 4, 4, 8, 4, 8, 8, 8, 4, 8, 8, 8,
  4,8, 8, 4, 4, 8, 4, 4, 4, 4, 8, 4, 8, 8, 8, 4, 8, 8, 8, 4,8, 8, 4, 4, 8, 8, 8,
  4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 8, 4, 2, 2, 4, 8, 8, 8, 4, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 4, 4, 8, 4, 2, 2, 8, 4, 8, 8, 8, 4, 8, 4, 8, 2,8, 4, 8, 8, 8, 8, 8,
  1, 8, 4, 8, 8, 8, 4, 8, 4, 8, 2
};


int starwars[] = {
  
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_F5, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_F6, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_F5, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_F6, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_G5,
  NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_D5,
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_C6, NOTE_G5, NOTE_G5, REST, NOTE_C5,
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_G5,
  NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_C6, NOTE_C6, NOTE_F6, NOTE_DS6,
  NOTE_CS6, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5, NOTE_C6
};

int swdurations[] = {
  7, 6, 6, 2, 2, 7, 7, 7, 2, 2, 7, 7, 7, 2, 2, 7, 7, 7, 1, 7, 7, 7, 2, 2,7, 7,
  7, 2, 2, 7, 7, 7, 2, 2, 7, 7, 7, 1, 7, 8, 4, 7, 7, 7, 7, 7, 7, 7, 7, 3, 7,
  4, 6, 16,4, 7, 7, 7, 7, 7, 7, 16, 2, 8, 8, 4, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7,
  4, 7, 16, 4, 7, 4, 7, 4, 7, 4, 7, 1
};


int gameofthrones[] = {
  NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_D4, NOTE_F4, NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_AS3, NOTE_DS4,
  NOTE_D4, NOTE_C4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4,
  NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_F4,
  NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_C4
};

int gotdurations[] = {
  4, 3, 8, 8, 3, 7, 7, 8, 3, 8, 8, 7, 3, 8, 8, 7, 3, 8, 8, 7, 3, 8, 8, 7,
  3, 8, 8, 7, 3, 8, 8, 7, 1, 3, 4, 4, 3, 2, 4, 4, 1, 1, 3, 4, 4, 3, 4, 8,
  8, 1, 1, 3, 4, 4, 3, 2, 4, 4, 1, 1, 3, 4, 4, 3, 4,8, 8, 1
};

// code for dancing music note
byte note[8] = {
  0b00100,
  0b00110,
  0b00101,
  0b00100,
  0b01100,
  0b11110,
  0b11110,
  0b01100};
byte note2[8] = {
  0b00100,
  0b01100,
  0b10100,
  0b00100,
  0b01100,
  0b11110,
  0b11110,
  0b01100};
byte note3[8] = {
  0b00100,
  0b01100,
  0b10100,
  0b00100,
  0b00110,
  0b01111,
  0b01111,
  0b00110};
byte note4[8] = {
  0b00100,
  0b00110,
  0b00101,
  0b00100,
  0b00110,
  0b01111,
  0b01111,
  0b00110};


void setup(){
  
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);
  
  for(int i=4;i<11;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(changeButton, INPUT);
  pinMode(pauseButton, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(changeButton), changeSong, RISING);
  attachInterrupt(digitalPinToInterrupt(pauseButton), pauseSong, RISING);
  
  lcd.createChar(0, note);
  lcd.createChar(1, note2);
  lcd.createChar(2, note3);
  lcd.createChar(3, note4);
}

void loop(){
  
  // change songs
  switch(song){
    case 1:
      lcd.setCursor(0,0);
      lcd.print("Mario          ");
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.print("Star Wars      ");
      break;
    case 3:
      lcd.setCursor(0,0);
      lcd.print("Game of thrones");
      break;
  }
  
  while(pause){
    lcd.setCursor(0,1);
    lcd.print("Now Playing");
    switch(song){
      case 1:  // mario
        size = sizeof(mariodurations) / sizeof(int);
        for (int note = 0; note < size; note++) {

          // dancing notes
          char num = note % 4;
          lcd.setCursor(12,1);
          lcd.write(byte(num));

          // music
          int duration = 1000 / mariodurations[note];
          light();
          tone(BUZZER_PIN, mario[note], duration);
          delay(duration * 1.30);
          
          if(!pause){
            lcd.clear();
            digitalWrite(lighting, LOW);
            break;
          }
        }
        break;
      case 2: // star wars
        size = sizeof(swdurations) / sizeof(int);
        for (int note = 0; note < size; note++) {

          // dancing notes
          char num = note % 4;
          lcd.setCursor(12,1);
          lcd.write(byte(num));

          // music
          int duration = 1000 / swdurations[note];
          tone(BUZZER_PIN, starwars[note], duration);
          light();
          delay(duration * 1.30);
          
          if(!pause){
            lcd.clear();
            digitalWrite(lighting, LOW);
            break;
          }
        }
        break;
      case 3: // game of thrones
        size = sizeof(gotdurations) / sizeof(int);
        for (int note = 0; note < size; note++) {

          // dancing notes
          char num = note % 4;
          lcd.setCursor(12,1);
          lcd.write(byte(num));

          //music
          int duration = 1000 / gotdurations[note];
          tone(BUZZER_PIN, gameofthrones[note], duration);
          light();
          delay(duration * 1.30);
          
          if(!pause){
            lcd.clear();
            digitalWrite(lighting, LOW);
            break;
          }
        }
        break;
    }
  }
}

void instructions(){
  lcd.setCursor(0, 0);
  lcd.print("Hi Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("our Arduify");
  lcd.setCursor(12,1);
  lcd.write(byte(0));
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("We have 3 songs");
  lcd.setCursor(0, 1);
  lcd.print("Enjoy the music");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Use Left Button");
  lcd.setCursor(0, 1);
  lcd.print("To Change songs");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Right Button to");
  lcd.setCursor(0, 1);
  lcd.print("Stop/Play songs");
  delay(2000);
  lcd.clear();
}

void changeSong(){
  song++;
  if(song > 3){
    song = 1;
  }
}

void pauseSong(){
  if(pause){
    pause = false;
  }else{
    pause = true;
  }
}


void light(){
  digitalWrite(lighting, LOW);
  lighting = random(4,10);
  digitalWrite(lighting, HIGH);
}
