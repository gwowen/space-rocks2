#include "entity.h"

extern void drawImage( SDL_Texture*, int, int );

void clearEntities()
{
  for( int i = 0; i < MAX_ENTITIES; ++i )
    {
      if( entity[i].active == 0 ) {
          memset( &entity[i], 0, sizeof( Entity ) );
          entity[i].active = 1;
          return i;
        }
    }

    /*if no free slots are active, return -1*/
    return -1;
}

void doEntities()
{
  for( int i = 0; i < MAX_ENTITIES; ++i )
    {
      self = &entity[i];

      if( self->active == 1 ) {

        self->action();
      }
    }
}

void doEntities()
{
  for( int i = 0; i < MAX_ENTITIES; ++i )
    {
      self = &entity[i];

      if( self->active == 1 ) {

        self->draw();
      }
    }
}

void drawStandardEntity()
{
  drawImage( self->sprite, self->x, self->y );
}

void drawAnimatedEntity()
{

}
