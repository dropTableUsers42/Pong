bin/sfml-app : bin/main.o
	g++ bin/main.o -o bin/sfml-app -L C:\SFML-2.3.1\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -ljpeg

bin/main.o : src/main.cpp
	g++ -DSFML_STATIC -c src/main.cpp -I C:\SFML-2.3.1\include -o bin/main.o

clean :
	rm -f bin/sfml-app bin/*.o
