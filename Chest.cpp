
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "Chest.h"
using namespace std;
extern int rng(int num);

Chest::Chest(WINDOW *win)//default constructor
{
    curwin = win;
    character = '#';//reprsented on map by a hash
    name = "Chest";
    yLoc = rng(16);//spawns at random location
    xLoc = rng(45);
}
void Chest::display() // displays given character in specifed coordinates on given window
{
    mvwaddch(curwin, yLoc, xLoc, character);
}
string Chest::get_Name()//returns the chests name
{
    return name;
}
Chest::~Chest()//destructor
{

}
