# include "MOHSprites.h"
//MOHSPRITE
MOHSprite::MOHSprite(const char* path, int id, int xPos, int yPos){

  // _texture = LoadSingleTexture(path);
  _id = id;
  _xPos = xPos;
  _yPos = yPos;

}
void MOHSprite::update(){

}
void MOHSprite::draw(){

}
MOHSprite::~MOHSprite(){


}
//ITEM
Item::Item(const char* path, int id, int x, int y, int s, const char* d)
:MOHSprite(path, id, x, y){

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
HealthBar::HealthBar(const char* path, int id, int x, int y, int s)
:MOHSprite(path, id, x, y){


}

void HealthBar::update(){

}

void HealthBar::draw(){

}

//ENEMY
Enemy::Enemy(const char* path, int id, int x, int y, int h)
:MOHSprite(path, id, x, y){
  _health = h;


}
void Enemy::update(){

}

void Enemy::draw(){

}

void Enemy::kill(){

}
Enemy::~Enemy(){
  for(list<Item*>::const_iterator i = _inventory.begin(); i!= _inventory.end)
}

//PLAYER
Player::Player(const char* path, int id, int x, int y, int h)
:MOHSprite(path, id, x, y){
  _health = h;

}

void Player::fireBullet(){

}

void Player::resetFlags(){
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
  for(map<int, Item*>::const_iterator i = _inventory.begin(); i!= _inventory.end();
      ++i)
        //Delete all items.
        delete i -> second;


}
