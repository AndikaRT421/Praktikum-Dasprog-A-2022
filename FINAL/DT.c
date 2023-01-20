#include <stdio.h>

void swap(int arr[], int x, int kecil)
{
    int temp;
    temp = arr[kecil];
    arr[kecil] = arr[x];
    arr[x] = temp;
}

int main()
{
    // Your code goes here
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        int arr[n];
        int tukar = 0;
        // int urutan = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            int min_indeks = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min_indeks])
                    min_indeks = j;

            // if (min_indeks == i)
            // {
            //     urutan++;
            //     continue;
            // }
            while (min_indeks != i)
            {
                swap (arr, min_indeks - 1, min_indeks);
                tukar++;
                min_indeks--;
                // urutan++;
            }           
        }
        printf ("Minimal lakukan %d pertukaran\n", tukar);

        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                printf ("Yeay ");
                flag = 1;
            }
            if (arr[i] % 5 == 0)
            {
                printf ("Lulus ");
                flag = 1;
            }
            if (arr[i] % 10 == 0)
            {
                printf ("Dasprog ");
                flag = 1;
            }

            if (flag == 1)
            {
                printf ("\n");
                flag = 0;
            }
            else
            {
                printf("%d\n",arr[i]);
            }
        }
        // printf ("Jumlah tukar %d\n", tukar);
    }
    return 0;
}