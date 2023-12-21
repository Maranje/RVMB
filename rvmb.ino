#include <ssd1306xled.h>
#include "bitmaps.h"

#define INTERRUPT_PIN PCINT4
#define INT_PIN PB4

int shaken = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  delay(40);
  SSD1306.ssd1306_init();

  cli();
  PCMSK |= (1 << INTERRUPT_PIN);
  GIMSK |= (1 << PCIE);
  pinMode(INT_PIN, INPUT_PULLUP);
  sei();

  SSD1306.ssd1306_fillscreen(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  defaultFace();
  shaken = 0;
  blink();
  int randomFace = random(14);

 switch(randomFace){
    case 0:
      peaceSmile();
      break;
    case 1:
      derpyFace();
      break;
    case 2:
      lennyFace();
      break;
    case 3:
      robotFace();
      break;
    case 4:
      blankStare();
      break;
    case 5:
      grouchoFace();
      break;
    case 6:
      kittyFace();
      break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    default:
      defaultFace();
      break;
  }


  blink();
  shaken = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void blink(){
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 3, eyesBlink);
  SSD1306.ssd1306_draw_bmp(48, 3, 80, 4, smileDefault);
  delay(10);
}

void defaultFace(){
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 3, eyesDefault);
  SSD1306.ssd1306_draw_bmp(48, 3, 80, 4, smileDefault);
  delay(random(500, 5000));
}

void derpyFace(){
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 3, eyesDefault);
  SSD1306.ssd1306_draw_bmp(48, 3, 80, 4, mouthRaspberry);
  delay(random(1000, 3000));
}

void wutFace(){
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 3, eyesSurprised);
  SSD1306.ssd1306_draw_bmp(48, 3, 80, 4, flatMouth);
  delay(random(1000, 3000));
}

void peaceSmile(){
  int randomDelayTime = random(250, 500);
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 3, eyesDefault);
  SSD1306.ssd1306_draw_bmp(48, 3, 80, 5, smileTeeth);
  SSD1306.ssd1306_draw_bmp(100, 4, 115, 7, peaceSign);
  delay(randomDelayTime);
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 3, eyesWink);
  SSD1306.ssd1306_draw_bmp(48, 3, 80, 5, smileTeeth);
  SSD1306.ssd1306_draw_bmp(105, 3, 120, 6, peaceSign);
  delay(randomDelayTime);
}

void lennyFace(){
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 4, faceLenny);
  delay(random(1000, 3000));
}

void blankStare(){
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 4, stareBlank);
  delay(random(1000, 2000));
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 4, stareBlink);
  delay(100);
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 4, stareBlank);
  delay(random(1000, 2000));
}

void grouchoFace(){
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(29, 1, 99, 3, grouchoMaskTop);
  SSD1306.ssd1306_draw_bmp(29, 3, 99, 5, grouchoMaskBottom);
  delay(random(1000, 2000));
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(29, 1, 99, 3, grouchoMaskTopBlink);
  SSD1306.ssd1306_draw_bmp(29, 3, 99, 5, grouchoMaskBottom);
  delay(50);
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(29, 1, 99, 3, grouchoMaskTop);
  SSD1306.ssd1306_draw_bmp(29, 3, 99, 5, grouchoMaskBottom);
  delay(200);
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(29, 1, 99, 3, grouchoMaskTopBlink);
  SSD1306.ssd1306_draw_bmp(29, 3, 99, 5, grouchoMaskBottom);
  delay(50);
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(29, 1, 99, 3, grouchoMaskTop);
  SSD1306.ssd1306_draw_bmp(29, 3, 99, 5, grouchoMaskBottom);
  delay(random(1000, 2000));
}

void robotFace(){
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 4, robot);
  delay(random(1000, 2000));
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 4, robot);
  SSD1306.ssd1306_draw_bmp(32, 5, 64, 6, beepText);
  delay(500);
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 4, robot);
  SSD1306.ssd1306_draw_bmp(64, 5, 96, 6, boopText);
  delay(500);
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 4, robot);
  delay(random(1000, 2000));
}

void kittyFace(){
  SSD1306.ssd1306_fillscreen(0);
  SSD1306.ssd1306_draw_bmp(32, 2, 96, 4, kitty);
  delay(random(1000, 3000));
}

//interrupt service routine
ISR(PCINT0_vect) {
  shaken++;
  if(shaken > 500){
    cli();
    shaken = 0;
    wutFace();
    sei();
  }
}

