# include "Engine.h"

Game::Game(SDL_Window window, SDL_Renderer renderer){
  _window = window;
  _renderer = renderer;

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
