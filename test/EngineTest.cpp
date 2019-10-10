# include "../core/Game.h"
# include <gtest/gtest.h>


TEST(ConstructorTest, GoodInput){

  ASSERT_NO_FATAL_FAILURE(Sprite("res", "Standard sprite", 1, 4, 5));
  ASSERT_NO_FATAL_FAILURE(Item("res", "Potion", 1, 4, 5, 6, "Give Health"));
  ASSERT_NO_FATAL_FAILURE(Enemy("res","Bat", 2, 4, 5, 200));
  ASSERT_NO_FATAL_FAILURE(Player("res", "Player", 2, 4, 5, 200));


}

TEST(CheckHealthGivesInvenoryToPlayer, EnemyDead){
  Enemy enemy = Enemy("res", "Bat", 1, 4, 5, 0);
  Player player = Player("res", "Dylan", 5, 6, 4, 100);
  Game game = Game(&player);
  game.spawner(&enemy);
  game.check_health();
  ASSERT_EQ(player.get_inventory(), enemy.get_inventory());
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


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
