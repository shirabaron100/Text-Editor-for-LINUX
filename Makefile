a.out: main.o Editor.o Document.o
	g++ -std=c++11 main.o Editor.o Document.o -o a.out # every time that main.o or editor.o changes then build new executable file names output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Editor.o: Editor.cpp Editor.h
	g++ -std=c++11 -c Editor.cpp

Document.o: Document.cpp Document.h
	g++ -std=c++11 -c Document.cpp

clean:
	rm -f *.o a.out # Remove everything that match *.o and output