# pragma once
# ifndef ENGINE_H
# define ENGINE_H
# include "Settings.h"
# include "Items.h"
# include "MOHSprites.h"
namespace MOHEngine{
class TextureLoader{

  public:
    template <class C>
    static SDL_Texture* LoadMultipleTextures(C container, const char* p, SDL_Renderer* r);
    static SDL_Texture* LoadSingleTexture(const char* p, SDL_Renderer* rend);
};

class Game{
  private:
    bool _isRunning;
    SDL_Window* _window;
    SDL_Renderer* _renderer;

  public:
      Game();
      //None player sprites.
      list <MOHSprite> npcPopulation;
      //Health packs and other game objects.
      list <Items> objectPopulation;

      //Title X POS Y POS WIDTH HEIGHT FULLSCREEN?
      void init(const char* t, int x, int y, int w, int h, bool fs);
      void update();
      inline MOHSprite Spawner(const char* type);
      void houseKeeping();
      void handleEvents(Player* player);
      void draw();
      void clean();
      inline bool running(){return _isRunning;};
      ~Game();

};
}
# endif
