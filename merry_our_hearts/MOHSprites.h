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
  list <Items> inventory;
  list <SDL_Texture> animations;

public:
  MOHSprite(const char* t);
  virtual void update();
  virtual void draw();
  void kill();

};
class HealthBar : MOHSprite{
public:
  HealthBar();
  void update();
  void draw();
  ~HealthBar();
};
class Player : MOHSprite {
private:
  bool _isMovingDown = false;
  bool _isMovingUp = false;
  bool _isMovingLeft = false;
  bool _isMovingRight = false;

public:
  Player();
  inline void movingUp(){_isMovingUp = true;};
  inline void movingDown(){_isMovingDown = true;};
  inline void movingLeft(){_isMovingLeft = true;};
  inline void movingRight(){_isMovingRight = true;};
  void update();
  void draw();
};
//Enemies.
class ChainMine : MOHSprite{
  public:
    ChainMine();
    void update();
    void draw();
    ~ChainMine();
  };
//Bosses
class Destroyer : MOHSprite {
  public:
    Destroyer();
    void update();
    void draw();
    ~Destroyer();
  };
class Kracken : MOHSprite{
  public:
    Kracken();
    void update();
    void draw();
    ~Kracken();
};
# endif
