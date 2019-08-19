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

template<class T>
void MOHEngine::item_spawner(ifstream& spawnList, T obj){
  char n, d, p;
  int i, x, y, s;

  // while(spawnlist >> n >> i >> x >> y >> s >> d){
  //   Item item = Item(p, n, i , x, y, s, d)
  //obj.add_to_inventory();
  // }

}

void MOHEngine::handle_events(Player* player, Game* game){

  SDL_Event event;
  SDL_PollEvent(&event);

  //Perform function depending upon input.
  switch(event.type){
    case SDL_QUIT:
      game -> change_run_state(false);
      printf("User exited the program\n");
      break;
    case SDLK_w:
      player -> moving_up();
      break;
    case SDLK_s:
      player -> moving_down();
      break;
    case SDLK_a:
      player -> moving_left();
      break;
    case SDLK_d:
      player -> moving_right();
      break;
    case SDLK_KP_SPACE:
      player -> fire_bullet();
      break;
  }

    player -> reset_flags();
}

void update_screen(Player *player, Game *game){

}

void draw(Player* player, Game* game){

}

void MOHEngine::check_enemy_health(Game *game){

<<<<<<< HEAD
    for(auto e : game -> enemyPop)
      if(e.getHealth() <= 0){
=======
    for(Enemy e : game -> enemyPop)
      if(e.get_health() <= 0){
>>>>>>> 33b8b4232c59c429559183a31d18ae76b6cf1bf2
        e.kill();
        //Transfer items to  players inventory.

        //Delete enemy from memory.
        game -> enemyPop.

      }
}

void MOHEngine::destroy_window(Game* game){

  SDL_DestroyWindow(game-> get_window());
  SDL_DestroyRenderer(game-> get_renderer());
  SDL_Quit();

}
