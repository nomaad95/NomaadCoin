#include"header/blockchain.h"
#include<list>
#include<ctime>
Blockchain::Blockchain() {

  time_t now = time(0);
  char* dt = ctime(&now);
	list<Transaction> trans;
_vChain.emplace_back(Block(time(0), trans));
_nDifficulty = 5;
}

void Blockchain::AddBlock(Block bNew) {
bNew.sPrevHash = _GetLastBlock().GetHash();
bNew.MineBlock(_nDifficulty);
_vChain.push_back(bNew);
}

void Blockchain::minePendingTransactions(string miningRewardAddress){

	Block block = Block(time(0), pendingTransactions);
	block.MineBlock(_nDifficulty);
	_vChain.emplace_back(block);
	pendingTransactions.empty();
	string test = "test";
	Transaction t1 =  Transaction(NULL, miningRewardAddress, miningRewards );
	pendingTransactions.push_back(t1);
  cout << "new block mined, giving reward" << endl;


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
