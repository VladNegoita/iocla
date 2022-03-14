#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int my_strcmp(const char *s1, const char *s2)
{
	int n = strlen(s1);
	int m = strlen(s2);
	int p = min(n, m);
	for (int i = 0; i < p; ++i)
		if ((*(s1 + i)) ^ (*(s2 + i)))
			return *(s1 + i) - *(s2 + i);

	if (p < n)
		return 1;
	else if (p < m)
		return -1;

	return 0;
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
	for (int i = 0; i < n; ++i)
		*((char *)dest + i) = *((char *)src + i);

	return dest;
}

char *my_strcpy(char *dest, const char *src)
{
	int n = strlen(src);//or my_strlen

	for (int i = 0; i <= n; ++i)
		*(dest + i) = *(src + i);

	return dest;
}

int main() {
	char s1[] = "Abracadabra";
	char s2[] = "Abracababra";
	char src[] = "Learn IOCLA, you must!";
	char *dest = malloc(sizeof(src));

	assert(my_strcmp(s1, s2) == strcmp(s1, s2));
	assert(my_memcpy(dest, src, sizeof(src)) == memcpy(dest, src, sizeof(src)));
	assert(my_strcpy(dest, src) == strcpy(dest, src));
	free(dest);

	return 0;
}
