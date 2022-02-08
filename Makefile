INCLUDE_DIR_SDL = -I/usr/include/SDL2
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

all: ./bin/console ./bin/test ./bin/jeu

./bin/test: ./obj/mainTest.o ./obj/binaro.o ./obj/grille.o 
	g++ -g -W -Wall ./obj/mainTest.o ./obj/binaro.o ./obj/grille.o -o ./bin/test $(LIBS_SDL) 

./bin/jeu: ./obj/mainJeu.o ./obj/binaro.o ./obj/grille.o ./obj/image.o ./obj/affichage.o
	g++ -g -W -Wall ./obj/mainJeu.o ./obj/binaro.o ./obj/grille.o ./obj/image.o ./obj/affichage.o -o ./bin/jeu $(LIBS_SDL) 

./bin/console: ./obj/mainConsole.o ./obj/binaro.o ./obj/grille.o
	g++ -g -W -Wall ./obj/mainConsole.o ./obj/binaro.o ./obj/grille.o -o ./bin/console $(LIBS_SDL) 

./obj/mainTest.o: ./src/mainTest.cpp ./src/Binaro.h
	g++ -g -W -Wall $(INCLUDE_DIR_SDL) -c ./src/mainTest.cpp -o ./obj/mainTest.o 

./obj/mainJeu.o: ./src/mainJeu.cpp ./src/Binaro.h
	g++ -g -W -Wall $(INCLUDE_DIR_SDL) -c ./src/mainJeu.cpp -o ./obj/mainJeu.o 

./obj/mainConsole.o: ./src/mainConsole.cpp ./src/Binaro.h 
	g++ -g -W -Wall $(INCLUDE_DIR_SDL) -c ./src/mainConsole.cpp -o ./obj/mainConsole.o

./obj/affichage.o: ./src/Affichage.h ./src/Affichage.cpp ./src/Image.h
	g++ -g -W -Wall $(INCLUDE_DIR_SDL) -c ./src/Affichage.cpp -o ./obj/affichage.o 

./obj/image.o: ./src/Image.h ./src/Image.cpp ./src/Binaro.h
	g++ -g -W -Wall $(INCLUDE_DIR_SDL) -c ./src/Image.cpp -o ./obj/image.o 

./obj/binaro.o: ./src/Binaro.h ./src/Binaro.cpp ./src/Grille.h
	g++ -g -W -Wall $(INCLUDE_DIR_SDL) -c ./src/Binaro.cpp -o ./obj/binaro.o 

./obj/grille.o: ./src/Grille.h ./src/Grille.cpp
	g++ -g -W -Wall $(INCLUDE_DIR_SDL) -c ./src/Grille.cpp -o ./obj/grille.o 

clean:
	rm obj/*.o rm bin/*
