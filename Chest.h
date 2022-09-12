//
//  Player.h
//
//
//  Created by Toby Cook on 28/9/21.
//  Child class Chest that corresponds to loot in the game
#ifndef CHEST_H
#define CHEST_H
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Entity.h"
#include "Enemy.h"

using namespace std;
class Chest : public Entity
{
public:
// window functions
    Chest(WINDOW *win);
    
    virtual void display();
    
    virtual string get_Name();
    int xLoc, yLoc;
    char character;
    WINDOW *curwin;
    ~Chest();
};

#endif

