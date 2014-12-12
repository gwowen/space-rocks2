#include "main.h"

extern void init( char * );
extern void cleanup();
extern void getInput();
extern void doStars();
extern void draw();
extern void resetStars();


int main( int argc, char* argv[] )
{
  unsigned int Limit = SDL_GetTicks() + 16;

  init( "Space Rocks!" );

  atexit( cleanup );

  int go = 1;

  resetStars();

  while( go == 1 )
  {
     getInput();

     doStars();

     draw();
  }

  exit( 0 );
}
