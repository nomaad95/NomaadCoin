#include "header/block.h"
#include "header/sha256.h"
#include <sstream>
#include <ctime>

Block::Block(time_t now, list<Transaction> transactionList, int index) {
_nIndex = index;
_nNonce = -1;
now = time(0);
sDataIn = transactionList;
}

string Block::GetHash() {
return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
  char cstr[nDifficulty + 1];
  for (uint32_t i = 0; i < nDifficulty; ++i) {
  cstr[i] = '0';
}
  cstr[nDifficulty] = '\0';
  string str(cstr);
  do {
    _nNonce++;
    _sHash = _CalculateHash();
  } while (_sHash.substr(0, nDifficulty) != str);
	/*cout<<"prevHash\n"<<sPrevHash<<endl;
  cout << "Block mined: " << _sHash << endl;
	cout<<"time\n"<<now<<endl;
	cout<<"data\n"<<_nNonce<<endl;
	cout<<"\n"<<endl;*/

}


inline string Block::_CalculateHash() const {
stringstream ss;

ss << _nIndex << now << _sData << _nNonce << sPrevHash;
return sha256(ss.str());
}
