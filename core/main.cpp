/**************************************************
NOM: ULTIMATE ABYSS
TYPE: RPG 2D
AUTEUR: ######### #####
------------------------------------------
BOUCLE PRINCIPALE DU JEU FICHIER DE DEPART
**************************************************/

#include "gameengine.h"
#include "start.h"
#include "field.h"
#include "menu.h"

#include <GL/gl.h>
#include <GL/glu.h>


#include <cstdlib>
#define LARGEUR_BASE 50
#define HAUTEUR_BASE 20

#define LARGEUR_BRAS_1 150
#define HAUTEUR_BRAS_1 15

#define LARGEUR_BRAS_2 50
#define HAUTEUR_BRAS_2 10

#define TAILLE_CAISSE 10

#define LARGEUR_ECRAN (LARGEUR_BASE + LARGEUR_BRAS_1 + HAUTEUR_BRAS_2 + 50)
#define HAUTEUR_ECRAN ( + LARGEUR_BRAS_1 + HAUTEUR_BRAS_2 + 50)




using namespace std;



int main ( int argc, char *argv[] )
{
	GameEngine game;
	// initialisation du jeu
	game.Init( "Ultimate Abyss" );
	// load the intro
	//game.ChangeState(new Start());
	//game.ChangeState(new Field());
	game.ChangeState(new Menu());



	// main loop
	while ( game.Running() )
	{
		game.HandleEvents();
		game.Update();
		game.Draw();

		SDL_Delay(1000/game.getFramesPerSecond());

	}


	// cleanup the engine
	game.Cleanup();

	return 0;
}

