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
		/* SET FLAGS HERE */
		AF->s.l += added;
	}

	


};

#endif
