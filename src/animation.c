#include "animation.h"

extern SDL_Texture* loadImage( char * );
extern void drawImage( SDL_Texture *, int, int );

void loadAnimation( int id, char *name )
{
  int i;
  FILE *fp = fopen( name, "rb" );
  char frameName[20];

  if( fp == NULL )
  {
    printf( "Failed to load animation file %s\n", name );
    exit(1);
  }

  /* Read the frame count from the file */
  fscanf( fp, "%d", &animation[id].frameCount );

  /*Allocate space for animation */
  animation[id].frame = ( SDL_Texture** )malloc( animation[id].frameCount * sizeof( SDL_Texture* ) );

  if( animation[id].frame == NULL )
  {
    printf( "Ran out of memory when creating the animation for %s\n", name );

    exit(1);
  }

  /* load up each frame, reading the frame names from file */
  for( i = 0; i < animation[id].frameCount; ++i )
  {
    fscanf( fp, "%s", frameName );

    animation[id].frame[i] = loadImage( frameName );

    if( animation[id].frame[i] == NULL )
    {
      printf( "Failed to load animation frame %s", frameName );
      exit(1);
    }
  }
}

void freeAnimation( Animation *anim )
{
  int i;

  /* loop through frames, freeing them up */

  if( anim->frame != NULL )
  {
    for( i = 0; i < anim->frameCount; ++i )
    {
      if( anim->frame[i] != NULL )
      {
        SDL_DestroyTexture( anim->frame[i] );
      }
    }

    free( anim->frame );
  }
}

void loadAllAnimations()
{
  loadAnimation( ROCK_ANIMATION, "../animdata/rock.dat");
}

void freeAnimations()
{
  int i;

  for( i = 0; i < MAX_ANIMATIONS; ++i )
  {
    freeAnimation( &animation[i] );
  }
}

void drawAnimation( Animation *anim, int index, int x, int y )
{
  drawImage( anim->frame[index], x, y );
}
