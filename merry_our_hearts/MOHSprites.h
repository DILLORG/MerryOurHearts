# pragma once
# ifndef MOH_SPRITE_H
# define MOH_SPRITE_H
# include "Settings.h"
class MOHSprite{
  private:
    SDL_Texture* _texture;
    SDL_Rect _srcRect, _destRect;
    char* _name;
    int _id;
    int _xPos;
    int _yPos;

  public:
    MOHSprite(const char* path, const char* n, int id, int x, int y);
    virtual int get_id(){return _id;};
    virtual void update();
    virtual void draw();
    void print(){printf("Name: %s, Object Id: %d, XPOS: %d, YPOS: %d\n"
                        ,_name, _id, _xPos, _yPos);};
    ~MOHSprite();

};

class Item : public MOHSprite{
  private:
    char* _description;
    int _sEffect;

  public:
    Item(const char* path, const char* n, int id, int x, int y, int s, const char* d);
    int getSEffect(){return _sEffect;};
    char* getDescription(){return _description;};
    void update();
    void draw();
    ~Item();
};

class HealthBar : public MOHSprite{
public:
  HealthBar(const char* path, const char* n, int id, int x, int y, int s);
  void update();
  void draw();
  ~HealthBar();
};

class Enemy : public MOHSprite{
  private:
    int _health;
    list <Item*> _inventory;
  public:

    Enemy(const char* path, const char* n, int id, int x, int y, int h);
    int getHealth(){return _health;};
    void addToInventory(Item* newItem);
    void showInventory();
    void setHealth(int value){this -> _health = value;};
    void update();
    void draw();
    void kill();
    ~Enemy();
};

class Player : public MOHSprite{
  private:
    int _health;
    bool _isMovingDown = false;
    bool _isMovingUp = false;
    bool _isMovingLeft = false;
    bool _isMovingRight = false;
    map <int , Item*> _inventory;
  public:

    Player(const char* path, const char* n ,int id, int x, int y, int h);
    inline void movingUp(){_isMovingUp = true;};
    inline void movingDown(){_isMovingDown = true;};
    inline void movingLeft(){_isMovingLeft = true;};
    inline void movingRight(){_isMovingRight = true;};
    void addToInventory(Item* newItem);

void fireBullet();
    void resetFlags();
    void update();
    void draw();
    void kill();
    ~Player();
};

//Bosses
class Destroyer : public Enemy{
  public:
    Destroyer();
    void update();
    void draw();
    ~Destroyer();
  };

class Kracken : public Enemy{
  public:
    Kracken();
    void update();
    void draw();
    ~Kracken();
};

# endif
