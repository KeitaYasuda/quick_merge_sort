/* チェイン法によるプログラム */
#ifndef CHAIN_H
#define CHAIN_H
//------------------------------------------------

	#include "../my_std.h"

//------------------------------------------------
//  マクロ定義(Macro definition)
//------------------------------------------------

	#define BUCKET_SIZE 10000	    				/* ハッシュ表の大きさ */

	#define keyequal(a, b) a==b ? 1 : 0				/* キーが等しければ真、等しくなければ偽 */
	#define hash(key) (key*key/2) % BUCKET_SIZE		/* 平方採中法によるハッシュ関数 */

//------------------------------------------------
//  型定義(Type definition)
//------------------------------------------------

	typedef unsigned int KEY;	/* キーとデータの型を後から変更するにはココ */
	typedef          int DATA;

	typedef struct cell {
		KEY		key;
		DATA	data;
		struct cell *next;
	}CELL;

//------------------------------------------------
//  プロトタイプ宣言(Prototype declaration)
//------------------------------------------------

	/*  ハッシュ表を初期化する  */
	void init(void);

	/*  ハッシュ表を探索する	       */
	/*	DATAへのポインタを返す      */
	/*	見つからなければ、NULLを返す */
	DATA *find(KEY);


	/*  ハッシュ表にデータを挿入する                */
	/*	登録に成功したら１を返す                   */
	/*	登録に失敗（すでに同じキーを持つデータがある） */
	/*	したら０を返す                            */
	int insert(KEY, DATA*);

	/* ハッシュ表から削除する           */
	/* 削除が成功したら１を返す         */
	/* データが見つからなければ０を返す	 */
	int delete(KEY);

//------------------------------------------------
#endif
