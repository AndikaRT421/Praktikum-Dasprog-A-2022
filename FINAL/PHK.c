#include <stdio.h>

int tengah_x, tengah_y;

void mboh (int x_min, int x_max, int y_min, int y_max)
{
    tengah_x = (x_min + x_max) / 2;
    tengah_y = (y_min + y_max) / 2;

    printf("LIHAT %d %d\n", tengah_x, tengah_y);
    fflush(stdout);
}

int main()
{
    // Your code goes here
    int n;
    scanf("%d", &n);

    int x_min = 1, y_min = 1;
    int x_max = n, y_max = n;
    mboh (x_min, x_max, y_min, y_max);

    while (1)
    {
        int masukan;
        scanf("%d", &masukan);
        switch (masukan)
        {
            case 1:
            y_min = tengah_y;
            x_max = tengah_x;
            mboh (x_min, x_max, y_min, y_max);
                break;
            case 2:
            y_min = tengah_y;
            mboh (x_min, x_max, y_min, y_max);
                break;
            case 3:
            x_min = tengah_x;
            y_min = tengah_y;
            mboh (x_min, x_max, y_min, y_max);
                break;
            case 4:
            x_max = tengah_x;
            mboh (x_min, x_max, y_min, y_max);
                break;
            case 5:
            printf ("KOORDINAT %d %d\n", tengah_x, tengah_y);
            return 0;
                break;
            case 6:
            x_min = tengah_x;
            mboh (x_min, x_max, y_min, y_max);
                break;
            case 7:
            y_max = tengah_y;
            x_max = tengah_x;
            mboh (x_min, x_max, y_min, y_max);
                break;
            case 8:
            y_max = tengah_y;
            mboh (x_min, x_max, y_min, y_max);
                break;
            case 9:
            y_max = tengah_y;
            x_min = tengah_x;
            mboh (x_min, x_max, y_min, y_max);
                break;
            default:
                break;
        }
    }
    return 0;
}