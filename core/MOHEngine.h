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
      inline SDL_Window* getWindow(){return _window;};
      inline SDL_Renderer* getRenderer(){return _renderer;};
      inline bool running(){return _isRunning;};
      inline void changeRunState(bool value){_isRunning = value;};

      //Title X POS Y POS WIDTH HEIGHT FULLSCREEN?
      void init(const char* t, int x, int y, int w, int h, bool fs);
      void draw();
      void destroy_window();
      void clean();
      ~Game();
  };

  //Engine Functions.

  vector <SDL_Texture> loadMultipleTextures(const char* path, Game &game);
  SDL_Texture* loadSingleTexture(const char* path, Game* game);
  template<class T>
  MOHSprite itemSpawner(ifstream& spawnlist , T obj);
  void handleEvents(Player* player, Game* game);
  void update_screen(Player* player, Game* game);
  void draw(Player* player, Game* game);
  void checkEnemyHealth(Game* game);
  void destroy_window(Game* game);

}
# endif
