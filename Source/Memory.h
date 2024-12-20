#ifndef MEMORY_H
#define MEMORY_H

#include "Bit.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <math.h>

#define null nullptr

class Memory
{
	private: 
	uint8_t* data;

	public:

	// Construtores //
	Memory()
	{
		data = new uint8_t[0xFFFF + 1];
	}

	~Memory()
	{
		if(data) delete[] data;
	}

	// Verificar se a matriz possui dados alocados
	bool isValid ()
	{
		return data != nullptr;
	}

	// Inserir valor na matriz
	void set (uint8_t in, uint16_t addr)
	{
		if(this->data) this->data[(int)addr] = in;
	}

	uint8_t get (uint16_t addr)
	{
		uint8_t ret = 0x00;
		if(this->data) ret = this->data[(int)addr];
		return ret;
	}

	void flush ()
	{
		int reps = 0xFFFF + 1;
		if(data){
			for(int i=0; i<reps; i++){
				this->data[i] = 0x00;
			}
		}
	}

	void print ()
	{
		if (this->isValid())
		{
			std::cout << "      0 1 2 3 4 5 6 7 8 9 A B C D E F" << "\n";
			std::cout << "     --------------------------------" << "\n";
			for (int i = 0; i < this->rows; i++)
			{
				std::cout << std::setfill('0') << std::setw(4);
				std::cout << i << " |";
				for (int y = 0; y < this->cols; y++)
				{
					std::cout << data[i][y] << " " << std::flush;
				}
				std::cout << "\n";
			}
		}
	}

	void print (const char* const filename)
	{
		if (filename && this->isValid())
		{
			std::ofstream file;
			file.open (filename);
			file << "      0 1 2 3 4 5 6 7 8 9 A B C D E F" << "\n";
			file << "     --------------------------------" << "\n";
			for (int i = 0; i < this->rows; i++)
			{
				file << std::setfill('0') << std::setw(4);
				file << i << " |";
				for (int y = 0; y < this->cols; y++)
				{
					file << data[i][y] << " " << std::flush;
				}
				file << "\n";
			}
		}
	}

};

#endif
