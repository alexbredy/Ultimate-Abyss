#ifndef ITEM_H
#define ITEM_H

#include <String>
#include <vector>
using namespace std;

//Classe servant à enregistrer la position dans le jeu (switchs) et supervise l'ordre des évènements

class Item
{

      public:

      void Init(int id, string name, string description, int quantity, string usability);



      int getItemID();
      string getItemName();
      string getItemDescription();
      int getItemQuantity();
      int getItemUsability();

      void setItemQuantity(int value);
      void appendItemQuantity(int value);






      protected:


      int id;
      string name;
      string description;
      int quantity;
      string usability;


      private:







}
;


#endif
