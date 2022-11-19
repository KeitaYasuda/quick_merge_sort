#include "quick_merge_sort.h"

void pre_sort(int array[], int array_size){	
    int layer = 0;

	//生成する配列
	int* desk_array = malloc(sizeof(int)*array_size);

	//要素を管理する変数を格納する配列
	ELEMENT* new_element = malloc(sizeof(ELEMENT) * (array_size/PRE_SORT_ELEMENT_INIT_SIZE + 1)); //軸以下の要素を格納する配列
	ELEMENT* element_eye = new_element;
    
    //ブロック数 初期化
    int i, element_block_size;
    int ele_size = 0;

	//前処理用変数
    int done_point, check_eye, sort_tmp;
    
	// ソート対象の配列を先頭から末尾に向かって PRE_SORT_ELEMENT_INIT_SIZE 個ずつソートしてエレメントブロックを生成する。
	for (
        i = 0, element_block_size = PRE_SORT_ELEMENT_INIT_SIZE;
        i < array_size;
        i += PRE_SORT_ELEMENT_INIT_SIZE, element_block_size = (i + PRE_SORT_ELEMENT_INIT_SIZE <= array_size ? PRE_SORT_ELEMENT_INIT_SIZE : array_size % i)
    ){
        // エレメントブロック管理配列に情報登録
        element_eye->element_p = &array[i];
        element_eye->size = element_block_size;

        // 挿入ソートによるブロック内ソート
        for (done_point = i + 1; done_point < i + element_block_size; done_point++) {
            check_eye = done_point;
            while (i < check_eye && array[check_eye-1] > array[check_eye]) {
                sort_tmp = array[check_eye]; array[check_eye] = array[check_eye-1]; array[check_eye-1] = sort_tmp;
                check_eye--;
            }
        }
        
        //エレメントブロック管理配列注目点とブロック数 更新
        element_eye++;
        ele_size++;
    }

    // 要素配列の最後にNULLを入れる
    element_eye->element_p = NULL;

    //ソート本体の呼び出し
    sort(array, desk_array, array_size, new_element, ele_size, layer);
    
    // 作業領域開放
    free(desk_array);
    free(new_element);
    
    return;
}