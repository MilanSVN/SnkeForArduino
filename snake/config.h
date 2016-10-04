#ifndef _CONFIG_H
#define _CONFIG_H

#define FOOD  1

#define INIT_OFFSET_X 0
#define INIT_OFFSET_PLAYGROUND_X 0
#define INIT_OFFSET_PLAYGROUND_Y 0
#define PLAYGROUND_X 8
#define PLAYGROUND_Y 8
#define SNAKE_X 1
#define SNAKE_Y 1

//#define NULL 0
//Ovi pinovi su za tastere
/*
#define A0 23
#define A1 24
#define A2 25
#define A3 26
*/

#define D0 13
#define D1 12
#define D2 11
#define D3 10
#define D4 9
#define D5 8
#define D6 7
#define D7 6
#define D 5
#define CLK 4
#define GIN 3 //Za ulay drugog shift registra

/*
#define UP 2
#define DOWN 3
#define LEFT 4
#define RIGHT 5 
Ovo ide u setup()
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
*/
typedef enum
{
  
  UP = 2,
  DOWN = 3,
  LEFT = 4,
  RIGHT = 5  
} DIRECTION;

typedef struct position
{
  uint8_t x;
  uint8_t y;
}POSITION;


#endif
