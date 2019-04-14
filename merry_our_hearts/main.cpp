# include "MOHEngine.h"
using namespace MOHEngine;
Game* game = nullptr;
int main(){
  game = new Game();
  
  while(game -> running()){
    game -> handleEvents();
    game -> update();
    game -> draw();
  }
  game -> clean();
}
