#include"header/transaction.h"
#include"header/sha256.h"
#include<sstream>
#include<ctime>

Transaction::Transaction(string sender, string receiver, int quantt){
	fromAddress = sender;
	toAddress = receiver;
	amount = quantt;
	stringstream ss;
	ss << sender << receiver << quantt << time(0);
	hash = sha256(ss.str());

}
