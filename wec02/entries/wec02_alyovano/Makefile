all:
	make -C ./srcs
	cp ./srcs/libftprintfgnl.a .
	gcc -Wall -Werror -Wextra *.c libftprintfgnl.a -o color

clean:
	make -C ./srcs clean
	@rm -rf color libftprintfgnl.a
