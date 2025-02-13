#include <iostream>
#include "cls.h"

#define logo " █████   ██████   █████  ███████  █████  ███████ ███    ███\n██   ██ ██  ████ ██   ██ ██      ██   ██ ██      ████  ████ \n █████  ██ ██ ██  █████  ███████ ███████ ███████ ██ ████ ██ \n██   ██ ████  ██ ██   ██      ██ ██   ██      ██ ██  ██  ██ \n █████   ██████   █████  ███████ ██   ██ ███████ ██      ██ \n"

int main(int argc, char** argv){
    std::cout << "\n\n" << logo;
	std::cout << "\n\nEscolha a opcao de uso:\n\n" <<
				"[1] - Abrir arquivo assembly (.asm/.txt)\n" << 
				"[2] - Abrir arquivo assembly (step-by-step)\n" <<
				"[3] - Carregar arquivo de memoria (.mem)\n" <<
				"[4] - Carregar arquivo de memoria (step-by-step)" << std::endl;
	int option = 0;
	do{
        std::cin >> option;
		switch(option){
            case 1: std::cout << "opt1" << std::endl; break;
            case 2: std::cout << "opt2" << std::endl; break;
            case 3: std::cout << "opt3" << std::endl; break;
            case 4: std::cout << "opt4" << std::endl; break;
            default: std::cout << "error" << std::endl; break;
            case 0: break;
        }
    } while (option != 0);

    return 0;
}
