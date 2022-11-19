#ifndef QUICK_MERGE_SORT_H
#define QUICK_MERGE_SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//可変長要素の構造体
typedef struct element{
	int* element_p;		// 実体へのポインタ
	int size;			// 要素の大きさ(含んでいるデータ数)
}ELEMENT;

void pre_sort(int[], int);
void sort(int[], int[], int, ELEMENT[], int, int);

ELEMENT *small_num_is(ELEMENT*, ELEMENT*);

#endif