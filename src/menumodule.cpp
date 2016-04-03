#include <stdio.h>
#include <string>
#include "SDL/SDL.h"
#include "menumodule.h"

int MenuModule::getId()
{
    return id;
}

string MenuModule::getName()
{
    return name;
}

int MenuModule::getCursorXPosition()
{
    return cursorXPosition;
}

int MenuModule::getCursorYPosition()
{
    return cursorYPosition;
}

int MenuModule::getCursorXVariation()
{
    return cursorXVariation;
}

int MenuModule::getCursorYVariation()
{
    return cursorYVariation;
}

bool MenuModule::upIsEnabled()
{
    return up;
}

bool MenuModule::downIsEnabled()
{
    return down;
}

bool MenuModule::rightIsEnabled()
{
    return right;
}

bool MenuModule::leftIsEnabled()
{
    return left;
}

void MenuModule::setCursorImage(SDL_Surface* cursor)
{
    this->cursor=cursor;
}

void MenuModule::showCursor()
{
    cursorOpaque=true;
}

void MenuModule::hideCursor()
{
    cursorOpaque=false;
}

Text& MenuModule::getText()
{
    return text;
}

string MenuModule::getPreviousCommand()
{
    return previousCommand;
}

void MenuModule::setPreviousCommand(string direction)
{
    previousCommand=direction;
}

void MenuModule::setUpExecuted(bool value)
{
    upPreviouslyExecuted=value;
}

void MenuModule::setDownExecuted(bool value)
{
    downPreviouslyExecuted=value;
}

void MenuModule::setRightExecuted(bool value)
{
    rightPreviouslyExecuted=value;
}

void MenuModule::setLeftExecuted(bool value)
{
    leftPreviouslyExecuted=value;
}

bool MenuModule::upExecuted()
{
    return upPreviouslyExecuted;
}

bool MenuModule::downExecuted()
{
    return downPreviouslyExecuted;
}

bool MenuModule::rightExecuted()
{
    return rightPreviouslyExecuted;
}

bool MenuModule::leftExecuted()
{
    return leftPreviouslyExecuted;
}

void MenuModule::setRepeatLoopActivated(bool value)
{
    repeatLoopActivated=value;
}

void MenuModule::setRepeating(bool value)
{
    repeating=value;
}

void MenuModule::setCurrentDelayIndex(int value)
{
    currentDelayIndex=value;
}



