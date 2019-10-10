# pragma once
# ifndef MOH_SPRITE_H
# define MOH_SPRITE_H
# include "Settings.h"
# include <SDL2/SDL_image.h>
class Sprite{

  private:
    SDL_Texture* _texture;
    SDL_Rect _srcRect, _destRect;
    std::string _name;
    int _id;
    int _xPos;
    int _yPos;

  public:
    Sprite(std::string path, std::string n, int id, int x, int y);
    virtual int get_id(){return _id;};
    virtual void update();
    virtual void draw();
    void print(){printf("Name: %s, Object Id: %d, XPOS: %d, YPOS: %d\n"
                        ,_name.c_str(), _id, _xPos, _yPos);};

    ~Sprite();

};

class Item : public Sprite{

  private:
    std::string _description;
    int _sEffect;

  public:
    Item(std::string path, std::string n, int id, int x, int y, int s, std::string d);
    int get_status_effect(){return _sEffect;};
    std::string get_description(){return _description;};
    void update();
    void draw();
    ~Item();
};

class HealthBar : public Sprite{

  public:
  HealthBar(std::string path, std::string n, int id, int x, int y, int s);
  void update();
  void draw();
  ~HealthBar();
};

class Enemy : public Sprite{

  private:
    int _health;
    std::list <Item*> _inventory;

  public:
    Enemy(std::string path, std::string n, int id, int x, int y, int h);
    int get_health(){return _health;};
    std::list<Item*> get_inventory(){return _inventory;};
    void add_to_inventory(Item* newItem);
    void show_inventory();
    void set_health(int value){this -> _health = value;};
    void update();
    void draw();
    void kill();
    ~Enemy();
};

class Player : public Sprite{

  private:
    int _health;
    bool _isMovingDown = false;
    bool _isMovingUp = false;
    bool _isMovingLeft = false;
    bool _isMovingRight = false;
    std::list <Item*> _inventory;

  public:
    Player(std::string path, std::string n ,int id, int x, int y, int h);
    inline void moving_up(){_isMovingUp = true;};
    inline void moving_down(){_isMovingDown = true;};
    inline void moving_left(){_isMovingLeft = true;};
    inline void moving_right(){_isMovingRight = true;};
    inline int get_health(){return _health;};
    std::list <Item*> get_inventory(){return _inventory;};
    void add_to_inventory(Item* newItem);

void fire_bullet();
    void reset_flags();
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
