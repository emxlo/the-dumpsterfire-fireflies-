#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <unistd.h>

#include "ui.h"
#include "matrix.h"

#define REFRESH_DELAY 50000L            
#define ITERATIONS 10
/*void child_prosses(int);*/
int main(int argc, char **argv) {


/*pid_t pid1;

int p[2];

if(pipe(p) == -1){
    perror("pipe cal");
    _exit(1);
}
pid1 = fork();

if (pid1 == 0) {
    close(p[0]);
    child_prosses(p[1]);
}*/


if (!init_ui()){
    return EXIT_FAILURE;
}

matrix_init();/*q*/

/*close(p[1]);*/
/*for (int i=0; i!='q';)*/
for (int i=0; i<ITERATIONS; i++)
/*while (true){*/{
    matrix_update();
    show_matrix();
    /*read(p[0], &i, sizeof(int));*/
    usleep(REFRESH_DELAY);
    }
     
    
    cleanup_ui();
    return EXIT_SUCCESS;
}

/*void child_prosses(int p) {
    int l = 'p';
    while (true) {
        if (l = getch() == 113) 
            write(p, &l, sizeof(int));
    }
}*/

