# include "../core/MOHEngine.h"
# include <gtest/gtest.h>

TEST(ConstructorTest, GoodInput){

  ASSERT_NO_FATAL_FAILURE(MOHSprite("res", "Standard sprite", 1, 4, 5));
  ASSERT_NO_FATAL_FAILURE(Item("res", "Potion", 1, 4, 5, 6, "Give Health"));
  ASSERT_NO_FATAL_FAILURE(Enemy("res","Bat", 2, 4, 5, 200));
  ASSERT_NO_FATAL_FAILURE(Player("res", "Player", 2, 4, 5, 200));

}
TEST(ItemsSpawner, GoodInput){
    ifstream spawnList;
    spawnList.open("testList.csv");
    Player player = Player("res", "Player", 2, 4, 5, 200);
    MOHEngine::item_spawner(spawnList, player);

}

TEST(AddToEnemyInventory, GoodInput){
  Enemy enemy = Enemy("res","Bat", 1 , 4, 5, 1000);
  Item item = Item("res","Potion", 1, 4, 6, 200, "Add to Health");
  ASSERT_NO_THROW(enemy.add_to_inventory(&item));
}

TEST(AddToPlayerInventory, GoodInput){
  Player player = Player("res", "PLayer", 5, 4, 6, 100);
  Item item = Item("res","Potion", 1, 4, 6, 200, "Add to Health");
  ASSERT_NO_THROW(player.add_to_inventory(&item));
}

TEST(ItemsSpawnerTest, GoodInput){
  ifstream spawnList("testList.csv");
  Player player = Player("res", "PLayer", 5, 4, 6, 100);
  ASSERT_NO_THROW(MOHEngine::item_spawner(spawnList, player));
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
