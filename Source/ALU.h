#ifndef ALU_H
#define ALU_H

#include "Registers.h"
#include "Memory.h"
#include <cstdint>

class ALU{

	private:
	Registers* r;
	Memory* mem;
	RegPair* AF;

	public:
	
	ALU (Registers* r, Memory* mem){
		this->r = r;
		this->AF = r->getPointerAF();
		this->mem = mem;
	}

	~ALU (void){
		this->r = nullptr;
		this->AF = nullptr;
		this->mem = nullptr;
	}

	void add (char c){
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
			case 'm': added = mem->get8bits(r->getHL()); break;
			default:  added = 0x00;      break;
		}
		if(added&0b10000000 == r->getA()&0b10000000) r->setCY();
		else r->resetCY();
		AF->l += added;
	}

	void sub(char c){
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
			case 'm': subbed= mem->get8bits(r->getHL()); break;
			default:  subbed= 0x00;      break;
		}
		if(subbed > r->getA()&0b10000000) r->setCY();
		else r->resetCY();
		AF->l -= subbed;
	}

	void adcReg(char c){
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
			case 'm': added = mem->get8bits(r->getHL()); break;
			default:  added = 0x00;      break;
		}
		bool cy = false;
		if(added&0b10000000 == r->getA()&0b10000000) cy = true;
		AF->l += added;
		if(AF->l == 0xFF && r->getCY()) cy = true;
		if(r->getCY()) AF->l += 0x01;
		if(cy) r->setCY();
		else r->resetCY();
	}

	void adi(uint8_t x){
		if(x&0b10000000 == r->getA()&0b10000000) r->setCY();
		else r->resetCY();
		AF->l += x;
	}

	void aci(uint8_t x){
		bool cy = false;
		if (x&0b10000000 == r->getA()&0b10000000) cy = true;
		AF->l += x;
		if(AF->l == 0xFF && r->getCY()) cy = true;
		if(r->getCY()) AF->l += 0x01;
		if(cy) r->setCY();
		else r->resetCY();
	}
};

#endif
