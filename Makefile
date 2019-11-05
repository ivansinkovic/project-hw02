SRC=src/cmplx.c src/io.c
OBJ=$(patsubst %c, %o, $(SRC))


all: exe/test01.elf exe/test02.elf exe/test03.elf exe/test04.elf exe/test05.elf exe/test06.elf exe/test07.elf exe/test08.elf exe/testdft.elf exe/testidft.elf

exe/%.elf: src/%.o $(OBJ)
	gcc $< $(OBJ) -o $@ -lm

%.o: %.c
	gcc -c $^ -I inc/ -o $@

clean:
	rm -f exe/test*.elf src/*.o

run: all
	./exe/test01.elf;./exe/test03.elf;./exe/test04.elf;./exe/test05.elf;./exe/test06.elf;./exe/test07.elf;./exe/test08.elf;./exe/testdft.elf;./exe/testidft.elf
