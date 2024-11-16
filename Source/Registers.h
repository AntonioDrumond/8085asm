struct SeparateAccess{
	uint8_t r : 8;
	uint8_t l : 8;
};	// Used to access the left or right halves of the register pair

union RegPair{
	SeparateAccess s;
	uint16_t both : 16;
};

class Registers{

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
		AF->both = 0x0000;
		BC = new RegPair;
		BC->both = 0x0000;
		DE = new RegPair;
		DE->both = 0x0000;
		HL = new RegPair;
		HL->both = 0x0000;
		SP = 0x0000;
		PC = 0x0000;
	}

	~Registers(){
		delete AF;
		delete BC;
		delete DE;
		delete HL;
	}

	/*____ Flag operations ____
	 *
	 *	Bits in the registers:
	 *	S Z - AC - P - CY
	 *	0 1 2  3 4 5 6  7
	*/

	bool getS(){
		return (AF->s.r & 0x80) != 0;
	}
	void setS(){
		AF->s.r = AF->s.r | 0x80;
	}
	void resetS(){
		AF->s.r = AF->s.r & 0x7F;
	}

	bool getZ(){
		return (AF->s.r & 0x40) != 0;
	}
	void setZ(){
		AF->s.r = AF->s.r | 0x40;
	}
	void resetZ(){
		AF->s.r = AF->s.r & 0xBF;
	}

	bool getAC(){
		return (AF->s.r & 0x10) != 0;
	}
	void setAC(){
		AF->s.r = AF->s.r | 0x10;
	}
	void resetAC(){
		AF->s.r = AF->s.r & 0xEF;
	}

	bool getP(){
		return (AF->s.r & 0x04) != 0;
	}
	void setP(){
		AF->s.r = AF->s.r | 0x04;
	}
	void resetP(){
		AF->s.r = AF->s.r & 0xFB;
	}

	bool getCY(){
		return (AF->s.r & 0x01) != 0;
	}
	void setCY(){
		AF->s.r = AF->s.r | 0x01;
	}
	void resetCY(){
		AF->s.r = AF->s.r & 0xFE;
	}


	//____ Get Methods ____

	uint8_t getA(){
		return AF->s.l;
	}

	uint8_t getB(){
		return BC->s.l;
	}
	uint8_t getC(){
		return BC->s.r;
	}
	uint16_t getBC(){
		return BC->both;
	}

	uint8_t getD(){
		return DE->s.l;
	}
	uint8_t getE(){
		return DE->s.r;
	}
	uint16_t getDE(){
		return DE->both;
	}

	uint8_t getH(){
		return HL->s.l;
	}
	uint8_t getL(){
		return HL->s.r;
	}
	uint16_t getHL(){
		return HL->both;
	}

	uint16_t getSP(){
		return SP;
	}
	uint16_t getPC(){
		return PC;
	}


	//____ Set Methods ____

	void setA(uint8_t x){
		AF->s.l = x;
	}

	void setB(uint8_t x){
		BC->s.l = x;
	}
	void setC(uint8_t x){
		BC->s.r = x;
	}
	void setBC(uint16_t x){
		BC->both = x;
	}

	void setD(uint8_t x){
		DE->s.l = x;
	}
	void setE(uint8_t x){
		DE->s.r = x;
	}
	void setDE(uint16_t x){
		DE->both = x;
	}

	void setH(uint8_t x){
		HL->s.l = x;
	}
	void setL(uint8_t x){
		HL->s.r = x;
	}
	void setHL(uint16_t x){
		HL->both = x;
	}

	void setSP(uint16_t x){
		SP = x;
	}
	void setPC(uint16_t x){
		PC = x;
	}

};
