# include "MOHSprites.h"

MOHSprite::MOHSprite(const char* path){
  //Load Texture.
  _texture = MOHEngine::LoadSingleTexture(path);

}
void MOHSprite::draw(){

  //Render given texture on given sprite at given location.
  SDL_RenderCopy(_renderer, _texture, &_srcRect, &_destRect);

}

void MOHSprite::update(){
  _xpos = 0;
  _ypos = 0;

  _srcRect.h = 180;
  _srcRect.w = 180;
  _srcRect.x = 0;
  _srcRect.y = 0;

  _destRect.x = _xpos;
  _destRect.y = _ypos;
  _destRect.h = _srcRect.w * 2;
  _destRect.h = ~_srcRect.h * 2;

}
void Player::ResetFlags(){
  _isMovingDown = false;
  _isMovingUp = false;
  _isMovingLeft = false;
  _isMovingRight = false;
}
