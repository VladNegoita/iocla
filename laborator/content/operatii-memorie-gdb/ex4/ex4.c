#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	Functie generica pentru calcularea valorii maxime dintr-un array.
	n este dimensiunea array-ului
	element_size este dimensiunea unui element din array
	Se va parcurge vectorul arr, iar la fiecare iteratie sa va verifica
	daca functia compare intoarce 1, caz in care elementul curent va fi
	si cel maxim. 
	Pentru a folosi corect aritmetica pe pointeri vom inmulti indexul curent
	din parcurgere cu dimensiunea unui element.
	Astfel, pentru accesarea elementului curent avem:
	void *cur_element = (char *)arr + index * element_size;
*/

void *find_max(void *arr, int n, int element_size, 
				int (*compare)(const void *, const void *)) {
	void *max_elem = arr;

	for (int i = 1; i < n; ++i) {
		if (compare(arr + i * element_size, max_elem))
			max_elem = arr + i * element_size;
	}

	return max_elem;
}

int compare(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b;

	if (*x > *y)
		return 1;
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);

	int *arr = malloc(n * sizeof(*arr));

	for (int i = 0 ; i < n; ++i)
		scanf("%d", &arr[i]);

	printf("%d\n", *((int *)find_max(arr, n, sizeof(int), compare)));   

	free(arr);
	return 0;
}
