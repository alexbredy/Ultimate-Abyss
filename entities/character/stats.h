#ifndef STATS_H
#define STATS_H

#include <String>
using namespace std;

class Stats
{


      public:

      void setLevel(int value);
      void setHp(int value);
      void setHpMax(int value);
      void setMp(int value);
      void setMpMax(int value);
      void setCp(int value);
      void setCpMax(int value);
      void setStrength(int value);
      void setMagic(int value);
      void setDefense(int value);
      void setMagicDefense(int value);
      void setAgility(int value);
      void setEvasion(int value);


      int getLevel();
      int getHp();
      int getHpMax();
      int getMp();
      int getMpMax();
      int getCp();
      int getCpMax();
      int getStrength();
      int getMagic();
      int getAgility();
      int getEvasion();
      int getDefense();
      int getMagicDefense();


      private:

      int level;

      int hp;
      int hpMax;
      int mp;
      int mpMax;
      //capacity points
      int cp;
      int cpMax;

      int strength;
      int magic;
      int agility;
      int evasion;

      int defense;
      int magicDefense;







};


#endif
