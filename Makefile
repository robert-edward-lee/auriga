CC = gcc
CFLAGS += -Wall -Wextra -pedantic

04_linked_list: htable.c

06_parens: stack.c

clean:
	@$(RM) *.exe *.o *.obj *.out

format:
	@clang-format -style=file:./.clang-format \
		-i *.c *.cpp *.cxx *.h *.hpp *.hxx \
		2> /dev/null ||:
