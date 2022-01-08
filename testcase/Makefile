CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC= $(wildcard ../*.cc)
OBJ= $(SRC:.cc=.o)
TST= $(wildcard *.cc)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cc=.o)

Testcase : $(OBJ_TEST) 
	$(CC) $^ -o $@ $(LIBFLAGS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

clean :
	rm -f $(OBJ_TEST) Testcase
