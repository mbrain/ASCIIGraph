#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

#define WIDTH 150
#define HEIGHT 50
#define X WIDTH/2
#define Y HEIGHT/2
#define XMAX WIDTH-X-1
#define XMIN -(WIDTH-X)
#define YMAX HEIGHT-Y
#define YMIN -(HEIGHT-Y)+1

char grid[HEIGHT][WIDTH];

int plot(int x, int y);
void init_grid(void);
void show_grid(void);

int plot(int x, int y) {
    if( x > XMAX || x < XMIN || y > YMAX || y < YMIN ) return(-1);
    grid[Y-y][X+x] = '*';
    return(1);
}

void init_grid(void) {
    int x,y;
    for(y=0;y<HEIGHT;y++)
        for(x=0;x<WIDTH;x++)
            grid[y][x] = ' ';
    /* draw the axis */
    for(y=0;y<HEIGHT;y++)
        grid[y][X] = '|';
    for(x=0;x<WIDTH;x++)
        grid[Y][x] = '-';
    grid[Y][X] = '+';
}

void show_grid(void) {
    int x,y;
    for(y=0;y<HEIGHT;y++) {
        for(x=0;x<WIDTH;x++)
            putchar(grid[y][x]);
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    float x,y;
    double a,b,c;
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);
    init_grid();
    for(x=a;x<=b;x+=c) {
        y = sin(x);
        plot(rintf(x*10),rintf(y*8));
    }
    show_grid();
    return(0);
}