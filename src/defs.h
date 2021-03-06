/* defs.h - contains global includes, definitions and enums*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define MAX_ENTITIES 50
#define MAX_STARS 200

#define PLAYER_SPEED 3
#define ROCK_SPEED 4

enum
{
  PLAYER_SPRITE,
  MAX_SPRITES
};

enum
{
  ROCK_ANIMATION,
  MAX_ANIMATIONS
};

enum
{
  EXPLOSION_SOUND,
  MAX_SOUNDS
};
