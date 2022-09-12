//
//  test.cpp
//
//
//  Created by Toby Cook on 28/9/21.
//

#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include <unistd.h>
using namespace std;

// calling external functions in other files
extern int rng(int num);
extern bool battle(Entity* monster, Entity* zade);

int main(){
  cout << "Testing core functionalities of the game" << endl;
  cout << endl;

// declaring variables and creating ncurses window
    int yMax, xMax;
    cout << "creating new window...: ";
      WINDOW *playwin = newwin(20,50,(yMax/2)-10,10);

      /* In all test cases, if the test criteria is not met,
      the terminal will output "fail" */

// if the window exists, print success
    if (playwin == newwin(20,50,(yMax/2)-10,10) ) {
      cout << "success!" << endl;
      sleep(1);
    }
    else {
      cout << "fail" << endl;
    }

    cout << "creating new objects...: ";
    Player *p = new Player(playwin,1,1, '*', "Zade");
    Enemy *e1 = new Enemy(playwin,1,10,'!',"Revenant");
    Enemy *e2 = new Enemy(playwin,rng(18),rng(48),'!',"Savage");
    Enemy *e3 = new Enemy(playwin,rng(18),rng(48),'!',"MARCUS");

// if the objects are created, print success
    if (p != NULL && e1 != NULL && e2 != NULL && e3 != NULL)
    {
      cout << "success!" << endl;
      sleep(1);
    }
    else {
      cout << "fail" << endl;
    }

  cout << "transferring player health...: ";
    int curHealth, curAtk;
    curHealth = p->get_Health();
    curAtk = p->get_Atk();

// if player health is successfully changed using our functions, print success
    if (curHealth == p->get_Health() && curAtk == p->get_Atk()) {
      cout << "success!" << endl;
      sleep(1);
    }
    else {
      cout << "fail" << endl;
    }

// if player location is moved, print success
    cout << "moving player...: ";
    int bLoc = p->getyPos();
    p->moveDown();
    if (bLoc != p->getyPos()) {
      cout << "success!" << endl;
      sleep(1);
    }
    else {
      cout << "fail" << endl;
    }


// if player location can be returned, print success
    cout << "locating player...: ";
    if (p->getyPos()) {
      cout << "success!" << endl;
      sleep(1);
    }
    else {
      cout << "fail" << endl;
    }

// if player health is changed, print success
    cout << "changing player health... ";
    p->set_Health(500);
    if (p->get_Health() == 500) {
      cout << "success!" << endl;
      sleep(1);
    }
    else {
      cout << "fail" << endl;
    }

// if the battle function is carried through successfully, and returns 'true', print success
    cout << "battling...: ";
    if (battle(e1,p) == true) {
      cout << "success!" << endl;
      sleep(1);
    }
    else {
      cout << "fail" << endl;
    }



cout << endl;
}