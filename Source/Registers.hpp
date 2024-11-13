#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <math.h>

#define null nullptr

class Par
{
	public:

	u_char x;
	u_char y;

	// Construtor

	Par ()
	{
		this->x = 0x00;
		this->y = 0x00;
	}

	Par (u_char c1, u_char c2)
	{
		this->x = c1;
		this->y = c2;
	}

	// Destrutor
	~Par ()
	{}

	// Metodos
}

class Registers
{
	public: 

	Par* BC;
	Par* DE;
	Par* HL;

	Registers ()
	{
		this->BC = new Par();
		this->DE = new Par();
		this->HL = new Par();
	}	

	void setB (u_char c)
	{
		this->BC->x = c;
	}

	void setC (u_char c)
	{
		this->BC->y = c;
	}

	void setD (u_char c)
	{
		this->DE->x = c;
	}

	void setE (u_char c)
	{
		this->DE->y = c;
	}

	void setH (u_char c)
	{
		this->HL->x = c;
	}

	void setL (u_char c)
	{
		this->HL->y = c;
	}

};
