//
//  Player.h
//
//
//  Created by Toby Cook on 28/9/21.
//  Child class player - what user controls


#ifndef PLAYER_H
#define PLAYER_H
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Entity.h"
#include "Enemy.h"

using namespace std;
class Player : public Entity
{
public:
// window functions
    Player(WINDOW *win, int y, int x, char c, string n);
    virtual void moveUp();//movment functions
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();
    virtual void takedmg(Entity* monster);//interacts with enemy
    virtual int getMove();
    virtual void display();
    int checkCollide();


// player functions
    virtual int get_Health(); // gets player health
    virtual void set_Health(int s_health); // sets player health
    virtual int get_Atk();
    string get_Name();
    virtual void set_Atk(int s_atk);
    int xLoc, yLoc, xMax, yMax;
    char character;
    WINDOW *curwin;
    ~Player();
};

#endif /* Player_h */
