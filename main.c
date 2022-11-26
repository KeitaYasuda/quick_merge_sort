#include "sort_program/quick_merge_sort.h"
#include "Common/data_factory/data_factory.h"


int main(void){

    // 検証回数
    int roop_num  = 1;

    clock_t	start,end;
    
    clock_t time_ave1 = 0;
    clock_t time_ave2 = 0;
    //clock_t time_ave3 = 0;


    // **** ランダムデータ生成・読み込み **** //
    //create_random_data_to_CSV(DATA_FILE_NAME, TARGET_DATA_SIZE, false);
    _array data; 
    if( importCSV(DATA_FILE_NAME, &data) ) return -1;
    printf("import DONE\n");

	// **** ソート前表示 **** //
	//for(int i=0; i < TARGET_DATA_SIZE; i++) printf("%5d:%10d\n", i, data.address[i]);
    
    // **** ランダムデータのソート **** //
    start = clock();
    pre_sort(data.address, data.size);
    end   = clock();
    //** ソート後表示 
    printf("ランダム整列\t: time = %lf (秒)\n",(double)(end-start)/CLOCKS_PER_SEC);
    //time_ave1 += (end-start)*1000/CLOCKS_PER_SEC;
    //** 整列チェック
    //sorted_check(&data);
    //for(int i=0; i < TARGET_DATA_SIZE; i++) printf("%5d:%10d\n", i, data.address[i]);



	// **** 昇順データのソート **** //
    start = clock();
    pre_sort(data.address, data.size);
    end   = clock();

    printf("昇順整列\t: time = %lf (秒)\n",(double)(end-start)/CLOCKS_PER_SEC);
    //sorted_check(&data);

    end_use_array(&data);

    // **** 平均実行時間の表示 ****
    //printf("\n");
    //printf("ランダム整列\t: pre_sort time =%ld (msec)\n",time_ave1/roop_num);
    //printf("昇順整列\t: pre_sort time =%ld (msec)\n",time_ave2/roop_num);

    return 0;
}
