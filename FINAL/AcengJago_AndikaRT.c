#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // Your code goes here
    int prima[100002];
    memset (prima, 0, sizeof(prima));
    prima [1] = -1; // non prima
    for (int n = 4; n <= 100000; n++)
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                prima[n] = -1; //non prima
                break;
            }
        }
    }

    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int flagg = 0;
        int angka;
        scanf("%d", &angka);
        for (int k = 0; k < angka; k++)
        {
            int num;
            scanf ("%d", &num);
            if (prima[num] == -1)
            {
                flagg++;
            }
            else if (prima[num] == 0)
            {
                printf ("%d ", num);
            }
        }

        if (flagg == angka)
        {
            printf("Unable to send Fever Slot Buckle.\n");
        }
        else
        {
            printf ("\n");
        }
    }
    return 0;
}