#ifndef BIT_H
#define BIT_H

#include <math.h>
#include <string.h>
#include <iostream>

char* cToBin(u_char c){
	int n = (int)c;
	char* result = new char[8];
	for(int exp=7; exp>=0; exp--){
		int p = pow(2, exp);
		if(n >= p){
			n -= p;
			result[7-exp] = '1';
		}
		else result[7-exp] = '0';
	}
	return result;
}

char* cToHexa(u_char c){
	int n = (int)c;
	char* result = new char[4];
	snprintf(result, 3, "%2X", n);
	return result;
}

#endif
