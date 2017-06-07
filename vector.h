#ifndef __VECTOR__
#define __VECTOR__

#include <string.h>

typedef struct Vector{
	void *elem;
	int elemsize;
	int allocsize;
	int logicsize;
	void (*freefn)(void *p);
}vector;

void vector_init(vector *vec, int elemsize, int n, void (*freefn)(void *p));
void vector_delete(vector *vec);

void vector_pushBack(vector *vec,const void *elemAddr);
void vector_popBack(vector *vec, const void *elemAddr);

bool vector_insert(vector *vec, void *destElemAddr, void *srcElemAddr);
bool vector_delete(vector *vec, void *destElemAddr, void *deleteElem);

void vector_resize(vector *vec, int size);

bool vector_empty(const vector *vec);
bool vector_full(const vector *vec);

int vector_size(const vector *vec);
int vector_capcity(const vector *vec);

void vector_foreach(vector *vec, void (*callBack)(void *elem, void *data), void *data);

#endif
