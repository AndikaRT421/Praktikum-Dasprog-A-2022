#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct MB
{
    char lokasi[21];
    int bom;
    char orang[21];
    char loc_orang[21];
} dt_dt;

void Set(dt_dt a[], char perintah[52]);

int UbahBom(dt_dt *a, int tes, char *loloc, int ubah);

void CHGbintang(dt_dt a[], char perintah[52], int tes);

void CHGtanpaBINTANG(dt_dt a[], char perintah[52], int tes);

int main()
{
    // Your code goes here
    int tes;
    scanf("%d", &tes);
    dt_dt situasi[101];
    for (int i = 0; i < tes; i++)
    {
        char perintah1[52]; // tes size arr 1
        scanf("%s", perintah1);
        char perintah2[52];

        int swp = 0;

        if (!strcmp(perintah1, "set"))
        {
            scanf("%s", perintah2);
            Set(&situasi[i], perintah2);
        }
        else if (!strcmp(perintah1, "chg"))
        {
            scanf("%s", perintah2);
            if (!strcmp(perintah2, "*"))
            {
                CHGbintang(situasi, perintah2, tes);
            }
            else
            {
                CHGtanpaBINTANG(situasi, perintah2, tes);
            }
        }
        else if (!strcmp(perintah1, "get"))
        {
            scanf(" * %s", perintah2);
            printf("%d\n", UbahBom(situasi, tes, perintah2, swp));
        }
    }
    return 0;
}

void Set(dt_dt a[], char perintah[52])
{
    if (strcmp(perintah, "*") == 0)
    {
        char selanjutnya[50];
        scanf("%s & ", selanjutnya);
        strcpy(a->orang, selanjutnya);
        scanf("%s", a->loc_orang);
    }
    else
    {
        strcpy(a->lokasi, perintah);
        scanf("%d", &a->bom);
    }
}

int UbahBom(dt_dt *a, int tes, char *loloc, int ubah)
{
    for (int i = 0; i < tes; i++)
    {
        if (!strcmp(loloc, a[i].orang))
            return UbahBom(a, tes, a[i].loc_orang, ubah);
        else if (strcmp(loloc, a[i].lokasi) == 0 && ubah == 0)
            return a[i].bom;
        else if (strcmp(loloc, a[i].lokasi) == 0)
        {
            a[i].bom = ubah;
            return a[i].bom;
        }
    }
    return -1;
}

void CHGbintang(dt_dt a[], char perintah[52], int test)
{
    char manungso[50], sesuatu[50];
    scanf("%s", manungso);
    for (int i = 0; i < test; i++)
    {
        if (!strcmp(manungso, a[i].orang))
        {
            scanf("%s", sesuatu);
            if (strcmp(sesuatu, "&") == 0)
            {
                scanf("%s", a[i].loc_orang);
            }
            else
            {
                UbahBom(a, test, a[i].loc_orang, atoi(sesuatu));
            }
        }
    }
}

void CHGtanpaBINTANG(dt_dt a[], char perintah[52], int tes)
{
    for (int i = 0; i < tes; i++)
    {
        if (!strcmp(perintah, a[i].orang))
        {
            scanf(" &");
            scanf("%s", a[i].loc_orang);
        }
        else if (!strcmp(perintah, a[i].lokasi))
        {
            scanf("%d", &a[i].bom);
        }
    }
}