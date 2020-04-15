CC = g++
CFLAGS=-W -Wall -Wextra --std=c++11 -pedantic
CFLAGSSTRICT=-Werror
CFLAGSCHEAT=-fpermissive -Wunused-variable

#type: obj/type.o

#move: obj/move.o

#specie: obj/specie.o

#pokemon: obj/pokemon.o

obj/type.o: src/type.cpp
	$(CC) -c $^ -o $@ $(CFLAGS) $(CFLAGSSTRICT)

obj/move.o: src/move.cpp obj/type.o
	$(CC) -c $^ -o $@ $(CFLAGS)

obj/specie.o: src/specie.cpp obj/type.o
	$(CC) -c $^ -o $@ $(CFLAGS) $(CFLAGSCHEAT)

obj/pokemon.o: src/pokemon.cpp obj/specie.o
	$(CC) -c $^ -o $@ $(CFLAGS)

testType: obj/type.o tests/testType.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSCHEAT)

testMove: obj/type.o obj/move.o tests/testMove.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS)

testSpecie: obj/type.o obj/specie.o tests/testSpecie.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS)

testPKMN: obj/pokemon.o tests/testPKMN.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf obj/*.o

mrproper: clean
	rm -rf bin/*