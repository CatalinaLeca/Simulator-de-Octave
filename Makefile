# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# define targets
TARGETS = my_octave

build: $(TARGETS)


my_octave: my_octave.c f_1_2_3.c f_4.c f_5.c f_6.c f_7.c f_8.c f_9.c f_10.c f_11.c
	$(CC) $(CFLAGS) my_octave.c f_1_2_3.c f_4.c f_5.c f_6.c f_7.c f_8.c f_9.c f_10.c f_11.c -o my_octave


pack:
	zip -FSr 315CA_LecaMaria-Catalina_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
