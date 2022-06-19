#CC=gcc-11
#CC=clang
O=-Os -g -Werror -Wno-variadic-macros -Wno-gnu-statement-expression
j: j.c j.h
	@$(CC) --std gnu89 $O $@.c -o$@ && ./$@
