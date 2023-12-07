#include <iostream>
#include <math.h>
#include "prototipos.h"


int asignarValor(std::string texto){
    int num=0;
    std::cout<<texto;
    std::cin>>num;
    std::cout<<"\n";
    return num;
}

void confirmarSalida(int *option){
    std::cout<<"You are about to exit the program, to confirm this action press 0.\n";
    std::cin>>*option;
}
