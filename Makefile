CC = g++
CFLAGS=-W -Wall -Wextra --std=c++11 -pedantic
CFLAGSSTRICT=-Werror
CFLAGSCHEAT=-fpermissive -Wunused-variable

type.o: src/type.cpp
	$(CC) -o obj/$@ -c src/type.cpp $(CFLAGS) $(CFLAGSSTRICT)

move.o: src/move.cpp
	$(CC) -o obj/$@ -c src/move.cpp $(CFLAGS)

specie.o: src/specie.cpp
	$(CC) -o obj/$@ -c $< $(CFLAGS) $(CFLAGSCHEAT)

pokemon.o: src/pokemon.cpp
	$(CC) -o obj/$@ -c $< $(CFLAGS)

testType: type.o
	$(CC) obj/type.o tests/testType.cpp -o bin/$@ $(CFLAGS) $(CFLAGSCHEAT)

testMove: move.o
	$(CC) obj/move.o tests/testMove.cpp -o bin/$@ $(CFLAGS)

testSpecie: specie.o
	$(CC) obj/specie.o tests/testSpecie.cpp -o bin/$@ $(CFLAGS)

testPKMN: pokemon.o
	$(CC) obj/pokemon.o tests/testPKMN.cpp -o bin/$@ $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf obj/*.o

cleanall: clean
	rm -rf bin/*