#include "init.h"

/* extern void freeSprites( void );
*  extern void freeSounds( void );
*  extern void freeAnimations( void );
* extern void closeFont( TTF_Font * ); */

void init( char *title )
{
  if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
    printf( "Failed to start SDL\n");
    exit(1);
  }

  game.gameWindow = SDL_CreateWindow( title, SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SCREEN_WIDTH,
                                        SCREEN_HEIGHT,
                                        SDL_WINDOW_SHOWN );

  if( game.gameWindow == NULL) {
    printf( "Could not create window, SDL Error %s", SDL_GetError() );
    exit(1);
  }

  game.gameRenderer = SDL_CreateRenderer( game.gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

  if( game.gameRenderer == NULL ) {
    printf( "Could not create renderer, SDL Error %s", SDL_GetError() );
    exit(1);
  }

}

void cleanup()
{
  SDL_DestroyRenderer( game.gameRenderer );
  SDL_DestroyWindow( game.gameWindow );
  SDL_Quit();
}
