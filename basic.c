#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void intheightwidth(int *height, int *width)
{
    printf("HEIGHT OF CANVAS:\n");
    scanf("%d", height);
    printf("WIDTH OF CANVAS:\n");
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

void drawCircle(int centerX, int centerY, int radius, int height, int width, char canvas[height][width])
{
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            int dx = x - centerX;
            int dy = y - centerY;

            int distanceSquared = dx*dx + dy*dy;

            if(abs(distanceSquared - radius*radius) <= radius)
            {
                canvas[y][x] = '*';
            }
        }
    }
}

void deleteArea(int x, int y, int areaWidth, int areaHeight, int height, int width, char canvas[height][width])
{
    for(int i = y; i < y + areaHeight; i++)
    {
        for(int j = x; j < x + areaWidth; j++)
        {
            if(i >= 0 && i < height &&
               j >= 0 && j < width)
            {
                canvas[i][j] = '_';
            }
        }
    }
}

int main()
{
    int height, width;
    intheightwidth(&height, &width);
    char canvas[height][width];
    initializeCanvas(height, width, canvas);

    int choice;

    while(1)
    {
    printf("choose among the following:\n1.point\n2.rectangle\n3.line\n4.triangle\n5.circle\n6.display canvas\n7.delete area\n8.clear canvas\n9.modify area\n10.exit canvas\n");
    scanf("%d", &choice);
    
    if(choice==1)
    {
    int x, y;
    printf("Enter x coordinate: ");
    scanf("%d", &x);

    printf("Enter y coordinate: ");
    scanf("%d", &y);

    if(x<0||y<0||x>width||y>height)
    {
        printf("invalid coordinates\n");
        exit(0);
    }
    
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
        printf("enter coordinates for vertex1:");
        scanf("%d\t%d", &x1, &y1);
        printf("enter coordinates for vertex2:");
        scanf("%d\t%d", &x2, &y2);
        printf("enter coordinates for vertex3:");
        scanf("%d\t%d", &x3, &y3);

        drawTriangle(x1,y1,x2,y2,x3,y3,height,width,canvas);

    }
    else if(choice==5)
    {
        int centerX, centerY, radius;
        printf("enter center x&y coordinates for circle:");
        scanf("%d\t%d", &centerX, &centerY);
        printf("enter radius of circle:");
        scanf("%d", &radius);

        drawCircle(centerX, centerY, radius, height, width, canvas);
    }
    else if(choice==6)
    {
        printf("\nCanvas:\n\n");

        displayCanvas(height, width, canvas);
        
    }
    else if(choice==7)
    {
        int deleteX, deleteY, deleteWidth, deleteHeight;

        printf("enter x&y coordinates of area to delete: ");
        scanf("%d\t%d", &deleteX, &deleteY);
        printf("enter height & width of area to delete: ");
        scanf("%d\t%d", &deleteWidth, &deleteHeight);

        deleteArea(deleteX, deleteY, deleteWidth, deleteHeight, height, width, canvas);
    }
    else if(choice==8)
    {
         initializeCanvas(height, width, canvas);
    }
    else if(choice==9)
    {
        
    }
    else if(choice==10)
    {
        printf("Exiting canvas\n");
        exit(0);
    }
    else
    {
        printf("Invalid choice! Please try again.\n");
    }
}
return 0;
}
