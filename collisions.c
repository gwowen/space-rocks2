#include "collisions.h"

extern void addRandomParticle( float, float );
extern void addScore();

int collision( int, int, int, int, int, int, int, int );

void doCollisions()
{

}

int collision( int x0, int y0, int w0, int h0, int x2, int y2, int w1, int h1 )
{
  int x1 = x0 + w0;
  int y1 = y0 + h0;

  int x3 = x2 + w1;
  int y3 = y2 + h1;

  return !( x1 < x2 || x3 < x0 || y1 < y2 || y3 < y0 );
}
