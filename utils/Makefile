CC = g++
CFLAGS=-W -Wall -Wextra --std=c++11 -pedantic
CFLAGSSTRICT=-Werror
CFLAGSCHEAT=-fpermissive -Wunused-variable

all: utils.o

utils.o: utils.cpp gender.cpp type.cpp personalityvalue.cpp
	$(CC) -c $^ -o ../obj/$@ $(CFLAGS) $(CFLAGSSTRICT)

