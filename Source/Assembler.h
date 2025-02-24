#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include "Memory.h"

struct LabelPos{
    char* name;
    uint16_t pos;

    LabelPos(const char* const name, uint16_t pos){
        this->pos = pos;
        this->name = new char[sizeof(name)];
        strcpy(this->name, name);
    }

    ~LabelPos(){
        if(this->name) delete[] this->name;
    }
};

class Labels{
    private:
    LabelPos** array;

    int hash(const char* const name){
        int ret = -1;
        if(!name){
            std::cerr << "ERRO: Nome da label inválido";
        }
        else{
            ret = 0;
            int reps = strlen(name);
            for(int i=0; i<reps; i++){
                ret += (i+1) * (int)name[i];
            }
            ret %= 200;
        }
        return ret;
    };

    void printHash(const char* const name){
        std::cout << hash(name) << "\n";
    }
    
    void print(){
        for(int i=0; i<256; i++){
            std::cout << i << ": ";
            if(!this->array[i]) std::cout << "empty\n";
            else std::cout << this->array[i]->name << "\n";
        }
    }

    public:

    Labels(){
        this->array = new LabelPos*[256];
    }

    ~Labels(){
        if(this->array){
            for(int i=0; i<256; i++){
                if(this->array[i]) delete this->array[i];
            }
            delete[] this->array;
        }
    }

    void insert(const char* const name, uint16_t addr){
        int hashed = hash(name);
        if(!this->array[hashed])
            this->array[hashed] = new LabelPos(name, addr);
        else{
            int i = 200;
            while(this->array[i] && i<256) i++;
            if(i == 256) std::cerr << "ERRO: Hash de Labels cheia\n";
            else {
                this->array[i] = new LabelPos(name, addr);
            }
        }
    }

    uint16_t find(const char* const name){
        int hashed = hash(name);
        uint16_t res = 0x0000;
        if(!this->array[hashed]){
            std::cerr << "ERRO: Label \"" << name << "\" nao encontrada\n";
        }
        else if(0 != strcmp(this->array[hashed]->name, name)){
            int i = 200;
            while(i<256 && this->array[i] && 0!=strcmp(this->array[i]->name, name)) i++;
            if(i==256){
                std::cerr << "ERRO: Label \"" << name << "\" nao encontrada\n";
            }
            else {
                res = this->array[i]->pos;
            }
        }
        else res = this->array[hashed]->pos;
        return res;
    }

};

    
class Assembler
{
	private:
	Memory* memory;

    /*
     * @return: Returns the position of the ':', or -1 if not found
     */
    int hasLabel(const char* const line){
        int ret = -1;
        int reps = strlen(line);
        for(int i=0; i<reps && ret==-1; ret = line[i++]==':' ? i-1 : -1);
        return ret;
    }

	public:

    Memory* assemble(const char* const filename) {
		Memory* res = nullptr;
        std::ifstream* fil = new std::ifstream(filename);
        if(!fil->is_open()){
            std::cerr << "ERRO: Arquivo nao encontrado\n";
        }
        else{
            char* line = new char[1];
            int i = 1;
            do{
                delete[] line;
                line = new char[201];
                fil->getline(line,200);
                if(0!=strcmp(line, "")) std::cout << i++ << "\n";
            } while(0!=strcmp(line, ""));
            if(line) delete[] line;
        }
        if(fil) delete fil;
		return (res);
    }

};
#endif
