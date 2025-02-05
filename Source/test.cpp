#include "Registers.h"
#include "Memory.h"
#include "ALU.h"

int main (void)
{
	Memory* mem = new Memory();
	Registers* reg = new Registers();
	ALU* alu = new ALU(reg, mem);

	reg->setA(0x01); // MVI A, 00H
	reg->setB(0x02); // MVI B, 01H

	alu->add('b');   // ADD B

	reg->setHL (0x0002); // LXI H, 0002H
	mem->set8bits(reg->getHL(), reg->getA()); // MOV M, A

	mem->writeLog();

	return (0);
}
