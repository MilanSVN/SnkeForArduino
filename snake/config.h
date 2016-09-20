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
