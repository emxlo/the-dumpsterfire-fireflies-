#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#define FROG_PAIR      1
#define WATER_PAIR     2
#define ROAD_PAIR      3
#define SAFE_PAIR      4       

#define TILE     ' '

void draw_map(int yMax, int xMax);


int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    start_color();

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_CYAN, COLOR_CYAN);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_MAGENTA);

clear(); 

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    
    do {
    draw_map(yMax, xMax);
    refresh();
    } while (wgetch(stdscr) != 'q');

    endwin();
    return 0;
}

void draw_map(int yMax, int xMax) {
  
    int x, y;

    attron(COLOR_PAIR(WATER_PAIR));
    for (y = 0; y < LINES/2; y++) {
        mvhline(y, 0, TILE, COLS);
    }
    attroff(COLOR_PAIR(WATER_PAIR));

    attron(COLOR_PAIR(ROAD_PAIR));
    for (y = LINES/2; y < LINES; y++) {
        mvhline(y, 0, TILE, COLS);
    }
    attroff(COLOR_PAIR(ROAD_PAIR));

    attron(COLOR_PAIR(SAFE_PAIR));
    for (y = LINES; y > LINES - 5; y--) {
        mvhline(y, 0, TILE, COLS);
    }
    attroff(COLOR_PAIR(SAFE_PAIR));

        attron(COLOR_PAIR(SAFE_PAIR));
    for (y = 0; y < 4; y++) {
        mvhline(y, 0, TILE, COLS);
    }
    attroff(COLOR_PAIR(SAFE_PAIR));

    attron(COLOR_PAIR(SAFE_PAIR));
    for (y = (LINES / 2) - 2; y < (LINES / 2) + 2; y++) {
        mvhline(y, 0, TILE, COLS);
    }
    attroff(COLOR_PAIR(SAFE_PAIR));


}


        /*attron(COLOR_PAIR(2));
        //for (int y = 0; y < LINES; y++)
        mvvline(1, 1, ' ', xMax/2);
        attroff(COLOR_PAIR(2));*/
/*WINDOW *w1;
initscr();
curs_set(0);
noecho();
start_color();

init_pair(1,COLOR_BLUE, COLOR_RED);
init_pair(2, COLOR_BLACK, COLOR_GREEN);
 w1= newwin (10,20,1,2); // Finestra in posizione y=1,x=2 di 10 linee e 20 colonne 
 box(w1,ACS_VLINE,ACS_HLINE); // Crea un bordo alla finestra 
acqua= newwin (10,20,11,2); // Finestra
box(w1,ACS_VLINE,ACS_HLINE);
//mvwprintw(w1,5,3,"premi un tasto"); // Scrive a partire dalla linea 5, colonna 3 

wbkgd(w1, COLOR_PAIR(1));
wbkgd(acqua, COLOR_PAIR(2));
wgetch(w1); // Legge un carattere dalla finestra specificata 
delwin(w1); // Rimuove finestra specificata 
refresh();
endwin();
return 0;
}*/
