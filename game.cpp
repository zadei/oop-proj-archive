//
//  playermove.cpp
//
//
//  Created by Toby Cook on 28/9/21.
//
// This handles the front-end aspect of the game visible to the user
// Calls battle functions differently depending on difficulty chosen by user

#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include <unistd.h>
#include "Chest.h"
using namespace std;

// declaring external functions
extern int rng(int num);
extern bool battle(Entity* monster, Entity* zade);

bool game(string difficulty){
  // increases strength of monster depending on difficulty chosen
    int difficultyBuff;
    if (difficulty=="Easy") {
        difficultyBuff = 0;
    }
    if (difficulty=="Medium") {
        difficultyBuff = 5;
    }
    if (difficulty=="Hard") {
        difficultyBuff = 10;
    }

    // initiating ncurses
    initscr();
    noecho();
    cbreak();

    // declaring variables
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // intitialising window
    WINDOW *playwin = newwin(20,50,(yMax/2)-10,10);
    box(playwin,0,0);

    refresh();
    wrefresh(playwin);

    // creating objects to be displayed on screen
    Player *p = new Player(playwin,1,1, '*', "Zade");
    Enemy *e1 = new Enemy(playwin,35+difficultyBuff,10+difficultyBuff,'!',"a horrible demon, brandishing a cutlass!");
    Enemy *e2 = new Enemy(playwin,rng(18),rng(48),'!',"e2");
    Enemy *e3 = new Enemy(playwin,rng(18),rng(48),'!',"e3");
    Chest *c1 = new Chest(playwin);

    c1->display();
    // while loop that handles constantly displaying objects in window
    do {
        p->display();
        e1->wander();
        e1->display();
        e2->wander();
        e2->display();
        e3->wander();
        e3->display();
        wrefresh(playwin);

    } while(p->getMove()!='x' && p->checkCollide() !=1); // constantly checks if there is a collision between player and an entity
    getch();
    clear();
    // ends window when condition is met
    endwin();

    int curHealth, curAtk;
    curHealth = p->get_Health();
    curAtk = p->get_Atk();

// battle mechanic
    if (battle(e1, p)== false)
    // if player health reaches 0 during battle, game over
        {
            cout<<"You die a horrible, painful death. The end"<<endl;
            return false;
        }
    else
    {
      // if monster health reaches 0 during battle
        cout<<"Your adventure continues..."<<endl;
        // dynamically allocated memory for objects is deleted
        delete e1;
        delete e2;
        delete e3;
        delete c1;
        cout << " " << endl;
        sleep(2);
    }

    // on player victory, ncurses window is re-opened
    initscr();
    noecho();
    cbreak();

    // this method is repeated until there are no more monsters alive
    WINDOW *win2 = newwin(20,50,(yMax/2)-10,10);
    box(win2,0,0);

    Player *p2 = new Player(win2,1,1, '*', "Toby");
    p2->set_Health(curHealth);
    p2->set_Atk(curAtk);

    Enemy *f2 = new Enemy(win2,50+difficultyBuff,15+difficultyBuff,'!',"an OOP tutor, scowling menacingly and about to ask about your test cases!");
    Enemy *f3 = new Enemy(win2,rng(18),rng(48),'!',"f3");
    Chest *c2 = new Chest(win2);

    refresh();
    wrefresh(win2);

    c2->display();
    do {
        p2->display();
        f2->wander();
        f2->display();
        f3->wander();
        f3->display();
        wrefresh(win2);
    } while(p2->getMove()!='x' && p2->checkCollide() !=1); // constantly checks if there is a collision between player and an entity

    getch();
    clear();
    endwin();

    curHealth = p2->get_Health();
    curAtk = p2->get_Atk();
    delete p;

    if (battle(f2, p2)== false)
        {
            cout<<"You die a horrible painful death. The end"<<endl;
            return false;
        }
    else
    {
        cout<<"Your adventure continues..."<<endl;
        delete f2;
        delete f3;
        sleep(2);
    }

    WINDOW *win3 = newwin(20,50,(yMax/2)-10,10);
    box(win3,0,0);
    Player *p3 = new Player(win3,1,1, '*', "MARCUS");

    p3->set_Health(curHealth);
    p3->set_Atk(curAtk);

    delete p2;
    Enemy *g3 = new Enemy(win3,25+difficultyBuff,40+difficultyBuff,'!',"an animated skeleton, wielding a giant longsword!");
    Chest *c3 = new Chest(win3);

    refresh();
    wrefresh(win3);

    c3->display();
    do {
        p3->display();
        g3->wander();
        g3->display();
        wrefresh(win3);
    } while(p3->getMove()!='x' && p3->checkCollide() != 1); // constantly checks if there is a collision between player and an entity
    getch();
    clear();
    endwin();

    if (battle(g3, p3)== false)
        {
            cout<<"You die a horrible painful death. The end"<<endl;
            return false;
        }
    else

    // initiates final boss sequence if all monsters are defeated
    {
        cout<<"You've done it, you have cleared all the monsters from the dungeon!"<<endl;
        delete g3;
        sleep(2);
        cout<<"But wait..."<<endl;
        sleep(1);
        cout<<"An ominous rumbling fills the air around you..."<<endl;
        sleep(2);
        cout<<"Footsteps echo through the gloomy expanse, slowly becoming closer... and closer..."<<endl;
        sleep(3);
        cout<<"A shadowy figure appears from the darkness.."<<endl;
        sleep(2);
        cout<<"Before you stands Nick Falkner himself!!!"<<endl;
        sleep(3);
        cout<<"'MANAGE YOUR MEMORY PROPERLY!!' he bellows. The final battle begins."<<endl;
        sleep(2);
        Enemy *h4 = new Enemy(win3,100+difficultyBuff,20+difficultyBuff,'!',"Nick Falkner");
        if (battle(h4, p3)== false)
            {
                cout<<"You die a horrible painful death. The end"<<endl;
                return false;
            }
        else
        {
            cout<<"You have done it. You fall to your knees and cry tears of joy. A door swings open out of the gloom and through it lies stairs taking you back up to the surface."<<endl;
            sleep(5);
    }
    return true;

  }
}
