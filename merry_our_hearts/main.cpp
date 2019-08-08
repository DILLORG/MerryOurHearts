# include "MOHSprites.h"
# include <iostream>
int main(){
  Item item = Item("res", 1, 3, 5, 7, "Gives Health");
  cout << item.getDescription();
}
