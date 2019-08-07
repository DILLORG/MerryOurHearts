# include "MOHEngine.h"
# include <gtest/gtest.h>


TEST(ItemConstructorTest, GoodInput){
  Item item = Item("res", 1, 4, 5, 6, "Give Health");
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
