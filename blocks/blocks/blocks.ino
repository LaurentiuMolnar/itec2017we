#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#include "colors.h"
#include "shapes.h"
#include "board.h"

// TEXT DEFINITIONS
#define CHAR_WIDTH 5
#define CHAR_HEIGHT 8
#define SCALE 3

// For the breakout, you can use any 2 or 3 pins
// These pins will also work for the 1.8" TFT shield
#define TFT_CS     10
#define TFT_RST    9  // you can also connect this to the Arduino reset
                      // in which case, set this #define pin to 0!
#define TFT_DC     8

// Option 1 (recommended): must use the hardware SPI pins
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be
// an output. This is much faster - also requiRED if you want
// to use the microSD card (see the image drawing example)
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

// Option 2: use any pins but a little slower!
#define TFT_SCLK 13   // set these to be whatever pins you like!
#define TFT_MOSI 11   // set these to be whatever pins you like!
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

int score = 0;

void setup(void) {
  Serial.begin(9600);
  Serial.print("Hello! TETRIS loading...");

  // Use this initializer (uncomment) if you're using a 1.44" TFT
  tft.initR(INITR_144GREENTAB);   // initialize a ST7735S chip, black tab
  score = 0;
  
  Serial.println("Initialized");
  tft.fillScreen(BLACK);
  drawWelcomeScreen();
  drawBoard();
  delay(1000);
  randomSeed(analogRead(3));
  drawShapeOnGrid(random(0, 7), 0);
  byte x = nextShape();
  delay(1000);

  while(true){

    drawShapeOnGrid(x, 0);
    x = nextShape();
    delay(1000);
    
  }
  
  
//  int i, j, s;
//
//  for (s=0; s<SHAPE_COUNT; s++){
//    Serial.print("Piece ");
//      Serial.print(s);
//      Serial.print(", color ");
//      Serial.println(colors[s], HEX);
//    for(i=0;i<4;i++){
//      for(j=0;j<4;j++){
//        Serial.print(shapes[s].rotations[i][j], BIN);
//        Serial.print("  ");
//      }
//      Serial.println();
//    }
//  }
  
  delay(1000);
}
void loop(){

//  randomSeed(analogRead(3));
//  drawShape(random(0,7), random(0,4));
//  delay(500);
}

void drawGrid(short color)
{
  for (int16_t y=8; y < 128; y+=CELL_SIZE) {
    tft.drawFastHLine(GRID_X, y, HL_LEN, color); 
  }
  for (int16_t x=0; x < 61; x+=CELL_SIZE) {
    tft.drawFastVLine(GRID_X+x, GRID_Y, VL_LEN, color);
  }
}

void drawBoard(){

  const int X = HL_LEN+GRID_X*3;
  const int Y = GRID_Y;

  tft.fillScreen(WHITE);
  drawGrid(BLACK);
  tft.setCursor(X, Y);
  tft.setTextColor(BLACK);
  tft.setTextSize(1);
  tft.print("SCORE");

  tft.setCursor(X, Y+20);
  tft.print(score, DEC);

  tft.setCursor(X, Y+60);
  tft.print("NEXT");
  
}

void drawShape(byte shapeCode){
  const int OFFSET_X = HL_LEN+GRID_X*3;
  const int OFFSET_Y = GRID_Y+80;

  Shape shape = shapes[shapeCode];

    for(int i = 0; i < 4; i++) {

        // suntem in matrice
        byte x = shape.rotations[0][i];
        for (int b = 3; b>=0; b--){

          if (bitRead(x, b) == 0) {
            tft.fillRect(
              OFFSET_X + (3-b)*CELL_SIZE, /* x */
              OFFSET_Y + i*CELL_SIZE, /* y */
              CELL_SIZE,
              CELL_SIZE,
              WHITE
            );        
          } else {
            tft.fillRect(
              OFFSET_X + (3-b)*CELL_SIZE, /* x */
              OFFSET_Y + i*CELL_SIZE, /* y */
              CELL_SIZE,
              CELL_SIZE,
              colors[shapeCode]
            );
            tft.drawRect(
              OFFSET_X + (3-b)*CELL_SIZE, /* x */
              OFFSET_Y + i*CELL_SIZE, /* y */
              CELL_SIZE,
              CELL_SIZE,
              BLACK
            );
          }
        }   
    }
}

void drawWelcomeScreen(){
  const int t = 1000;
  tft.setCursor(CHAR_WIDTH * SCALE - 1, tft.height()/2 - CHAR_HEIGHT * SCALE/2);
  tft.setTextSize(SCALE);
  tft.setTextColor(RED);
  tft.print("T");
  tft.setTextColor(ORANGE);
  tft.print("E");
  tft.setTextColor(YELLOW);
  tft.print("T");
  tft.setTextColor(GREEN);
  tft.print("R");
  tft.setTextColor(CYAN);
  tft.print("I");
  tft.setTextColor(PURPLE);
  tft.print("S");
  tft.setTextColor(WHITE);
  delay(t);
}

void drawShapeOnGrid(byte shapeCode, unsigned rotationCode){

  const int OFFSET_X = GRID_X + 3*CELL_SIZE;
  const int OFFSET_Y = GRID_Y;

  Shape shape = shapes[shapeCode];

    drawGrid(WHITE);
    
    for(int i = 0; i < 4; i++) {

        // suntem in matrice
        byte x = shape.rotations[rotationCode][i];
        for (int b = 3; b>=0; b--){

          if (bitRead(x, b) == 0) {
            tft.fillRect(
              OFFSET_X + (3-b)*CELL_SIZE, /* x */
              OFFSET_Y + i*CELL_SIZE, /* y */
              CELL_SIZE,
              CELL_SIZE,
              WHITE
            );        
          } else {
            tft.fillRect(
              OFFSET_X + (3-b)*CELL_SIZE, /* x */
              OFFSET_Y + i*CELL_SIZE, /* y */
              CELL_SIZE,
              CELL_SIZE,
              colors[shapeCode]
            );
          }
        }   
    }
    drawGrid(BLACK);
}

byte nextShape() {

  
  byte next = random(0,7);
  
  drawShape(next);

  return next;
}
















