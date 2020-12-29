#include <cstdint>
#include <iostream>


using namespace std;


class Transaction{
  public:
		Transaction(string fromAddress,string toAddress, int amount);
    string fromAddress;
    string toAddress;
    int amount;

};
