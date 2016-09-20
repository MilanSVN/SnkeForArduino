#ifndef _GAME_H
#define _GAME_H






uint8_t initGame(arg[PLAYGROUND_Y / SNAKE_Y][PLAYGROUND_X / SNAKE_X]);
void runGame(void);

void setGameOver(void);
void setDirection(uint8_t pomDir);


#endif

