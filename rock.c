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
    rockChance = rand() % 30;
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

  entity[i].x = SCREEN_WIDTH + rand() % 100;
  entity[i].y = rand() % SCREEN_HEIGHT;
  entity[i].action = &moveRock;
  entity[i].speed = 1 + ( rand() % 5 );
  entity[i].draw = &drawAnimatedEntity;
  entity[i].animID = ROCK_ANIMATION;
  entity[i].currentFrame = 0;
  entity[i].frameTimer = 3;

  SDL_QueryTexture( animation[entity[i].animID].frame[entity[i].currentFrame], NULL, NULL, &entity[i].w, &entity[i].h );
}

static void moveRock()
{
  /* Move the rock from right to left, then once it goes off the screen remove it */
  self->x -= self->speed;

  if( self->x <= -self->w )
  {
    self->active = 0;
  }

  /* update animation frame */

  self->frameTimer--;

  /* reset the frameTimer if it's come to the end of the frame and update frame */

  if( self->frameTimer <= 0 )
  {
    self->frameTimer = 3;
    self->currentFrame++;

    if( self->currentFrame >= animation[self->animID].frameCount )
    {
      self->currentFrame = 0;
    }
  }
}
