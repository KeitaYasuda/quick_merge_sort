/* チェイン法によるプログラム */
#include"chain.h"

/* ハッシュ表の定義 */
CELL *table[BUCKET_SIZE];

void init(){
    int i;
    for (i = 0; i < BUCKET_SIZE; i++)
		table[i] = NULL;
}

DATA *find(KEY key){
    CELL *p;

    for (p = table[hash(key)]; p != NULL; p = p->next)
		if (keyequal(key, p->key))
			return  &p->data;
    return  NULL;
}

int insert(KEY key, DATA *data){
    CELL *p;
    int h;

    if (find(key) != NULL) return 0;
	
    if ((p = malloc(sizeof(CELL))) == NULL) {
		fprintf(stderr, "メモリ確保失敗\n");
		exit(2);
    }
    h = hash(key);
	
    p->key = key; p->data = *data;
    p->next = table[h]; table[h] = p;
    return 1;
}


int delete(KEY key){
    int h;
    CELL *p, *q;

    h = hash(key);
    /* そのバケットは空か? */
    if (table[h] == NULL)
		return 0;
	
    /* リストの先頭のセルが削除すべきデータか? */
    if (keyequal(key, table[h]->key)) {
		p = table[h];
		table[h] = p->next;
		free(p);
		return 1;
    }
    /* リストの２番目以降のセルについて順番にチェックする */
    for (q = table[h], p = q->next; p != NULL; q = p, p = p->next) {
		if (keyequal(key, p->key)) {
			q->next = p->next;
			free(p);
			return 1;
		}
    }
    return 0;
}
