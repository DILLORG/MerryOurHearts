# include "MOHEngine.h"

using namespace MOHEngine;
Game* game = nullptr;
Player* player = nullptr;
int main(){

  game = new Game();
  player = new Player();

  //Main game loop.
  while(game -> running()){
    MOHEngine::handleEvents(player, game);
    MOHEngine::update(player, game);
    MOHEngine::draw(player, game);
  }
  //TODO Serialize game objects.

  game -> clean();
  delete [] game;
  delete [] player;


}
