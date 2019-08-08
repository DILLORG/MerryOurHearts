# pragma once
# ifndef MOH_SPRITE_H
# define MOH_SPRITE_H
# include "Settings.h"
class MOHSprite{
  private:
    SDL_Texture* _texture;
    SDL_Rect _srcRect, _destRect;
    int _id;
    int _xPos;
    int _yPos;

  public:
    MOHSprite(const char* path, int id, int x, int y);
    int get_id(){return _id;};
    virtual void update();
    virtual void draw();
    ~MOHSprite();

};

class Item : MOHSprite{
  private:

    char* _description;
    int _sEffect;

  public:
    Item(const char* path, int id, int x, int y, int s, const char* d);
    int getSEffect(){return _sEffect;};
    char* getDescription(){return _description;};
    void update();
    void draw();
    ~Item();
};

class HealthBar : MOHSprite{
public:
  HealthBar(const char* path, int id, int x, int y, int s);
  void update();
  void draw();
  ~HealthBar();
};

class Enemy : MOHSprite{
  private:
    int _health;
    list <Item*> _inventory;
  public:

    Enemy(const char* path, int id, int x, int y, int h);
    int getHealth(){return _health;};
    void setHealth(int value){this -> _health = value;};
    void update();
    void draw();
    void kill();
    ~Enemy();
};
class Player : MOHSprite{
  private:
    int _health;
    bool _isMovingDown = false;
    bool _isMovingUp = false;
    bool _isMovingLeft = false;
    bool _isMovingRight = false;
    map <int , Item*> _inventory;
  public:

    Player(const char* path, int id, int x, int y, int h);
    inline void movingUp(){_isMovingUp = true;};
    inline void movingDown(){_isMovingDown = true;};
    inline void movingLeft(){_isMovingLeft = true;};
    inline void movingRight(){_isMovingRight = true;};
    void fireBullet();
    void resetFlags();
    void update();
    void draw();
    void kill();
    ~Player();
};

//Bosses
class Destroyer : MOHSprite{
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
