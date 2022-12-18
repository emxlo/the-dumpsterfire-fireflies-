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

