# include "MOHSprites.h"

//MOHSPRITE
MOHSprite::MOHSprite(const char* path, const char* n, int id, int xPos, int yPos){

  // _texture = LoadSingleTexture(path);
  _id = id;
  _xPos = xPos;
  _yPos = yPos;
  _name = new char[strlen(n) + 1];
  strcpy(_name, n);

}
void MOHSprite::update(){

}
void MOHSprite::draw(){

}

MOHSprite::~MOHSprite(){
  delete [] _name;

}

//ITEM
Item::Item(const char* path, const char* n, int id, int x, int y, int s, const char* d)
:MOHSprite(path, n, id, x, y){

  _description = new char[strlen(d) + 1];
  strcpy(_description, d);

}

void Item::update(){

}

void Item::draw(){

}

Item::~Item(){

  delete [] _description;

}

//HEALTHBAR
HealthBar::HealthBar(const char* path, const char* n, int id, int x, int y, int s)
:MOHSprite(path, n, id, x, y){

}

void HealthBar::update(){

}

void HealthBar::draw(){

}

//ENEMY
Enemy::Enemy(const char* path, const char* n, int id, int x, int y, int h)
:MOHSprite(path, n, id, x, y){
  _health = h;



}
void Enemy::update(){

}

void Enemy::draw(){

}

void Enemy::kill(){

}
void Enemy::add_to_inventory(Item *newItem){
  try{
    _inventory.push_back(newItem);
  } catch(std::bad_alloc){
    std::cout << "Inventory is full.";
  }

}
void Enemy::show_inventory(){

  //For each item in inventory.
  for(const auto &item : _inventory){
      item -> print();
  }
}
Enemy::~Enemy(){

}

//PLAYER
Player::Player(const char* path, const char* n, int id, int x, int y, int h)
:MOHSprite(path, n, id, x, y){
  _health = h;

}

void Player::fire_bullet(){

}

void Player::add_to_inventory(Item* item){
  throw std::bad_alloc();

}

void Player::reset_flags(){
  _isMovingDown = false;
  _isMovingUp = false;
  _isMovingLeft = false;
  _isMovingRight = false;
}

void Player::update(){

}

void Player::draw(){

}


void Player::kill(){

}
Player::~Player(){
  //For item in inventory.
  for(std::map<int, Item*>::const_iterator i = _inventory.begin(); i!= _inventory.end();
      ++i)
        //Delete all items.
        delete i -> second;


}
