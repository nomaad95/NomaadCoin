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
		/*
		Transaction trans = Transaction("ok","ok",1);
		list<Transaction> transactions;
		transactions.emplace_front(trans);
	  cout << "Mining new block" << endl;
	  cout << numblock << endl;
	  Block stBlock = Block(time(0),transactions, bChain._vChain.size());
		cout << "adding block" << endl;
	  bChain.minePendingTransactions("test");
		cout << "validate chain" << endl;
	  bChain.isChainValid();
		//t1.amount++;
		//t2.amount++;*/
	  *numblock++;
  }

  return 0;
}
