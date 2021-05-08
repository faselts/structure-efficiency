objs=preparation.o main.o
flags+=-c -Wall -g

all:$(objs)
	cc $^ -o  $@

%.o:%.c
	cc $^ $(flags) -o  $@

clean:
	rm *.o all -f
