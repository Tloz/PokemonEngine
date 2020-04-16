CC = g++
CFLAGS=--std=c++11 -W -Wall -Wextra -pedantic
CFLAGSSTRICT=-Werror
CFLAGSCHEAT=-fpermissive -Wunused-variable

# UTILITES
utils: obj/gender.o obj/utils.o obj/type.o obj/personalityvalue.o

obj/gender.o: utils/gender.cpp
	$(CC) -c $^ -o $@ $(CFLAGS) $(CFLAGSSTRICT)

obj/utils.o: utils/utils.cpp
	$(CC) -c $^ -o $@ $(CFLAGS) $(CFLAGSSTRICT)

obj/type.o: utils/type.cpp
	$(CC) -c $^ -o $@ $(CFLAGS) $(CFLAGSSTRICT)

obj/personalityvalue.o: utils/personalityvalue.cpp
	$(CC) -c $^ -o $@ $(CFLAGS) $(CFLAGSSTRICT)


# FACTORIES
obj/pkmnfactory.o: factories/pokemonfactory.cpp obj/specie.o
	$(CC) -c $^ -o $@ $(CFLAGS)

# ENGINE
obj/move.o: src/move.cpp
	$(CC) -c $^ -o $@ $(CFLAGS)

obj/specie.o: src/specie.cpp obj/utils.o
	$(CC) -c $^ -o $@ $(CFLAGS) $(CFLAGSCHEAT)

obj/pokemon.o: src/pokemon.cpp 
	$(CC) -c $^ -o $@ $(CFLAGS)

obj/savagepokemon.o: src/savagepokemon.cpp
	$(CC) -c $^ -o $@ $(CFLAGS)

obj/trainerpokemon.o: src/trainerpokemon.cpp
	$(CC) -c $^ -o $@ $(CFLAGS)

# TESTS
testType: obj/utils.o tests/testType.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSCHEAT)

testMove: obj/utils.o obj/move.o tests/testMove.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS)

testSpecie: obj/utils.o obj/type.o obj/specie.o tests/testSpecie.cpp obj/pkmnfactory.o
	$(CC) $^ -o bin/$@ $(CFLAGS)

testSavagePokemon: obj/specie.o obj/savagepokemon.o tests/testSavagePokemon.cpp obj/pokemon.o obj/gender.o obj/utils.o obj/type.o obj/personalityvalue.o
	$(CC) $^ -o bin/$@ $(CFLAGS)

.PHONY: clean mrproper
 
clean:
	@rm -rf *.o
	@rm -rf obj/*.o

mrproper: clean
	@rm -rf bin/*