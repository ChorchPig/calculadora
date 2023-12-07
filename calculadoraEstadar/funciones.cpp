#include <iostream>
#include <cstdlib>
#include<math.h>
#include "prototipos.h"

void insertarFila(nodo *&inicioFila, nodo *&finalFila, char op, double valor){
    nodo *nuevoNodo=new nodo();
    verificarMemoria(nuevoNodo, 1);
    nuevoNodo->valorVariable=valor;
    nuevoNodo->operador=op;
    nuevoNodo->siguiente=NULL;
    (inicioFila==NULL)?inicioFila=nuevoNodo:finalFila->siguiente=nuevoNodo;
    finalFila=nuevoNodo;
}

bool quitarLista(nodo *&inicioFila, nodo *&finalFila){
    double num=0;
    nodo *aux=inicioFila;
    std::cout<<"Element to remove: ";
    std::cin>>num;
    if(inicioFila->valorVariable==num){
        eliminarNodo(inicioFila, finalFila);
        return true;
    }
    if(inicioFila==finalFila)return false;
    while(aux->siguiente!=finalFila){
        if(aux->siguiente->valorVariable==num){
            eliminarNodo(aux->siguiente, finalFila);
            return true;
        }
        else aux=aux->siguiente;
    }
    if(aux->siguiente->valorVariable==num){
        eliminarNodo(aux->siguiente, finalFila);
        finalFila=aux;
        return true;
    }
    return false;
}

void eliminarNodo(nodo *&inicioFila, nodo *&finalFila){
    nodo *aux=inicioFila;
    if(inicioFila==finalFila){
        inicioFila=NULL;
        finalFila=NULL;
    }
    else{
        inicioFila=inicioFila->siguiente;
    }
    delete aux;
}

void mostratFila(nodo *&inicioFila){
    nodo *aux=inicioFila;
    while(aux){
        std::cout<<aux->valorVariable<<aux->operador;
        aux=aux->siguiente;
    }
    std::cout<<"\n";
}

void confirmarSalida(int *option){
    std::cout<<"You are about to exit the program, to confirm this action press 0.\n";
    std::cin>>*option;
}

void verificarMemoria(void *ptr, int llamado){
    if(!ptr){
        std::cout<<"Error occurd in the "<<llamado<<" call.\n";
        exit(EXIT_FAILURE);
    }
}

double calcularResultado(nodo *&inicioFila){
    nodo *aux=inicioFila;
    double resultado=aux->valorVariable, termino=0.0;
    while(aux){
        switch(aux->operador){//actualmente  no calcula potencias ni raíces
            case '+' : {
                termino=calcularTermino(aux->siguiente);
                resultado+=termino;
            } break;
            case '-' : {
                termino=calcularTermino(aux->siguiente);
                resultado-=termino;
            } break;
            case '*' : resultado *=aux->siguiente->valorVariable; break;
            case '/' : resultado/=aux->siguiente->valorVariable; break;
        }
        aux=aux->siguiente;
    }
    return resultado;
}

double calcularTermino(nodo *&inicioFila){
    nodo *aux=inicioFila;
    double resultado=aux->valorVariable;
    while(aux->operador=='*'||aux->operador=='/'){
        (aux->operador=='*')?resultado *=aux->siguiente->valorVariable : resultado/=aux->siguiente->valorVariable;
        aux=aux->siguiente;
    }
    inicioFila=aux;
    return resultado;

}
