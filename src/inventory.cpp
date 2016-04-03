
#include <stdio.h>

#include "SDL/SDL.h"
#include "inventory.h"
#include "item.h"
using namespace std;

void Inventory::Init()
{

    potion.Init(101, "potion", "heals 100 HP", 5, "ALL");
    hiPotion.Init(102, "Hi-Potion", "heals 500 HP", 2, "ALL");

    busterSword.Init(501, "Buster Sword", "Starting weapon", 1, "NULL", 23, 0);


}



map<int,Item> Inventory::getNormalItemsInventoryList()
{
    return normalItemsPosition;
}
