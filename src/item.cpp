#include <stdio.h>

#include "SDL/SDL.h"
#include "item.h"
using namespace std;

void Item::Init(int id, string name, string description, int quantity, string usability)
{
    this->id = id;
    this->name = name;
    this->description = description;
    this->quantity = quantity;
    this->usability = usability;

}
