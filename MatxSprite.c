#include <unistd.h>
#include <curses.h>
#include <stdbool.h>

int main() {
 int maxy = 0, maxx = 0;
 int newx = 0, newy = 0;
 int direzionex = 1, direzioney = 1;

initscr();
noecho();
curs_set(false);
char spritetop[5] = {"<-|->"};
char spritebot[5] = {" /|> "};
int spritelen = sizeof(spritetop)/sizeof(spritetop[0]) - 1;
getmaxyx(stdscr, maxy, maxx); /* Ottiene dimensioni schermo */
int x = maxx/2, y = maxy/2; /* Centro dello schermo */

 while(true) {
clear();
mvprintw(y, x, spritetop);
//mvprintw(y+1, x, spritebot);
refresh();
usleep(30000);
newx = x + direzionex;
newy = y + direzioney;
/* Inverte la direzione del movimento toccando il bordo */
 if(newx + spritelen >= maxx || newx < 0) direzionex*= -1;
 else x+= direzionex;

 if(newy >= maxy || newy < 0) 
    direzioney*= - 1;
else y+= direzioney;

timeout(1); /* Non attende il tasto invio */
if(getch() == 113) break; /* Esce alla pressione del tasto 'q' */
}
endwin();}
