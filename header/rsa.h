#include<iostream>
#include<cmath>
#include<vector>
#include<numeric>

using namespace std;


class Rsa{
public:
	Rsa(int * pub, int * pri, int * mod);

private:
	int randomBigPrime( int max);
	mp::cpp_int testBigPrime(mp::cpp_int a);
	mp::cpp_int recursiveBigGCD(mp::cpp_int a, mp::cpp_int b, mp::cpp_int *x, mp::cpp_int *y);
	int recursiveGCD(int a, int b, int *x, int *y)




};
