#ifndef WEAPON_H
#define WEAPON_H

#include <String>
#include <vector>
#include "item.h"
using namespace std;

//Classe servant à enregistrer la position dans le jeu (switchs) et supervise l'ordre des évènements

class Weapon: public Item
{

      public:

      void Init(int id, string name, string description, int quantity, string usability, int attack, int slots);





      protected:


      private:

      int attack;
      int slots;
      int numberEquiped;






};


#endif
