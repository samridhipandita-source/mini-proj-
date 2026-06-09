#include <stdio.h>


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

int main()
{
    int height, width;
    intheightwidth(&height, &width);
    char canvas[height][width];
    initializeCanvas(height, width, canvas);

    int choice;
    printf("choose among the following:\n1.point\n2.rectangle");
    scanf("%d", &choice);
    
    if(choice==1)
    {
    int x, y;
    printf("Enter X coordinate: ");
    scanf("%d", &x);

    printf("Enter Y coordinate: ");
    scanf("%d", &y);
    
    drawPoint(x, y, height, width, canvas);
    }
    else if(choice==2)
    {
    int rectX, rectY, rectWidth, rectHeight, res;

        printf("Rectangle X: ");
        scanf("%d", &rectX);

        printf("Rectangle Y: ");
        scanf("%d", &rectY);

        printf("Rectangle Width: ");
        scanf("%d", &rectWidth);

        printf("Rectangle Height: ");
        scanf("%d", &rectHeight);
        
        printf("1. Hollow Rectangle\n");
        printf("2. Filled Rectangle\n");
        
        printf("input 1 for hollow rect, 2 for filled rect ");
        scanf("%d", &res);

        drawRectangle(rectX,rectY,rectWidth,rectHeight,res,height,width,canvas);
    }
    
    printf("\nCanvas:\n\n");

    displayCanvas(height, width, canvas);

    return 0;
}
