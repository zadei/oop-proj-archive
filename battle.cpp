//
//  battle.cpp
//
//
//  Created by Toby Cook on 11/10/21.
//
//  The function responsible for the command window battles

#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include <string>
#include <unistd.h>
#include <ctime>

using namespace std;
extern int rng(int num);
bool battle(Entity* monster, Entity* zade){// takes in entity pointers for the enemy monster and player - entity pointer prevents object slicing -
    string curAtk, curDef;
    int userAtk, userDef;
    //bunch of object functions used to show stats before fight
    cout<<"Before you stands "<<monster->get_Name()<<endl;
    sleep(1);
    cout<<"It has "<<monster->get_Health()<<" health, and has "<<monster->get_Atk()<<" attack damage!"<<endl;
    sleep(3);
    cout<<"You have "<<zade->get_Health()<<" health and "<<zade->get_Atk()<<" attack damage"<<endl;
    sleep(2);
    
    while (monster->get_Health() >0 && zade->get_Health() >0) {
        curAtk = "";
        curDef = "";
    cout<< "Your turn to attack, hack, thrust or sweep?"<<endl;
    cin>>curAtk;
        sleep(1);
        userAtk=0;
        userDef=0;
/* we needed to use the string find function as the "press key to continue"
  was being read into cin. Now a substring is looked for in curAtk to determine what
  the attack was */

    if (curAtk.find("hack") != string::npos ||curAtk == "h") {
        userAtk = 1;
    }
    if (curAtk.find("thrust") != string::npos ||curAtk == "t") {
        userAtk = 2;
    }
    if (curAtk.find("sweep") != string::npos || curAtk == "s") {
        userAtk = 3;
    }

    switch (userAtk) {
        case 1:
            cout<<"You hack at your opponent's head!"<<endl;
            sleep(1);
            break;
        case 2:
            cout<<"You thrust at your opponent's torso!"<<endl;
            sleep(1);
            break;
        case 3:
            cout<<"You sweep at your opponent's feet!"<<endl;
            sleep(1);
            break;
        default:
            cout<<"I don't know what you mean, you miss your turn."<<endl;//in case incorrect input is entered
            sleep(1);
            break;

    } //computer move is randomly generated
    int cpuDef = rng(3);
    switch (cpuDef) {
        case 1:
            cout<<"Your opponent ducks!"<<endl;
            sleep(1);
            break;
        case 2:
            cout<<"Your opponent protects its torso!"<<endl;
            sleep(1);
            break;
        case 3:
            cout<<"Your opponent jumps!"<<endl;
            sleep(1);
        default:
            break;
    }
    if (cpuDef!=userAtk&&userAtk!=0) {
        monster->takedmg(zade);
        cout<<"Your attack lands!"<<endl;
        sleep(1);
        cout<<"You dealt "<<zade->get_Atk()<< " damage, reducing your opponent to "<<monster->get_Health()<<" health!"<<endl;
        sleep(1);
    }
        if (cpuDef==userAtk) {
            cout<<"Your attack has beeen countered!"<<endl;
            sleep(1);
        }
    if (monster->get_Health() <=0) {//checks both players havent died
        return true;
    }
    if (zade->get_Health() <=0) {
        return false;
    }
    cout<< "Your turn to defend, duck, parry or jump?"<<endl;
    cin>>curDef;// same for attacj
        sleep(1);
        userDef =0;
    if (curDef == "duck" ||curAtk == "d") {
        userDef = 1;
    }
    if (curDef == "parry" ||curAtk == "p") {
        userDef = 2;
    }
    if (curDef == "jump" ||curAtk == "j") {
        userDef = 3;
    }

    int cpuAtk = rng(3);
    switch (cpuAtk) {
        case 1:
            cout<<"Your opponent hacks at your head!"<<endl;
            sleep(1);
            break;
        case 2:
            cout<<"Your opponent thrusts at your torso!"<<endl;
            sleep(1);
            break;
        case 3:
            cout<<"Your opponent sweeps at your feet!"<<endl;
            sleep(1);
        default:
            break;
    }

    switch (userDef) {
        case 1:
            cout<<"You drop into a crouch, ducking your head!"<<endl;
            sleep(1);
            break;
        case 2:
            cout<<"You raise your sword, protecting your torso!"<<endl;
            sleep(1);
            break;
        case 3:
            cout<<"You jump, bringing your knees to your chest!"<<endl;
            sleep(1);
            break;
        default:
            cout<<"Thats not a valid defence! You look like an idiot, standing there like a sitting duck."<<endl;
            sleep(3);
            break;

    }
    if (cpuAtk!=userDef&&userDef !=0) {
        zade->takedmg(monster);
        cout<<"The opponent's attack lands!"<<endl;
        sleep(1);
        cout<<"They dealt "<<monster->get_Atk()<< " damage, reducing you to "<<zade->get_Health()<< " health!"<<endl;
        sleep(1);
    }
    if (cpuAtk==userDef) {
        cout<<"You countered your opponents attack!"<<endl;
        sleep(1);
        }
    if (monster->get_Health() <=0) {
        return true;
    }
    if (zade->get_Health() <=0) {
        return false;
    }

}
return true;
}
