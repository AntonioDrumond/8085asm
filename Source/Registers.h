#ifndef REGISTERS_H
#define REGISTERS_H

#include <cstdint>

union RegPair{
    struct {
        uint8_t r; // only right register
        uint8_t l; // only left register
    };
	uint16_t b; // both registers in pair
};

clasregisters{

	private:
	RegPair* AF;
	RegPair* BC;
	RegPair* DE;
	RegPair* HL;
	uint16_t SP;
	uint16_t PC;

	public:

	Registers(){
		AF = new RegPair;
		AF->b = 0x0000;
		BC = new RegPair;
		BC->b = 0x0000;
		DE = new RegPair;
		DE->b = 0x0000;
		HL = new RegPair;
		HL->b = 0x0000;
		SP = 0x0000;
		PC = 0x0000;
	}

	~Registers(){
		delete AF;
		delete BC;
		delete DE;
		delete HL;
	}

	RegPair* getPointerAF(){
		return this->AF;
	}

	/*____ Flag operations ____
	 *
	 *	Bits in the flag register:
	 *	S Z - AC - P - CY
	 *	0 1 2  3 4 5 6  7
	*/

	bool getS(){
		return (AF->r & 0x80) != 0;
	}
	void setS(){
		AF->r = AF->s.r | 0x80;
	}
	void resetS(){
		AF->r = AF->s.r & 0x7F;
	}

	bool getZ(){
		return (AF->r & 0x40) != 0;
	}
	void setZ(){
		AF->r = AF->s.r | 0x40;
	}
	void resetZ(){
		AF->r = AF->s.r & 0xBF;
	}

	bool getAC(){
		return (AF->r & 0x10) != 0;
	}
	void setAC(){
		AF->r = AF->s.r | 0x10;
	}
	void resetAC(){
		AF->r = AF->s.r & 0xEF;
	}

	bool getP(){
		return (AF->r & 0x04) != 0;
	}
	void setP(){
		AF->r = AF->s.r | 0x04;
	}
	void resetP(){
		AF->r = AF->s.r & 0xFB;
	}

	bool getCY(){
		return (AF->r & 0x01) != 0;
	}
	void setCY(){
		AF->r = AF->s.r | 0x01;
	}
	void resetCY(){
		AF->r = AF->s.r & 0xFE;
	}


	//____ Get Methods ____

	uint8_t getA(){
		return AF->l;
	}

	uint8_t getB(){
		return BC->l;
	}
	uint8_t getC(){
		return BC->r;
	}
	uint16_t getBC(){
		return BC->b;
	}

	uint8_t getD(){
		return DE->l;
	}
	uint8_t getE(){
		return DE->r;
	}
	uint16_t getDE(){
		return DE->b;
	}

	uint8_t getH(){
		return HL->l;
	}
	uint8_t getL(){
		return HL->r;
	}
	uint16_t getHL(){
		return HL->b;
	}

	uint16_t getSP(){
		return SP;
	}
	uint16_t getPC(){
		return PC;
	}


	//____ Set Methods ____

	void setA(uint8_t x){
		AF->l = x;
	}

	void setB(uint8_t x){
		BC->l = x;
	}
	void setC(uint8_t x){
		BC->r = x;
	}
	void setBC(uint16_t x){
		BC->b = x;
	}

	void setD(uint8_t x){
		DE->l = x;
	}
	void setE(uint8_t x){
		DE->r = x;
	}
	void setDE(uint16_t x){
		DE->b = x;
	}

	void setH(uint8_t x){
		HL->l = x;
	}
	void setL(uint8_t x){
		HL->r = x;
	}
	void setHL(uint16_t x){
		HL->b = x;
	}

	void setSP(uint16_t x){
		SP = x;
	}
	void setPC(uint16_t x){
		PC = x;
	}

	// ____INR and DCR methods____
	void inrA(){
		if(AF->l == 0xFF) setCY();
		AF->l += 0x01;
	}
	void dcrA(){
		if(AF->l == 0x00) setCY();
		AF->l -= 0x01;
	}

	void inrB(){
		if(BC->l == 0xFF) setCY();
		BC->l += 0x01;
	}
	void dcrB(){
		if(BC->l == 0x00) setCY();
		BC->l -= 0x01;
	}

	void inrC(){
		if(BC->r == 0xFF) setCY();
		BC->r += 0x01;
	}
	void dcrC(){
		if(BC->r == 0x00) setCY();
		BC->r -= 0x01;
	}

	void inrD(){
		if(DE->l == 0xFF) setCY();
		DE->l += 0x01;
	}
	void dcrD(){
		if(DE->l == 0x00) setCY();
		DE->l -= 0x01;
	}

	void inrE(){
		if(DE->r == 0xFF) setCY();
		DE->r += 0x01;
	}
	void dcrE(){
		if(DE->r == 0x00) setCY();
		DE->r -= 0x01;
	}

	void inrH(){
		if(HL->l == 0xFF) setCY();
		HL->l += 0x01;
	}
	void dcrH(){
		if(HL->l == 0x00) setCY();
		HL->l -= 0x01;
	}

	void inrL(){
		if(HL->r == 0xFF) setCY();
		HL->r += 0x01;
	}
	void dcrL(){
		if(HL->r == 0x00) setCY();
		HL->r -= 0x01;
	}

};

#endif
