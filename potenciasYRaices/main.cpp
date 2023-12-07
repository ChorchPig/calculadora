#include <iostream>
#include <math.h>
#include "prototipos.h"

int main(){ //actualmente el calculo de raíces retorna un valor entero exclusivamente
    int base=0, potencia=0, option=1;
    double resultado=0;
    while(option){
        std::cout<<"Select an option \n\t";
        std::cout<<"1. Calculate power\n\t2. Calculate root";
        std::cout<<"\n\t0. Exit program \n";
        std::cin>>option;
        switch(option){
            case 0: confirmarSalida(&option); break;
            case 1: {
                base=asignarValor("Base: ");
                potencia=asignarValor("Power: ");
                std::cout<<base<<"^"<<potencia<<"="<<pow(base, potencia)<<"\n";
            }break;
            case 2: {
                base=asignarValor("Base: ");
                potencia=asignarValor("Root: ");
                resultado=pow(base, 1/potencia);
                std::cout<<base<<"^1/"<<potencia<<"="<<resultado<<"\n";
            }break;
            default : std::cout<<"No option selected\n";
        }
    }
    return 0;
}
