//
//  main.cpp
//  
//
//  Created by Toby Cook on 20/10/21.
//
//
// The magical game itself: runs the tutorial function, then the actual game, and if you win, prints a congratulations message.



#include <iostream>
#include <string>
using namespace std;

extern bool game(string difficulty);
extern string menu();
extern void tutorial();
int main(){
    tutorial();
    string dif= menu();
    if (game(dif)==0) {
        return 0;
    }else{
        cout<<"Congratulations! You have completed ZT Dungeon Crawler"<<endl;
    }
}
