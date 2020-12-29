#include"header/blockchain.h"

#include<ctime>

int main() {
  Blockchain bChain = Blockchain();

  int numblock = 0;

  while(true){
		Transaction trans = Transaction("ok","ok",1);
		list<Transaction> transactions;
		transactions.emplace_front(trans);
	  cout << "Mining new block" << endl;
	  cout << numblock << endl;
	  Block stBlock = Block(time(0),transactions);
		cout << "adding block" << endl;
	  bChain.AddBlock(stBlock);
		cout << "validate chain" << endl;
	  bChain.isChainValid();
	  numblock++;
  }

  return 0;
}
