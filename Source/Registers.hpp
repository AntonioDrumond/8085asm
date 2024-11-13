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

	// Construtor //

	Registers ()
	{
		this->BC = new Par();
		this->DE = new Par();
		this->HL = new Par();
	}

	// Destrutor

	~Registers ()
	{
		delete (BC);
		delete (DE);
		delete (HL);
	}

	// Metodos set //

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

	// Metodos set //

	u_char getB (void)
	{
		return (this->BC->x);
	}

	u_char getC (void)
	{
		return (this->BC->y);
	}

	u_char getD (void)
	{
		return (this->DE->x);
	}

	u_char getE (void)
	{
		return (this->DE->y);
	}

	u_char getH (void)
	{
		return (this->HL->x);
	}

	u_char getL (void)
	{
		return (this->HL->y);
	}


};
