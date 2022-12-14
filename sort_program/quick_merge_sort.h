#ifndef QUICK_MERGE_SORT_H
#define QUICK_MERGE_SORT_H
//------------------------------------------------
	
	#include "../Common/my_std.h"
	#include <time.h>

//------------------------------------------------
//  マクロ定義(Macro definition)
//------------------------------------------------

	#define TARGET_DATA_SIZE           100000000
	#define PRE_SORT_ELEMENT_INIT_SIZE 10

//------------------------------------------------
//  型定義(Type definition)
//------------------------------------------------

	// エレメントブロックの構造体
	typedef struct {
		int* element_p;		// 実体へのポインタ
		int size;			// 要素の大きさ(含んでいるデータ数)
	}ELEMENT;

//------------------------------------------------
//  プロトタイプ宣言(Prototype declaration)
//------------------------------------------------

	void pre_sort(int[], int);
	int sort(int[], int[], int, ELEMENT[], int, int);

	void sorted_check(_array * array);

	ELEMENT *small_num_is(ELEMENT*, ELEMENT*);

//------------------------------------------------
#endif
