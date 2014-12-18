#include "player.h"

extern int loadSprite( char * );
extern void drawImage( SDL_Texture *, int , int );
extern SDL_Texture *getSprite( int );

void initPlayer()
{
  player.sprite = getSprite( PLAYER_SPRITE );

  player.x = SCREEN_WIDTH / 2;
  player.y = SCREEN_HEIGHT / 2;

  SDL_QueryTexture( player.sprite, NULL, NULL, &player.w, &player.h );

  player.active = 1;

}

void doPlayer()
{
  if( player.active == 1 )
  {
    if( input.up == 1 )
    {
      player.y -= PLAYER_SPEED;

      /* keep player from moving off the screen */
      if( player.y < 0 )
      {
        player.y = 0;
      }
    }

    if( input.down == 1 )
    {
      player.y += PLAYER_SPEED;

      if( player.y + player.h >= SCREEN_HEIGHT )
      {
        player.y = SCREEN_HEIGHT - ( player.h + 1 );
      }
    }

    if( input.left == 1 )
    {
      player.x -= PLAYER_SPEED;

      if( player.x < 0 )
      {
        player.x = 0;
      }
    }

    if( input.right == 1 )
    {
      player.x += PLAYER_SPEED;

      if( player.x + player.w >= SCREEN_WIDTH )
      {
        player.x = SCREEN_WIDTH - ( player.w + 1 );
      }
    }
  }
}

void drawPlayer()
{
  if( player.active == 1 )
  {
    drawImage( player.sprite, player.x, player.y );
  }
}
