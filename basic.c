#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void intheightwidth(int *height, int *width)
{
    printf("HEIGHT:\n");
    scanf("%d", height);
    printf("WIDTH:\n");
    scanf("%d", width);
}

void initializeCanvas(int height, int width, char canvas[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++) 
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas(int height, int width, char canvas[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawPoint(int x, int y, int height, int width, char canvas[height][width])
{
    if(x >= 0 && x < width &&
       y >= 0 && y < height)
    {
        canvas[y][x] = '*';
    }
    else
    {
        printf("Invalid coordinates!\n");
    }
}

void drawRectangle(int x, int y, int rectWidth, int rectHeight, int res, int height, int width, char canvas[height][width])
{
    if(res==1)
    {

    for(int j = x; j < x + rectWidth; j++)
    {
        canvas[y][j] = '*';

        canvas[y + rectHeight - 1][j] = '*';
    }

    for(int i = y; i < y + rectHeight; i++)
    {
        canvas[i][x] = '*';

        canvas[i][x + rectWidth - 1] = '*';
    }
    }

    else
    {
    for(int i = y ; i <y + rectHeight ; i++)
    {
        for(int j = x ; j < x + rectWidth ; j++)
        {
            canvas[i][j] = '*';
        }
    }
    }
}

void drawLine(int x1, int y1, int x2, int y2, int height, int width, char canvas[height][width])
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1;
    float y = y1;

    for(int i = 0; i <= steps; i++)
    {
        int px = round(x);
        int py = round(y);

        if(py >= 0 && py < height && px >= 0 && px < width)
        {
            canvas[py][px] = '*';
        }

        x += xIncrement;
        y += yIncrement;
    }
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int height, int width, char canvas[height][width])
{
    drawLine(x1, y1, x2, y2,
             height, width, canvas);

    drawLine(x2, y2, x3, y3,
             height, width, canvas);

    drawLine(x3, y3, x1, y1,
             height, width, canvas);
}

int main()
{
    int height, width;
    intheightwidth(&height, &width);
    char canvas[height][width];
    initializeCanvas(height, width, canvas);

    int choice;
    printf("choose among the following:\n1.point\n2.rectangle\n3.line\n4.triangle");
    scanf("%d", &choice);
    
    if(choice==1)
    {
    int x, y;
    printf("Enter x coordinate: ");
    scanf("%d", &x);

    printf("Enter y coordinate: ");
    scanf("%d", &y);
    
    drawPoint(x, y, height, width, canvas);
    }
    else if(choice==2)
    {
    int rectX, rectY, rectWidth, rectHeight, res;

        printf("Rectangle X&Y coordinates: ");
        scanf("%d\t%d", &rectX, &rectY);

        printf("Rectangle width and height: ");
        scanf("%d\t%d", &rectWidth, &rectHeight);
        
        printf("1. hollow Rectangle\n");
        printf("2. filled Rectangle\n");
        
        printf("input 1 for hollow rect, 2 for filled rect \n");
        scanf("%d", &res);

        drawRectangle(rectX,rectY,rectWidth,rectHeight,res,height,width,canvas);
    }
    else if(choice==3)
    {
        int x1,y1,x2,y2;
        printf("enter point1 x&y coordinates:");
        scanf("%d\t%d", &x1, &y1);
        printf("enter point2 x&y coordinates:");
        scanf("%d\t%d", &x2, &y2);
        drawLine(x1,y1,x2,y2,height,width,canvas);
    }
    else if(choice==4)
    {
        int x1,x2,x3,y1,y2,y3;
        printf("enter coordinates for vetex1:");
        scanf("%d\t%d", &x1, &y1);
        printf("enter coordinates for vetex2:");
        scanf("%d\t%d", &x2, &y2);
        printf("enter coordinates for vetex3:");
        scanf("%d\t%d", &x3, &y3);

        drawTriangle(x1,y1,x2,y2,x3,y3,height,width,canvas);

    }
    
    printf("\nCanvas:\n\n");

    displayCanvas(height, width, canvas);

    return 0;
}
