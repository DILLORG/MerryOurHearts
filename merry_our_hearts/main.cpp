# include "MOHEngine.h"

using namespace MOHEngine;
Game* game = nullptr;
Player* player = nullptr;
int main(){

  game = new Game();
  player = new Player();

  //Main game loop.
  while(game -> running()){
    game -> handleEvents(player);
    game -> update();
    game -> draw();
  }
  //TODO Serialize game objects.

  game -> clean();
  delete [] game;
  delete [] player;

}
