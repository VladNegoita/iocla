#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "pixel.h"

void swap_p(Pixel **a, Pixel **b)
{
	Pixel *aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void reversePic(Picture *pic)
{
	for (int i = 0; i < (pic->height >> 1); ++i)
		swap_p(pic->pix_array + i, pic->pix_array + pic->height - i - 1);
}

void gray(Pixel *p)
{
	p->R = (unsigned char)((double) p->R * 0.3);
	p->G = (unsigned char)((double) p->G * 0.59);
	p->B = (unsigned char)((double) p->B * 0.11);
}

void colorToGray(Picture *pic)
{
	for (int i = 0; i < pic->height; ++i)
		for (int j = 0; j < pic->width; ++j)
			gray(*(pic->pix_array + i) + j);
}

int main() {
	int height, width;
	scanf("%d%d", &height, &width);
	Pixel **pix_array = generatePixelArray(height, width);
	Picture *pic = generatePicture(height, width, pix_array);

	printPicture(pic);

	reversePic(pic);

	printPicture(pic);

	colorToGray(pic);

	printPicture(pic);

	freePicture(&pic);
	freePixelArray(&pix_array, height, width);

	return 0;
}
