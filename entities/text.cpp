#include <stdio.h>
#include <iostream>
#include <sstream>
#include "text.h"

void Text::setFont(SDL_Surface* font)
{
    this->font=font;
}

void Text::setMenuFieldsImage(SDL_Surface* menuFields)
{
    this->menuFields=menuFields;
}

void Text::setClipWidthHeight(int width, int height)
{
    symbolClip.w=width;
    symbolClip.h=height;
}

void Text::setFieldClipWidthHeight(int width, int height)
{
    menuFieldsClip.w=width;
    menuFieldsClip.h=height;
}


void Text::setSymbolPixelSpace(int value)
{
    symbolPixelSpace=value;
}

void Text::setWordPixelSpace(int value)
{
    wordPixelSpace=value;
}

int Text::getWordPixelSpace()
{
    return wordPixelSpace;
}

void Text::setVerticalPixelSpace(int value)
{
    verticalPixelSpace=value;
}

void Text::displaySymbol(string symbol, int x, int y)
{
    SDL_Rect coordinates;
    coordinates.x=x;
    coordinates.y=y;
    setSymbolClip(symbol);
    SDL_BlitSurface(font,&symbolClip,SDL_GetVideoSurface(),&coordinates);
}

void Text::displayWord(string word, int x, int y)
{
    xCoordinate=x;
    yCoordinate=y;
    for(int currentSymbol=0; word[currentSymbol] != '\0'; currentSymbol++)
    {
        if(word[currentSymbol]== ' ')
        {
            xCoordinate+=wordPixelSpace;
        }
        else if(word[currentSymbol]=='\n')
        {
            yCoordinate+=verticalPixelSpace;
            xCoordinate=x;
        }
        else
        {
            //conversion du char en string (symbole unique)
            stringstream ss;
            string symbol;
            ss<<word[currentSymbol];
            ss>>symbol;
            displaySymbol(symbol,xCoordinate,yCoordinate);
            xCoordinate+=symbolPixelSpace;
        }

    }



}

void Text::write(string word)
{

}

void Text::displayField(string field, int x, int y)
{
    SDL_Rect coordinates;
    coordinates.x=x;
    coordinates.y=y;
    setFieldClip(field);
    SDL_BlitSurface(menuFields,&menuFieldsClip,SDL_GetVideoSurface(),&coordinates);

}

void Text::setFieldClip(string field)
{
    if(field == "HP")
    {
        menuFieldsClip.x=0;
        menuFieldsClip.y=0;
    }
    else if(field == "MP")
    {
        menuFieldsClip.x=55;
        menuFieldsClip.y=0;
    }
    else if(field == "AP")
    {
        menuFieldsClip.x=110;
        menuFieldsClip.y=0;
    }
}

void Text::setSymbolClip(string symbol)
{

    if(symbol == "A")
    {
        symbolClip.x=0;
        symbolClip.y=0;
        symbolPixelSpace=24;
    }
    else if(symbol == "B")
    {
        symbolClip.x=39;
        symbolClip.y=0;
        symbolPixelSpace=23;
    }
    else if(symbol == "C")
    {
        symbolClip.x=78;
        symbolClip.y=0;
        symbolPixelSpace=20;
    }
    else if(symbol == "D")
    {
        symbolClip.x=117;
        symbolClip.y=0;
        symbolPixelSpace=25;
    }
    else if(symbol == "E")
    {
        symbolClip.x=156;
        symbolClip.y=0;
        symbolPixelSpace=22;
    }
    else if(symbol == "F")
    {
        symbolClip.x=195;
        symbolClip.y=0;
        symbolPixelSpace=22;
    }
    else if(symbol == "G")
    {
        symbolClip.x=234;
        symbolClip.y=0;
        symbolPixelSpace=23;
    }
    else if(symbol == "H")
    {
        symbolClip.x=273;
        symbolClip.y=0;
        symbolPixelSpace=26;
    }
    else if(symbol == "I")
    {
        symbolClip.x=312;
        symbolClip.y=0;
        symbolPixelSpace=15;
    }
    else if(symbol == "J")
    {
        symbolClip.x=351;
        symbolClip.y=0;
        symbolPixelSpace=18;
    }
    else if(symbol == "K")
    {
        symbolClip.x=390;
        symbolClip.y=0;
        symbolPixelSpace=25;
    }
    else if(symbol == "L")
    {
        symbolClip.x=429;
        symbolClip.y=0;
        symbolPixelSpace=23;
    }
    else if(symbol == "M")
    {
        symbolClip.x=468;
        symbolClip.y=0;
        symbolPixelSpace=27;
    }
    else if(symbol == "N")
    {
        symbolClip.x=507;
        symbolClip.y=0;
        symbolPixelSpace=24;
    }
    else if(symbol == "O")
    {
        symbolClip.x=546;
        symbolClip.y=0;
        symbolPixelSpace=23;
    }
    else if(symbol == "P")
    {
        symbolClip.x=585;
        symbolClip.y=0;
        symbolPixelSpace=24;
    }
    else if(symbol == "Q")
    {
        symbolClip.x=0;
        symbolClip.y=55;
        symbolPixelSpace=25;
    }
    else if(symbol == "R")
    {
        symbolClip.x=39;
        symbolClip.y=55;
        symbolPixelSpace=25;
    }
    else if(symbol == "S")
    {
        symbolClip.x=78;
        symbolClip.y=55;
        symbolPixelSpace=19;
    }
    else if(symbol == "T")
    {
        symbolClip.x=117;
        symbolClip.y=55;
        symbolPixelSpace=24;
    }
    else if(symbol == "U")
    {
        symbolClip.x=156;
        symbolClip.y=55;
        symbolPixelSpace=25;
    }
    else if(symbol == "V")
    {
        symbolClip.x=195;
        symbolClip.y=55;
        symbolPixelSpace=25;
    }
    else if(symbol == "W")
    {
        symbolClip.x=234;
        symbolClip.y=55;
        symbolPixelSpace=34;
    }
    else if(symbol == "X")
    {
        symbolClip.x=273;
        symbolClip.y=55;
        symbolPixelSpace=26;
    }
    else if(symbol == "Y")
    {
        symbolClip.x=312;
        symbolClip.y=55;
        symbolPixelSpace=25;
    }
    else if(symbol == "Z")
    {
        symbolClip.x=351;
        symbolClip.y=55;
        symbolPixelSpace=21;
    }

    //normal alphabet

    else if(symbol == "a")
    {
        symbolClip.x=0;
        symbolClip.y=110;
        symbolPixelSpace=16;
    }
    else if(symbol == "b")
    {
        symbolClip.x=39;
        symbolClip.y=110;
        symbolPixelSpace=17;
    }
    else if(symbol == "c")
    {
        symbolClip.x=78;
        symbolClip.y=110;
        symbolPixelSpace=15;
    }
    else if(symbol == "d")
    {
        symbolClip.x=117;
        symbolClip.y=110;
        symbolPixelSpace=17;
    }
    else if(symbol == "e")
    {
        symbolClip.x=156;
        symbolClip.y=110;
        symbolPixelSpace=14;
    }
    else if(symbol == "f")
    {
        symbolClip.x=195;
        symbolClip.y=110;
        symbolPixelSpace=12;
    }
    else if(symbol == "g")
    {
        symbolClip.x=234;
        symbolClip.y=110;
        symbolPixelSpace=16;
    }
    else if(symbol == "h")
    {
        symbolClip.x=273;
        symbolClip.y=110;
        symbolPixelSpace=19;
    }
    else if(symbol == "i")
    {
        symbolClip.x=312;
        symbolClip.y=110;
        symbolPixelSpace=11;
    }
    else if(symbol == "j")
    {
        symbolClip.x=351;
        symbolClip.y=110;
        symbolPixelSpace=12;
    }
    else if(symbol == "k")
    {
        symbolClip.x=390;
        symbolClip.y=110;
        symbolPixelSpace=18;
    }
    else if(symbol == "l")
    {
        symbolClip.x=429;
        symbolClip.y=110;
        symbolPixelSpace=11;
    }
    else if(symbol == "m")
    {
        symbolClip.x=468;
        symbolClip.y=110;
        symbolPixelSpace=26;
    }
    else if(symbol == "n")
    {
        symbolClip.x=507;
        symbolClip.y=110;
        symbolPixelSpace=17;
    }
    else if(symbol == "o")
    {
        symbolClip.x=546;
        symbolClip.y=110;
        symbolPixelSpace=16;
    }
    else if(symbol == "p")
    {
        symbolClip.x=585;
        symbolClip.y=110;
        symbolPixelSpace=18;
    }
    else if(symbol == "q")
    {
        symbolClip.x=0;
        symbolClip.y=165;
        symbolPixelSpace=17;
    }
    else if(symbol == "r")
    {
        symbolClip.x=39;
        symbolClip.y=165;
        symbolPixelSpace=15;
    }
    else if(symbol == "s")
    {
        symbolClip.x=78;
        symbolClip.y=165;
        symbolPixelSpace=12;
    }
    else if(symbol == "t")
    {
        symbolClip.x=117;
        symbolClip.y=165;
        symbolPixelSpace=13;
    }
    else if(symbol == "u")
    {
        symbolClip.x=156;
        symbolClip.y=165;
        symbolPixelSpace=16;
    }
    else if(symbol == "v")
    {
        symbolClip.x=195;
        symbolClip.y=165;
        symbolPixelSpace=18;
    }
    else if(symbol == "w")
    {
        symbolClip.x=234;
        symbolClip.y=165;
        symbolPixelSpace=23;
    }
    else if(symbol == "x")
    {
        symbolClip.x=273;
        symbolClip.y=165;
        symbolPixelSpace=20;
    }
    else if(symbol == "y")
    {
        symbolClip.x=312;
        symbolClip.y=165;
        symbolPixelSpace=20;
    }
    else if(symbol == "z")
    {
        symbolClip.x=351;
        symbolClip.y=165;
        symbolPixelSpace=15;
    }
    else if(symbol == "0")
    {
        symbolClip.x=0;
        symbolClip.y=385;
        symbolPixelSpace=17;
    }
    else if(symbol == "1")
    {
        symbolClip.x=39;
        symbolClip.y=385;
        symbolPixelSpace=17;
    }
    else if(symbol == "2")
    {
        symbolClip.x=78;
        symbolClip.y=385;
        symbolPixelSpace=17;
    }
    else if(symbol == "3")
    {
        symbolClip.x=117;
        symbolClip.y=385;
        symbolPixelSpace=17;
    }
    else if(symbol == "4")
    {
        symbolClip.x=156;
        symbolClip.y=385;
        symbolPixelSpace=17;
    }
    else if(symbol == "5")
    {
        symbolClip.x=195;
        symbolClip.y=385;
        symbolPixelSpace=17;
    }
    else if(symbol == "6")
    {
        symbolClip.x=234;
        symbolClip.y=385;
        symbolPixelSpace=17;
    }
    else if(symbol == "7")
    {
        symbolClip.x=273;
        symbolClip.y=385;
        symbolPixelSpace=17;
    }
    else if(symbol == "8")
    {
        symbolClip.x=312;
        symbolClip.y=385;
        symbolPixelSpace=17;
    }
    else if(symbol == "9")
    {
        symbolClip.x=351;
        symbolClip.y=385;
        symbolPixelSpace=17;
    }

}
