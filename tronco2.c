#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

#define MAXLENGTH 73
#define MAXHEIGHT 33
#define LEN 6
#define HGT 2

typedef struct {
    int x, y;
    int maxx, maxy;
    int direzionex;
}position;

void draw_tronco( position, char (*));

int main() {

    position log = {0};
    log.direzionex = 1;

    initscr();
    noecho();
    keypad(stdscr, 1);
    cbreak();
    curs_set(false);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    char * sprite_log[LEN][HGT] = {{"<-|->"},
                                   {"-/|>-"}};  
    //getmaxyx(stdscr, log.maxy, log.maxx); /* Ottiene dimensioni schermo */
    /*this is golden*/
    log.maxx = MAXLENGTH;
    log.maxy = MAXHEIGHT;
    /*dont fuckin touch... it works*/
    log.x = log.maxx/2, log.y = log.maxy/2; /* Centro dello schermo */
    attron(COLOR_PAIR(1));
    mvaddstr(log.y, log.x, sprite1);
    mvaddstr(log.y+1, log.x, sprite2);
    attroff(COLOR_PAIR(1));

    draw_tronco(log, sprite_log);

    endwin();
}

void draw_tronco(position log, char sprite) {
    while(true) {
        clear();
        attron(COLOR_PAIR(1));
        mvaddstr(log.y, log.x, sprite1);
        mvaddstr(log.y +1, log.x, sprite2);
        attroff(COLOR_PAIR(1));
        int newx;
        newx = log.x + log.direzionex;
        mvprintw(3, 1, "Dimensione Massima: %d", log.maxx);
        mvprintw(1, 1, "Prossima posizione: %d", newx);
        mvprintw(2, 1, "Direzione: %d", log.direzionex);
        mvprintw(4, 1, "Posizione corrente: %d", newx);

        refresh();
        usleep(50000);
        newx = log.x + log.direzionex;
        //newy = y + direzioney;
        /* Inverte la direzione del movimento toccando il bordo */
        if(newx >= log.maxx || newx < 1) {
            log.direzionex *= -1;
            mvprintw(5, 1, "Cambio Direzione: %d", log.x);
            //log.x += direzionex;
            //usleep(100000);
            }   else {
                    log.x += log.direzionex; 
                    //usleep(100000);
                    }

        timeout(1); /* Non attende il tasto invio */
        if(getch() == 113) break; /* Esce alla pressione del tasto 'q' */
        }

/*    newx = x + direzionex; perch 2 volte
    //newy = y + direzioney;

    refresh();
    usleep(30000); 
    newx = x + direzionex;      ???
    //newy = y + direzioney;
    /* Inverte la direzione del movimento toccando il bordo *
    if(newx + LEN >= maxx || newx < 0) direzionex*= -1;
    else x+= direzionex;

    /* if(newy >= maxy || newy < 0) 
        direzioney*= - 1;
    else y+= direzioney;*

    timeout(1); /* Non attende il tasto invio *
    if(getch() == 113) break; /* Esce alla pressione del tasto 'q' *

    i think it cuz it doesnt load the changes in the struct?
    }*/

}