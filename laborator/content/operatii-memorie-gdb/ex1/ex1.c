#include <stdio.h>

/**
 * Afisati adresele elementelor din vectorul "v" impreuna cu valorile
 * de la acestea.
 * Parcurgeti adresele, pe rand, din octet in octet,
 * din 2 in 2 octeti si apoi din 4 in 4.
 */

void print(int *v, int byte_count, int step)
{

	void *p = v;

	byte_count /= step;

	for (int i = 0; i < byte_count; ++i) {
		if (step == 1)
			printf("Char : Address : %p Value : 0x%hhx\n", (char *)p + i, *((char *)p + i));
		else if (step == 2)
			printf("Short: Address : %p Value : 0x%hx\n", (short *)p + i, *((short *)p + i));
		else
			printf("Int : Address : %p Value : 0x%x\n", (int *)p + i, *((int *)p + i));
	}
}

int main() {
    int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};

    print(v, sizeof(v), 1);
    print(v, sizeof(v), 2);
    print(v, sizeof(v), 4);
    return 0;
}
