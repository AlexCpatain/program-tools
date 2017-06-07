#include "lsearch.h"
#include "bsearch.h"
#include "swap.h"
#include <stdio.h>

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int elem = 2;
	int *ret = bsearch(&elem, arr, 6, sizeof(int));
	if(ret != NULL)
		printf("%d\n", *ret);
	int other = 4;
	swap(&elem, &other, sizeof(int));
	printf("elem = %d other = %d\n", elem, other);
	return 0;
}
