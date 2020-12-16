#include"header/blockchain.h"
#include<ctime>
Blockchain::Blockchain() {

  time_t now = time(0);
  char* dt = ctime(&now);
_vChain.emplace_back(Block(0, "Genesis Block", dt));
_nDifficulty = 6;
}

void Blockchain::AddBlock(Block bNew) {
bNew.sPrevHash = _GetLastBlock().GetHash();
bNew.MineBlock(_nDifficulty);
_vChain.push_back(bNew);
}

bool Blockchain::isChainValid(){

  for(int i=0; i<_vChain.size();i++){
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
