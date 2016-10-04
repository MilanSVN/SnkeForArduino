#include "driver.h"
#include "game.h"

static void showBlank();                                   

void showScreean(uint8_t matrix[PLAYGROUND_Y][PLAYGROUND_X])
{
  int k = 0;
  for(int i =0; i < (PLAYGROUND_X -1); i++)
  {

    for(int j = 0; j < (PLAYGROUND_Y -1); j++)
    {
      k = (i+6)%PLAYGROUND_X ;
      if(matrix[k][j]>FOOD)
       digitalWrite (D0-j, HIGH);
      else
       digitalWrite (D0-j, LOW);
      //j = j % 8;
    }
    
    delay (200);

    showBlank();
    
    if(i==0)
    {
      digitalWrite (D, LOW);
    }
    else
    {
      digitalWrite (D, HIGH);
    }
    delay (10);
    
    digitalWrite (CLK, HIGH);
    delay (10);
    digitalWrite (CLK, LOW);
  

}
static void showBlank()
{
	digitalWrite (D0, LOW);
    digitalWrite (D1, LOW);
    digitalWrite (D2, LOW);
    digitalWrite (D3, LOW);
    digitalWrite (D4, LOW);
    digitalWrite (D5, LOW);
    digitalWrite (D6, LOW);
    digitalWrite (D7, LOW);
    delay (10);
} 

void showFood(uint8_t matrix[PLAYGROUND_Y][PLAYGROUND_X])
{
   int k = 0;
  for(int i =0; i < (PLAYGROUND_X); i++)
  {

    for(int j = 0; j < (PLAYGROUND_Y); j++)
    {
      k = (i+6)%PLAYGROUND_X ;
      if(matrix[k][j]==FOOD)
       digitalWrite (D0-j, HIGH);
      else
       digitalWrite (D0-j, LOW);
      //j = j % 8;
    }
    
    delay (200);

    showBlank();
    
    if(i==0)
    {
      digitalWrite (GIN, LOW);
    }
    else
    {
      digitalWrite (GIN, HIGH);
    }
    delay (10);
    
    digitalWrite (CLK, HIGH);
    delay (10);
    digitalWrite (CLK, LOW);
  
  }
}