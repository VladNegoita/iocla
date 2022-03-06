#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *str)
{
	int cnt = 0;
	while (*(str + cnt)) {
		++cnt;
	}
	return cnt;
}

void equality_check(const char *str)
{
	int n = my_strlen(str), i = 0;
	while (i < n) {
		if (!((*(str + i)) ^ (*(str + (i + (1 << i)) % n)))) {
			printf("Addresses of %c: %p and %p\n", *(str + i), str + i, str + (i + (1 << i)) % n);
		}
		++i;
	}
}

int main(void)
{
	char s[100];
	scanf("%s", s);
	printf("%d\n", my_strlen(s));
	equality_check(s);
	return 0;
}

