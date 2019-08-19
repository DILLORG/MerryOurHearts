# pragma once
# ifndef MOH_ENGINE_H
# define MOH_ENGINE_H
# include "Settings.h"
# include "MOHSprites.h"

namespace MOHEngine{
class Game{

  private:
    bool _isRunning;
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    int _populationSize;
    Player* player;
    public:
      Game();
      vector <Enemy> enemyPop;
      inline SDL_Window* get_window(){return _window;};
      inline SDL_Renderer* get_renderer(){return _renderer;};
      inline bool running(){return _isRunning;};
      inline void change_run_state(bool value){_isRunning = value;};

      //Title X POS Y POS WIDTH HEIGHT FULLSCREEN?
      void init(const char* t, int x, int y, int w, int h, bool fs);
      void draw();
      void destroy_window();
      void clean();
      ~Game();
  };

  //Engine Functions.

  vector <SDL_Texture> load_multiple_textures(const char* path, Game &game);
  SDL_Texture* load_single_texture(const char* path, Game* game);
  template<class T>
<<<<<<< HEAD
  MOHSprite itemSpawner(ifstream& spawnlist , T obj);
  void handleEvents(Player* player, Game* game);
=======
  void item_spawner(ifstream& spawnList, T obj);
  MOHSprite spawner();
  void handle_events(Player* player, Game* game);
>>>>>>> 33b8b4232c59c429559183a31d18ae76b6cf1bf2
  void update_screen(Player* player, Game* game);
  void draw(Player* player, Game* game);
  void check_enemy_health(Game* game);
  void destroy_window(Game* game);

}
# endif
