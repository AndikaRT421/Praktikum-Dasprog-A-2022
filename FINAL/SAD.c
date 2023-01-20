#include <stdio.h>

int main()
{
    // Your code goes here
    int test;
    scanf ("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int num;
        scanf ("%d", &num);
        while (1)
        {
            if (num == 0)
            {
                printf ("YES\n");
                break;
            }
            else if ((num < 11 && num != 0) || (num > 11 && num < 15))
            {
                printf ("NO\n");
                break;
            }

            if (num % 11 == 0)
            {
                num -= 11;
            }
            else if (num % 15 == 0)
            {
                num -= 15;
            }
            else
            {
                num -= 26;
            }
        }
    }
    return 0;
}