# include "MOHSprites.h"
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
Enemy::Enemy(const char* path, int id, int x, int y, int h)
:MOHSprite(path,id, x, y){
    _health = h;

}


Item::Item(const char* path, int id, int x, int y, int s, const char* d)
:MOHSprite(path, id, x, y){
  _description = new char[strlen(d) + 1];
  strcpy(_description, d);
}

void Player::resetFlags(){
  _isMovingDown = false;
  _isMovingUp = false;
  _isMovingLeft = false;
  _isMovingRight = false;
}
