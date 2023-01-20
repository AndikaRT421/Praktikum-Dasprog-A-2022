#include <stdio.h>
#include <string.h>

// typedef struct Ujana_AndikaRT
// {
//     long long biaya;
// }akun;

long long poin(unsigned long long x)
{
    long long ppoin;
    if (x <= 100000)
    {
        ppoin = 1;
    }
    else if (x > 100000 && x <= 500000)
    {
        ppoin = 5;
    }
    else if (x > 500000 && x <= 10000000)
    {
        ppoin = 20;
    }
    else if (x > 10000000 && x <= 500000000)
    {
        ppoin = 35;
    }
    else if (x > 500000000)
    {
        ppoin = 50;
    }
    return ppoin;
}

int main()
{
    // Your code goes here
    unsigned long long saldo;
    scanf("%llu", &saldo);
    int test;
    scanf("%d", &test);

    int krisis = 0;

    long long total = 0;
    for (int i = 0; i < test; i++)
    {
        char perintah[7];
        scanf("%s", perintah);
        if (!strcmp(perintah, "Iya"))
        {
            unsigned long long biaya;
            scanf("%llu", &biaya);
            total += poin(biaya);
            // long long mboh = 0;
            if (saldo < biaya)
            {
                krisis = 1;
                break;
            }
            else
            {
                saldo -= biaya;
            }
        }
        else if (!strcmp(perintah, "Tidak"))
        {
            unsigned long long biaya;
            scanf("%llu", &biaya);
            total = total + (poin(biaya) * -1);
            // long long mboh = 0;
            if (saldo < biaya)
            {
                krisis = 1;
                break;
            }
            else
            {
                saldo -= biaya;
            }
        }
    }

    if (krisis == 0 && total > 0 && saldo > 0)
    {
        printf("Ujana berakhir bahagia.\n");
    }
    else if (krisis == 0 && total == 0 && saldo > 0)
    {
        printf("Ujana berakhir b aja.\n");
    }
    else if (krisis != 0 || total < 0 || saldo <= 0)
    {
        printf("Ujana tidak berakhir bahagia.\n");
    }
    return 0;
}