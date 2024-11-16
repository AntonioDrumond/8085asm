#ifndef MEMORY_Hj
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
	int usingX, usingY;
	int totalX, totalY;

	uint8_t** data;

	// Construtores //
	Memory()
	{
		totalX = totalY = 256;
		data = new uint8_t* [256];
		for(int i=0; i<256; i++)
		{
			data[i] = new uint8_t [256];
		}
	}

	~Memory()
	{
		if(data){
			for(int i=0; i<256; i++)
			{
				if(data[i]) delete data[i];
			}
			delete[] data;
		}
	}

	// Verificar se a matriz possui dados alocados
	bool isValid ()
	{
		bool res = this->data != nullptr;
		if (res)
		{
			for(int i=0; i<256 && res; i++)
			{
				if(!this->data[i]) res = false;
			}
		}
		return (res);
	}

	// Inserir valor na matriz
	void insert (uint8_t in, int y, int x)
	{
		if (this->isValid())
		{
			this->data[y%256][x%256] = in;
		}
	}

	uint8_t get (int y, int x)
	{
		uint8_t res = 0x00;
		if (this->isValid())
		{
			res = this->data[abs(y%256)][abs(x%256)];
		}
		return (res);
	}

	void flush ()
	{
		if (this->isValid())
		{
			for (int i = 0; i < totalY; i++)
			{
				for (int j = 0; j < totalX; j++)
				{
					this->data[i][j] = 0x00;
				}
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
