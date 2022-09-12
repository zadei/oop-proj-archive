//
//  Player.h
//
//
//  Created by Toby Cook on 28/9/21.
//
#ifndef ENEMY_H
#define ENEMY_H
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Entity.h"
#include "Player.h"

using namespace std;

class Enemy : public Entity
{
public:
// window functions
    Enemy(WINDOW *win, int health, int atkd, char c, string n);
    virtual void moveUp();
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();
    virtual void takedmg(Entity* user);
    virtual void display();
    virtual int getMove();
    void wander();


// player functions
    virtual string get_Name();
    virtual int get_Health(); // gets enemy health
    virtual void set_Health(int e_health); // sets enemy health
    virtual int get_Atk();
    virtual void set_Atk(int s_atk);
    int xLoc, yLoc, xMax, yMax;
    char character;
    WINDOW *curwin;
    ~Enemy();
};

#endif /* Player_h */
