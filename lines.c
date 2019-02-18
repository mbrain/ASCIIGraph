#include <stdio.h>

#define WIDTH 60
#define HEIGHT 20
#define X WIDTH/2
#define Y HEIGHT/2
#define XMAX WIDTH-X-1
#define XMIN -(WIDTH-X)
#define YMAX HEIGHT-Y
#define YMIN -(HEIGHT-Y)+1

char grid[HEIGHT][WIDTH];

int line(int x1, int y1, int x2, int y2);
int horzline(int x1, int x2, int y);
int vertline(int x, int y1, int y2);
int plot(int x, int y);
void init_grid(void);
void show_grid(void);

int main()
{
    init_grid();
    line(-4,3,3,-5);
    line(-20,-5,20,-5);
    line(-20,-9,20,9);
    show_grid();

    return(0);
}

/* draw a line from point x1,y1 to x2,y2 */
int line(int x1, int y1, int x2, int y2)
{
    int x,deltaY,deltaX;
    float slope,y;

    /* Calculate the slope */
    deltaY=(Y-y1)-(Y-y2);       /* Calculate using absolute */
    deltaX=(X+x2)-(X+x1);       /*  coordinates */
    slope=(float)deltaY/(float)deltaX;

    /* check for certain exceptions */
    if( y1 == y2 )          /* line is flat */
    {
        horzline(x1,x2,y1);
        return(1);
    }
    if( slope > X)          /* line is too steep */
    {
        vertline(x1,y1,y2);
        return(1);
    }

    /* Plot the points on the line */
    x = x1;
    y = (float)y1;
    while( x!=x2 && (int)y!=y2)
    {
        plot(x,(int)y);
        y += slope;
        if( x1 < x2 )
            x++;
        if( x1 > x2 )
            x--;
    }
    return(1);
}

/* Draw Horizontal Line */
int horzline(int x1, int x2, int y)
{
    int x;

    for(x=x1;x<=x2;x++)
        plot(x,y);

    return(1);
}

/* Draw Vertical Line */
int vertline(int x, int y1, int y2)
{
    int y;

    for(y=y1;y<=y2;y++)
        plot(x,y);

    return(1);
}

/* Set "pixel" at specific coordinates */
int plot(int x, int y)
{
    if( x > XMAX || x < XMIN || y > YMAX || y < YMIN )
        return(-1);

    grid[Y-y][X+x] = '*';
    return(1);
}

/* Initialize grid */
void init_grid(void)
{
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

/* display grid */
void show_grid(void)
{
    int x,y;

    for(y=0;y<HEIGHT;y++)
    {
        for(x=0;x<WIDTH;x++)
            putchar(grid[y][x]);
        putchar('\n');
    }
}