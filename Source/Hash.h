#ifndef HASH_H
#define HASH_H
#include <cstdint>
#include <cstring>
#include <iostream>

class AssemblerHash
{
	private:
	public:
	uint8_t* table;
	int CTindex;
	uint8_t* colisionTable;

	AssemblerHash ()
	{
		table = new uint8_t[79];
		colisionTable = new uint8_t[21];
		CTindex = 0;
		if (!table || !colisionTable)
		{
			std::cerr << "ERROR: Not enough memory!\n";
		}
		else
		{

		}
	}

	~AssemblerHash()
	{
		delete(table);
	}

	int hash (const char* const str)
	{
		int res = 0;	
		if (!str)
		{
			std::cerr << "ERROR: Invalid string!\n";
		}
		else
		{
			int n = (int)strlen(str);

			for (int i = 0; i < n; i++)
			{
				if (str[i] != ' ')
				{
					res += (int)str[i] * (i+6);
					if ((int)str[i] % 2 == 0)
					{
						res+=1;
					}
					else
					{
						res-=22;
					}
				}
			}
			res = (res % 79);
		}
		return (res);
	}

};

class DisassemblerHash
{

};

#endif
