#include "vector.h"
#include <stdio.h>
#include <errno.h>

void vector_init(vector *vec, int elemsize, int n, void (*freefn)(void *p))
{
	vec->elem = malloc(elemsize * n);
	if(vec->elem == NULL)
		perror("alloc error");
	vec->elemsize = elemsize;
	vec->allocsize = n;
	vec->logicsize = 0;
	vec->freefn = freefn;
}
void vector_delete(vector *vec)
{
	int i;
	if(vec->freefn != NULL)
		for(i = 0; i<vec->logicsize; i++){
			vec->freefn((char *)vec->elem + i * vec->elemsize)
		}
	free(vec->elem);
	vec->elem = NULL;
	vec->logicsize = 0;
	vec->allocsize = 0;
}

void vector_resize(vector *vec, int size)
{
	if(size <= 0) return ;
	vec->elem = realloc(vec->elem, size);
	vec->allocsize = size;
	if(size < vec->logicsize)
		vec->logicsize = size;
}

void vector_pushBack(vector *vec,const void *elemAddr)
{
	if(vector_full(vec)){
		vector_resize(vec, vec->logicsize * 2);
	}
	memcpy(elemAddr, (char *)vec->elem + vec->logicsize * vec->elemsize, vec->elemsize);
	vec->logicsize++;
}
void vector_popBack(vector *vec, const void *elemAddr)
{
	if(!vector_empty(vec)){
		vec->logicsize--;
		memcpy(elemAddr, (char *)vec->elem + vec->logicsize * vec->elemsize);
	}
}

bool vector_insert(vector *vec, void *destElemAddr, void *srcElemAddr)
{
	if(vector_full(vec))
		vector_resize(vec, vec->logicsize * 2);
	int rightSize = (char *)vec->elem + vec->logicsize * vec->elemsize -
			        (char *)destElemAddr;
	if(rightSize < 0) return false;
	memmove((char *)destElemAddr + vec->elemsize, 
			(char *)destElemAddr, 
			rightsize);
	memcpy(destElemAddr, srcElemAddr, vec->elemsize);
	vec->logicsize++;
	return true;
}
bool vector_delete(vector *vec, void *destElemAddr, void *deleteElem)
{
	if(vector_empty(vec))
		return false;
	int rightSize = (char *)vec->elem + vec->logicsize * vec->elemsize -
			        (char *)destElemAddr;
	if(rightsize < 0) return false;
	memcpy(deleteElemAddr, destElemAddr, vec->elemsize);
	memmove((char *)destElemAddr,
			(char *)destElemAddr + vec->elemsize, 
			rightsize - vec->eelmsize);
	vec->logicsize--;
	return true;
}

bool vector_empty(const vector *vec)
{
	return vec->logic == 0;
}

bool vector_full(const vector *vec)
{
	return vec->logicsize == vec->allocsize;
}

int vector_size(const vector *vec)
{
	return vec->logicsize;
}
int vector_capcity(const vector *vec)
{
	return vec->allocsize;
}

void vector_foreach(vector *vec, void (*callBack)(void *elem, void *data), void *data)
{
	int i;
	for(i = 0; i < vec->logicsize; i++){
		callBack((char *)vec->elem + i * vec->elemsize, data);
	}
}

