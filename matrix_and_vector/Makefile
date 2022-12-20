EXEC=main.exe
SRC=vector.cpp matrix.cpp main.cpp
OBJs=$(SRC:.cpp=.o)
OBJ_DIR=./obj
OBJ=$(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJs))
FLAGS=-c
OPT=-O3

#SCR1= vector.cpp matrix.cpp
LIBs=$(SRC:.cpp=.a)
LIB_DIR=./lib
LIB=$(patsubst %.a,$(LIB_DIR)/lib%.a,$(LIBs))
#OPT=-fcheck-new

.SUFFIXES:.o .cpp
comp = g++

all: ${EXEC} ${LIB}
	@ echo "ok"

clean:
	@ rm *.o


${EXEC}: ${OBJ}
	${comp} -o ${EXEC} ${OBJ}

$(OBJ_DIR)/%.o:%.cpp
	${comp} ${FLAGS} ${OPT} $< -o $@


${EXEC}: ${LIB}
	${comp} -L ${EXEC} ${LIB}	        
	

$(LIB_DIR)/%.a:%.o
	ar cr ${LIB} ${OPT} $< -l $@ 
