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
#include "Enemy.h"
#include "Entity.h"
#include <unistd.h>
#include "Player.h"
using namespace std;
extern int rng(int num);

Enemy::Enemy(WINDOW *win, int health, int atkd, char c, string n)
{
    curwin=win;
    yLoc = rng(16);
    xLoc = rng(45);
    getmaxyx(curwin, yMax, xMax);
    character = c;
    hp = health;
    atk = atkd;
    name = n;
}
string Enemy::get_Name()
{
    return name;
}
void Enemy::takedmg(Entity* user)
{
    hp = hp - user->get_Atk();
}

void Enemy::moveUp()
{
    mvwaddch(curwin,yLoc,xLoc, ' ');
    yLoc--;
    if (yLoc<1) {
        yLoc=1;
    }
}
void Enemy::moveDown()
{
    mvwaddch(curwin,yLoc,xLoc, ' ');

    yLoc++;

    if (yLoc>yMax-2) {
        yLoc= yMax-2;

    }
}
void Enemy::moveLeft() // move left one space
{
    mvwaddch(curwin,yLoc,xLoc, ' ');

    xLoc--;
    if (xLoc<1) {
        xLoc= 1;
    }
}
void Enemy::moveRight() // move right one space
{
    mvwaddch(curwin,yLoc,xLoc, ' ');

    xLoc++;
    if (xLoc>xMax-2) {
        xLoc = xMax-2;
    }
}
int Enemy::getMove()
{
  int mate = 0;
    /* int choice = rng(4);
    switch (choice) {
        case 1:
            moveUp();
            sleep(2);
            break;
        case 2:
            moveDown();
            sleep(2);
            break;
        case 3:
            moveLeft();
            sleep(2);
            break;
        case 4:
            moveRight();
            sleep(2);
            break;
        default:
            break;
    }*/
    return true;
}

void Enemy::wander()
{
  int choice = rng(16);
  switch (choice) {
    case 1:
      moveLeft();
      if (xLoc>19) {
        xLoc = 18;
      }
      break;
    case 2:
      moveRight();
      if (xLoc<2) {
          xLoc= 2;
      }
      break;
    case 3:
      moveUp();
      if (yLoc<2) {
          yLoc= 2;
      }
      break;
    case 4:
      moveDown();
      if (yLoc>49) {
        yLoc = 48;
      }
      break;
    default:
      break;
              }
}

int Enemy::get_Health() // gets enemy health
{
  if (hp < 0)
  {
    hp = 0;
  }
    return hp;
}

void Enemy::set_Health(int e_health) // sets enemy health
{
    hp = e_health;
}

void Enemy::display()
{
    mvwaddch(curwin, yLoc, xLoc, character);
}
int Enemy::get_Atk()
{
    return atk;
}
void Enemy::set_Atk(int s_atk)
{
    atk = s_atk;
}

Enemy::~Enemy() // destructor
{

}
