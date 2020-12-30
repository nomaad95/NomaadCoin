#include <cstdint>
#include <iostream>
#include <ctime>
#include<list>
#include "transaction.h"

using namespace std;


class Block {
public:
	Block(time_t now, list<Transaction> transactionList, int index);
	list<Transaction> sDataIn;
  string sPrevHash;
  string GetHash();
  void MineBlock(uint32_t nDifficulty);
  string _CalculateHash() const;
	uint32_t _nIndex;
	
private:
  int64_t _nNonce;
  string _sData;
  string _sHash;
  time_t now;


};
