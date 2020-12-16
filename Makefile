main: main.o blockchain.o block.o sha256.o
	g++ main.o blockchain.o block.o sha256.o -o main


main.o: main.cpp blockchain.h
	g++ -c main.cpp

blockchain.o: blockchain.cpp blockchain.h
							g++ -c blockchain.cpp

block.o: block.cpp block.h sha256.h
	g++ -c block.cpp

sha256.o: sha256.cpp sha256.h
	g++ -c sha256.cpp

clean:
	rm *.o
