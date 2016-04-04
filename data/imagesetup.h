#ifndef IMAGESETUP_H
#define IMAGESETUP_H

#include <String>

SDL_Surface* ChargementImage( std::string filename );
SDL_Surface* ChargementImageAlpha( std::string filename ); ///A UTILISER AVEC IMAGE AYANT COUCHE ALPHA


#endif
