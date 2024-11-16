#ifndef BIT_H
#define BIT_H

#include <math.h>
#include <string.h>
#include <cstdint>

char* toBin(uint8_t x){
	char* result = new char[9];
	snprintf(result, 9, "%8b", x);
	return result;
}

char* toHexa(uint16_t x){
	char* result = new char[5];
	snprintf(result, 5, "%4X", x);
	return result;
}

char* toHexa(uint8_t x){
	char* result = new char[3];
	snprintf(result, 3, "%2X", x);
	return result;
}

#endif
