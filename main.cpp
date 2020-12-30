#include"header/blockchain.h"

#include<ctime>

int main() {
  Blockchain bChain = Blockchain();

  int *numblock = 0;
	Transaction t1 = Transaction("address1", "address2", 100);
	Transaction t2 = Transaction("address2", "address3", 50);
	double address1Balance;
  while(true){
		bChain.createTransaction(t1);
		bChain.createTransaction(t2);
		bChain.minePendingTransactions("miner");
		double address1Balance = bChain.getBalance("miner");
		cout << "miner balance:" << address1Balance << endl;
	  *numblock++;
  }

  return 0;
}
