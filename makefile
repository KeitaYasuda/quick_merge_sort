## makeルール

# コンパイラとアセンブラ
CC=gcc
AS=as

# サフィックスルール適用対象の拡張子の定義
.SUFFIXES: .c .o

# コンパイル時のフラグ
CCFLAGS = -c -g -I./sort_program

# リンク時のフラグ
#LDFLAGS = -lpthread -lm -lpthread

#プログラム名
PROGRAM = quick_merge_sort

# mainプログラム
MSRC    = main.c
MOBJ    = $(MSRC:.c=.o)

# ソートプログラムが格納されているディレクトリ
SORTDIR  = ./sort_program

# ビルド時に必要なオブジェクトファイル一覧
SRCS    = main.c $(SORTDIR)/pre_sort.c $(SORTDIR)/quick_merge_sort.c
OBJS    = $(SRCS:.c=.o)


# all
all: $(PROGRAM)

$(PROGRAM) : $(MOBJ) $(OBJS)
	$(CC) -o $@ $^
#	$(CC) -o $@ $^ $(LDFLAGS)
	
.c.o:
	$(CC) -o $@ $< $(CCFLAGS)


clean:
	$(RM) $(OBJS) $(MOBJ) $(PROGRAM)
