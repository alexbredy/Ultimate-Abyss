#include <stdio.h>
#include <String>
#include <iostream>

#include "SDL/SDL.h"
#include "../gameengine.h"
/*OBLIGATOIRE!! la d�claration de la classe dans character.h ne nous permet pas de travailler
sur ladite classe d'o� l'obligation d'include le fichier ici (et la d�claration cyclique n'existe plus �tant donn� que nous
sommes dans le .cpp*/
#include "sounddata.h"
using namespace std;

void SoundData::Init()
{
    cursorMove = FSOUND_Sample_Load(FSOUND_FREE, "SOUND/cursormove.wav", 0, 0, 0);

}
