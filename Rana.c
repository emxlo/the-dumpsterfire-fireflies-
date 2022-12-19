#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

#define LEN 6

typedef struct
{
    int x;
    int y;
}pos;

int main() {
 int maxy = 0, maxx = 0;
 int direzionex = 1, direzioney = 1;
initscr();
noecho();
keypad(stdscr, true);
curs_set(false);
start_color();
init_pair(1, COLOR_BLACK, COLOR_GREEN);
char spritetop[LEN] = {"<-|->"}; 
char spritebot[LEN] = {"-/|>-"};
//-2 perchè per avere la lunghezza giusta non deve 
//considerare l'ultimo oggetto ed il terminatore di riga 
int sprlen = sizeof(spritetop)/sizeof(char);
int sprhgt = 2;
getmaxyx(stdscr, maxy, maxx); /* Ottiene dimensioni schermo */
int x = maxx/2, y = maxy/2; /* Centro dello schermo */
int newx = x, newy = y, newy2 = y+1;
pos oggetto = {x, y}; /* Centro dello schermo */ 
attron(COLOR_PAIR(1));
mvprintw(oggetto.y, oggetto.x, "%s", spritetop);
mvprintw(oggetto.y + 1, oggetto.x, "%s", spritebot);
attroff(COLOR_PAIR(1));

    while(true){
        clear();
        attron(COLOR_PAIR(1));
        mvprintw(newy, newx, "%s",spritetop);
        mvprintw(newy2, newx, "%s", spritebot); 
        attroff(COLOR_PAIR(1));
        refresh();
        int c;
        switch(getchar()) {
        case 'w':
            if(oggetto.y > 0)
            newy2 -= sprhgt;
            newy -= sprhgt;
            break;
        case 's':
            if(oggetto.y < maxy - 1)
            newy2 += sprhgt;
            newy += sprhgt;
            break;
        case 'a':
            if(oggetto.x > 0)
            newx -= sprlen;
            break;
        case 'd':
            if(oggetto.x < maxx - 1)
            newx += sprlen;
            break;
        case 'q': /* Tasto 'q' */
            endwin();
            exit(0);}
}
endwin();

}

   


