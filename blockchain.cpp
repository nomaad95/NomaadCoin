#include"header/blockchain.h"
#include<list>
#include<ctime>
Blockchain::Blockchain() {

  time_t now = time(0);
  char* dt = ctime(&now);
	list<Transaction> trans;
	Block root = Block(time(0), trans, _vChain.size());
	root.sPrevHash = root._CalculateHash();
_vChain.emplace_back(root);
_nDifficulty = 5;
}

void Blockchain::AddBlock(Block bNew) {
bNew.sPrevHash = _GetLastBlock().GetHash();
bNew.MineBlock(_nDifficulty);
_vChain.push_back(bNew);
}

void Blockchain::minePendingTransactions(string miningRewardAddress){
	cout << "number of blocks" << pendingTransactions.size() << endl;
	Block block = Block(time(0), pendingTransactions, _vChain.size());
	block.sPrevHash = _GetLastBlock().GetHash();
	block.MineBlock(_nDifficulty);
	_vChain.emplace_back(block);
	pendingTransactions.empty();
	Transaction t1 =  Transaction("", miningRewardAddress, miningRewards );
	pendingTransactions.push_back(t1);
  cout << "new block mined, giving reward" << endl;


}

double Blockchain::getBalance(string walletAddress){
	double balance = 0;
	vector<Block>::iterator blockIterator;
	list<Transaction>::iterator transIterator;
	for(blockIterator = _vChain.begin(); blockIterator != _vChain.end(); blockIterator++ ){
		for(transIterator = blockIterator->sDataIn.begin(); transIterator != blockIterator->sDataIn.end(); transIterator++){
			if(transIterator->fromAddress == walletAddress){
				balance -= transIterator->amount;
				cout << "went in" <<endl;
			}

			if(transIterator->toAddress == walletAddress){
				balance += transIterator->amount;
				cout << "went in" <<endl;

			}
		}
	}
	return balance;
}

void Blockchain::createTransaction(Transaction transaction){
	pendingTransactions.push_back(transaction);
	cout << "pending transactions :" << pendingTransactions.size() << endl;
}

bool Blockchain::isChainValid(){
  for(int i=1; i<_vChain.size();i++){

    Block currentBlock = _vChain[i];
    Block prevBlock = _vChain[i-1];
    if((currentBlock.GetHash() != currentBlock._CalculateHash()) || currentBlock.sPrevHash != prevBlock.GetHash()){
      return false;
    }
  }

  return true;


}

Block Blockchain::_GetLastBlock() const {
return _vChain.back();
}
