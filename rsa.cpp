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

Rsa::Rsa(){
}

void Rsa::genKey(){
	do{
		int p;
		int q;
		int k;
		int m;
		p = randomBigPrime(100);
		do{
			q = randomBigPrime(100);
		} while(q == p);
		mod = p*q; 												// modulo of rsa algorithm
		pub = randomBigPrime(mod);			 // generation of a random prime number for the public key

		m = (p-1)*(q-1);	 								// definition of phi (used in RSA calculation)
		recursiveGCD(m,pub,&k,&pri); 					//finds the value of the integer of the private key for a given phi and a given prime number

		if( pri < 0){ 												//In certain cases the found Integer may be negative. Adding phi makes it positive
			pri += m;
		}
	} while(pri == 1); // if pri is equal to 1 the RSA logic cannot work


}

mp::cpp_int Rsa::encrypt(int message){
	return mp::pow(mp::cpp_int(message), pub)%mod;
}

mp::cpp_int Rsa::decrypt(mp::cpp_int encrypted){
	return mp::pow(mp::cpp_int(encrypted), pri)%mod;
}

int Rsa::randomBigPrime( int max){ // returns a random large prime integer

	vector<int> primes;
	for(int i = 2; i < max; i++){
		if(testBigPrime(i)==1){
			primes.push_back(i);
		}
	}
	srand(time(NULL));
	if(primes.size() == 0){
		cout << "division par 0" << endl;
	}
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

int Rsa::recursiveGCD(int a, int b, int *x, int *y){ // returns the gcd of 2 integers
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
