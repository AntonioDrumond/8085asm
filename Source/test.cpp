#include <iostream>
#include "Flags.h"
#include <format>

struct TA{
	uint8_t a : 8;
	uint8_t f : 8;
};

union T{
	TA s;
	uint16_t af : 16;
};

int main(){

	std::cout << sizeof(TA) << "\n";
	std::cout << sizeof(T) << "\n\n\n";
	
	T* t = new T();

	t->af = 0xF0A4;

	printf("A  = %.8b\nF  = %.8b\nAF = %.16b\n", t->s.a, t->s.f, t->af);

	delete t;

	return 0;
}
