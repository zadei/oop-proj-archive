//
//  Player.cpp
//
//
//  Created by Toby Cook on 28/9/21.
//
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include <unistd.h>
using namespace std;
extern int rng(int num);
extern void blankScr(WINDOW *curwin);
Player::Player(WINDOW *win, int y, int x, char c, string n)
{// default contstructor, takes in the window its spawned it, its location, its character and its name
    curwin=win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
    hp = 100;
    atk = 20;
    name =n;
}

int Player::checkCollide() // checks is in the immediate vicinity of an entity
{
    char enemychar = '!';//checking for an enemy
    if (mvwinch(curwin,yLoc,xLoc++) == enemychar || mvwinch(curwin,yLoc,xLoc--) == enemychar || mvwinch(curwin,yLoc++,xLoc) == enemychar || mvwinch(curwin,yLoc--,xLoc) == enemychar)
    {
        move(2,2);
        printw("You are about to enter a fight. Press any key to continue.");
        return 1;
    }
    char chestchar = '#';//checking for a chest
    if (mvwinch(curwin,yLoc,xLoc) == chestchar)
    {
        int loot = rng(3);
        move(2,2);
        switch (loot) {
            case 1:
                blankScr(curwin);
                mvwprintw(curwin, 2,2,"You open the chest to find a magic whetstone,    sharpening your sword!. Your attacks now deal 5   extra damage per hit! Press Enter.");

                atk = atk+5;
                break;
            case 2:
                blankScr(curwin);
                mvwprintw(curwin, 2,2,"You open the chest to find a health potion. You have gained 20 health! Press Enter.");


                hp = hp+20;

                break;
            case 3:
                blankScr(curwin);
                mvwprintw(curwin, 2,2,"You open the chest to find a bomb. It explodes   in your face dealing 5 damage! Press Enter.");


                hp = hp-5;

                break;
        }
        return 2;
    }
    return 0;
}


void Player::moveUp() // moves player up one space
{
    mvwaddch(curwin,yLoc,xLoc, ' ');

    yLoc--;
    if (yLoc<1) {
        yLoc=1;
    }
}
void Player::moveDown() // moves player down one space
{
    mvwaddch(curwin,yLoc,xLoc, ' ');

    yLoc++;

    if (yLoc>yMax-2) {
        yLoc= yMax-2;

    }
}
void Player::moveLeft() // moves player left one space
{
    mvwaddch(curwin,yLoc,xLoc, ' ');

    xLoc--;
    if (xLoc<1) {
        xLoc= 1;
    }
}
void Player::moveRight() // move player right one space
{
    mvwaddch(curwin,yLoc,xLoc, ' ');

    xLoc++;
    if (xLoc>xMax-2) {
        xLoc = xMax-2;
    }
}
int Player::getMove() // return the key pressed by user
{
    int choice = wgetch(curwin);
    switch (choice) {
        case KEY_UP:
            moveUp();
            break;
        case KEY_DOWN:
            moveDown();
            break;
        case KEY_LEFT:
            moveLeft();
            break;
        case KEY_RIGHT:
            moveRight();
            break;
        case 10:
            mvwprintw(curwin, 1,1,"                                                                                                                                                                                                                                 ");
            box(curwin,0,0);
            break;
        default:
            break;
    }
    return choice;
}

int Player::get_Health() // return hp
{
  if (hp < 0)
  {
    hp = 0;
  }
    return hp;
}
string Player::get_Name()
{
    return name;
}

void Player::set_Health(int s_health) // set health
{
    hp = s_health;
}
int Player::get_Atk()
{
    return atk;
}
void Player::set_Atk(int s_atk)
{
    atk = s_atk;
}
void Player::display() // displays given character in specifed coordinates on given window
{
    mvwaddch(curwin, yLoc, xLoc, character);
}
void Player::takedmg(Entity* monster)//takes damage from the monster specified
{
    hp = hp - monster->get_Atk();
}
Player::~Player()//destructor
{

}
