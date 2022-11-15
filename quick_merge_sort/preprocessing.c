void y_3_sort(int array[], int array_size){	
    layer = 1;

	//生成する配列
	int* desk_array = malloc(sizeof(int)*array_size);

	//要素を管理する変数を格納する配列
	ELEMENT* new_element = malloc(sizeof(ELEMENT) * array_size+1);			//軸以下の要素を格納する配列
	ELEMENT* element_eye = new_element;
    
    //ブロック数
    int ele_size = 0;

	//マージ処理
	int i;
	int tmp_a, tmp_b, tmp_c;
    
	// 一番最初のマージループ
	for(i=0; i+2 < array_size; i+=3){
        element_eye->element_p = &desk_array[i];
        element_eye->size = 3;
        //b < c
        if(array[i+1] < array[i+2]){
            // a < b < c
            if(array[i] < array[i+1]){
                tmp_a = array[i];
                tmp_b = array[i+1];
                tmp_c = array[i+2];
            }// b < a < c 
            else if(array[i] < array[i+2]){
            	tmp_a = array[i+1];
                tmp_b = array[i];
                tmp_c = array[i+2];
            }// b < c < a
            else{
            	tmp_a = array[i+1];
                tmp_b = array[i+2];
                tmp_c = array[i];
            }
        }//c < b
        else{
            //a < c < b
            if(array[i] < array[i+2]){
            	tmp_a = array[i];
            	tmp_b = array[i+2];
                tmp_c = array[i+1];
        	}//c < a < b
            else if(array[i] < array[i+1]){
            	tmp_a = array[i+2];
            	tmp_b = array[i];
                tmp_c = array[i+1];
            }//c < b < a
            else{
            	tmp_a = array[i+2];
            	tmp_b = array[i+1];
                tmp_c = array[i];
            }
        }
        desk_array[i] = tmp_a;
        desk_array[i+1] = tmp_b;
        desk_array[i+2] = tmp_c;
        
        //要素eye更新
        element_eye++;
    }
    ele_size = array_size/3;
    
    // 配列要素が余ってないか確認
    switch(i%3){
        case 2:
            element_eye->element_p = &desk_array[i];
        	element_eye->size = 2;
            if(array[i] < array[i+1]){
            	tmp_a = array[i];
                tmp_b = array[i+1];
            }else{
            	tmp_a = array[i+1];
                tmp_b = array[i];
            }
            desk_array[i] = tmp_a;
            desk_array[i+1] = tmp_b;
            element_eye++;
        	ele_size++;
            break;
        case 1:
            element_eye->element_p = &desk_array[i];
            element_eye->size = 1;

            desk_array[i] = array[i];

            element_eye++;
            ele_size++;
            break;
        default:
            break;
    }

    // 要素配列の最後にNULLを入れる
    element_eye->element_p = NULL;
    
    //併合分割ソート
    //sort(desk_array, array, array_size, new_element, ele_size);
    free(desk_array);
    free(new_element);
    
    return;
}