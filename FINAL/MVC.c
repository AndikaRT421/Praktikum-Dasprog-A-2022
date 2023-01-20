#include <stdio.h>
#include <string.h>

char angka[21];
char temp[21];
char maxx [21];
int digit;

void mengurutkan (int a, int b)
{
    int z = 0;
    for (int i = a; i <= b; i++)
    {
        temp[z] = angka[i];
        z++;
    }

    for (int i = 0; i < digit - 1; i++)
    {
        for (int k = 1 + i; k < digit; k++)
        {
            if (temp[k] > temp[i])
            {
                char sementara = temp[k];
                temp[k] = temp[i];
                temp[i] = sementara;
            }
        }
    }

    if (strcmp(temp, maxx) > 0)
    {
        strcpy(maxx, temp);
    }
}

int main()
{
    // Your code goes here
    scanf("%s", angka);
    char terbesar = angka[0];
    int indeks_terbesar[21];
    indeks_terbesar[0] = 0;

    for (int i = 1; i < strlen(angka); i++) // cek terbesar
    {
        if (terbesar < angka[i])
        {
            terbesar = angka[i];
            indeks_terbesar[0] = i;
        }
    }

    int indeks_cuy = 1;
    for (int i = 0; i < strlen(angka); i++) // cek terbesar yang sama
    {
        if (terbesar == angka[i] && i != indeks_terbesar[0])
        {
            indeks_terbesar[indeks_cuy] = i;
            indeks_cuy++;
        }
    }

    scanf("%d", &digit);
    strcpy (maxx, "0");
    for (int x = 0; x < indeks_cuy; x++) //worst case
    {
        int kanan = indeks_terbesar[x];
        int kiri = indeks_terbesar[x]-(digit - 1);
        if (kiri < 0)
        {
            kiri++;
            kanan++;
        }
        
        while (kiri != indeks_terbesar[x] + 1)
        {
            if (kanan > strlen (angka))
            {
                break;
            }
            mengurutkan (kiri, kanan);
            kiri++;
            kanan++;
        }
    }

    printf ("%s\n", maxx);

    // printf ("%c\n%d\n%d\n", terbesar, indeks_terbesar[1], indeks_cuy);
    return 0;
}