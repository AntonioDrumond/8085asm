#ifndef MEMORY_H
#define MEMORY_H
#include "Bit.h"
#include <cstdint>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <math.h>

#define null nullptr

#define __MEMLEN__ (0xFFFF+1)

class Memory
{
	// ============ Define basics ============ //
	private:

	// Define memory pointer
	uint8_t* memory = nullptr;

	public:
	
	// Constructor
	Memory()
	{
		memory = new uint8_t[__MEMLEN__]; 	// 65535

		if (this->isValid())
		{
			for (int i = 0; i < __MEMLEN__; i++)
			{
				memory[i] = 0x00;
			}
		}
	}

	// Destructor
	~Memory()
	{
		if (memory)
		{
			delete (memory);
		}
	}

	// Check memory availability
	bool isValid (void)
	{
		bool res = (memory);
		if (!res)
		{
			std::cout << "ERROR: The memory is empty!\n";
		}
		return (res);
	}

	// ============ Define set methods ============ //

	// Set 8 bits in the memory
	void set8bits (uint16_t index, uint8_t value)
	{
		if (this->isValid())
		{
			// Set bits
			memory[index] = value;
		}
	}

	// Set 16 bits in the memory
	void set16bits (uint16_t index, uint16_t value)
	{
		if (this->isValid())
		{
			if (index < (__MEMLEN__-1))
			{
				// Separate bits
				uint8_t maskTop = ( (value & 0xFF00) >> 8 );
				uint8_t maskBot = 	(value & 0x00FF);

				// Set bits
				memory[index] = maskTop;
				memory[index+1] = maskBot;
			}
			else
			{
				std::cout << "ERROR: Invalid index at [set16bits]!\n";
			}
		}
	}

	// ============ Define get methods ============ //

	// Get a 8 bits value from the memory
	uint8_t get8bits (uint16_t index)
	{
		uint8_t res = 0x00;
		if (this->isValid())
		{
			res = memory[index];
		}
		return (res);
	}

	// Get a 16 bits value from the memory
	uint16_t get16bits (uint16_t index)
	{
		uint16_t res = 0x0000;
		if (this->isValid())
		{
			if (index < (__MEMLEN__-1))
			{
				uint8_t tmp = memory[index];
				res = memory[index] << 8;
				res = res + memory[index+1];
			}
			else
			{
				std::cout << "ERROR: Index error at [get16bits]!\n";
			}
		}
		return (res);
	}

	// ============ Define print method ============ //	

	// Print memory //
	void print (void)
	{
		for (int i = 0; i < __MEMLEN__; i++)
		{
			printf ("%u ", memory[i]);

			if (i % 65 == 0)
			{
				printf("\n");
			}
		}
	}

	// ============ Define file methods ============ //

	// Write memory in a file //
	void writeLog (void)
	{
		if (this->isValid())
		{
			std::fstream fs;

			fs.open("memoryLog.bin", std::ios::out | std::ios::binary);

			if (!fs.good()) // Check file
			{
				std::cout << "ERROR: The file could not be opened!\n";	
			}
			else
			{
				for (int i = 0; i < __MEMLEN__; i = i+1)
				{
					fs << memory[i] << '\n';
				}

				fs.close();
			}
		}
	}

	// Read memory in a file //
	void readLog (void)
	{
		std::fstream fs;

		fs.open("memoryLog.bin", std::ios::in | std::ios::binary);

		if (!fs.good())
		{
			std::cout << "ERROR: The file could not be opened!\n";	
		}
		else
		{
			for (int i = 0; i < __MEMLEN__; i++)
			{
				fs >> memory[i];
			}
			fs.close();
		}
	}
};
#endif
