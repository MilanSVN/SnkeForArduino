#ifndef _GAME_H
#define _GAME_H
#include <stdint.h>
#include "config.h"

extern uint8_t matrix[PLAYGROUND_Y][PLAYGROUND_X];

uint8_t initGame(uint8_t *dire, uint8_t *gO);
void runGame(void);

void setGameOver(void);
void setDirection(uint8_t pomDir);//for SDL


#endif

