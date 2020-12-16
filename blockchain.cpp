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

Block Blockchain::_GetLastBlock() const {
return _vChain.back();
}
