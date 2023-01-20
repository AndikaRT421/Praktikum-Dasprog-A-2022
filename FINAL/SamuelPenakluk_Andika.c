#include <stdio.h>

int main()
{
    // Your code goes here
    unsigned long long N;
    scanf ("%lld", &N);
    for (int i = 0; i < N; i++)
    {
        unsigned long long temp;
        scanf ("%lld", &temp);
        if (temp % 2 == 0)
        {
            temp = (2 * temp) - 1;
        }
        else
        {
            temp = (2 * temp) + 1;
        }
        printf ("%lld\n", temp);
    }
    return 0;
}