#include "rock.h"

extern int getFreeEntity();
extern void drawAnimatedEntity();
extern SDL_Texture *getSprite( int );

static void moveRock();

void addRock( int score )
{
  int i, rockChance;

  /*the chance of rocks appearing is based on the player's score - higher
  the score, the higher the chance of a rock appearing! */
  if( score < 10000 )
  {
    rockChance = rand() % 60;
  }

  else if( score < 20000 )
  {
    rockChance = rand() % 45;
  }

  else if( score < 30000 )
  {
    rockChance = rand % 30;
  }

  else
  {
    rockChance = rand() % 15;
  }

  if( rockChance != 0 )
  {
    return;
  }

  i = getFreeEntity();

  if( i == -1 )
  {
    return;
  }

  
}

static void moveRock()
{

}
