#include "./data_factory.h"

// ランダムデータを作成してCSV形式で出力する
int create_random_data_to_CSV(char *file_name, unsigned int num, bool unique_onry){

	unsigned int *data;
	data = malloc(sizeof(unsigned int) * num);
	
// *
	/* 初期化 */
	srand(SEED);
   	if(unique_onry) init();

// *
	/* データ生成 */
	for(int i=0; i < num; ){
		// キーにランダムな値を設定
		data[i] = rand();
		
		if(unique_onry){
			// データ構造への登録&キーの重複があればキー再発行
			if(insert(data[i], &data[i]) == 0){
				//printf("キーを再発行します\n");
				continue;
			}
		}

		i++;
	}
	//printf("-> 重複%s データ %d件 生成完了\n", unique_onry ? "なし":"を排除しない", num);

// *     
	/* ファイルへの書き出し */
	FILE *fp = fopen(file_name, "w");
	fprintf(fp, "%d:", num);
	for (int i = 0; i < num; i++) fprintf(fp, "%d,", data[i]);
	fclose(fp);

	free(data);
	return 0;
}

int importCSV(char *file_name, _array *array){
	unsigned int import_data_size;

	if(array->address == NULL) free(array->address);

	FILE *fp = fopen(file_name, "r");
	fscanf(fp, "%u:", &array->size);

	array->address = malloc(sizeof(int)* array->size);

	for(int i = 0; EOF != fscanf(fp, "%u,", &array->address[i]); i++);

	fclose(fp);

	return 0;
}

void end_use_array(_array *array){
	if(array->address == NULL) return;
	
	free(array->address);
	array->address = NULL;
	array->size    = 0;
}
