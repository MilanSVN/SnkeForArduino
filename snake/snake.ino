#include <Arduino_FreeRTOS.h>
#include <semphr.h>
extern "C" {
#include "game.h"
#include "config.h"
//#include "score.h"
}

static void debugShowDisply(uint8_t arg[PLAYGROUND_Y][PLAYGROUND_X]);
void TaskGame( void *pvParameters );
void TaskDisplay( void *pvParameters );
void TaskButton( void *pvParameters );

SemaphoreHandle_t directionkeeper = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("setup begin");
  directionkeeper = xSemaphoreCreateMutex();

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(13, OUTPUT);

  xTaskCreate(
    TaskGame
    ,  "Game"  // A name just for humans
    ,  256  // Stack size
    ,  NULL
    ,  1  // priority
    ,  NULL );

  xTaskCreate(
    TaskDisplay
    ,  "Display"  // A name just for humans
    ,  256  // Stack size
    ,  NULL
    ,  1  // priority
    ,  NULL );

  xTaskCreate(
    TaskButton
    ,  "Button"
    ,  66  // Stack size
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

    initGame();
    while (gameOver == 0)
    {
      if (xSemaphoreTake(directionkeeper, 500))
      {
        runGame();
        xSemaphoreGive(directionkeeper);
      }
      vTaskDelay(600 / portTICK_PERIOD_MS);
    }
    drawScore();
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    
  }
}

void TaskDisplay(void *pvParameters)  // This is a task.
{
  Serial.println("TaskDisplay started");


  for (;;) // A Task shall never return or exit.
  {

    debugShowDisply(matrix);
    vTaskDelay(300 / portTICK_PERIOD_MS);

  }
}

void TaskButton(void *pvParameters)  // This is a task.
{
  Serial.println("TaskGame started");
  const int buttonRight = A0;
  const int buttonUp = A1;
  const int buttonLeft = A2;
  const int buttonDown = A3;

  const int signalLed = 13;


  setDirection(UP);

  for (;;) // A Task shall never return or exit.
  {
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(signalLed, LOW);
    if (xSemaphoreTake(directionkeeper, 500))
    {
        if (digitalRead(buttonRight) == HIGH)
        {
            setDirection(RIGHT);
            //direction = RIGHT;
            digitalWrite(signalLed, HIGH);
            Serial.println("RIGHT");
            Serial.println(direction);
        }
        
        else if (digitalRead(buttonUp) == HIGH)
        {
              setDirection(UP);
              //direction = UP;
              digitalWrite(signalLed, HIGH);
              Serial.println("UP");
              Serial.println(direction);
        }
        
        else if (digitalRead(buttonLeft) == HIGH)
        {
            setDirection(LEFT);
            digitalWrite(signalLed, HIGH);
            Serial.println("LEFT");
            Serial.println(direction);
        }
        
        else if (digitalRead(buttonDown) == HIGH)
        {
            setDirection(DOWN);
            digitalWrite(signalLed, HIGH);
            Serial.println("DOWN");
            Serial.println(direction);
        }
        
    xSemaphoreGive(directionkeeper);
    }    
  }
}


static void debugShowDisply(uint8_t arg[PLAYGROUND_Y][PLAYGROUND_X])
{
  uint8_t i = 0;
  uint8_t j = 0;
  //Serial.write(13);//clearScreen

  Serial.write(27);       // ESC command
  Serial.print("[2J");    // clear screen command
  Serial.write(27);
  Serial.print("[H");     // cursor to home command


  for (i = 0; i < PLAYGROUND_Y; i++)
  {

    for (j = 0; j < PLAYGROUND_X; j++)
    {
      Serial.print("  ");
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
  
}
