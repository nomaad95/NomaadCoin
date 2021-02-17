#include "header/rsa.h"
#include<stdio.h>
#include <iostream>
#include<vector>
#include<list>
#include<time.h>
#include<stdlib.h>
#include<cmath>
#include<climits>
#include<math.h>
#include<boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

Rsa::Rsa(int * pub, int * pri, int * mo){
}

void Rsa::genKey(int * pub, int * pri, int *mod){
	int p;
	int q;
	int e;
	int k;
	int d;
	int message = 8;
	p = randomBigPrime(100);
	do{
		q = randomBigPrime(100);
	} while(q == p);

	e = randomBigPrime(p*q);
	int n = p*q;
	int m = (p-1)*(q-1);
	int c = recursiveGCD(m,e,&k,&d);
	if( d < 0){
		d += m;
	}

	mp::cpp_int encrypt = mp::pow(mp::cpp_int(message), e)%n;  //public is (n,E)
	mp::cpp_int decrypt = mp::pow(mp::cpp_int(encrypt), d)%n; // private is (n,D)
}

int Rsa::randomBigPrime( int max){

	vector<int> primes;
	for(int i = 2; i < max; i++){
		if(testBigPrime(i)==1){
			primes.push_back(i);
		}
	}
	srand(time(NULL));
	int number = (rand()%primes.size());
	//cout << "number " << number << endl;
	return primes[number];

}

mp::cpp_int Rsa::testBigPrime(mp::cpp_int a){ // checks if an integer is prime
	mp::cpp_int x;
	mp::cpp_int y;
	for(mp::cpp_int i = 1; i < a; i++){
		//cout << "loop"<< i << endl;
		if(recursiveBigGCD(a,i, &x,&y) != 1){
			//cout << "not primary" << endl;
			return 0;
		}
	}
	//scout << "primary" << endl;

	return 1;
}

mp::cpp_int Rsa::recursiveBigGCD(mp::cpp_int a, mp::cpp_int b, mp::cpp_int *x, mp::cpp_int *y){ // gives the gcd of 2 integers
	if(b == 0){
		*x = 1;
		*y = 0;
		return a;
	}

		mp::cpp_int _x;
		mp::cpp_int _y;
		mp::cpp_int gcd = recursiveBigGCD(b, a%b, &_x, &_y);
		*x = _y;
		*y = _x - (a/b)*_y;
		return gcd;

}

int Rsa::recursiveGCD(int a, int b, int *x, int *y){ // gives the gcd of 2 integers
	if(b == 0){
		*x = 1;
		*y = 0;
		return a;
	}
		int _x;
		int _y;
		int gcd = recursiveGCD(b, a%b, &_x, &_y);
		*x = _y;
		*y = _x - (a/b)*_y;
		return gcd;
}
