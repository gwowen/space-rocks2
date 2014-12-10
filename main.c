#include "main.h"

extern void init( char * );
extern void cleanup();


int main( int argc, char* argv[] )
{
  bool running;

  init( "Space Rocks!" );

  atexit( cleanup );

  int go = 1;

  while( go == 1 )
  {
     getInput();
  }

  exit( 0 );
}
