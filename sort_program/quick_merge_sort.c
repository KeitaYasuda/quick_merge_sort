#include "quick_merge_sort.h"

/*与えられた2つの数字を比較し、小さい方を返す。*/
ELEMENT *small_num_is(ELEMENT* a, ELEMENT* b){
    if(*(a->element_p) < *(b->element_p)) return a;
    return b;
}


/*オリジナルクイックマージソート*/
int sort(int sort_array[], int desk_array[], int layer_size, ELEMENT old_element[], int element_size, int layer){
    /* 層について
    	偶数層での書き込みは、元配列への書き込み。
        ≒ 奇数層での読み込みは、元配列の読み込み。
     */
    layer++;
    //printf("layer[%d]/ele_size[%d]\n", layer, element_size);
    
    ELEMENT* p;//比較後に選ばれた要素を入れる作業台
    int i=0;
    // リターン
    if(element_size <= 2){
    	//0 return; 1 確定return; 2 marg return
        switch(element_size){
            case 0:
                break;

            case 1: // 何もせず書き込み
                if(layer%2 == 0){
                    for(i=0; i < layer_size; i++){
                        desk_array[i] = sort_array[i];
                        //printf("case1:%d\n", desk_array[i]);
                    }
                }
                break;

            case 2:
                for(i=0; old_element[0].size > 0 && old_element[1].size > 0; i++){
                    p = small_num_is(&old_element[0], &old_element[1]);
                    desk_array[i] = *p->element_p++;
                    p->size--;
                }
                if(old_element[0].size > 0) p = &old_element[0];
                else p = &old_element[1];

                for(; p->size > 0; i++){
                    desk_array[i] = *p->element_p++;
                    p->size--;
                }
                // 奇数配列なら、マージ結果を元配列にコピーする
                if(layer%2 == 1){
                    for(i=0; i < layer_size; i++){
                        sort_array[i] = desk_array[i];
                        //printf("case2:%d\n", desk_array[i]);
                    }
                }
                break;
        }
        
        return --layer;
    }
    
    // 枢軸を格納
    int pivot;

    //読み込み配列と書き込み配列
	int* read_array, *write_array;
	read_array = sort_array;
    write_array = desk_array;
    //生成した配列の、先頭と末尾それぞれから書き込むためのポインタ
    int* write_eyeS = write_array, *write_eyeB;

    //新たな要素を格納する配列、要素数+NULL領域
	ELEMENT* new_s_element = malloc(sizeof(ELEMENT) * element_size/2+1);//軸以下の要素を格納する配列
	ELEMENT* new_b_element = malloc(sizeof(ELEMENT) * element_size/2+1);//軸以上の要素を格納する配列
    ELEMENT *element_eyeS = new_s_element, 
    		*element_eyeB = new_b_element;
	int s_size = 0, b_size = 0;
    
    //要素の作成準備
    element_eyeS->element_p = write_array;
    //element_eyeB->element_p = write_eyeB;
    element_eyeS->size = 0; 
    element_eyeB->size = 0;
    
    // 軸を決める
    //pivot = *old_element[0].element_p++;//先頭の先頭
    //pivot = *old_element[0].element_p + old_element[0].size-1;//先頭要素の末尾要素
    i = old_element[element_size/2].size -1;
    if(*old_element[0].element_p < *old_element[element_size/2].element_p){
    	pivot = *old_element[element_size/2].element_p++;
        old_element[element_size/2].size--;
    }else if(*old_element[0].element_p < *old_element[element_size/2].element_p + i){
        pivot = *old_element[0].element_p++;
        old_element[0].size--;
    }else{
    	pivot = *old_element[element_size/2].element_p + i;
        old_element[element_size/2].size--;
    }
    
    //if(old_element[0].size == 0) i++;
    //printf("pivot = %d\n", pivot);
    //printf("old_ele[0].ele_p = %d : size = %d\n",*old_element[0].element_p, old_element[0].size);
    
    
    
    // メインマージ
    int ele_A, ele_B;
    ele_A = 0;
    
    ELEMENT* first = NULL;
    int second;
    // *** 軸下マージ ***
    //*** new version!! ***
    //ele_Aのサイズが0なら注目点を進める。ブロック配列終端に来ても終了
    while(1){   
        while(ele_A < element_size && *old_element[ele_A].element_p > pivot) ele_A++;
        //ele_Aが終端じゃなければBをセット。終端ならループを抜ける
        if(ele_A < element_size) ele_B = ele_A+1;
        else break;
        //サイズがあるブロックまで注目点を進める
        while(ele_B < element_size && *old_element[ele_B].element_p > pivot) ele_B++;
        //ele_BがNULLなら、ele_Aを吐き出して軸上処理終了
        if(ele_B == element_size){
            while(*old_element[ele_A].element_p < pivot && old_element[ele_A].size > 0){
                //printf("余下要素の書き込み：%d\n", *p->element_p);
                *write_eyeS++ = *old_element[ele_A].element_p++;//下に書き
                old_element[ele_A].size--;
            }//要素更新
            element_eyeS->size = write_eyeS - element_eyeS->element_p;
            element_eyeS++;
            //element_eyeS->element_p = write_eyeS;
            s_size++;
            //printf("-------------------------------\n");
            break;
        }
        
        //最小と基準の選定
        if(*old_element[ele_A].element_p < pivot){ // A < pivot
            if(*old_element[ele_B].element_p < *old_element[ele_A].element_p){ // B < A < pivot
                second = *old_element[ele_A].element_p;	// A = 2位
                first = &old_element[ele_B]; // B = 1位
            }else{ // A < B
                if(*old_element[ele_B].element_p < pivot){// A < B < pivot
                    second = *old_element[ele_B].element_p;// B ＝ 2位
                	first = &old_element[ele_A];// A = 1位
            	}else{ // A < pivot < B
                    second = pivot; //pivot = 2位
                    first = &old_element[ele_A];// A = 1位
                }
            }
        }else if(*old_element[ele_B].element_p < pivot){ // B < pivot < A
            second = pivot; // pivot = 2位
            first = &old_element[ele_B]; // B = 1位
        }else{// pivot < B or A
            second = 0; // pivot =1位
            first = NULL;
        }
        
        //マージ処理
        while(first != NULL){//枢軸が最小じゃない間繰り返す
            //最小が基準を追い越すまでor無くなるまで吐き出す
            while(*first->element_p <= second && first->size != 0){
                //printf("枢軸以下の書き込み：%d\n", *first->element_p);
                *write_eyeS++ = *first->element_p++;//下に書き
                first->size--;
            }
            //printf("\n");
            //基準が最小に、最小だったものは、枢軸より小さいか？
            if(second == pivot){// 基準が枢軸だった。while文を抜ける。
                break;
            }else if(*first->element_p < pivot && first->size != 0){ // 2位候補は枢軸より小さいか？
                if(first == &old_element[ele_A]){
                    first = &old_element[ele_B];
                    second = *old_element[ele_A].element_p;
                }else{
                    first = &old_element[ele_A];
                    second = *old_element[ele_B].element_p;
                }
            }else{// 枢軸を2位にして最終マージ準備
                if(first == &old_element[ele_A]) first = &old_element[ele_B];
                else first = &old_element[ele_A];
                second = pivot;
            }
        }
        
        //要素更新
        element_eyeS->size = write_eyeS - element_eyeS->element_p;
        element_eyeS++;
        element_eyeS->element_p = write_eyeS;
        s_size++;
        
        ele_A = ele_B+1;
    }
    
    // *** 軸以上マージ ***
    //注目点変数の交代
    //int* ele_s_end = write_eyeS++;
    write_eyeB = write_eyeS+1;
    //要素準備
    element_eyeB->element_p = write_eyeB;
    
    ele_A = 0;
    
    while(1){
    	//ele_Aのサイズが0なら注目点を進める。ブロック配列終端に来ても終了
        while(ele_A < element_size && old_element[ele_A].size == 0) ele_A++;
        //ele_Aが終端じゃなければBをセット。終端ならループを抜ける
        if(ele_A < element_size) ele_B = ele_A+1;
        else break;
        //サイズがあるブロックまで注目点を進める
        while(ele_B < element_size && old_element[ele_B].size == 0) ele_B++;
        //ele_BがNULLなら、ele_Aを吐き出して軸上処理終了
        if(ele_B == element_size){
            while(old_element[ele_A].size > 0){
                //printf("余上要素の書き込み：%d\n", *old_element[ele_A].element_p);
                *write_eyeB++ = *old_element[ele_A].element_p++;
                old_element[ele_A].size--;
            }//要素更新
            element_eyeB->size = write_eyeB - element_eyeB->element_p;
            element_eyeB++;
            //element_eyeB->element_p = write_eyeB;
            b_size++;
            //printf("-------------------------------\n");
            break;
        }
        
        //マージ処理
        while(old_element[ele_A].size > 0 && old_element[ele_B].size > 0){
        	if(*old_element[ele_A].element_p < *old_element[ele_B].element_p) p = &old_element[ele_A];
            else p = &old_element[ele_B];
            //printf("軸上要素の書き込み：%d\n", *p->element_p);
            *write_eyeB++ = *p->element_p++;
            p->size--;
        }
        
        if(old_element[ele_A].size > 0) p = &old_element[ele_A];
        else p = &old_element[ele_B];
        
        for(;p->size > 0; p->size--){
            //printf("方上要素の書き込み：%d\n", *p->element_p);
            *write_eyeB++ = *p->element_p++;
        }
        
        //要素更新
        element_eyeB->size = write_eyeB - element_eyeB->element_p;
        element_eyeB++;
        element_eyeB->element_p = write_eyeB;
        b_size++;
        
        ele_A = ele_B+1;
        //printf("-------------------------------\n");
    }

    // 要素配列の最後にNULL入れる。
    element_eyeS->element_p = NULL;
    element_eyeB->element_p = NULL;
    
    write_eyeB = write_eyeS+1;
    
    // 軸の位置が確定。元配列に軸を追加
     if(layer%2 == 0) *write_eyeS = pivot;
     else read_array[(write_eyeS - write_array)] = pivot;
    //*write_eyeS = pivot;
    //read_array[(write_eyeS - write_array)] = pivot;
    //printf("枢軸要素の書き込み[%ld]：%d\n", write_eyeS - write_array, pivot);


    /*printf("渡された配列\t書き込んだ配列\t枢軸[%ld]：%d\n",write_eyeS - write_array, pivot);
    for(i=0; i<layer_size;i++){
    	printf("%3d:%10d\t", i, sort_array[i]);
        printf("%3d:%10d\n", i, desk_array[i]);
    }*/
    
    //for(i=0; i<layer_size; i++)printf("write_array[%d] = %d\n",i, write_array[i]);
    //     return;
    //printf("%d層：枢軸以下：%d\t枢軸以上：%d\n", layer, s_size, b_size);
    
    // 軸以下を整列
    layer = sort(write_array, read_array, write_eyeS - write_array, new_s_element, s_size, layer);    
    free(new_s_element);
    
    // 軸以上を整列
    layer = sort(write_eyeB, &read_array[write_eyeB - write_array], &write_array[layer_size] - write_eyeB, new_b_element, b_size, layer);
    free(new_b_element);
    
    return --layer;
}

void sorted_check(_array * array){
    int j = 0;
    for(int i=0 ; i< array->size; i++){
        if(j <= array->address[i]) j = array->address[i];
        else{
        	printf("整列してない！\n");
            break;
        }
    }
    printf("- sort done -\n");
}
