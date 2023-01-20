#include <stdio.h>

unsigned long long hasil = 0;
unsigned long long fix_modulo = 1000000007;

unsigned long long FPB(int x, unsigned long long y)
{
    if (y == 0)
    {
        return x;
    }
    return FPB(y, x % y);
}

unsigned long long powerr(unsigned long long a, unsigned long long b, unsigned long long M)
{
    if (b == 0)
    {
        return 1;
    }  

    unsigned long long temp = powerr(a, b / 2, M);
    temp = (temp * temp)%M;

    if (b & 1)
    {
        temp = (a * temp)%M;
    }

    return temp;
}

int main()
{
    unsigned long long manik, warna;
    scanf("%llu %llu", &manik, &warna);

    unsigned long long x;

    for (int i = 0; i < manik; i++)
    {
        x = FPB(i, manik);
        hasil = (powerr(warna, x, fix_modulo) + hasil) % fix_modulo;
    }
    hasil = (powerr(manik, fix_modulo - 2, fix_modulo) * hasil) % fix_modulo;

    printf("%llu", hasil);

    return 0;
}

