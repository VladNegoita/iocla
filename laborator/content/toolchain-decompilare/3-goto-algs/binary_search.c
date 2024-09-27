#include <stdio.h>

int main(void)
{
	int v[] =  {1, 2, 15, 51, 53, 66, 202, 7000};
	int dest = 3;
	int start = 0;
	int end = sizeof(v) / sizeof(int) - 1;
	int index, ans = -1;

start:
	if (end < start)
		goto out;

	index = start + ((end - start) >> 1);
	if (v[index] == dest) {
		ans = index;
		goto out;
	}

	if (v[index] > dest) {
		end = index - 1;
		goto start;
	}

	if (v[index] < dest) {
		start = index + 1;
		goto start;
	}

out:
	printf("%d\n", ans);
	return 0;
}
