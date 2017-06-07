#ifndef __BSEARCH__
#define __BSEARCH__

#include <string.h>

//s2 default to be a sequence,like array and already sorted
void *bsearch(void *s1, void *s2, int n, int elemsize)
{
	if(s1 == NULL || s2 == NULL || n <= 0 || elemsize <= 0)
		return ;
	int lo = 0, hi = n-1;
	while(lo <= hi){
		int mid = (lo+hi)/2;
		int result = memcmp((char *)s1, (char *)s2 + mid * elemsize, elemsize);
		if(result == 0)
			return s2 + mid * elemsize;
		else if(result < 0){
			hi = mid-1;
		}
		else {
			lo = mid + 1;
		}
	}
	return NULL;
}

#endif
