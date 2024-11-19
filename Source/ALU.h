#ifndef ALU_H
#define ALU_H

#include "Registers.h"

class ALU{

	private:
	Registers* r;
	RegPair* AF;

	public:
	
	ALU(Registers* r){
		this->r = r;
		this->AF = r->getPointerAF();
	}

	~ALU(){
		this->r = nullptr;
		this->AF = nullptr;
	}

	void addReg(char c){
		char C = c<'a' ? c+'a'-'A' : c;
		uint8_t added = 0x00;
		switch (C)
		{
			case 'a': added = r->getA(); break;
			case 'b': added = r->getB(); break;
			case 'c': added = r->getC(); break;
			case 'd': added = r->getD(); break;
			case 'e': added = r->getE(); break;
			case 'h': added = r->getH(); break;
			case 'l': added = r->getL(); break;
			default:  added = 0x00;      break;
		}
		if(added&0b10000000 == r->getA()&0b10000000) r->setCY();
		AF->s.l += added;
	}

	void subReg(char c){
		char C = c<'a' ? c+'a'-'A' : c;
		uint8_t subbed= 0x00;
		switch (C)
		{
			case 'a': subbed= r->getA(); break;
			case 'b': subbed= r->getB(); break;
			case 'c': subbed= r->getC(); break;
			case 'd': subbed= r->getD(); break;
			case 'e': subbed= r->getE(); break;
			case 'h': subbed= r->getH(); break;
			case 'l': subbed= r->getL(); break;
			default:  subbed= 0x00;      break;
		}
		if(subbed0b10000000 == r->getA()&0b10000000) r->setCY();
		AF->s.l -= subbed
	}

	


};

#endif
