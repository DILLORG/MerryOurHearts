# include "Engine.h"

Game::Game(){

}
void Game::init(const char *title, int xpos, int ypos, int width, int height,
           bool fullscreen)
{

}

void Game::update(){

}

void Game::draw(){

}

void Engine::handleEventes(Game game){

  SDL_Event event;
  SDL_PollEvent(&event);

  //Perform function depending upon input.
  switch(event.type){
    case SDL_QUIT:
      game.stopGame();
      break;

    default:
      break;

  }
}
