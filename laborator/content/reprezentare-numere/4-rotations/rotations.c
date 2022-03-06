#include <stdio.h>

void rotate_left(int *number, int bits)
{
	const int size = sizeof(int) * 8;
	bits %= size;
	int mask = (*number) >> (size - bits);
	*number <<= bits;
	*number |= mask;
}

void rotate_right(int *number, int bits)
{
	const int size = sizeof(int) * 8;
	bits %= size;
	int mask = (*number) << (size - bits);
	*number >>= bits;
	*number |= mask;
}

int main()
{
	int n;
	scanf("%d", &n);
	rotate_right(&n, 1);
	printf("%d\n", n);
	return 0;
}

