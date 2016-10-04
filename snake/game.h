#ifndef _GAME_H
#define _GAME_H
#include <stdint.h>
#include "config.h"


uint8_t initGame(void);
void runGame(void);
void drawScore();
void setGameOver(void);
void setDirection(uint8_t pomDir);//for SDL


#endif

