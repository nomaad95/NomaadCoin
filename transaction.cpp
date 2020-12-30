#include"header/transaction.h"
#include<sstream>

Transaction::Transaction(string from, string to, int am){
	fromAddress = from;
	toAddress = to;
	amount = am;
}
