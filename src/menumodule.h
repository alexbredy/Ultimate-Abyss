/**************************************************
CLASSE MERE GERANT LES VARIABLES ET FONCTIONS
COMMUNES DES DIFFERENTS MENUS
**************************************************/

#ifndef MENUMODULE_H
#define MENUMODULE_H

#include <String>
#include <SDL.h>
#include "character.h"
#include "text.h"


class MenuModule
{

      public:

      virtual void openAnimation()=0;
      virtual void closeAnimation()=0;
      virtual void upCommand()=0;
      virtual void downCommand()=0;
      virtual void rightCommand()=0;
      virtual void leftCommand()=0;
      virtual void display()=0;
      virtual void updateCursor()=0;
      virtual void setCharacters(Character* char1, Character* char2, Character* char3)=0;


      //Inutile mais permet d'�viter les warnings du compilateur (erreur de compilateur)
      virtual ~MenuModule(){}

      int getId();
      string getName();

      int getCursorXPosition();
      int getCursorYPosition();
      int getCursorXVariation();
      int getCursorYVariation();

      bool upIsEnabled();
      bool downIsEnabled();
      bool rightIsEnabled();
      bool leftIsEnabled();


      void setCursorImage(SDL_Surface* cursor);
      void showCursor();
      void hideCursor();

      Text& getText();


      string getPreviousCommand();
      void setPreviousCommand(string direction);

      bool upExecuted();
      bool downExecuted();
      bool rightExecuted();
      bool leftExecuted();

      void setUpExecuted(bool value);
      void setDownExecuted(bool value);
      void setRightExecuted(bool value);
      void setLeftExecuted(bool value);

      void setRepeatLoopActivated(bool value);
      void setRepeating(bool value);
      void setCurrentDelayIndex(int value);

      protected:

      int id;
      string name;

      //Matrice des positions du menu - la valeur la plus inf�rieure est haut gauche (0,0)
      int columnTotalNumber;
      int lineTotalNumber;

      //Valeurs actuelles de la position du curseur
      int currentColumn;
      int currentLine;

      bool cursorOpaque;
      int cursorXOrigin;
      int cursorYOrigin;
      int cursorXPosition;
      int cursorYPosition;
      int cursorXVariation;
      int cursorYVariation;

      bool up;
      bool down;
      bool right;
      bool left;

      //Variables importantes relatives � la gestion du curseur d�s que deux ou plusieurs fl�ches directionnelles sont appuy�es
      string previousCommand;
      bool upPreviouslyExecuted;
      bool downPreviouslyExecuted;
      bool rightPreviouslyExecuted;
      bool leftPreviouslyExecuted;



      ///Variables g�rant la r�p�tition des touches

      //variable permettant de v�rifier si on peut tenir appuy� sur une touche
      bool keyRepeat;
      //Variable permettant de rep�rer si le processus de r�p�tition des touches est activ�e
      bool repeatLoopActivated;
      //variable permettant de rep�rer si le processus de r�p�tition est en cours (le d�lai initial est pass�)
      bool repeating;

      SDL_Surface* cursor;
      //Temps qui doit �tre pass� pour activer la r�p�tition de l'ex�cution d'une touche
      int delayBeforeRepeat;
      int delayBetweenRepeat;
      int currentDelayIndex;

      //Autres classes incluses dans le menu

      Text text;





}
;


#endif
