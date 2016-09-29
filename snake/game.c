/**
 * @file Game.c
 * @brief Document contains short description of used structures and functions 
 * @author RT-RK Snake
 * @date Oktober, 2015
 */

#include "game.h"
#include "config.h"


static void moveHead();
static void moveTail();
static uint8_t sRandom();
static void putFood();


//static SDL_Rect rect;
static POSITION rect;//pozicija od koje pocinje crtanje

//static SDL_Surface* background = NULL;
//static SDL_Surface* playgound = NULL;
//static SDL_Surface* snake = NULL; 
//static SDL_Surface* delSnake = NULL; 
///////static SDL_Surface* screen = NULL;

uint8_t matrix[PLAYGROUND_Y][PLAYGROUND_X];
uint8_t height;
uint8_t width;
uint8_t direction = RIGHT;
uint8_t* gameOver;
//uint8_t pomDirection;

POSITION head;
POSITION tail;

static void putFood()
{
  uint8_t fX = sRandom() % width;
  uint8_t fY = sRandom() % height;
  while(matrix[fY][fX] != 0)
  {
    fX = sRandom() % width;
    fY = sRandom() % height;
  }
  matrix[fY][fX] = FOOD; //u arduiono verziji se matrica direktno iscrtava
  //rect.x = fX * SNAKE_X + INIT_OFFSET_PLAYGROUND_X; //nije potrebno u verziji za ARDUINO
  //rect.y = fY * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y; //koristi se samo za SDL za proporcije 
  //drawFood(rect);
}

static uint8_t sRandom() //TODO make beter radom
{
  static uint8_t z = 1;
  z = (9 * z + 3) % 127;
  return z;
}

//for SDL - in arduino directin is set externaly

void setDirection(uint8_t pomDir)
{
  if(direction == UP && pomDir == DOWN)
  {
    return;
  }
  if(direction == DOWN && pomDir == UP)
  {
    return;
  }
  if(direction == LEFT && pomDir == RIGHT)
  {
    return;
  }
  if(direction == RIGHT && pomDir == LEFT)
  {
    return;
  }
  direction = pomDir;
}

void setGameOver()
{
  *gameOver = 1;
  //TODO add showScore()
}

static void moveHead()
{
  uint8_t newPos = matrix[head.y][head.x];
  if(newPos == 0)
  {
	matrix[head.y][head.x] = direction;
    //rect.x = head.x * SNAKE_X + INIT_OFFSET_PLAYGROUND_X;
    //rect.y = head.y * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y;
    //drawSnake(rect); //SDL function
    moveTail();
  }
  else if(newPos == FOOD)
  {
    
 matrix[head.y][head.x] = direction;
   //rect.x = head.x * SNAKE_X + INIT_OFFSET_PLAYGROUND_X;
    //rect.y = head.y * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y;
    //drawSnake(rect);
      //  moveTail();
    putFood();
    //scorepp();//TODO set score
  }
  else if(newPos > 1)
  {
    *gameOver = 1;
  }
}

static void moveTail()
{
  //rect.x = tail.x * SNAKE_X + INIT_OFFSET_PLAYGROUND_X;
  //rect.y = tail.y * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y;
  //unDrowSnake(rect);//for SDL
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

uint8_t initGame(uint8_t* dire, uint8_t* gO)
{
//	matrix = arg;
	direction = *dire;
	gameOver = gO;
  height = PLAYGROUND_Y / SNAKE_Y;
  width = PLAYGROUND_X / SNAKE_X;
  
  direction = RIGHT;
  *gameOver = 0;
  
  uint8_t i;
  uint8_t j;
  for (i = 0; i < height; i++)
  {
    for (j = 0; j < width; j++)
    {
      matrix[i][j] = 0;
    }
  }

  // rect.x = INIT_OFFSET_PLAYGROUND_X;//for SDL
  // rect.y = INIT_OFFSET_PLAYGROUND_Y;
  // drawPlayground(rect);

  tail.y = height / 2;
  tail.x = width / 2;
  head.y = height / 2;
  head.x = width / 2;
  matrix[tail.y][tail.x] = RIGHT;
  //rect.x = head.x * SNAKE_X + INIT_OFFSET_PLAYGROUND_X;
  //rect.y = head.y * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y;
  //drawSnake(rect);
  
  putFood();
 
  return 0;
  
}



void runGame(void)
{
  //while(*gameOver == 0)//for SDL
  //{
    //handleUserCommands();for SDL
	//for arduiono directin is set externaly
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
    //gameOver = 1; //< For test 3,4,5,6,7
    
    
  //}
}


