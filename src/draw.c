#include "draw.h"

extern void drawEntities();
extern void drawStars();
extern void drawPlayer();
extern void drawString( char*, int, int, TTF_Font *, int, int );

void draw()
{
  char text[20];

  SDL_FillRect( game.bgSurface, NULL, 0 );

  drawStars();

  SDL_UpdateTexture( game.bgTexture, NULL, game.bgSurface->pixels, game.bgSurface->pitch );

  SDL_RenderCopy( game.gameRenderer, game.bgTexture, NULL, NULL );

  sprintf( text, "SCORE: %06d", game.score );

  drawString( text, 100, 10, game.gameFont, 1, 0 );

  drawPlayer();

  drawEntities();

  SDL_RenderPresent( game.gameRenderer );

  SDL_Delay( 1 );
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
