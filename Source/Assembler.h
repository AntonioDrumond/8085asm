#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include "Memory.h"

class Assembler
{
	private:
	Memory* memory;

	public:

    Memory* assemble(char* filename){
        if(!filename){
            std::cerr << "Erro: Nome de arquivo inválido\n";
            return nullptr;
        }

    }

}
