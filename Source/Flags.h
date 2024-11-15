#ifndef FLAGS_H
#define FLAGS_H

#include <cstdint>

class Flags{

	private:

	uint8_t data;
	/*
	bytes:
		0 - Z
		1 - CY
		2 - S
		3 - P
		4 - AC
	*/

	public:

	Flags(){
		this->data = 0x00;
	}

	~Flags(){
	}

	void setZ(){
		this->data = this->data | 0x80;
	}
	void resetZ(){
		this->data = this->data & 0x7F;
	}
	bool getZ(){
		return 0 != (this->data & 0x80);
	}

	

};

#endif
