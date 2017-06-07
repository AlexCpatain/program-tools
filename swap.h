#ifndef __SWAP__
#define __SWAP__

#include <string.h>

void swap(void *first, void *second, int elemsize)
{
	if(first == NULL || second == NULL || elemsize <= 0)
		return ;
	char buf[elemsize];
	memcpy(buf, (char *)first, elemsize);	
	memcpy((char *)first, (char *)second, elemsize);
	memcpy((char *)second, buf, elemsize);
}

#endif
