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

        //___ Data Transfer Instructions ___

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

        void STA(uint16_t addr){ // 3
        }

        void STAX(uint16_t addr){
        }

        void SHLD(uint16_t addr){ // 3
        }

        void XCHG(){
        }

        void SPHL(){
        }

        void XTHL(){
        }

        void PUSH(){ // IDK
        }

        void POP(){ // IDK
        }

        void OUT(){ // IDK
        }

        void IN(){ // IDK
        }

        //___ Arithmetic Instructions ___

        void ADD(uint8_t data){
        }

        void ADC(uint8_t data){
        }

        void ADI(uint8_t value){
        }

        void ACI(uint8_t value){
        }

        void DAD(uint16_t data){
        }

        void SUB(uint8_t data){
        }

        void SBB(uint8_t data){
        }

        void SUI(uint8_t value){
        }

        void SBI(uint8_t value){
        }

        void INR(uint8_t* data){
        }

        void INX(uint16_t* data){
        }

        void DCR(uint8_t* data){
        }

        void DCX(uint16_t* data){
        }

        void DAA(){ // IDK
        }

        //___ Branching Instructions ___

        void JMP(uint16_t loc){
        }

        void JC(uint16_t loc){
        }

        void JNC(uint16_t loc){
        }

        void JP(uint16_t loc){
        }

        void JZ(uint16_t loc){
        }

        void JNZ(uint16_t loc){
        }

        void JPE(uint16_t loc){
        }

        void JPO(uint16_t loc){
        }

        void CALL(uint16_t loc){
        }

        void CC(uint16_t loc){
        }

        void CNC(uint16_t loc){
        }

        void CP(uint16_t loc){
        }

        void CM(uint16_t loc){
        }

        void CZ(uint16_t loc){
        }

        void CNZ(uint16_t loc){
        }

        void CPE(uint16_t loc){
        }

        void CPO(uint16_t loc){
        }

        void RET(){
        }

        void RC(){
        }

        void RNC(){
        }

        void RP(){
        }

        void RM(){
        }

        void RZ(){
        }

        void RNZ(){
        }

        void RPE(){
        }

        void RPO(){
        }

        void PCHL(){
        }

        void RST(){ // IDK
        }

        //___ Logical Instructions ___

        void CMP(uint8_t data){
        }

        void CPI(uint8_t value){
        }

        void ANA(uint8_t data){
        }

        void ANI(uint8_t value){
        }

        void XRA(uint8_t data){
        }

        void XRI(uint8_t value){
        }

        void ORA(uint8_t data){
        }

        void ORI(uint8_t value){
        }

        void RLC(){
        }

        void RRC(){
        }

        void RAL(){
        }

        void RAR(){
        }

        void CMA(){
        }

        void CMC(){
        }

        void STC(){
        }

        //___ Control Instructions ___

        void NOP(){
            //does nothing
        }

        void HLT(){
        }

        void DI(){
        }

        void EI(){
        }

        void RIM(){
        }

        void SIM(){
        }

};

#endif
