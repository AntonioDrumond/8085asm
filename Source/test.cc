#include <iostream>
#include "temp.h"
#include "Bit.h"

int main(){
    Labels* l = new Labels();
    l->printHash("a");
    l->printHash("ad");
    l->printHash("cc");
    l->printHash("ANTONIO");
    std::cout << "\n\n";
    l->insert("a", 0x4501);
    l->insert("ad", 0x2301);
    l->insert("cc", 0xFF01);
    l->insert("ANTONIO", 0xCA01);

    //l->print();
    char* buffer;

    buffer = toHexa(l->find("a"));
    std::cout << buffer << "\n";
    delete[] buffer;

    buffer = toHexa(l->find("cc"));
    std::cout << buffer << "\n";
    delete[] buffer;

    buffer = toHexa(l->find("ANTONIO"));
    std::cout << buffer << "\n";
    delete[] buffer;

    buffer = toHexa(l->find("ad"));
    std::cout << buffer << "\n";
    delete[] buffer;

    buffer = toHexa(l->find("AMTHE"));
    std::cout << buffer << "\n";
    delete[] buffer;


    delete l;

    return 0;
}
    
