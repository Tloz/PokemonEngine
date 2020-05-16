CC = g++
CFLAGS=--std=c++11
LDFLAGS=-Lbin -lpokemonEngine -lfactories -lparser
CFLAGSSTRICT=-W -Wall -Wextra -pedantic
#CFLAGSSUPERSTRICT=-Werror
CFLAGSCHEAT=-fpermissive -Wunused-variable
CFLAGSOPT=-O3

all: parser pokemonEngine factories

pokemonEngine: bin/libpokemonEngine.a

factories: bin/libfactories.a

parser: bin/libparser.a

tests: testType testMove testSpecie testTrainerPokemon

################### ENGINE ##################
bin/libpokemonEngine.a: obj/item.o obj/ball.o obj/world.o obj/trainer.o obj/move.o obj/specie.o obj/pokemon.o obj/type.o obj/utils.o obj/gender.o obj/knownmove.o obj/savagepokemon.o obj/trainerpokemon.o obj/personalityvalue.o
	ar rcs $@ $^

obj/item.o: src/item.cpp inc/item.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/ball.o: src/ball.cpp inc/ball.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/utils.o: src/utils/utils.cpp inc/utils.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/gender.o: src/utils/gender.cpp inc/gender.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/type.o: src/utils/type.cpp inc/type.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/personalityvalue.o: src/utils/personalityvalue.cpp inc/personalityvalue.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/move.o: src/move.cpp inc/move.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/knownmove.o: src/knownmove.cpp inc/knownmove.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/specie.o: src/specie.cpp inc/specie.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/pokemon.o: src/pokemon.cpp inc/pokemon.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/savagepokemon.o: src/savagepokemon.cpp inc/savagepokemon.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/trainerpokemon.o: src/trainerpokemon.cpp inc/trainerpokemon.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/trainer.o: src/trainer.cpp inc/trainer.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/world.o: src/world.cpp inc/world.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)


#############################################

################### PARSER ##################
bin/libparser.a: obj/parser.o
	ar rcs $@ $^

obj/parser.o: src/parser/parser.cpp inc/parser.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

#############################################

################# FACTORIES #################
bin/libfactories.a: obj/ballfactory.o obj/typefactory.o obj/pokefactory.o obj/movefactory.o obj/trainerfactory.o
	ar rcs $@ $^

obj/ballfactory.o: src/factories/ballfactory.cpp inc/factories.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/typefactory.o: src/factories/typefactory.cpp inc/factories.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/pokefactory.o: src/factories/pokefactory.cpp inc/factories.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/movefactory.o: src/factories/movefactory.cpp inc/factories.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

obj/trainerfactory.o: src/factories/trainerfactory.cpp inc/factories.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT) $(CFLAGSSUPERSTRICT) $(CFLAGSOPT)

############################################

################### TESTS ##################
tests: testMove testSpecie testSavagePokemon testTrainerPokemon testTrainer testBall

testType: src/tests/testType.cpp bin/libparser.a bin/libpokemonEngine.a bin/libfactories.a
	$(CC) $^ $(LDFLAGS) -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

testMove: src/tests/testMove.cpp bin/libparser.a bin/libpokemonEngine.a bin/libfactories.a
	$(CC) $^ $(LDFLAGS) -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

testSpecie: src/tests/testSpecie.cpp bin/libparser.a bin/libpokemonEngine.a bin/libfactories.a
	$(CC) $^ $(LDFLAGS) -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

testTrainerPokemon: src/tests/testTrainerPokemon.cpp bin/libparser.a bin/libpokemonEngine.a bin/libfactories.a
	$(CC) $^ $(LDFLAGS) -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

testSavagePokemon: src/tests/testSavagePokemon.cpp bin/libparser.a bin/libpokemonEngine.a bin/libfactories.a
	$(CC) $^ $(LDFLAGS) -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

testTrainer: src/tests/testTrainer.cpp bin/libparser.a bin/libpokemonEngine.a bin/libfactories.a
	$(CC) $^ $(LDFLAGS) -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

testBall: src/tests/testBall.cpp bin/libparser.a bin/libpokemonEngine.a bin/libfactories.a
	$(CC) $^ $(LDFLAGS) -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

############################################

.PHONY: clean mrproper
 
clean:
	@rm -rf *.o
	@rm -rf obj/*.o

mrproper: clean
	@rm -rf bin/*