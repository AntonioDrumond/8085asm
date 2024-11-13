#ifndef MAINMEMORY_H
#define MAINMEMORY_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <math.h>

#define null nullptr

class Memory
{
	public: 
	// Elementos da classe
	int rows;
	int cols;
	int ix;
	int iy;

	u_char** data;

	// Inicializar com dados invalidos
	void initVoid (void)
	{
		ix = -1;
		iy = -1;
		rows = 0;
		cols = 0;
		data = null;
	}

	// Construtores //
	Memory (void)
	{
		initVoid();
	}

	Memory (int r)
	{
		initVoid();
		if (r > 0)
		{
			u_char deft = 0x00;
			ix = 0;
			iy = 0;
			rows = r;
			cols = 16;
			data = new u_char* [rows];
			for (int i = 0; i < this->rows; i++)
			{
				data[i] = new u_char [cols];
				for (int y = 0; y < this->cols; y++)
				{
					data[i][y] = deft;
				}
			}
		}
		else
		{
			std::cout << "O tamanho fornecido para a memoria e invalido!" << "\n";
		}
	}

	// Verificar se a matriz possui dados alocados
	bool isValid ()
	{
		bool res = false;
		if (this->data)
		{
			int i = 0;
			while (i < this->rows && this->data[i])
			{
				i++;
			}

			if (i == this->rows)
			{
				res = true;
			}
		}
		return (res);
	}

	// Destrutor
	~Matrix ()
	{	
		if (this->isValid())
		{
			for (int i = 0; i < this->rows; i++)
			{
				delete (data[i]);
			}
			delete (data);
		}
	}

	// Inserir valor na matriz
	void insert (u_char x, int r, int c)
	{
		if (this->isValid())
		{
			if (r > 0 && r < this->rows && c > 0 && c < this->cols)
			{
				this->data[r][c] = x;
			}
		}
	}

	u_char get (int r, int c)
	{
		u_char res = 0;
		if (this->isValid() && r > 0 && c > 0 && r < this->rows && c < this->cols)
		{
			res = this->data[r][c];
		}
		return (res);
	}

	void flush (void)
	{
		if (this->isValid())
		{
			for (int i = 0; i < this->rows; i++)
			{
				for (int y = 0; y < this->rows; y++)
				{
					this->data[i][y] = 0x00;
				}
			}
		}
	}

	void print (void)
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
