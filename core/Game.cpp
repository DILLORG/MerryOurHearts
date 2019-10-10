# include "Game.h"

Game::Game(Player* player){
  _player = player;

}
void Game::spawner(std::ifstream in, std::string fileName){
    in.open(fileName);

}

void Game::handle_events(){

  // SDL_Event event;
  // SDL_PollEvent(&event);
  //
  // //Perform function depending upon input.
  // switch(event.type){
  //   case SDLK_w:
  //     _player -> moving_up();
  //     break;
  //   case SDLK_s:
  //     _player -> moving_down();
  //     break;
  //   case SDLK_a:
  //     _player -> moving_left();
  //     break;
  //   case SDLK_d:
  //     _player -> moving_right();
  //     break;
  //   case SDLK_KP_SPACE:
  //     _player -> fire_bullet();
  //     break;
  // }
  //
  //   _player -> reset_flags();
}

void Game::update_screen(){

  //Update player
  _player -> update();

  //Update all enemies
  for(auto e: _enemyPop)
    e -> update();
}

void Game::show_population(){
  for(auto e : _enemyPop){
      std::cout << e -> get_id();
  }
}
void Game::draw(){

  //Draw player
  _player -> draw();

  //Draw all enemies to screen.
  for(auto e: _enemyPop)
    e -> draw();
}

void Game::check_health(){
    std::list<Item*> enemysInventory;
    for(auto e : _enemyPop)

      if(e -> get_health() <= 0){
        e -> kill();
        enemysInventory = e -> get_inventory();

        //Transfer items to  players inventory.
        for(auto i : enemysInventory){
          _player -> add_to_inventory(i);
        }

        //Delete enemy from memory.
        // delete e;
      }
      if (_player -> get_health() <= 0){

        // Kill player.
        _player -> kill();

      }
}

void Game::destroy_window(){

  // SDL_DestroyWindow(game-> get_window());
  // SDL_DestroyRenderer(game-> get_renderer());
  // SDL_Quit();

}
Game::~Game(){

  for(auto e : _enemyPop){
    delete e;
  }
  delete _player;
}
