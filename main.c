#include "main.h"

extern void init( char * );
extern void cleanup();
extern void getInput();
extern void doStars();
extern void initPlayer();
extern void doPlayer();
extern void loadAllSprites();
extern void draw();
extern void resetStars();


int main( int argc, char* argv[] )
{
  unsigned int Limit = SDL_GetTicks() + 16;

  init( "Space Rocks!" );

  atexit( cleanup );

  int go = 1;

  /* load all the sprites (player's actually) */
  loadAllSprites();

  /* initialize the player */
  initPlayer();

  /* reset the stars */
  resetStars();

  while( go == 1 )
  {
     getInput();

     doPlayer();

     doStars();

     draw();
  }

  exit( 0 );
}
