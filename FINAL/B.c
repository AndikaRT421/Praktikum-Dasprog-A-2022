#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int palind = 0;

void HitungPalind(char str[])
{
	int panjang = strlen(str);

	for (int i = 0; i < panjang; i++)
	{
		int z = i - 1;
		int k = i;
		while (k < panjang-1 && str[k] == str [k+1])
		{
			k++;
		}

		palind += (k-z)*(k-z+1)/2;
		i = k++;
		while (z >= 0 && k < panjang && str[k++] == str[z--])
		{
			palind++;
		}
	}	
}

int main()
{
	// Your code goes here
	char kata[100002];
	scanf("%s", &kata);


	int panjang_kata = strlen(kata);
	// printf ("%d\n", panjang_kata);
	char kakatata [panjang_kata];
	memcpy (kakatata, kata, panjang_kata + 1);
	// printf ("%s\n", kakatata);
	HitungPalind(kakatata);
	// palind += panjang_kata;
	printf("%d\n", palind);
	return 0;
}