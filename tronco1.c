#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

#define MAXLENGTH 73
#define MAXHEIGHT 33
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
keypad(stdscr, 1);
cbreak();
curs_set(false);
start_color();
init_pair(1, COLOR_BLACK, COLOR_YELLOW);
char spritetop[LEN] = {"<-|->"}; 
char spritebot[LEN] = {"-/|>-"};
//-2 perchè per avere la lunghezza giusta non deve 
//considerare l'ultimo oggetto ed il terminatore di riga 
int sprlen = sizeof(spritetop)/sizeof(char);
int sprhgt = 2;
getmaxyx(stdscr, maxy, maxx); /* Ottiene dimensioni schermo */
int x = maxx/2, y = maxy/2; /* Centro dello schermo */
int newx, newy;
attron(COLOR_PAIR(1));
mvaddstr(y, x, spritetop);
mvaddstr(y + 1, x, spritebot);
attroff(COLOR_PAIR(1));

 while(true) {
    clear();
    attron(COLOR_PAIR(1));
    mvaddstr(y, x, spritetop);
    mvaddstr(y + 1, x, spritebot);
    attroff(COLOR_PAIR(1));

    newx = x + direzionex;
    newy = y + direzioney;

    refresh();
    usleep(30000);
    newx = x + direzionex;
    //newy = y + direzioney;
    /* Inverte la direzione del movimento toccando il bordo */
    if(newx + LEN >= maxx || newx < 0) direzionex*= -1;
    else x+= direzionex;

    /* if(newy >= maxy || newy < 0) 
        direzioney*= - 1;
    else y+= direzioney;*/

    timeout(1); /* Non attende il tasto invio */
    if(getch() == 113) break; /* Esce alla pressione del tasto 'q' */
    }
endwin();}
