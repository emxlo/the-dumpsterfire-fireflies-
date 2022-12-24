#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

#define MAXLENGTH 73
#define MAXHEIGHT 33
#define LEN 13
#define HGT 2

typedef struct {
    int x, y;
    int maxx, maxy;
    int direzionex;
    int direzionexx;
}position;

void draw_tronco(void);

int main() {

    initscr();
    int l = 0;
    attroff(COLOR_PAIR(2));
    noecho();
    keypad(stdscr, 1);
    cbreak();
    curs_set(false);
    start_color();

    draw_tronco();

    endwin();
}

void draw_tronco(void) {
    
    position log = {0};
    log.y = 5;
    log.direzionex = 1;
    log.direzionexx = -1;
    log.maxx = MAXLENGTH;
    log.maxy = MAXHEIGHT;
    log.x = log.maxx/2; /* Centro dello schermo */

    init_color(COLOR_RED, 300, 200, 150);
    init_pair(1, COLOR_YELLOW, COLOR_RED);
    char sprite1[LEN] = {" __||___//_ "};
    char sprite2[LEN] = {"(___-____-_)"};  

    while(true) {
        clear();
        attron(COLOR_PAIR(1));
        mvaddstr(log.y, log.x, sprite1);
        mvaddstr(log.y+1, log.x, sprite2);
        attroff(COLOR_PAIR(1));

        attron(COLOR_PAIR(1));
        mvaddstr(log.y+3, log.x, sprite1);
        mvaddstr(log.y+4, log.x, sprite2);
        attroff(COLOR_PAIR(1));

        attron(COLOR_PAIR(1));
        mvaddstr(log.y+6, log.x, sprite1);
        mvaddstr(log.y+7, log.x, sprite2);
        attroff(COLOR_PAIR(1));

        int newx;
        newx = log.x + log.direzionex;

        refresh();
        usleep(50000);
        newx = log.x + log.direzionex;
        /* Inverte la direzione del movimento toccando il bordo */
        if(newx >= log.maxx || newx < 1) {
            log.direzionex *= -1;
            }   else {
                    log.x += log.direzionex; 
                    }

        timeout(1); /* Non attende il tasto invio */
        char c = getch();
        if(c == 'q' || c == 'Q') break; /* Esce alla pressione del tasto 'q' */
        }
    }