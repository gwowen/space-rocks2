#include "draw.h"

extern void drawStars();

void draw()
{

  SDL_FillRect( game.bgSurface, NULL, 0 );
  drawStars();
  SDL_UpdateTexture( game.bgTexture, NULL, game.bgSurface->pixels, game.bgSurface->pitch );
  SDL_RenderCopy( game.gameRenderer, game.bgTexture, NULL, NULL );
  SDL_RenderPresent( game.gameRenderer );
}

void delay( unsigned int frameLimit )
{
  unsigned int ticks = SDL_GetTicks();

  if( frameLimit < ticks ) {
    return;
  }

  if( frameLimit > ticks + 16 ) {
    SDL_Delay( 16 );
  }
  else {
    SDL_Delay( frameLimit - ticks );
  }

}
