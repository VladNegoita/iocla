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

void mirror(char *s)
{
	int n = my_strlen(s), i = 0;
	char ch;
	while (i < (n >> 1)) {
		ch = *(s + i);
		*(s + i) = *(s + n - i - 1);
		*(s + n - i - 1) = ch;
		++i;
	}
}

int main()
{
	char s[100];
	scanf("%s", s);
	mirror(s);
	printf("%s\n", s);
	return 0;
}

