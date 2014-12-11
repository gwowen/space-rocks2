#include "main.h"

extern void init( char * );
extern void cleanup();


int main( int argc, char* argv[] )
{  
  unsigned int Limit = SDL_GetTicks() + 16;

  init( "Space Rocks!" );

  atexit( cleanup );

  int go = 1;

  while( go == 1 )
  {
     getInput();
  }

  exit( 0 );
}
