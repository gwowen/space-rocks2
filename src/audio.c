#include "audio.h"

void loadSound( int index, char* filename )
{
  /* load sounds specified by filename */
  if( index < 0 || index >= MAX_SOUNDS )
  {
    printf( "Invalid index for sound! Index %d, Maximum %d\n", index, MAX_SOUNDS );
    exit(1);
  }

  sound[index].effect = Mix_LoadWAV( filename );
  printf ( "Sound %s loaded!", filename );

  if( sound[index].effect == NULL )
  {
    printf( "Failed to load sound %s\n", filename );
    exit(1);
  }
}

void playSound( index )
{
  /* play sound on first free channel once */
  if( index < 0 || index >= MAX_SOUNDS )
  {
    printf( "Invalid index for sound! Index %d, Maximum %d\n", index, MAX_SOUNDS );
    exit(1);
  }

  Mix_PlayChannel( -1, sound[index].effect, 0 );
}

void loadAllSounds()
{
  loadSound( EXPLOSION_SOUND, "../sound/explosion.wav" );
}

void freeSounds()
{
  int i;

  for( i = 0; i < MAX_SOUNDS; ++i )
  {
    if( sound[i].effect != NULL )
    {
      Mix_FreeChunk( sound[i].effect );
    }
  }
}
