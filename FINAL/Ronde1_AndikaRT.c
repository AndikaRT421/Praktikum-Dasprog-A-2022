#include <stdio.h>
#include <string.h>

typedef struct Ronde1_AndikaRT
{
    char nama [52];
    int diambil;
}dt_dt;

int JumlahinSub(int a[], int ukuran)
{
	int nilai_max = -2147483648, nilai_ending = 0;

	for (int i = 0; i < ukuran; i++) {
		nilai_ending = nilai_ending + a[i];
		if (nilai_max < nilai_ending)
			nilai_max = nilai_ending;

		if (nilai_ending < 0)
			nilai_ending = 0;
	}
	return nilai_max;
}


int main()
{
    // Your code goes here
    int test;
    scanf ("%d", &test);
    dt_dt orang[test];
    for (int i = 0; i < test; i++)
    {
        scanf ("%s", orang[i].nama);
        int jumlah_arr;
        scanf ("%d", &jumlah_arr);
        int arr[jumlah_arr];
        for (int k = 0; k < jumlah_arr; k++)
        {
            int temp;
            scanf ("%d", &temp);
            arr[k] = temp;
        }
        int ukuran_arr = sizeof (arr) / sizeof (arr[0]);
        orang[i].diambil = JumlahinSub (arr, ukuran_arr);
    }

    int terbanyak = orang[0].diambil;
    int indeks_terbanyak = 0;
    for (int i = 0; i < test; i++)
    {
        if (terbanyak < orang[i].diambil)
        {
            terbanyak = orang[i].diambil;
            indeks_terbanyak = i;
        }
    }

    printf ("%s\n", orang[indeks_terbanyak].nama);
    return 0;
}