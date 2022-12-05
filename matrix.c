#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include "ui.h"
#include <stdbool.h>

#define NUM_DRIPS 250

#define PROB_DRIP_SPAWN 0.65
#define PROB_DIM 0.65
#define PROB_CHANGE 0.95

#define RANDOME_PRINTABLE_CHARRACTER (33 + (rand()%80))


typedef struct
{
    int x, y;
    bool live;
    bool bright;
} drip;

cell matrix[XMAX][YMAX];
drip drips[NUM_DRIPS];


double rand01()
{
    return (double)rand() / (double)RAND_MAX;
}

void init_drips()
{
    for (int i = 0; i < NUM_DRIPS; i++)
    {
        drips[i].live = false;
    }
}

void matrix_init()
{
    // matrix = all black
    for (int x = 0; x < XMAX; x++)
    {
        for (int y = 0; y < YMAX; y++)
        {
            matrix[x][y].charracter = 0;
            matrix[x][y].intensity = 0;
        }
    }

    // init drips
    init_drips();
}

void fade_n_change_matrix()
{
    for (int x = 0; x < XMAX; x++)
    {
        for (int y = 0; y < YMAX; y++)
        {
            //          randomly change characters ---- even invisible ones.
            if (rand01() < PROB_CHANGE || matrix[x][y].charracter == 0)
            {
                matrix[x][y].charracter = RANDOME_PRINTABLE_CHARRACTER;
            }
            //          randomely dim the cells
            if (rand01() < PROB_DIM)
            {
                if (matrix[x][y].intensity > 0)
                    matrix[x][y].intensity--;
            }
        }
    }
}

void try_add_drips()
{
    for (int i = 0; i < NUM_DRIPS; i++)
    {
        if (drips[i].live == false)
        {
            drips[i].live = true;
            drips[i].x = rand() % XMAX;
            drips[i].y = 0;  /*rand() % XMAX;.... for some spice, if needed.*/
            drips[i].bright = rand() % 2;
            return;
        }
    }
}

void update_drips()
{
    for (int i = 0; i < NUM_DRIPS; i++)
    {
        if (drips[i].live)
        {
            if (drips[i].bright)
            {
                matrix[drips[i].x][drips[i].y].intensity = MAX_INTENSITY;
            }
            else
            {
                matrix[drips[i].x][drips[i].y].intensity = MIN_INTENSITY;
            }
            // drips die at bottom
            if (++drips[i].y >= YMAX - 1)
            {
                drips[i].live = false;
            }
        }
    }
}

void matrix_update()
{
    if (rand01() < PROB_DRIP_SPAWN)
    {
        try_add_drips();
    }
    update_drips();

    fade_n_change_matrix();
}