#include <iostream>
#include "prototipos.h"

int main(){
    nodo *inicioLista=NULL;
    nodo *finalLista=NULL;
    int option=1, frecuencia=0;
    float valorVariable=0.0; //Si se trabaja con variables continuas ingresar el punto medio del intervalo
    while(option){
        std::cout<<"Select an option \n\t";
        std::cout<<"1. Add data\n\t2. Remove data";
        std::cout<<"\n\t3. Show data\n\t4. Calculate average";
        std::cout<<"\n\t5. Calculate median\n\t6. Calculate mode";
        std::cout<<"\n\t7. Calculate variability\n\t0. Exit program \n";
        std::cin>>option;
        switch(option){
            case 0: confirmarSalida(&option); break;
            case 1: {
                std::cout<<"Value of the variable: ";
                std::cin>>valorVariable;
                std::cout<<"\nFrequency of the variable: ";
                std::cin>>frecuencia;
                insertarNuevoNodoLista(inicioLista, finalLista, frecuencia, valorVariable);
                std::cout<<valorVariable<<" succesfuly stored.\n";
            } break;
            case 2: {
                if(inicioLista){
                    bool elementoEliminado=quitarLista(inicioLista, finalLista);
                    (elementoEliminado)?std::cout<<"Element succesfully removed.\n":std::cout<<"The element is not in the queue.\n";
                }
                else std::cout<<"The queue is empty.\n";
            } break;
            case 3: {
                if(inicioLista)mostratLista(inicioLista);
                else std::cout<<"The queue is empty.\n";
            } break;
            case 4:(inicioLista)?std::cout<<"The average of the data is: "<<calcularPromedio(inicioLista)<<"\n" : std::cout<<"The queue is empty.\n";break;
            case 5:(inicioLista)?std::cout<<"The median of the data is: "<<calcularMediana(inicioLista)<<"\n" : std::cout<<"The queue is empty.\n";break;
            case 6:(inicioLista)?std::cout<<"The mode of the data is: "<<obtenerModa(inicioLista)<<"\n" : std::cout<<"The queue is empty.\n";break;
            case 7:(inicioLista)?std::cout<<"The average of the data is: "<<calcularVariabilidad(inicioLista)<<"\n" : std::cout<<"The queue is empty.\n";break;
            default : std::cout<<"No option selected\n";
        }
    }
    while(inicioLista){
        eliminarNodo(inicioLista, finalLista);
    }
    return 0;
}
