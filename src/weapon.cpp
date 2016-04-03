#include <stdio.h>

#include "SDL/SDL.h"
#include "weapon.h"
#include "item.h"
using namespace std;

void Weapon::Init(int id, string name, string description, int quantity, string usability, int attack, int slots)
{
    this->id = id;
    this->name = name;
    this->description = description;
    this->quantity = quantity;
    this->usability = usability;
    this->attack = attack;
    this->slots = slots;
}
