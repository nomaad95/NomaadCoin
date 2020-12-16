#include"blockchain.h"
#include<ctime>

int main() {
  Blockchain bChain = Blockchain();
  time_t now = time(0);
  char * dt = ctime(&now);
  cout << "Mining block 1…" << endl;
  bChain.AddBlock(Block(1, "Block 1 Data",dt));
  now = time(0);
  cout << "Mining block 2…" << endl;
  bChain.AddBlock(Block(2, "Block 2 Data", dt));
  now= time(0);
  cout << "Mining block 3…" << endl;
  bChain.AddBlock(Block(3, "Block 3 Data", dt));
  return 0;
}
