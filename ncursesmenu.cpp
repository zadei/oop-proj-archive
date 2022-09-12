//
//  ncursesmenu.cpp
//
//
//  Created by Toby Cook on 26/9/21.
//

#include <ncurses.h>
#include <string>
using namespace std;
int main(){
    initscr();
    noecho();
    cbreak();

    WINDOW *menuwin = newwin(20,40,3,3);
    box(menuwin,0,0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);// makes it do we can use arrow keys

    string choices[3] = {"Easy", "Medium", "Hard"};
    int choice;
    int highlight=0;

    while(1)
    {
        for (int i=0; i<3; i++)desk
        {
            if(i==highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1,1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);
        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if(highlight==-1)
                    highlight=0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight==3)
                    highlight=2;
                break;
            default:
                break;

        }
        if(choice == 10)
            break;
    }
    printw("You chose: %s", choices[highlight].c_str());
    getch();
    endwin();
}
