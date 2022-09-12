//
//  menu.cpp
//  
//
//  Created by Toby Cook on 20/10/21.
//  This function creates a menu in which players can select the difficulty at which they play at

#include <stdio.h>


#include <ncurses.h>
#include <string>
using namespace std;
string menu(){
    initscr();
    noecho();
    cbreak();
    
    WINDOW *menu = newwin(5,10,3,3);
    
    printw("What level of difficulty would you like to play at?");
    box(menu,0,0);
    refresh();
    wrefresh(menu);
    keypad(menu, true);// makes it so we can use arrow keys
    
    string options[3] = {"Easy", "Medium", "Hard"};
    int choice;
    int highlight=0;
    
    while(1)//idefinitely running while loop
    {
        for (int i=0; i<3; i++)//for loop cycles through the menu options and checks which option the cursor is on. Highlights that option.
        {
            if(i==highlight)
                wattron(menu, A_REVERSE);//this ncurses function highlights the option the user is currently on
            mvwprintw(menu, i+1,1, options[i].c_str());
            wattroff(menu, A_REVERSE);
        }
        choice = wgetch(menu);
        switch(choice)// this switch statement controls movement of the cursor through the menu
        {
            case KEY_UP:
                highlight--;
                if(highlight==-1)
                    highlight=0;//wont let you go up past the top option
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight==3)
                    highlight=2;
                break;
            default:
                break;
                
        }
        if(choice == 10)//breaks once the enter key is pressed
            break;
    }
   string diff = options[highlight].c_str();//stoeres the string last highlighted by the cursor in the diff variable
    clear();
    endwin();
    return diff;
}
