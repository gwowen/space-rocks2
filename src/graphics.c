#include "graphics.h"

/* load images into an SDL_Surface then convert to a texture */

SDL_Texture* loadImage( char* filename )
{
  SDL_Texture* newTexture = NULL;
  SDL_Surface* tempSurface = IMG_Load( filename );

  if( tempSurface == NULL ) {
    printf( "Unable to load image %s! SDL_image error: %s\n", filename, IMG_GetError() );
  } else {
    SDL_SetColorKey( tempSurface, SDL_TRUE, SDL_MapRGB( tempSurface->format, 0, 0xFF, 0xFF ) );
    newTexture = SDL_CreateTextureFromSurface( game.gameRenderer, tempSurface );

  if( newTexture == NULL ) {
    printf( "Unable to create texture from %s! SDL Error: %s\n", filename, SDL_GetError() );
  }

  printf( "%s loaded successfully!\n", filename );
  SDL_FreeSurface( tempSurface );
  }

  return newTexture;
}


void drawImage( SDL_Texture* drawTex, int x, int y )
{
  SDL_Rect dest;

  dest.x = x;
  dest.y = y;

  SDL_QueryTexture( drawTex, NULL, NULL, &dest.w, &dest.h );
  SDL_RenderCopy( game.gameRenderer, drawTex, NULL, &dest );
}

void loadSprite( int index, char* filename)
{
  /*Load the image into the next slot in the sprite bank*/
  if( index >= MAX_SPRITES || index < 0 ) {
    printf( "Invalid index for sprite! Index %d Maximum %d\n", index, MAX_SPRITES );
    exit(1);
  }

  sprite[index].image = loadImage( filename );

  if( sprite[index].image == NULL ) {
      exit(1);
    }
}

SDL_Texture* getSprite( int index )
{
  if( index >= MAX_SPRITES || index < 0 ) {
    printf( "Invalid index for sprite! Index %d Maximum %d\n", index, MAX_SPRITES );
    exit(1);
  }

  return sprite[index].image;
}

void freeSprites()
{
  int i;
  
  for( i = 0; i < MAX_SPRITES; ++i )
    {
        if( sprite[i].image != NULL ) {
          SDL_DestroyTexture( sprite[i].image );
        }
    }
}

void loadAllSprites()
{
  /* load the player sprite into its slot
  for later reference */
  loadSprite( PLAYER_SPRITE, "../gfx/firefly.png" );
}
