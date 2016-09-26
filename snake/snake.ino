#include <Arduino_FreeRTOS.h>
extern "C"{
#include "game.h"
#include "config.h"
}

static void debugShowDisply(uint8_t arg[PLAYGROUND_Y][PLAYGROUND_X]);
void TaskGame( void *pvParameters );
void TaskDisplay( void *pvParameters );
void TaskButton( void *pvParameters );

//uint8_t matrix[PLAYGROUND_Y][PLAYGROUND_X];
uint8_t direction;
uint8_t gameOver; 


void setup() {
  Serial.begin(9600);
  Serial.println("setup begin");
  xTaskCreate(
    TaskGame
    ,  "Game"  // A name just for humans
    ,  1024  // Stack size
    ,  NULL
    ,  1  // priority
    ,  NULL );

   xTaskCreate(
    TaskDisplay
    ,  "Display"  // A name just for humans
    ,  512  // Stack size
    ,  NULL
    ,  1  // priority
    ,  NULL );

   xTaskCreate(
    TaskButton
    ,  "Button"  
    ,  512  // Stack size
    ,  NULL
    ,  1  // priority
    ,  NULL );

}

void loop()
{
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskGame(void *pvParameters)  // This is a task.
{
  Serial.println("TaskGame started");
 

  for (;;) // A Task shall never return or exit.
  {
    /*
    initGame(&direction,&gameOver);
    while(gameOver == 0)
    {
      runGame();
      vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    */
  }
}

void TaskDisplay(void *pvParameters)  // This is a task.
{
  Serial.println("TaskDisplay started");
 

  for (;;) // A Task shall never return or exit.
  {
    /*
    //debugShowDisply(matrix); 
    vTaskDelay(100 / portTICK_PERIOD_MS);
    */
  }
}

void TaskButton(void *pvParameters)  // This is a task.
{
  Serial.println("TaskGame started");
 

  for (;;) // A Task shall never return or exit.
  {
    /*
    vTaskDelay(10000 / portTICK_PERIOD_MS);
    */
  }
}

/*
static void debugShowDisply(uint8_t arg[PLAYGROUND_Y][PLAYGROUND_X])
{
  uint8_t i = 0;
  uint8_t j = 0;
  Serial.write(12);//clearScreen
  for(i = 0; i < PLAYGROUND_Y; i++)
  {
    for(j = 0; j < PLAYGROUND_X; j++)
      {
        switch (arg[i][j]) 
        {
          case 0:
            Serial.print("0");
            break;
          case 1:
            Serial.print("8");
            break;
          default: 
            Serial.print("x");
          break;
        }
      }
      Serial.println();
  }  
}*/
