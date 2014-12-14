/* structs.h - all the main structs for the game go here */
#include "defs.h"

typedef struct Game
{
  int score;
  SDL_Window* gameWindow;
  SDL_Renderer* gameRenderer;
  TTF_Font *gameFont;
  SDL_Surface* bgSurface;
  SDL_Texture* bgTexture;
} Game;

typedef struct Control
{
  int up, down, left, right;
} Control;

typedef struct Star
{
  int x, y, speed;
} Star;

typedef struct Sprite
{
  SDL_Texture *image;
} Sprite;

typedef struct Entity
{
  int active, speed;
  int x, y, w, h;
  int currentFrame, animID, frameTimer;
  SDL_Texture* sprite;
  void (*action)(void);
  void (*draw)(void);
} Entity;

/*TODO: add structs for Animation, Sprite, Sound, Entities and Stars*/
