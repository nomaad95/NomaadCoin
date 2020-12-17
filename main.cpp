#include"header/blockchain.h"
#include<ctime>

int main() {
  Blockchain bChain = Blockchain();

  int numblock = 0;

  while(true){
	  cout << "Mining new block" << endl;
	  cout << numblock << endl;
	  Block stBlock = Block(1,"hi", 1);
		cout << "adding block" << endl;
	  bChain.AddBlock(stBlock);
		cout << "validate chain" << endl;
	  bChain.isChainValid();
	  numblock++;
  }

  return 0;
}
