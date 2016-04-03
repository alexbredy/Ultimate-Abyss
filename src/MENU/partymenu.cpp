#include <stdio.h>
#include <String>
#include "SDL/SDL.h"

#include <iostream>
#include <sstream>

#include "partymenu.h"
#include "../DATA/imagesetup.h"
#include "../display.h"

void PartyMenu::Init()
{
    id=1;
    name = "Party";
    background = ChargementImageAlpha("IMG/party.png");
    menuPane = ChargementImageAlpha("IMG/menuPane.png");
    characterPane = ChargementImageAlpha("IMG/characterPane.png");
    up = true;
    down = true;
    right = false;
    left = false;
    keyRepeat=true;
    repeating=false;
    delayBeforeRepeat=20;
    delayBetweenRepeat=4;
    currentDelayIndex=0;
    columnTotalNumber=1;
    lineTotalNumber=11;
    currentColumn=1;
    currentLine=1;
    cursorXOrigin=955;
    cursorYOrigin=68;
    cursorXPosition=cursorXOrigin;
    cursorYPosition=cursorYOrigin;
    cursorXVariation=0;
    cursorYVariation=37;
    previousCommand="";

    menuPaneYVariation=0;
    menuPaneXVariation=0;
    charPaneXVariation=0;
    charPaneYVariation=0;

    text.setClipWidthHeight(39,55);
    text.setFieldClipWidthHeight(55,55);
    text.setSymbolPixelSpace(21);
    text.setWordPixelSpace(17);
    text.setVerticalPixelSpace(40);

}

void PartyMenu::openAnimation()
{
    for(int variation=0;variation<200;variation+=10)
    {
        menuPaneYVariation-=40;
        charPaneXVariation-=60;
        SDL_Delay(1000/60);
    }
    showCursor();
    SDL_EventState(SDL_KEYDOWN, SDL_ENABLE);


}

void PartyMenu::closeAnimation()
{
    hideCursor();
    for(int variation=0;variation<200;variation+=10)
    {
        menuPaneYVariation+=40;
        charPaneXVariation+=60;
        SDL_Delay(1000/60);
    }

}

void PartyMenu::upCommand()
{
    if(!repeatLoopActivated)
    {
        currentLine--;
        if(currentLine<1)
        {
            currentLine=11;
        }
        repeatLoopActivated=true;
        updateCursor();
    }
    else
    {
        currentDelayIndex++;
        if(!repeating)
        {
            if(currentDelayIndex==delayBeforeRepeat)
            {
                repeating=true;
                currentDelayIndex=0;
                currentLine--;
                if(currentLine<1)
                {
                    currentLine=11;
                }
                updateCursor();
            }
        }
        else
        {
            if(currentDelayIndex==delayBetweenRepeat)
            {
                currentDelayIndex=0;
                currentLine--;
                if(currentLine<1)
                {
                    currentLine=11;
                }
                updateCursor();
            }
        }
    }



}

void PartyMenu::downCommand()
{
    if(!repeatLoopActivated)
    {
        currentLine++;
        if(currentLine>lineTotalNumber)
        {
            currentLine=1;
        }
        repeatLoopActivated=true;
        updateCursor();
    }
    else
    {
        currentDelayIndex++;
        if(!repeating)
        {
            if(currentDelayIndex==delayBeforeRepeat)
            {
                repeating=true;
                currentDelayIndex=0;
                currentLine++;
                if(currentLine>lineTotalNumber)
                {
                    currentLine=1;
                }
                updateCursor();
            }
        }
        else
        {
            if(currentDelayIndex==delayBetweenRepeat)
            {
                currentDelayIndex=0;
                currentLine++;
                if(currentLine>lineTotalNumber)
                {
                    currentLine=1;
                }
                updateCursor();
            }
        }
    }



}

void PartyMenu::rightCommand()
{
}

void PartyMenu::leftCommand()
{
}

void PartyMenu::display()
{
    SDL_SetAlpha(cursor, SDL_SRCALPHA, 0);
    SDL_Rect cursorCoordinates;
    cursorCoordinates.x=cursorXPosition;
    cursorCoordinates.y=cursorYPosition;

    SDL_BlitSurface(background,NULL,SDL_GetVideoSurface(),NULL);
    displayImage(characterPane,85+charPaneXVariation,78);
    displayCharacterData();
    displayImage(menuPane,983,40+menuPaneYVariation);
    if(cursorOpaque)
    {
        SDL_BlitSurface(cursor,NULL,SDL_GetVideoSurface(),&cursorCoordinates);
    }
    displayMenuList();
    text.displayWord("01234567890 9999 9999",500,300);
}

void PartyMenu::updateCursor()
{
    cursorXPosition+=0;
    cursorYPosition=cursorYOrigin+cursorYVariation*(currentLine-1); //On commence à la colonne 1 donc pas d'incrémentation à la position 1 (index 0))
}

void PartyMenu::displayMenuList()
{
    text.displayWord("Objets",1010,53+menuPaneYVariation);
    text.displayWord("Magie",1010,90+menuPaneYVariation);
    text.displayWord("Materia",1010,127+menuPaneYVariation);
    text.displayWord("Equiper",1010,164+menuPaneYVariation);
    text.displayWord("Etat",1010,201+menuPaneYVariation);
    text.displayWord("Limite",1010,238+menuPaneYVariation);
    text.displayWord("Carnet",1010,275+menuPaneYVariation);
    text.displayWord("Formation",1010,312+menuPaneYVariation);
    text.displayWord("Options",1010,349+menuPaneYVariation);
    text.displayWord("Enregistrer",1010,387+menuPaneYVariation);
    text.displayWord("Quitter",1010,423+menuPaneYVariation);
}

void PartyMenu::displayCharacterData()
{
    stringstream value;
    string symbols;
    if(character1!=NULL)
    {
        //display fields name (Nv HP MP niveau suivant PC)
        displayImage(character1->getFaceImage(),93+charPaneXVariation,86);

        //HP
        text.displayField("HP", 290+charPaneXVariation, 133);

        value << character1->getStats().getHp();
        value >> symbols;
        text.displayWord(symbols, 395-text.getWordPixelSpace()*(symbols.length()-1)+charPaneXVariation, 133);
        value.clear();
        value << character1->getStats().getHpMax();
        value >> symbols;
        text.displayWord(symbols, 395+text.getWordPixelSpace()*(symbols.length()-1)+charPaneXVariation, 133);
        value.clear();


        //MP
        text.displayField("MP", 290+charPaneXVariation, 176);
        value << character1->getStats().getMp();
        value >> symbols;
        text.displayWord(symbols, 395-text.getWordPixelSpace()*(symbols.length()-1)+charPaneXVariation, 176);
        value.clear();
        value << character1->getStats().getMpMax();
        value >> symbols;
        text.displayWord(symbols, 430+text.getWordPixelSpace()*(symbols.length()-1)+charPaneXVariation, 176);
        value.clear();

        //AP
        text.displayField("AP", 520+charPaneXVariation, 176);

        //display character data
        text.displayWord(character1->getName(),290+charPaneXVariation,90);
        text.displayField("HP", 290+charPaneXVariation, 322);
        text.displayField("MP", 290+charPaneXVariation, 365);
        text.displayField("AP", 520+charPaneXVariation, 365);

    }
    if(character2!=NULL)
    {
        text.displayWord(character2->getName(),290+charPaneXVariation,275);

    }
    if(character3!=NULL)
    {
        text.displayWord(character3->getName(),290+charPaneXVariation,460);
    }
}

void PartyMenu::setCharacters(Character* char1, Character* char2, Character* char3)
{
    character1=char1;
    character2=char2;
    character3=char3;
}

void PartyMenu::setCharPaneXVariation(int value)
{
    charPaneXVariation=value;
}

void PartyMenu::setCharPaneYVariation(int value)
{
    charPaneYVariation=value;

}

void PartyMenu::setMenuPaneXVariation(int value)
{
    menuPaneXVariation=value;
}

void PartyMenu::setMenuPaneYVariation(int value)
{
    menuPaneYVariation=value;
}

