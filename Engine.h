# ifndef ENGINE_H
# define ENGIINE_H
# include "Settings.h"
# include "Items.h"
# include "Sprites.h"

class Game{
  private:
    bool _isRunning;

    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;

  public:
      list <Sprite> npcPopulation;
      list <Items> objectPopulation;
      Game(SDL_Window, SDL_Renderer);
      void init(const char* title, int xpos, int ypos, int width, int height,
                bool fullscreen);
      void update();
      void houseKeeping();
      void draw();
      inline void stopGame(){_isRunning = false;};
      inline void startGame(){_isRunning = true;};
      inline bool running(){return _isRunning;};

      ~Game();

};
namespace Engine{
  void handleEventes(Game game);

}
# endif
