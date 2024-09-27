#include <stdio.h>
#include <stdlib.h>

void print_binary(int number, int nr_bits)
{
	printf("0b");
	for (int i = nr_bits - 1; i >= 0; --i)
		printf("%d", (((1 << i) & number ) >> i));
	printf("\n");
}

void print_hex(int number, int nr_bits)
{
	printf("0x");
	for (int i = nr_bits - 1; i >= 3; i -= 4)
		printf("%x", ((((1 << i) + (1 << (i - 1)) + (1 << (i - 2)) + (1 << (i - 3))) & number) >> (i - 3)));
	printf("\n");
}

void check_parity(int *numbers, int n)
{
	for (int i = 0; i < n; ++i)
		if ((*(numbers + i)) & 1)
			print_hex(*(numbers + i), 8 * sizeof(int));
		else
			print_binary(*(numbers + i), 8 * sizeof(int));
}

int main()
{
	int n, v[100];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", v + i);
	check_parity(v, n);
	return 0;
}

