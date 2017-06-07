#ifndef __LSEARCH__
#define __LSEARCH__

#include <string.h>

//s2 default to be a sequence,like array
void *lsearch(void *s1, void *s2, int n, int elemsize)
{
	if(s1 == NULL || s2 == NULL || n <= 0 || elemsize <= 0)
		return ;
	int i = 0;
	for(i = 0; i < n; ++i){
		if(memcmp((char *)s1, (char *)s2 + i * elemsize, elemsize) == 0)
			return s2 + i * elemsize;
	} 
	return NULL;
}

#endif
