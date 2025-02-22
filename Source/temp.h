#include <cstdint>
#include <cstring>


void flag(){
    std::cout << "\nFLAG\n\n";
}

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

    public:

    void printHash(const char* const name){
        std::cout << hash(name) << "\n";
    }
    
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

    void print(){
        for(int i=0; i<256; i++){
            std::cout << i << ": ";
            if(!this->array[i]) std::cout << "empty\n";
            else std::cout << this->array[i]->name << "\n";
        }
    }

};




    int hasLabel(const char* const line){
        int ret = -1;
        int reps = strlen(line);
        for(int i=0; i<reps && ret==-1; ret = line[i++]==':' ? i-1 : -1);
        return ret;
    }
