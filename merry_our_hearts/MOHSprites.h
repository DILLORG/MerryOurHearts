#pragma once
# ifndef MOH_SPRITE_H
# define MOH_SPRITE_H
# include "MOHEngine.h"
using namespace MOHEngine;
class MOHSprite{
private:
  SDL_Texture* texture;
  SDL_Rect _srcRect, _destRect;
  SDL_Renderer* renderer;
  int _xpos;
  int _ypos;
public:
  MOHSprite(const char* t, SDL_Renderer* r);
  virtual void Update();
  virtual void Draw();
  virtual void Kill();
  ~MOHSprite();
};

class Destroyer : MOHSprite {

};

class ChineMine : MOHSprite{

};

class Player : MOHSprite {

private:
  list <Items> inventory;
public:
  Player();
  inline bool MovingDown();
  inline bool MovingUp();
  inline bool MovingLeft();
  inline bool MovingRight();
  void Update();
  void Draw();
  void Kill();
  void FireBullet();
  ~Player();

};

class HealthBar : MOHSprite {

};

# endif
