#include <stdio.h>

int main(void)
{
	int v[] = {4, 1, 2, -17, 15, 22, 6, 2};
	int max;
	int i;
	int n = sizeof(v)/sizeof(v[0]);

	/* TODO: Implement finding the maximum value in the vector */
	max = v[0];
	i = 1;

label2:
	if (i >= n)
		goto label1;

	if (i > max)
		max = v[i];

	++i;

	goto label2;

label1:
	printf("%d\n", max);
	return 0;
}
