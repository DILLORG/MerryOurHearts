# include "MOHEngine.h"
int main() {
  ifstream myList;
  Player player = Player("res", "Player", 1, 3, 5, 7);
  myList.open("list.csv");
  MOHEngine::item_spawner(myList, player);
  return 0;
}
