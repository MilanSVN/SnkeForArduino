#include <Arduino_FreeRTOS.h>

void TaskGame( void *pvParameters );
void TaskDisplay( void *pvParameters );
void TaskButton( void *pvParameters );

uint8_t matrix[8][8];
uint8_t direction;
uint8_t gameOver; 


void setup() {
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

  }
}

void TaskDisplay(void *pvParameters)  // This is a task.
{
  Serial.println("TaskGame started");
 

  for (;;) // A Task shall never return or exit.
  {

  }
}

void TaskButton(void *pvParameters)  // This is a task.
{
  Serial.println("TaskGame started");
 

  for (;;) // A Task shall never return or exit.
  {

  }
}

