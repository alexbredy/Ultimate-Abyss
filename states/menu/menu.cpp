#include "SDL/SDL.h"
#include "SDL_image.h"
#include <FMOD/fmod.h>
#include <iostream>
#include "gameengine.h"
#include "gamestate.h"

#include "menu.h"
#include "character.h"
#include "inventory.h"
#include "weapon.h"

#include "vector"
using namespace std;

void Menu::Init(GameEngine* game)
{

    menu = game->getSystem().getCurrentMenu();

    //2 lignes dessous à replacer ailleurs pour éviter la répétition
    menu->setCursorImage(game->getSystem().getCursorImage());
    menu->getText().setFont(game->getSystem().getFontImage());
    menu->getText().setMenuFieldsImage(game->getSystem().getMenuFieldsImage());

    upKey=false;
    downKey=false;
    leftKey=false;
    rightKey=false;
    menu->setRepeatLoopActivated(false);
    menu->setRepeating(false);
    menu->setCurrentDelayIndex(0);

    if(menu->getId()==1)
    {
        menu->hideCursor();
        SDL_EventState(SDL_KEYDOWN, SDL_IGNORE);
        menu->setCharacters(game->getSystem().getCharacter1(),game->getSystem().getCharacter2(),game->getSystem().getCharacter3());
        game->getSystem().getMenuData().getPartyMenu().setCharPaneXVariation(1200);
        game->getSystem().getMenuData().getPartyMenu().setCharPaneYVariation(0);
        game->getSystem().getMenuData().getPartyMenu().setMenuPaneXVariation(0);
        game->getSystem().getMenuData().getPartyMenu().setMenuPaneYVariation(800);

    }

    pthread_create(&animation,NULL,callOpenAnimation,menu);


}

void Menu::Cleanup()
{
}

void Menu::Pause()
{

}

void Menu::Resume()
{

}

void Menu::HandleEvents(GameEngine* game)
{
    while( SDL_PollEvent( &game->event ) )
    {
if( game->event.type == SDL_KEYDOWN )
        {

            switch( game->event.key.keysym.sym )
            {

                case SDLK_UP:
                {
                    upKey=true;
                    break;
                }
                case SDLK_DOWN:
                {
                    downKey=true;
                    break;
                }
                case SDLK_LEFT:
                {
                    leftKey=true;
                    break;
                }
                case SDLK_RIGHT:
                {
                    rightKey=true;
                    break;
                }
                case SDLK_RETURN:
                {
                    pthread_create(&animation,NULL,callOpenAnimation,menu);
                    break;

                }
                case SDLK_ESCAPE:
                {
                    pthread_create(&animation,NULL,callCloseAnimation,menu);
                    break;

                }
                default:{};


            }
        }

        if(game->event.type == SDL_KEYUP)
        {
            switch( game->event.key.keysym.sym )
            {

                case SDLK_UP:
                {
                    upKey=false;
                    menu->setUpExecuted(false);
                    break;
                }
                case SDLK_DOWN:
                {
                    downKey=false;
                    menu->setDownExecuted(false);
                    break;
                }
                case SDLK_LEFT:
                {
                    leftKey=false;
                    menu->setLeftExecuted(false);
                    break;
                }
                case SDLK_RIGHT:
                {
                    rightKey=false;
                    menu->setRightExecuted(false);
                    break;
                }
                case SDLK_RETURN:
                {
                    break;
                }
                default:{};


            }
        }

        if( game->event.type == SDL_QUIT )
        {
            //On quitte le programme
            game->Quit();
        }

    }




}

void Menu::Update(GameEngine* game)
{

    if(!checkAllDisabled())
    {
        if(upKey && !leftKey && !rightKey && !downKey)
        {
            if(menu->upIsEnabled())
            {
                menu->setPreviousCommand("up");
                menu->setUpExecuted(true);
                menu->upCommand();
            }
        }
        else if(!upKey && !leftKey && !rightKey && downKey)
        {
            if(menu->downIsEnabled())
            {
                menu->setPreviousCommand("down");
                menu->setDownExecuted(true);
                menu->downCommand();
            }
        }
        else if(!upKey && leftKey && !rightKey && !downKey)
        {
            if(menu->leftIsEnabled())
            {
                menu->setPreviousCommand("left");
                menu->setDownExecuted(true);
                menu->leftCommand();
            }
        }
        else if(!upKey && !leftKey && rightKey && !downKey)
        {
            if(menu->rightIsEnabled())
            {
                menu->setPreviousCommand("right");
                menu->setDownExecuted(true);
                menu->rightCommand();
            }
        }
        else if(upKey && leftKey && !rightKey && !downKey)
        {
            if(menu->getPreviousCommand()=="up")
            {
                if(menu->leftIsEnabled())
                {
                    if(!menu->leftExecuted())
                    {
                        menu->setPreviousCommand("left");
                        menu->setLeftExecuted(true);
                        menu->leftCommand();
                    }
                    else
                    {
                        menu->setUpExecuted(true);
                        menu->upCommand();
                    }
                }
                else
                {
                    menu->setUpExecuted(true);
                    menu->upCommand();
                }
            }

            else
            {
                menu->setPreviousCommand("up");
                menu->setUpExecuted(true);
                menu->upCommand();
            }
        }

    }
    else
    {
        menu->setPreviousCommand("");
        menu->setRepeatLoopActivated(false);
        menu->setRepeating(false);
        menu->setCurrentDelayIndex(0);
    }

}

void Menu::Draw(GameEngine* game)
{
    menu->display();
    SDL_UpdateRect(game->screen, 0, 0, 0, 0);


}

bool Menu::checkAllDisabled()
{
    return !upKey&&!downKey&&!rightKey&&!leftKey;
}

void* Menu::callOpenAnimation(void* data)
{
    MenuModule* mirror;
    mirror = (MenuModule*)data;
    mirror->openAnimation();
    return NULL;
}

void* Menu::callCloseAnimation(void* data)
{
    MenuModule* mirror;
    mirror = (MenuModule*)data;
    mirror->closeAnimation();
    return NULL;
}

