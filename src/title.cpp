
#include <stdio.h>

#include "SDL/SDL.h"
#include "SDL_image.h"
#include <FMOD/fmod.h>
#include "gameengine.h"
#include "gamestate.h"
#include "title.h"
#include "character.h"

void Title::Init(GameEngine* game)
{
     image1=ChargementImage("IMG/title.png");
     image2=ChargementImage("IMG/cursor.pcx");
     image02.x = 300;
     image02.y = 515;
     fondu = SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 600, 32, 0, 0, 0, 0);
     SDL_FillRect(fondu, NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
     musique1 = FSOUND_Stream_Open("SOUND/music.mp3", 0, 0, 0);
     sonCurseurDeplacement = FSOUND_Sample_Load(FSOUND_FREE, "SOUND/cursormove.wav", 0, 0, 0);
     sonCurseurValider = FSOUND_Sample_Load(FSOUND_FREE, "SOUND/cursorselect.wav", 0, 0, 0);

     positionCurseur = 1;
	 quit = false;


}

void Title::Cleanup()
{
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	SDL_FreeSurface(fondu);

	FSOUND_Sample_Free(sonCurseurDeplacement);
	FSOUND_Sample_Free(sonCurseurValider);
	FSOUND_Stream_Close(musique1);
}

void Title::Pause()
{

}

void Title::Resume()
{

}

void Title::HandleEvents(GameEngine* game)
{
     /*la majorité du code de l'écran titre se trouve ici (mise à jour des images inclue)
     étant donné le fonctionnement de l'écran titre

     la méthode de gestion des évènements de l'exploration peut également s'appliquer, mais il faut
     penser à inclure des variables static de fonction et "simuler" la répétition des touches
     après un certain temps appuyé sur une des deux touches (haut/bas)

     Ce type de code devra être simulé lors des combats si la jauge ATB reste active
     pendant la gestion des commandes*/

     SDL_EnableKeyRepeat(400, 100);
     int tempsPrecedent = 0, tempsActuel = 0;
     FSOUND_Stream_Play(FSOUND_FREE, musique1);
     SDL_BlitSurface(image1,NULL,SDL_GetVideoSurface(),NULL);
     SDL_BlitSurface(image2,NULL,SDL_GetVideoSurface(),&image02);
     SDL_UpdateRect(game->screen, 0, 0, 0, 0);

     //SDL_EventState(SDL_KEYDOWN, SDL_IGNORE); //Désactive et annule les anciens évènements
     SDL_EventState(SDL_KEYDOWN, SDL_ENABLE); // Réactive les évènements

     while ( quit==false  && positionCurseur != 0 )

     {

           //Tant qu'il y a un événement
           while( SDL_WaitEvent( &game->event ) ) //////ON ATTEND QU'UN EVENEMENT SE DECLBNCHE POUR EXECUTER LES ACTIONS EN DESSOUS
           {
                  switch (game->event.type)
                  {
                         //A retirer lorsque phase de test terminée
                         case SDL_QUIT: //Si l'utilisateur a cliqué sur le X de la fenêtre

                                            //On quitte the programme
                                             quit = true;



                                            break;
                         case SDL_KEYDOWN:
                              switch (game->event.key.keysym.sym)
                              {
                                     case SDLK_DOWN:
                                           FSOUND_PlaySound(FSOUND_FREE, sonCurseurDeplacement);
                                           positionCurseur++;
                                           if ( positionCurseur > 2 )
                                           {
                                                positionCurseur = 1;
                                           }
                                           SDL_Delay(10);
                                           break;

                                     case SDLK_UP:
                                           FSOUND_PlaySound(FSOUND_FREE, sonCurseurDeplacement);
                                           positionCurseur--;
                                           if ( positionCurseur < 1 )
                                           {
                                                positionCurseur = 2;
                                           }
                                           break;
                                     case SDLK_RETURN:
                                          FSOUND_PlaySound(FSOUND_FREE, sonCurseurValider);
                                          FSOUND_Stream_Stop(musique1);
                                          positionCurseur = 0;
                                          break;
                                    default:;

                              }


                  }

                  if (positionCurseur == 0 && quit==false )
                  {
                                 for (int i = 0 ; i <= 255 ; i+=24) // transition noir
                                 {
                                 alpha = i;
                                 SDL_SetAlpha(fondu, SDL_SRCALPHA, alpha);
                                 SDL_BlitSurface(image1,NULL,SDL_GetVideoSurface(),NULL);
                                 SDL_BlitSurface(image2,NULL,SDL_GetVideoSurface(),&image02);
                                 SDL_BlitSurface(fondu, NULL, SDL_GetVideoSurface(), NULL);

                                 SDL_UpdateRect(game->screen, 0, 0, 0, 0);

                                 tempsPrecedent = tempsActuel;

                                 while( tempsActuel - tempsPrecedent < 1000 / FRAMES_PER_SECOND )
                                 {
                                  tempsActuel = SDL_GetTicks();
                                 }

                                  }

                                 alpha = 255;
                                 SDL_SetAlpha(fondu, SDL_SRCALPHA, alpha);
                                 SDL_BlitSurface(fondu, NULL, SDL_GetVideoSurface(), NULL);
                                 SDL_UpdateRect(game->screen, 0, 0, 0, 0);
                                 break;

                  }

                  if ( positionCurseur == 1 && quit==false )
                  {
                  image02.x = 300;
                  image02.y = 515;
                  }
                  if ( positionCurseur == 2 && quit==false)
                  {
                  image02.x = 300;
                  image02.y = 539;
                  }
                  if ( positionCurseur != 0 && quit==false)
                  {
                  SDL_BlitSurface(image1,NULL,SDL_GetVideoSurface(),NULL);
                  SDL_BlitSurface(image2,NULL,SDL_GetVideoSurface(),&image02);
                  SDL_UpdateRect(game->screen, 0, 0, 0, 0);
                  }
                  break;
           }


     }
     game->Quit();



}

void Title::Update(GameEngine* game)
{

}

void Title::Draw(GameEngine* game)
{

}


SDL_Surface *Title::ChargementImage( std::string filename )
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

SDL_Surface *Title::ChargementImageAlpha( std::string filename ) ///A UTILISER AVEC IMAGE AYANT COUCHE ALPHA
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

