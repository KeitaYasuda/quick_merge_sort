#ifndef DATA_FACTORY_H
#define DATA_FACTORY_H
//------------------------------------------------

	#include "../my_std.h"
	#include "../hash_search/chain.h"

//------------------------------------------------
//  マクロ定義(Macro definition)
//------------------------------------------------

	#define DATA_FILE_NAME "data.csv"
	#define SEED      10

//------------------------------------------------
//  型定義(Type definition)
//------------------------------------------------

//------------------------------------------------
//  プロトタイプ宣言(Prototype declaration)
//------------------------------------------------

	int create_random_data_to_CSV(char *file_name, unsigned int num, bool unique_onry);
	int importCSV(char *file_name, _array *array);
	void end_use_array(_array *array);

//------------------------------------------------
#endif
