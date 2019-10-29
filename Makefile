SRC=$(wildcard src/*.c)
OBJ=$(patsubst %.c, %.o, $(SRC))

EXE=exe/app.elf

all: $(EXE)

%.elf: $(OBJ)
	gcc $(OBJ) -o $@

%.o: %.c
	gcc -c $< -I inc/ -o $@

clean:
	rm  $(OBJ) $(EXE)

run: all
	./exe/app.elf 2 2
