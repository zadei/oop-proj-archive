//
//  tutorial.cpp
//  
//
//  Created by Toby Cook on 20/10/21.
//  tutorial for the game






#include <unistd.h>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

void tutorial(){
    int c=0;
cout<<"Welcome to ZT dungeon crawler! Do you know how to play?"<<endl;
string tutorialStatus="";
cin>>tutorialStatus;

    // if the user says no, then they will recieve this message
if (tutorialStatus=="no"||tutorialStatus=="n") {
    cout<<"No problem, here is a quick tutorial!"<<endl;
    sleep(2);
    cout<<endl<< "In ZT dungeon crawler you play as an asterisk *, exploring a mysterious cave. You control your character with arrow keys, allowing you to move around the 2D world."<<endl<<endl<< "On your adventure, you will encounter several different entities. Enemies are denoted by an exclamation mark !, while chests are represented by a hash #."<<endl<<endl<<"When you approach an enemy, it will start a sword fight. You and your opponent will take turns attacking and defending. On attack, you can either hack at the head, thrust at the torso, or sweep at the feet. Conversely on defence, you can either duck, parry at torso level, or jump. If an attack is met with the corresponding defence, it is countered, and deals no damage. Otherwise, the attack is considered successful, and will deal the character's attack damage. Fights continue until one participant is reduced to 0 health"<<endl<<endl<<"To escape the dungeon, you must defeat all the enemies. The chests are optional, but USUALLY contain helpful items to help you on your quest."<<endl<<endl<<"Theres not much more to it, so good luck on your adventure!"<< endl<< endl<<"Enter ok to continue."<<endl<<endl;
  

        cin>>c;
    
    return;
}
    // if the user says yes, then they will recieve this message
    if (tutorialStatus=="yes"||tutorialStatus=="y") {
        cout<<"Fantastic. Good luck on your adventure!"<<endl;
        sleep(1);
        return;
}
    // if the user says something else, then they will recieve this message
    cout<<"I'm not sure what you mean. Better to be safe than sorry, here is a tutorial for you."<<endl<<endl;
    sleep(3);
    cout<<endl<< "In ZT dungeon crawler you play as an asterisk *, exploring a mysterious cave. You control your character with arrow keys, allowing you to move around the 2D world."<<endl<<endl<< "On your adventure, you will encounter several different entities. Enemies are denoted by an exclamation mark !, while chests are represented by a hash #."<<endl<<endl<<"When you approach an enemy, it will start a sword fight. You and your opponent will take turns attacking and defending. On attack, you can either hack at the head, thrust at the torso, or sweep at the feet. Conversely on defence, you can either duck, parry at torso level, or jump. If an attack is met with the corresponding defence, it is countered, and deals no damage. Otherwise, the attack is considered successful, and will deal the character's attack damage. Fights continue until one participant is reduced to 0 health"<<endl<<endl<<"To escape the dungeon, you must defeat all the enemies. The chests are optional, but USUALLY contain helpful items to help you on your quest."<<endl<<endl<<"Theres not much more to it, so good luck on your adventure!"<< endl<< endl<<"Enter ok to continue."<<endl<<endl;
        cin>>c;
    return;
}
