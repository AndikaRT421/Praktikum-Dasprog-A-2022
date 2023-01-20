#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DyingKing_AndikaRT
{
    char tempat[102];
    char latitude[100003];
    char longitude[100003];
    int kondisi;
} struk;

int main()
{
    // Your code goes here
    int prima[100002];
    memset(prima, 0, sizeof(prima));
    prima[1] = -1; // non prima
    for (int n = 4; n <= 100000; n++)
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                prima[n] = -1; // non prima
                break;
            }
        }
    }

    int tes_struk, tes_out;
    scanf("%d %d", &tes_struk, &tes_out);
    struk lokasi[tes_struk];
    for (int i = 0; i < tes_struk; i++)
    {
        scanf("%s", lokasi[i].tempat);
        scanf("%s", lokasi[i].latitude);
        char *ptr1;
        int ret1;
        ret1 = strtol(lokasi[i].latitude, &ptr1, 10);
        scanf("%s", lokasi[i].longitude);
        char *ptr2;
        int ret2;
        ret2 = strtol(lokasi[i].longitude, &ptr2, 10);

        if (prima[ret1] == 0 && prima[ret2] == 0)
        {
            lokasi[i].kondisi = 1;
        }
        else
        {
            lokasi[i].kondisi = 0;
        }
    }
    int flagg = 0;
    for (int i = 0; i < tes_out; i++)
    {
        char perintah[102];
        scanf("%s", perintah);
        int indeks;
        for (int k = 0; k < tes_struk; k++)
        {
            if (!strcmp(perintah, lokasi[k].tempat))
            {
                flagg = 1;
                indeks = k;
                break;
            }
        }

        if (flagg == 1)
        {
            if (lokasi[indeks].kondisi == 1)
            {
                printf("%s aman! Bangunlah Kesatria!\n", lokasi[indeks].tempat);
                flagg = 0;
                // continue;
            }
            else
            {
                printf("%s tidak aman! Ini pasti ulah Gorgom!\n", lokasi[indeks].tempat);
                flagg = 0;
                // continue;
            }
        }
        else
        {
            printf("Tempat apa itu? Kotaro tidak tahu!\n");
            flagg = 0;
        }
    }

    return 0;
}