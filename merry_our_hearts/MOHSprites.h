#pragma once
# ifndef MOH_SPRITE_H
# define MOH_SPRITE_H
# include "MOHEngine.h"

class MOHSprite{
private:
  SDL_Texture* _texture;
  SDL_Rect _srcRect, _destRect;
  SDL_Renderer* _renderer;
  int _xpos;
  int _ypos;
public:
  MOHSprite(const char* t);
  virtual void update();
  virtual void draw();
  virtual void kill();

};

class Destroyer : MOHSprite {

};

class ChineMine : MOHSprite{

};

class Player : MOHSprite {

private:
  list <Items> inventory;
  bool _isMovingDown = false;
  bool _isMovingUp = false;
  bool _isMovingLeft = false;
  bool _isMovingRight = false;
public:
  Player();
  inline void movingDown(){_isMovingDown = true;};
  inline void movingUp(){_isMovingUp = true;};
  inline void movingLeft(){_isMovingLeft = true;};
  inline void movingRight(){_isMovingRight = true;};
  void resetFlags();
  void update();
  void draw();
  void kill();
  void fireBullet();
  ~Player();

};

class HealthBar : MOHSprite {

};

# endif
