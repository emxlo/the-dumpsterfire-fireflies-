#ifndef _UI_H
#define _UI_H

#define XMAX 160
#define YMAX 50

#define MAX_INTENSITY 13
#define MIN_INTENSITY 4

#include <stdbool.h>

typedef struct {
    char charracter;
    int intensity;    
} cell;

//external
extern cell matrix[XMAX][YMAX];

//prototipes
bool init_ui();
void cleanup_ui();
void show_matrix();

#endif