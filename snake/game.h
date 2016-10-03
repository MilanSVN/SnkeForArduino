#ifndef _GAME_H
#define _GAME_H
#include <stdint.h>
#include "config.h"

extern uint8_t score;
extern uint8_t matrix[PLAYGROUND_Y][PLAYGROUND_X];
extern uint8_t direction;
extern uint8_t gameOver;
uint8_t initGame(void);
void runGame(void);
void drawScore();
void setGameOver(void);
void setDirection(uint8_t pomDir);//for SDL


#endif

