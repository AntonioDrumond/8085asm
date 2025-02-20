#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include "Memory.h"

class Assembler
{
	private:
	Memory* memory;

	public:

    Memory* assemble(char* filename)
	{
		Memory* res = NULL;
        if(!filename)
		{
            std::cerr << "Erro: Nome de arquivo inválido\n";
        }
		else
		{
			
		}
		return (res);
    }

};
#endif
