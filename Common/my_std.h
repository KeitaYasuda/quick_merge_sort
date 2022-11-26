#ifndef MY_STD_H
#define MY_STD_H
//------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//------------------------------------------------
//  マクロ定義(Macro definition)
//------------------------------------------------


//------------------------------------------------
//  型定義(Type definition)
//------------------------------------------------

    typedef char _string[];

    typedef struct
    {
        int         *address;
        unsigned int size;
    } _array;

//------------------------------------------------
//  プロトタイプ宣言(Prototype declaration)
//------------------------------------------------

//------------------------------------------------
#endif
