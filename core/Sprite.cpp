# include "Sprite.h"

//Sprite
Sprite::Sprite(std::string path, std::string n, int id, int xPos, int yPos){

  // _texture = LoadSingleTexture(path);
  _id = id;
  _xPos = xPos;
  _yPos = yPos;
  _name = n;
}

void Sprite::update(){

}
void Sprite::draw(){

}

Sprite::~Sprite(){
  delete [] _name.c_str();

}

//ITEM
Item::Item(std::string path, std::string n, int id, int x, int y, int s, std::string d)
:Sprite(path, n, id, x, y){

  _description = d;


}

void Item::update(){

}

void Item::draw(){

}


//HEALTHBAR
HealthBar::HealthBar(std::string path, std::string n, int id, int x, int y, int s)
:Sprite(path, n, id, x, y){

}

void HealthBar::update(){

}

void HealthBar::draw(){

}

//ENEMY
Enemy::Enemy(std::string path, std::string n, int id, int x, int y, int h)
:Sprite(path, n, id, x, y){
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
  for(auto item : _inventory){
      item -> print();
  }
}
Enemy::~Enemy(){

}

//PLAYER
Player::Player(std::string path, std::string n, int id, int x, int y, int h)
:Sprite(path, n, id, x, y){
  _health = h;

}

void Player::fire_bullet(){

}

void Player::add_to_inventory(Item* item){
      try{
        _inventory.push_back(item);
      } catch(std::bad_alloc){
        std::cout << "Inventory is full.";
      }

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
  for(const auto &i : _inventory)
        //Delete all items.
        delete i;
}
