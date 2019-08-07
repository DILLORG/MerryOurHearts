# include "MOHEngine.h"
using namespace MOHEngine;
Game::Game(){

  //Initialize sdl.
  Game::init("MERRY OUR HEARTS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
             SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);
}

void Game::init(const char *t, int x, int y, int w, int h, bool fs)
{

  int flags = 0;
  if(fs)
    flags = SDL_WINDOW_FULLSCREEN;

  //Initialize Sdl.
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    printf("SDL Inititalized\n");

    //Create window object.
    _window = SDL_CreateWindow(t, x, y ,w , h, flags);
    if(_window){
      printf("Game's window created.\n");

    }

    //Create renderer object.
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if(_renderer){
      printf("Games renderer initialized.\n");
      SDL_SetRenderDrawColor(_renderer, 255 ,255 ,255 ,255 );

    }

    _isRunning = true;

  }else{ //Sdl or one of games components faile to initialize.
    printf("One or more components faild to initialize! ");
    _isRunning = false;

  }

}



void Game::draw(){
  SDL_RenderClear(_renderer);

  //Add objects to render.
  SDL_RenderPresent(_renderer);
}

void Game::clean(){

}

void MOHEngine::destroy_window(Game* game){

  SDL_DestroyWindow(game-> getWindow());
  SDL_DestroyRenderer(game-> getRenderer());
  SDL_Quit();

}
void MOHEngine::handleEvents(Player* player, Game* game){

  SDL_Event event;
  SDL_PollEvent(&event);

  //Perform function depending upon input.
  switch(event.type){
    case SDL_QUIT:
      game -> changeRunState(false);
      printf("User exited the program\n");
      break;
    case SDLK_w:
      player -> movingUp();
      break;
    case SDLK_s:
      player -> movingDown();
      break;
    case SDLK_a:
      player -> movingLeft();
      break;
    case SDLK_d:
      player -> movingRight();
      break;
    case SDLK_KP_SPACE:
      player -> fireBullet();
      break;
  }

    player -> resetFlags();
}


void MOHEngine::checkEnemyHealth(Game* game){
    for(Enemy e : game -> enemyPop)
      if(e.getHealth() <= 0){
        e.kill();
        //Transfer items to  players inventory.

        //Delete enemy from memory

      }
}
