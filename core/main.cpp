# include "MOHEngine.h"
# include <iostream>
using namespace MOHEngine;
int main(){
  Item item = Item("res", "Potion", 1, 3, 5, 7, "Gives Health");
  Item item2 = Item("res", "Ether", 1, 3, 5, 7, "Gives MP");
  Enemy bat = Enemy("res", "Bat", 1, 3, 5, 200);
  bat.addToInventory(&item);
  bat.addToInventory(&item2);
  bat.showInventory();
  bat.print();
  Player player = Player("res", "Player", 5, 1, 3, 100);
  Game game = Game();

  while(true){
    MOHEngine::update_screen(&player, &game);
    
  }
}
