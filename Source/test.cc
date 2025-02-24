#include "Assembler.h"

int main (int argc, char *argv[]) {
    Assembler* a = new Assembler();
    a->assemble("dados.txt");
    delete a;
    return 0;
}
