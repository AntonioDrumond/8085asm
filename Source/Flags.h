#ifndef FLAGS_H
#define FLAGS_H

class Flags{

	private:

	u_char data;
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
		this->data = this->data | 0b10000000;
	}
	void resetZ(){
		this->data = this->data & 0b01111111;
	}
	bool getZ(){
		return this->data == (this->data | 0b10000000);
	}

	

};

#endif
