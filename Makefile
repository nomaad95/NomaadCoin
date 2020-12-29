main: main.o blockchain.o block.o sha256.o transaction.o
	g++ main.o blockchain.o block.o sha256.o transaction.o -o main


main.o: main.cpp header/blockchain.h header/transaction.h
	g++ -c main.cpp

blockchain.o: blockchain.cpp header/blockchain.h
							g++ -c blockchain.cpp

block.o: block.cpp header/block.h header/sha256.h
	g++ -c block.cpp

transaction.o: transaction.cpp header/transaction.h
	g++ -c transaction.cpp

sha256.o: sha256.cpp header/sha256.h
	g++ -c sha256.cpp

clean:
	rm *.o
