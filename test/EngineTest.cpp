# include "../merry_our_hearts/MOHEngine.h"
# include <gtest/gtest.h>


TEST(ItemConstructorTest, GoodInput){
  Item item = Item("res", 1, 4, 5, 6, "Give Health");


}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
