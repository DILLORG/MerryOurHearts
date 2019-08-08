# include "../merry_our_hearts/MOHEngine.h"
# include <gtest/gtest.h>


TEST(ConstructorTest, GoodInput){

  ASSERT_NO_FATAL_FAILURE(MOHSprite("res", "Standard sprite", 1, 4, 5));
  ASSERT_NO_FATAL_FAILURE(Item("res", "Potion", 1, 4, 5, 6, "Give Health"));
  ASSERT_NO_FATAL_FAILURE(Enemy("res","Bat", 2, 4, 5, 200));
  ASSERT_NO_FATAL_FAILURE(Player("res", "Player", 2, 4, 5, 200));

}

TEST(AddItemToInventory, GoodInput){
  Enemy enemy = Enemy("res","Bat", 1 , 4, 5, 1000);
  Item item = Item("res","Potion", 1, 4, 6, 200, "Hello");
  Player player = Player("res", "Player", 1, 5, 6, 200);
  ASSERT_NO_THROW(enemy.addToInventory(&item));
  ASSERT_NO_THROW(player.addToInventory(&item));
  enemy.showInventory();
  

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
