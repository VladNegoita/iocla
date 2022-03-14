#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* delete_first(char *s, char *pattern)
{
	char *p = strstr(s, pattern);
	if (p) {
		strcpy(p, p + strlen(pattern));
	}
	return s;
}

int main(){
	char s[100] = "Ana are mere";
	char *pattern = "re";

	printf("%s\n", delete_first(s, pattern));

	return 0;
}
