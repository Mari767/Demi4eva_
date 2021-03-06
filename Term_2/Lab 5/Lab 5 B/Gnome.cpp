#include <iostream>

void Gnome_sort(int* massiv, int Size) {
	int i = 1, j = 2;
	while (i < Size)
	{
		if (*(massiv + i - 1) <= *(massiv + i)) {
			i = j; j++;
		}
		else
		{
			int t = *(massiv + i);
			*(massiv + i) = *(massiv + i - 1);
			*(massiv + i - 1) = t;
			i--;
			if (i == 0) {
				i = j;
				j++;
			}
		}
	}
}
