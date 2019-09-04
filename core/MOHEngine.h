# pragma once
# ifndef MOH_ENGINE_H
# define MOH_ENGINE_H
# include "MOHSprites.h"
# include <SDL2/SDL.h>
namespace MOHEngine{
  //Engine Functions.
  std::list<Enemy*> enemyPop;
  std::vector <SDL_Texture> load_multiple_textures(const char* path);
  SDL_Texture* load_single_texture(const char* path);
  template<class T>
  void item_spawner(std::ifstream& spawnList , T obj);
  void handle_events(Player* player);
  void update_screen(Player* player);
  void draw(Player* player);
  void check_enemy_health();
  void destroy_window();

}
# endif
