/**
   @file Game.c
   @brief Document contains short description of used structures and functions
   @author RT-RK Snake
   @date Oktober, 2015
*/

#include "game.h"
#include "config.h"
#include "score.h"

static void moveHead();
static void moveTail();
static uint8_t sRandom();
static void putFood();
void drawScore();

static POSITION rect;//pozicija od koje pocinje crtanje

uint8_t score;
uint8_t matrix[PLAYGROUND_Y][PLAYGROUND_X];
uint8_t height;
uint8_t width;
uint8_t globalna;
static uint8_t direction;
uint8_t gameOver;
//uint8_t pomDirection;

POSITION head;
POSITION tail;

static void putFood()
{
  uint8_t fX = sRandom() % width;
  uint8_t fY = sRandom() % height;
  while (matrix[fY][fX] != 0)
  {
    fX = sRandom() % width;
    fY = sRandom() % height;
  }
  matrix[fY][fX] = FOOD; //u arduiono verziji se matrica direktno iscrtava
}

static void incrementScore() {
  score++;
}

static uint8_t sRandom() //TODO make beter radom
{
  static uint8_t z = 1;
  z = (9 * z + 3) % 127;
  return z;
}

//for SDL - in arduino directin is set externaly
uint8_t getDirection()
{
	return direction;
}
void setDirection(uint8_t pomDir)
{
  if (direction == UP && pomDir == DOWN)
  {
    return;
  }
  if (direction == DOWN && pomDir == UP)
  {
    return;
  }
  if (direction == LEFT && pomDir == RIGHT)
  {
    return;
  }
  if (direction == RIGHT && pomDir == LEFT)
  {
    return;
  }
  direction = pomDir;
}

void setGameOver(void)
{
  gameOver = 1;
  //TODO add showScore()
}

static void moveHead()
{
  uint8_t newPos = matrix[head.y][head.x];
  if (newPos == FOOD)
  {
    incrementScore();
    //matrix[head.y][head.x] = direction;
    putFood();
  }
  else {
    moveTail();
  if (newPos == 0) {
    //matrix[head.y][head.x] = direction;
  }
  else if (newPos > 1 && newPos < 5)
  {
    setGameOver();
  }
  }
}

static void moveTail()
{
  uint8_t tailDirection = matrix[tail.y][tail.x];
  matrix[tail.y][tail.x] = 0;
  if(tailDirection == DOWN)
  {
    tail.y = (tail.y + 1) % (height);
  }
  else if(tailDirection == UP)
  { 
    tail.y--;
    if(tail.y <= 0)
    {
      tail.y = height - 1;
    }
  }
  else if(tailDirection == LEFT)
  {
    tail.x--;
    if(tail.x <= 0)
    {
      tail.x = width - 1;
    }
  }
  else if(tailDirection == RIGHT)
  {
    tail.x = (tail.x + 1) % (width);
  }
  
}

uint8_t initGame(void)
{
  height = PLAYGROUND_Y / SNAKE_Y;
  width = PLAYGROUND_X / SNAKE_X;
  score = 1;

  direction = RIGHT;
  gameOver = 0;

  uint8_t i;
  uint8_t j;
  for (i = 0; i < height; i++)
  {
    for (j = 0; j < width; j++)
    {
      matrix[i][j] = 0;
    }
  }

  tail.y = height / 2;
  tail.x = (width / 2);
  head.y = height / 2;
  head.x = (width / 2) + 1;
  matrix[tail.y][tail.x] = RIGHT;

  putFood();

  return 0;

}

void runGame(void)
{
	globalna = direction;

    if(direction == DOWN)
    {
      matrix[head.y][head.x] = DOWN;
      head.y = (head.y + 1) % (height);
      moveHead();
    }
    else if (direction == UP)
    {
      matrix[head.y][head.x] = UP;
      head.y--;
      if(head.y <= 0) 
      {
		head.y = height - 1;
      }
      moveHead();      
    }
    else if (direction == LEFT)
    {
      matrix[head.y][head.x] = LEFT;
      head.x--;
      if(head.x <= 0) 
      {
		head.x = width - 1;
      }
      moveHead(); 
    }
    else if (direction == RIGHT)
    {
      matrix[head.y][head.x] = RIGHT;
      head.x = (head.x + 1) % (width);
      moveHead();      
    }

    
    
  
}

void drawScore()
{
  uint8_t s1;
  uint8_t s2;
  uint8_t i;
  uint8_t j;
  s1 = score / 10;
  s2 = score % 10;

  switch (s1) {
    case 0:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j] = nula[i][j];
        }
      }
      break;
    case 1:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j] = jedan[i][j];
        }
      }
      break;
    case 2:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j] = dva[i][j];
        }
      }
      break;
    case 3:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j] = tri[i][j];
        }
      }
      break;
    case 4:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j] = cetiri[i][j];
        }
      }
      break;
    case 5:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j] = pet[i][j];
        }
      }
      break;
    case 6:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j] = sest[i][j];
        }
      }
      break;
    case 7:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j] = sedam[i][j];
        }
      }
      break;
    case 8:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j] = osam[i][j];
        }
      }
      break;
    case 9:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j] = devet[i][j];
        }
      }
      break;
    default:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 8; j++)
        {
          matrix[i][j] = 0;
        }
      }
  }

  for (i = 0; i < 8; i++)
  {
    for (j = 3; j < 5; j++)
    {
      matrix[i][j] = 0;
    }
  }


  switch (s2) {
    case 0:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j + 5] = nula[i][j];
        }
      }
      break;
    case 1:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j + 5] = jedan[i][j];
        }
      }
      break;
    case 2:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j + 5] = dva[i][j];
        }
      }
      break;
    case 3:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j + 5] = tri[i][j];
        }
      }
      break;
    case 4:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j + 5] = cetiri[i][j];
        }
      }
      break;
    case 5:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j + 5] = pet[i][j];
        }
      }
      break;
    case 6:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j + 5] = sest[i][j];
        }
      }
      break;
    case 7:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j + 5] = sedam[i][j];
        }
      }
      break;
    case 8:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j + 5] = osam[i][j];
        }
      }
      break;
    case 9:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 3; j++)
        {
          matrix[i][j + 5] = devet[i][j];
        }
      }
      break;
    default:
      for (i = 0; i < 8; i++)
      {
        for (j = 0; j < 8; j++)
        {
          matrix[i][j] = 0;
        }
      }
  }


}


