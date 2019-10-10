# pragma once
# ifndef MOH_ENGINE_H
# define MOH_ENGINE_H
# include "Sprite.h"
# include <SDL2/SDL.h>
class Game{

  private:
    Player* _player;
    std::list<Enemy*> _enemyPop;
    // std::vector <SDL_Texture> load_multiple_textures(std::stringpath);

  public:
    Game(Player* player);
    SDL_Texture* load_single_texture(std::string path);
    void spawner(std::ifstream in, std::string fileName);
    void handle_events();
    void update_screen();
    void show_population();
    void draw();
    void check_health();
    void destroy_window();
    ~Game();


};
# endif
