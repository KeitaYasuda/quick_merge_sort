#include "sort_program/quick_merge_sort.h"

int main(void){
    int data_size = 10000;
    int roop_num  = 1;
    int layer = 0;

    int i, i2;
    int tane;
    int j=0, z=0;
    clock_t	start,end;
    
    clock_t time_ave1 = 0;
    clock_t time_ave2 = 0;
    //clock_t time_ave3 = 0;
    
    tane = 10;
    
    for(i=0; i < roop_num; i++){
        int* data1 = malloc(sizeof(int)*data_size);
        srand(tane);
        //int* data2 = malloc(sizeof(int)*data_size);
        // **** ランダムデータ生成 ****
        for(i2=0; i2 < data_size; i2++){
            data1[i2] = rand();
            //data2[i2] = data1[i2];
        }
    	// **** data1内容表示 ****
    	//for(i=0; i< data_size; i++)printf("%3d:%10d\n", i, data1[i]);
    
        //printf("乱数の種：%d\tデータ件数：%d\n",tane, data_size);
        //y_sort(data1, data_size);
        
        start = clock();
        pre_sort(data1, data_size);
        end   = clock();
        //printf("ランダム整列\t：pivot_y_sort time =%ld (msec)\n",(end-start)*1000/CLOCKS_PER_SEC); 
        time_ave1 += (end-start)*1000/CLOCKS_PER_SEC;
        
        
        start = clock();
        pre_sort(data1, data_size);
        end   = clock();
        //printf("ランダム整列\t：pivot_y_sort time =%ld (msec)\n",(end-start)*1000/CLOCKS_PER_SEC); 
        time_ave2 += (end-start)*1000/CLOCKS_PER_SEC;
        
        
        for(i2=0; i2 < data_size; i2++)printf("%3d:%10d\n", i2, data1[i2]);
        j=0;
        for(i2=0 ; i2 < data_size; i2++){
            if(j <= data1[i2]) j = data1[i2];
            else{
            	printf("整列してない！\n");
                break;
            }
        }
        
    	// **** data1内容表示 ****
    	//for(i=0; i< data_size; i++)printf("%3d:%10d\n", i, data1[i]);
    
        // start = clock();
        // y_sort(data1, data_size);
        // end   = clock();
        // printf("昇順整列\t：K_sort time =%ld (msec)\n",(end-start)*1000/CLOCKS_PER_SEC);    
        
        //printf("--------------------------------------\n");
        
        tane++;
        free(data1);
        //free(data2);
	}
    printf("\n");
    printf("ランダム整列\t: pre_sort time =%ld (msec)\n",time_ave1/roop_num);
    printf("昇順整列\t: pre_sortr time =%ld (msec)\n",time_ave2/roop_num);
    
    /*
    int* data1 = malloc(sizeof(int)*data_size);
    srand(tane);
    // **** ランダムデータ生成 ****
    for(i2=0; i2 < data_size; i2++) data1[i2] = rand();

    // **** data1内容表示 ****
    //for(i=0; i< data_size; i++)printf("%3d:%10d\n", i, data1[i]);

    printf("乱数の種：%d\tデータ件数：%d\n",tane, data_size);
    start = clock();
    k_sort(data1, data_size);
    end   = clock();
    printf("ランダム整列\t：K_sort time =%ld (msec)\n",(end-start)*1000/CLOCKS_PER_SEC); 
    // **** data1内容表示 ****
    //for(i=0; i< data_size; i++)printf("%3d:%10d\n", i, data1[i]);
    // **** 整列チェック ****
    // printf("整列チェックします\n");
    
    // for(i=0 ; i< data_size; i++){
    //     if(j <= data1[i]) j = data1[i];
    //     else{
    //     	printf("整列してない！\n");
    //         break;
    //     }
    // }
    // for(i = 0; i < data_size; i++){
    //     if(data1[i] == j){
    //         z++;
    //         if(z == 2) printf("重複してる！:%d\n",j);
    //     }
    // }
    // printf("チェック終わり(`･ω･´)b\n");
    free(data1);
    */
    
    // **** 連続データ生成 ****
    //for(i=0; i < data_size; i++) data1[i] = i;
    
    // **** data1内容表示 ****
    //for(i=0; i< data_size; i++)printf("%3d:%10d\n", i, data1[i]);
    
    // **** 整列チェック ****
    /*// printf("整列チェックします\n");
    // for(i=0 ; i< data_size; i++){
    //     if(j <= data1[i]) j = data1[i];
    //     else{
    //     	printf("整列してない！\n");
    //         break;
    //     }
    // }
    // for(i = 0; i < data_size; i++){
    //     if(data1[i] == j){
    //         z++;
    //         if(z == 2) printf("重複してる！:%d\n",j);
    //     }
    // }
    // printf("チェック終わり(`･ω･´)b\n");
    */
    return 0;
}