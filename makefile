bin/sfml-app : bin/main.o bin/GameObject.o bin/player.o bin/Game.o bin/SplashScreen.o bin/MainMenu.o
	g++ bin/main.o bin/GameObject.o bin/player.o bin/Game.o bin/SplashScreen.o bin/MainMenu.o -lsfml-graphics -lsfml-window -lsfml-system -o bin/sfml-app

bin/main.o : src/main.cpp
	g++ -c src/main.cpp -I inc -o bin/main.o

bin/GameObject.o : src/GameObject.cpp
	g++ -c src/GameObject.cpp -I inc -o bin/GameObject.o

bin/player.o : src/player.cpp
	g++ -c src/player.cpp -I inc -o bin/player.o

bin/Game.o : src/Game.cpp
	g++ -c src/Game.cpp -I inc -o bin/Game.o

bin/SplashScreen.o : src/SplashScreen.cpp
	g++ -c src/SplashScreen.cpp -I inc -o bin/SplashScreen.o

bin/MainMenu.o : src/MainMenu.cpp
	g++ -c src/MainMenu.cpp -I inc -o bin/MainMenu.o

clean :
	rm -f bin/sfml-app bin/*.o
