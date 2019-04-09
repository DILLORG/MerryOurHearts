# include "MOHEngine.h"

void Game::init(const char *title, int xpos, int ypos, int width, int height,
           bool fullscreen)
{

  int flags = 0;
  if(fullscreen)
    flags = SDL_WINDOW_FULLSCREEN;

  //Initialize Sdl.
  if(SDL_Init(SDL_INIT_EVERYTHING)== 0){
    cout << "SDL initialized.";

    //Create window object.
    _window = SDL_CreateWindow(title, xpos, ypos,width, height, flags);
    if(_window)
      cout << "Game's window created.";

    //Create renderer object.
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if(_renderer)
      cout << "Games renderer initialized.";

    _isRunning = true;

  }else{ //Sdl or one of games components faile to initialize.
    cerr << "Failed to initialize game";
    _isRunning = false;
  }

}

void Game::update(){

}

void Game::draw(){

}

void MOHEngine::handleEventes(Game game){

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
