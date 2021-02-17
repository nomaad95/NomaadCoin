#include<iostream>
#include<cmath>
#include<vector>
#include<numeric>
#include<boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;

class Rsa{
public:
	Rsa();
	void genKey();
	int pub; // prime number of the public key
	int pri; // prime number of the private key;
	int mod; // modulo used for rsa algorithm


private:
	int randomBigPrime( int max);
	mp::cpp_int testBigPrime(mp::cpp_int a);
	int recursiveGCD(int a, int b, int *x, int *y);
	mp::cpp_int recursiveBigGCD(mp::cpp_int a, mp::cpp_int b, mp::cpp_int *x, mp::cpp_int *y);
	mp::cpp_int encrypt(int message);
	mp::cpp_int decrypt(mp::cpp_int encrypted);




};
