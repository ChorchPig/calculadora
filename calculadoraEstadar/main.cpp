#include <iostream>
#include "prototipos.h"

//falta agregar la posibilidad de calcular potencias y raíces
int main(){
    nodo *inicioFila=NULL;
    nodo *finalFila=NULL;
    int option=1;
    double valorVariable=0.0;
    char operador;
    while(option){
        std::cout<<"Select an option \n\t";
        std::cout<<"1. Add data\n\t2. Remove data";
        std::cout<<"\n\t3. Show data\n\t4. Calculate";
        std::cout<<"\n\t0. Exit program \n";
        std::cin>>option;
        switch(option){
            case 0: confirmarSalida(&option); break;
            case 1: {
                std::cout<<"Value of the variable: ";
                std::cin>>valorVariable;
                std::cout<<"\nOperation: ";
                std::cin>>operador;
                insertarFila(inicioFila, finalFila, operador, valorVariable);
            } break;
            case 2: {
                if(inicioFila){
                    bool elementoEliminado=quitarLista(inicioFila, finalFila);
                    (elementoEliminado)?std::cout<<"Element succesfully removed.\n":std::cout<<"The element is not in the queue.\n";
                }
                else std::cout<<"The queue is empty.\n";
            } break;
            case 3: {
                if(inicioFila)mostratFila(inicioFila);
                else std::cout<<"The queue is empty.\n";
            } break;
            case 4: std::cout<<calcularResultado(inicioFila); break;
            default : std::cout<<"No option selected\n";
        }
    }
    while(inicioFila){
        eliminarNodo(inicioFila, finalFila);
    }
    return 0;
}
