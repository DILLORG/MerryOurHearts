# include "MOHEngine.h"
using namespace MOHEngine;

template<class T>
void MOHEngine::item_spawner(std::ifstream &spawnList, T obj){

}

void MOHEngine::handle_events(Player* player){

  SDL_Event event;
  SDL_PollEvent(&event);

  //Perform function depending upon input.
  switch(event.type){
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

void update_screen(Player *player){

}

void draw(Player* player){

}

void MOHEngine::check_enemy_health(){

    for(auto e : enemyPop)
      if(e -> get_health() <= 0){
        e -> kill();
        //Transfer items to  players inventory.

        //Delete enemy from memory.

      }
}

void MOHEngine::destroy_window(){

  // SDL_DestroyWindow(game-> get_window());
  // SDL_DestroyRenderer(game-> get_renderer());
  SDL_Quit();

}
