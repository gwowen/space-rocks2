#include "main.h"

extern void init( char * );
extern void cleanup();
extern void getInput();
extern void doStars();
extern void initPlayer();
extern void doPlayer();
extern void doEntities();
extern void loadAllSprites();
extern void addRock( int );
extern void loadAllAnimations();
extern void draw();
extern void resetStars();
extern void delay( unsigned int );


int main( int argc, char* argv[] )
{
  unsigned int frameLimit = SDL_GetTicks() + 16;

  init( "Space Rocks!" );

  atexit( cleanup );

  int go = 1;

  /* load all the sprites (player's actually) */
  loadAllSprites();

  loadAllAnimations();

  /* initialize the player */
  initPlayer();

  /* reset the stars */
  resetStars();

  while( go == 1 )
  {
     getInput();

     doPlayer();

     addRock( 10000 );

     doEntities();

     doStars();

     draw();

     delay( frameLimit );

     frameLimit = SDL_GetTicks() + 16;
  }

  exit( 0 );
}
