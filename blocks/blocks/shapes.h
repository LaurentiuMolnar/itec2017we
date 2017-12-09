#ifndef SHAPES_H
#define SHAPES_H

#define SH_I 0
#define SH_J 1
#define SH_L 2
#define SH_O 3
#define SH_S 4
#define SH_T 5
#define SH_Z 6

#define SHAPE_COUNT 7

typedef struct _Shape {

  byte rotations[4][4];
  
} Shape;


Shape shapes[7] = {

  // I shape
  {
      B0000,
      B1111,
      B0000,
      B0000,
      
      B0010,
      B0010,
      B0010,
      B0010,
      
      B0000,
      B0000,
      B1111,
      B0000,
      
      B0100,
      B0100,
      B0100,
      B0100  
  }, 

  // J piece
  {
      B1000,
      B1110,
      B0000,
      B0000,
      
      B0110,
      B0100,
      B0100,
      B0000,
      
      B0000,
      B1110,
      B0010,
      B0000,
      
      B0100,
      B0100,
      B1100,
      B0000  
  },   
  
  // L shape
  {
      B0010,
      B1110,
      B0000,
      B0000,
      
      B0100,
      B0100,
      B0110,
      B0000,
      
      B0000,
      B1110,
      B1000,
      B0000,
      
      B1100,
      B0100,
      B0100,
      B0000
  }, 

  // O shape
  {
      B0110,
      B0110,
      B0000,
      B0000,
      
      B0110,
      B0110,
      B0000,
      B0000,
      
      B0110,
      B0110,
      B0000,
      B0000,
      
      B0110,
      B0110,
      B0000,
      B0000
  },

   // S shape
  {
      B0110,
      B1100,
      B0000,
      B0000,
      
      B0100,
      B0110,
      B0010,
      B0000,
      
      B0000,
      B0110,
      B1100,
      B0000,
      
      B1000,
      B1100,
      B0100,
      B0000
  },

   // T shape
  {
      B0100,
      B1110,
      B0000,
      B0000,
      
      B0100,
      B0110,
      B0100,
      B0000,
      
      B0000,
      B1110,
      B0100,
      B0000,
      
      B0100,
      B1100,
      B0100,
      B0000
  }, 

  // Z shape
  {
      B1100,
      B0110,
      B0000,
      B0000,
      
      B0010,
      B0110,
      B0100,
      B0000,
      
      B0000,
      B1100,
      B0110,
      B0000,
      
      B0100,
      B1100,
      B1000,
      B0000
  }
};

short colors[7] = {CYAN, BLUE, ORANGE, YELLOW, GREEN, PURPLE, RED};

#endif
