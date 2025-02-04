#ifndef DECODERH_H
#define DECODER_H

#include <cstdint>
#include <iostream>
//#include "Memory.h"
//#include "ALU.h"
#include "Registers.h"
#include "Bit.h"

class Decoder{

    private:
    //Memory* mem;
    Registers* reg;
    //ALU* alu;

    public:
    //Decoder(Memory* mem, Registers* reg, ALU* alu){
    Decoder(Registers* reg){
        //this->mem = mem;
        this->reg = reg;
        //this->alu = alu;
    }

    ~Decoder(){
        //this->mem = nullptr;
        this->reg = nullptr;
        //this->alu = nullptr;
    }

    bool instruction1byte(uint8_t opcode){
        return true;
    }

    bool instruction2byte(uint8_t opcode, uint8_t operand){
        return true;
    }

    bool instruction3byte(uint8_t opcode, uint16_t operand){
        return true;
    }

    bool instruction3byte(uint8_t opcode, uint8_t oper1, uint8_t oper2){
        uint16_t operand = oper2;
        uint16_t buffer = oper1;
        operand += buffer << 8;
        return instruction3byte(opcode, operand);
    }

    //___ Instructions ___
    
    void MOV(uint8_t* rd, uint8_t rs){ //  
    }

    void MVI(uint8_t* rd, uint8_t data){
    }

    void LDA(uint16_t address){
    }

    void LDAX(uint8_t data){
    }

    void LXI(uint16_t* rd, uint16_t data){
    }

    void LHLD(uint16_t addr){
    }

    void STA(uint16_t addr){
    }

    void STAX(uint16_t addr){
    }

};

#endif
