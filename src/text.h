#ifndef TEXT_H
#define TEXT_H

#include <String>
#include "SDL/SDL.h"

using namespace std;

class Text
{
    public:

    void setClipWidthHeight(int width, int height);
    void setFieldClipWidthHeight(int width, int height);

    void displaySymbol(string symbol, int x, int y);
    void displayWord(string word, int x, int y);
    void write(string text);
    void displayField(string field, int x, int y);

    void setSymbolClip(string symbol);
    void setFieldClip(string field);
    void setSymbolPixelSpace(int value);
    void setWordPixelSpace(int value);
    int getWordPixelSpace();
    void setVerticalPixelSpace(int value);

    void setFont(SDL_Surface* font);
    void setMenuFieldsImage(SDL_Surface* menuFields);


    private:

    SDL_Surface* font;
    SDL_Surface* menuFields;
    SDL_Rect symbolClip;
    SDL_Rect menuFieldsClip;
    int xCoordinate;
    int yCoordinate;
    int symbolPixelSpace;
    int wordPixelSpace;
    int verticalPixelSpace;


};


#endif

