
#include <stdio.h>

#include "SDL/SDL.h"
#include "SDL_image.h"
#include <FMOD/fmod.h>
#include "gameengine.h"
#include "gamestate.h"
#include "start.h"
#include "title.h"
#include "character.h"


void Start::Init(GameEngine* game)
{
     image1=ChargementImage("IMG/production.png");
     fondu = SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 600, 32, 0, 0, 0, 0);
     SDL_FillRect(fondu, NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));

     alpha = 255;

     SDL_SetAlpha(fondu, SDL_SRCALPHA, alpha);




//Appel de fonctions flash screens de présentation
//changement de state vers title screen

}

void Start::Cleanup()
{
     SDL_FreeSurface(image1);
     SDL_FreeSurface(fondu);



}

void Start::Pause()
{

}

void Start::Resume()
{

}

void Start::HandleEvents(GameEngine* game)
{

}

void Start::Update(GameEngine* game)
{
     //Dans cette classe, la fonction Update servira uniquement à lancer la présentation du début
/*
     int tempsPrecedent = 0, tempsActuel = 0, tempsTransition = 4000;

     tempsActuel = SDL_GetTicks();
     tempsPrecedent = tempsActuel;

     while( tempsActuel - tempsPrecedent < 1000 )
          {


                 tempsActuel = SDL_GetTicks();
          }
          tempsPrecedent = tempsActuel;

     for (int i = 255 ; i >= 0 ; i--)
     {
         alpha = i;
         SDL_SetAlpha(fondu, SDL_SRCALPHA, alpha);
         SDL_BlitSurface(image1,NULL,SDL_GetVideoSurface(),NULL);
         if (alpha != 0)
                  SDL_BlitSurface(fondu, NULL, SDL_GetVideoSurface(), NULL);

         SDL_UpdateRect(game->screen, 0, 0, 0, 0);

         if (alpha != 0)
         {
                   while( tempsActuel - tempsPrecedent < tempsTransition/(255) )
                   {
                          tempsActuel = SDL_GetTicks();
                   }
                   tempsPrecedent = tempsActuel;
         }
     }

     while( tempsActuel - tempsPrecedent < 1000 )
                   {
                          tempsActuel = SDL_GetTicks();
                   }
                   tempsPrecedent = tempsActuel;

     for (int i = 0 ; i <= 255 ; i++)
     {
         alpha = i;
         SDL_SetAlpha(fondu, SDL_SRCALPHA, alpha);
         if (alpha != 255)
                  SDL_BlitSurface(image1,NULL,SDL_GetVideoSurface(),NULL);

         SDL_BlitSurface(fondu, NULL, SDL_GetVideoSurface(), NULL);
         SDL_UpdateRect(game->screen, 0, 0, 0, 0);

         if (alpha != 255)
         {
                   while( tempsActuel - tempsPrecedent < tempsTransition/(255) )
                   {
                          tempsActuel = SDL_GetTicks();
                   }
                   tempsPrecedent = tempsActuel;
         }
          tempsPrecedent = tempsActuel;

     }
*/

       game->ChangeState(new Title());






}

void Start::Draw(GameEngine* game)
{

}

SDL_Surface *Start::ChargementImage( std::string filename )
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load( filename.c_str() );

    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
        if( optimizedImage != NULL )
        {
            SDL_SetColorKey( optimizedImage, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }


    return optimizedImage;
}

SDL_Surface *Start::ChargementImageAlpha( std::string filename ) ///A UTILISER AVEC IMAGE AYANT COUCHE ALPHA
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load( filename.c_str() );

    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );
        SDL_FreeSurface( loadedImage );
        if( optimizedImage != NULL )
        {
            SDL_SetColorKey( optimizedImage, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }


    return optimizedImage;
}
