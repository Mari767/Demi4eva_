
void Fsum(int* massiv, int* Sum, int *Size, int * negative) {
	for (int i = 0; i < *Size; i++) {
		if (*(massiv + i) < 0) {
			*Sum += *(massiv + i);
			++*negative;
		}
	}
}