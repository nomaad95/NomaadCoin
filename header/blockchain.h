#include <cstdint>
#include <vector>
#include <list>
#include "block.h"
using namespace std;


class Blockchain {
  public:
    Blockchain();
    void AddBlock(Block bNew);
    bool isChainValid();
    int miningRewards = 10;
		list<Transaction> pendingTransactions;
		void minePendingTransactions(string miningRewardAddress);
		void createTransaction(Transaction transaction);
  private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;
    Block _GetLastBlock() const;
};
