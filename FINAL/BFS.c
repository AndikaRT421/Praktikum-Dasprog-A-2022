#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NUM_BITS_INT (sizeof(int) * 8)

int bitflipp(int n, int m)
{
    int hitung = 0;
    bool kondisi = false;
    int a, b;
    for (int i = NUM_BITS_INT - 1; i >= 0; i--)
    {
        a = (n >> i) & 1;
        b = (m >> i) & 1;
        // if (a != b)
        //     count++;
        if (a != b && i != 0)
        {
            kondisi = true;
        }
        else if (a != b && i == 0)
        {
            kondisi = true;
            hitung++;
        }
        if (a == b && kondisi)
        {
            kondisi = false;
            hitung++;
        }
    }
    return hitung;
}

int main()
{
    // Your code goes here
    int test;
    scanf("%d", &test);
    int angka;
    scanf("%d", &angka);

    for (int i = 0; i < test; i++)
    {
        int flipp;
        scanf("%d", &flipp);
        if (flipp != 0)
        {
            angka = angka ^ (1 << flipp - 1);
        }
        int num;
        scanf("%d", &num);
        int tukar = bitflipp(angka, num);
        angka = num;
        printf("%d\n", tukar);
    }
    return 0;
}