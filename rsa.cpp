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

Rsa::Rsa(int * pub, int * pri, int * mod){
	Rsa::genKey(pub, pri, mod);
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
