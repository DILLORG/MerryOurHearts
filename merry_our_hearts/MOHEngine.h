# pragma once
# ifndef MOH_ENGINE_H
# define MOH_ENGINE_H
# include "Settings.h"
# include "Items.h"
# include "MOHSprites.h"

namespace MOHEngine{
class Game{

  private:
    bool _isRunning;
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    public:
      Game();
      //None player sprites.
      list <MOHSprite*> npcPopulation;
      //Health packs and other game objects.
      list <Items*> objectPopulation;
      inline SDL_Window* getWindow(){return _window;};
      inline SDL_Renderer* getRendere(){return _renderer;};
      inline bool running(){return _isRunning;};
      inline void changeRunState(bool value){_isRunning = value;};

      //Title X POS Y POS WIDTH HEIGHT FULLSCREEN?
      void init(const char* t, int x, int y, int w, int h, bool fs);
      void update();
      void draw();
      void clean();

      ~Game();
  };

  //Engine Functions.
  list <SDL_Texture> LoadMultipleTextures(const char* path, Game &game);
  SDL_Texture LoadSingleTexture(const char* path, Game* game);
  MOHSprite Spawner(const char* path, Game* game);
  void handleEvents(Player* player, Game* game);
  void update(Player* player, Game* game);
  void draw(Player* player, Game* game);


}
# endif
