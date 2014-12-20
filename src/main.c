#include "main.h"

extern void init( char * );
extern void cleanup();
extern void getInput();
extern void doStars();
extern void initPlayer();
extern void doPlayer();
extern void doEntities();
extern void doCollisions();
extern void loadAllSprites();
extern TTF_Font *loadFont( char *, int);
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

  game.gameFont = loadFont( "../font/font.ttf", 16 );

  /* initialize the player */
  initPlayer();

  /* reset the stars */
  resetStars();

  while( go == 1 )
  {
     getInput();

     doPlayer();

     addRock( game.score );

     doEntities();

     doStars();

     doCollisions();

     draw();

     if( player.active == 1 )
     {
       game.score += 10;
     }

     delay( frameLimit );

     frameLimit = SDL_GetTicks() + 16;
  }

  exit( 0 );
}
