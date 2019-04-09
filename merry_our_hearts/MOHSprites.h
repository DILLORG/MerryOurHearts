# ifndef MOH_SPRITE_H
# define MOH_SPRITE_H
# include "Settings.h"
# include "Items.h"

class MOHSprite{

};

class Destroyer : MOHSprite {

};

class ChineMine : MOHSprite{

};

class Ship : MOHSprite {

public:
  list <Items> inventory;
};

class HealthBar : MOHSprite {

};

# endif
