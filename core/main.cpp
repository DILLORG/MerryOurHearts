# include "Game.h"
int main(){
  Enemy enemy = Enemy("res", "Bat", 5, 5, 7, 100);
  Player player = Player("res", "Dylan", 5, 4, 4, 100);
  Item item = Item("res", "Potion", 5, 4, 4, 6, "Add Health");
  enemy.add_to_inventory(&item);
  player.add_to_inventory(&item);
  enemy.show_inventory();


}
