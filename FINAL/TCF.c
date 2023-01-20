#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool flag[51][51];

typedef struct TCF
{
    char tempat[52];
    char nama[52];
    int umur;
    char telepon[52];
    int konco;
    int koncosatue;
} keterangan;

typedef struct
{
    keterangan orang[12];
    int total_penduduk;
} dt_penduduk;

typedef struct
{
    dt_penduduk asal[11];
    char kota[51];
} lokasi;

keterangan dt_masukan()
{
    keterangan var;
    scanf("%s", var.nama);
    scanf("%d", &var.umur);
    scanf("%s", var.telepon);

    return var;
}

int main()
{
    // Your code goes here
    memset(flag, false, sizeof(flag));
    int tes;
    scanf("%d", &tes);
    lokasi manusia;
    char loc[52][52];
    // int i = 0;
    // int wong_piro[tes];
    // int indeks_penduduk = 0;

    for (int i = 0; i < tes; i++)
    {
        scanf("%s", loc[i]);
        int wong_piro;
        scanf("%d", &wong_piro);
        manusia.asal[i].total_penduduk = wong_piro;
        for (int k = 0; k < wong_piro; k++)
        {
            manusia.asal[i].orang[k] = dt_masukan();
            strcpy(manusia.asal[i].orang[k].tempat, loc[i]);
            // penduduk[indeks_penduduk].konco = -1;
            // indeks_penduduk++;
        }
        // i++;
    }
    int jumlah_konco;
    scanf("%d", &jumlah_konco);

    for (int i = 0; i < jumlah_konco; i++)
    {
        char siapa[52], temannya[52];
        scanf("%s %s", siapa, temannya);
        for (int j = 0; j < tes; j++)
        {
            for (int k = 0; k < manusia.asal[j].total_penduduk; k++)
            {
                if (!strcmp(siapa, manusia.asal[j].orang[k].nama))
                {
                    for (int m = 0; m < tes; m++)
                    {
                        for (int x = 0; x < manusia.asal[m].total_penduduk; x++)
                        {
                            if (!strcmp(temannya, manusia.asal[m].orang[x].nama))
                            {
                                manusia.asal[j].orang[k].konco = m;
                                manusia.asal[j].orang[k].koncosatue = x;
                                flag[j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < tes; i++)
    {
        printf("%s\n", loc[i]);
        for (int j = 0; j < manusia.asal[i].total_penduduk; j++)
        {
            printf("Name: %s\n", manusia.asal[i].orang[j].nama);
            printf("Age: %d\n", manusia.asal[i].orang[j].umur);
            printf("Phone Number:%s\n", manusia.asal[i].orang[j].telepon);
            if (flag[i][j])
            {
                printf("His/Her bestie is: %s\nHis/Her contact info is as follows\n", manusia.asal[manusia.asal[i].orang[j].konco].orang[manusia.asal[i].orang[j].koncosatue].nama);
                printf("Name: %s\n", manusia.asal[manusia.asal[i].orang[j].konco].orang[manusia.asal[i].orang[j].koncosatue].nama);
                printf("Age: %d\n", manusia.asal[manusia.asal[i].orang[j].konco].orang[manusia.asal[i].orang[j].koncosatue].umur);
                printf("Phone Number:%s\n", manusia.asal[manusia.asal[i].orang[j].konco].orang[manusia.asal[i].orang[j].koncosatue].telepon);
            }
            else
            {
                printf("His/Her bestie is: No one\n");
            }
            printf("\n");
        }
    }
    return 0;
}