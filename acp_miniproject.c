#include <stdio.h>
#include <stdlib.h>

#define ROWS 25
#define COLS 60

char canvas[ROWS][COLS];

/* Function Prototypes */
void newCanvas();
void displayCanvas();
void plot(int x, int y, char ch);
void drawLine(int x1, int y1, int x2, int y2, char ch);
void drawRectangle(int x, int y, int width, int height, char ch);
void circlePoints(int xc, int yc, int x, int y, char ch);
void drawCircle(int xc, int yc, int r, char ch);
void drawTriangle(int x1, int y1, int x2, int y2,
                  int x3, int y3, char ch);

int main()
{
    int choice;

    newCanvas();

    while (1)
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Circle\n");
        printf("4. Draw Triangle\n");
        printf("5. Delete Rectangle\n");
        printf("6. Delete Line\n");
        printf("7. Delete Circle\n");
        printf("8. Delete Triangle\n");
        printf("9. Modify Rectangle\n");
        printf("10. Display Canvas\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int x, y, w, h;

                printf("Top-left row col width height: ");
                scanf("%d %d %d %d", &x, &y, &w, &h);

                drawRectangle(x, y, w, h, '*');

                printf("\nRectangle drawn successfully!\n");
                displayCanvas();
                break;
            }

            case 2:
            {
                int x1, y1, x2, y2;

                printf("x1 y1 x2 y2: ");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

                drawLine(x1, y1, x2, y2, '*');

                printf("\nLine drawn successfully!\n");
                displayCanvas();
                break;
            }

            case 3:
            {
                int xc, yc, r;

                printf("Center row col radius: ");
                scanf("%d %d %d", &xc, &yc, &r);

                drawCircle(xc, yc, r, '*');

                printf("\nCircle drawn successfully!\n");
                displayCanvas();
                break;
            }

            case 4:
            {
                int x1, y1, x2, y2, x3, y3;

                printf("Vertex1 (row col): ");
                scanf("%d %d", &x1, &y1);

                printf("Vertex2 (row col): ");
                scanf("%d %d", &x2, &y2);

                printf("Vertex3 (row col): ");
                scanf("%d %d", &x3, &y3);

                drawTriangle(x1, y1, x2, y2, x3, y3, '*');

                printf("\nTriangle drawn successfully!\n");
                displayCanvas();
                break;
            }

            case 5:
            {
                int x, y, w, h;

                printf("Rectangle to delete (row col width height): ");
                scanf("%d %d %d %d", &x, &y, &w, &h);

                drawRectangle(x, y, w, h, '_');

                printf("\nRectangle deleted successfully!\n");
                displayCanvas();
                break;
            }

            case 6:
            {
                int x1, y1, x2, y2;

                printf("Line to delete (x1 y1 x2 y2): ");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

                drawLine(x1, y1, x2, y2, '_');

                printf("\nLine deleted successfully!\n");
                displayCanvas();
                break;
            }

            case 7:
            {
                int xc, yc, r;

                printf("Circle to delete (center row center col radius): ");
                scanf("%d %d %d", &xc, &yc, &r);

                drawCircle(xc, yc, r, '_');

                printf("\nCircle deleted successfully!\n");
                displayCanvas();
                break;
            }

            case 8:
            {
                int x1, y1, x2, y2, x3, y3;

                printf("Vertex1 (row col): ");
                scanf("%d %d", &x1, &y1);

                printf("Vertex2 (row col): ");
                scanf("%d %d", &x2, &y2);

                printf("Vertex3 (row col): ");
                scanf("%d %d", &x3, &y3);

                drawTriangle(x1, y1, x2, y2, x3, y3, '_');

                printf("\nTriangle deleted successfully!\n");
                displayCanvas();
                break;
            }

            case 9:
            {
                int ox, oy, ow, oh;
                int nx, ny, nw, nh;

                printf("Old rectangle (row col width height): ");
                scanf("%d %d %d %d", &ox, &oy, &ow, &oh);

                drawRectangle(ox, oy, ow, oh, '_');

                printf("New rectangle (row col width height): ");
                scanf("%d %d %d %d", &nx, &ny, &nw, &nh);

                drawRectangle(nx, ny, nw, nh, '*');

                printf("\nRectangle modified successfully!\n");
                displayCanvas();
                break;
            }

            case 10:
            {
                displayCanvas();
                break;
            }

            case 0:
            {
                printf("Exiting program...\n");
                return 0;
            }

            default:
            {
                printf("Invalid Choice!\n");
            }
        }
    }

    return 0;
}

/* Initialize Canvas */
void newCanvas()
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

/* Display Canvas */
void displayCanvas()
{
    int i, j;

    printf("\n");

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

/* Plot a Point */
void plot(int x, int y, char ch)
{
    if (x >= 0 && x < ROWS &&
        y >= 0 && y < COLS)
    {
        canvas[x][y] = ch;
    }
}

/* Draw Rectangle */
void drawRectangle(int x, int y,
                   int width,
                   int height,
                   char ch)
{
    int i;

    for (i = 0; i < width; i++)
    {
        plot(x, y + i, ch);
        plot(x + height - 1, y + i, ch);
    }

    for (i = 0; i < height; i++)
    {
        plot(x + i, y, ch);
        plot(x + i, y + width - 1, ch);
    }
}

/* Draw Line (Bresenham) */
void drawLine(int x1, int y1,
              int x2, int y2,
              char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (1)
    {
        plot(x1, y1, ch);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

/* Circle Helper */
void circlePoints(int xc, int yc,
                  int x, int y,
                  char ch)
{
    plot(xc + x, yc + y, ch);
    plot(xc - x, yc + y, ch);
    plot(xc + x, yc - y, ch);
    plot(xc - x, yc - y, ch);

    plot(xc + y, yc + x, ch);
    plot(xc - y, yc + x, ch);
    plot(xc + y, yc - x, ch);
    plot(xc - y, yc - x, ch);
}

/* Draw Circle (Midpoint Algorithm) */
void drawCircle(int xc, int yc,
                int r, char ch)
{
    int x = 0;
    int y = r;
    int d = 1 - r;

    while (x <= y)
    {
        circlePoints(xc, yc, x, y, ch);

        if (d < 0)
        {
            d += 2 * x + 3;
        }
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }

        x++;
    }
}

/* Draw Triangle */
void drawTriangle(int x1, int y1,
                  int x2, int y2,
                  int x3, int y3,
                  char ch)
{
    drawLine(x1, y1, x2, y2, ch);
    drawLine(x2, y2, x3, y3, ch);
    drawLine(x3, y3, x1, y1, ch);
}