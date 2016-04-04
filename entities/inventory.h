#ifndef INVENTORY_H
#define INVENTORY_H

#include <String>
#include <map>
using namespace std;

#include "item.h"
#include "weapon.h"
#include "helmet.h"
#include "armor.h"
#include "accessory.h"

//Classe servant à enregistrer la position dans le jeu (switchs) et supervise l'ordre des évènements

class Inventory
{

      public:

        void Init();
        bool WeaponEmptyCheck();
        int WeaponVectorSize();
        string WeaponName();
        vector<Weapon> weapon;

        map<int,Item> getNormalItemsInventoryList();



      private:

        //Normal items

        //Heal items

        Item potion;
        Item hiPotion;
        Item xPotion;
        Item ether;
        Item turboEther;
        Item elixer;
        Item megalixer;
        Item phoenixDown;
        Item antidote;
        Item eyeDrop;
        Item soft;
        Item maidensKiss;
        Item echoScreen;
        Item cornucopia;
        Item remedy;
        Item fury;
        Item tranquilizer;
        Item tent;

        //Bonus items

        Item powerSource;
        Item guardSource;
        Item magicSource;
        Item mindSource;
        Item speedSource;
        Item luckSource;



        //Key Items

        map<int, Item> normalItemsPosition;
        map<int, Item> keyItemsPosition;
        map<int, Item> weaponsPosition;
        map<int, Item> helmetsPosition;
        map<int, Item> armorsPosition;
        map<int, Item> accessoriesPosition;

        //Weapons

        //Kholkir weapons

        Weapon busterSword;
        Weapon mythrilSaber;
        Weapon hardEdge;
        Weapon forceStealer;
        Weapon butterflyEdge;
        Weapon runeBlade;
        Weapon enhanceSword;
        Weapon murasame;
        Weapon yoshiyuki;
        Weapon organics;
        Weapon nailBat;
        Weapon crystalSword;
        Weapon apocalypse;
        Weapon heavensCloud;
        Weapon ragnarok;
        Weapon ultimaWeapon;

        //Zika weapons

        Weapon guardStick;
        Weapon mythrilRod;
        Weapon fullMetalStaff;
        Weapon wizardStaff;
        Weapon strikingStaff;
        Weapon wizerStaff;
        Weapon fairyTale;
        Weapon prismStaff;
        Weapon auroraRod;
        Weapon princessGuard;



};


#endif
