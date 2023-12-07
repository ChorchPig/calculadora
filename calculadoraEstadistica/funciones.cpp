#include <iostream>
#include <cstdlib>
#include<math.h>
#include "prototipos.h"

void insertarNuevoNodoLista(nodo *&inicioLista, nodo *&finalLista, int frec, float valor){
    nodo *nuevoNodo=new nodo();
    verificarMemoria(nuevoNodo, 1);
    nuevoNodo->valorVariable=valor;
    nuevoNodo->frecuencia=frec;
    nuevoNodo->siguiente=NULL;
    (inicioLista==NULL)?inicioLista=nuevoNodo:finalLista->siguiente=nuevoNodo;
    finalLista=nuevoNodo;
}

bool quitarLista(nodo *&inicioLista, nodo *&finalLista){
    float num=0;
    nodo *aux=inicioLista;
    std::cout<<"Element to remove: ";
    std::cin>>num;
    if(inicioLista->valorVariable==num){
        eliminarNodo(inicioLista, finalLista);
        return true;
    }
    if(inicioLista==finalLista)return false;
    while(aux->siguiente!=finalLista){
        if(aux->siguiente->valorVariable==num){
            eliminarNodo(aux->siguiente, finalLista);
            return true;
        }
        else aux=aux->siguiente;
    }
    if(aux->siguiente->valorVariable==num){
        eliminarNodo(aux->siguiente, finalLista);
        finalLista=aux;
        return true;
    }
    return false;
}

void eliminarNodo(nodo *&inicioLista, nodo *&finalLista){
    nodo *aux=inicioLista;
    if(inicioLista==finalLista){
        inicioLista=NULL;
        finalLista=NULL;
    }
    else{
        inicioLista=inicioLista->siguiente;
    }
    delete aux;
}

void mostratLista(nodo *&inicioLista){
    nodo *aux=inicioLista;
    while(aux){
        std::cout<<"X: "<<aux->valorVariable<<" fa: "<<aux->frecuencia<<"\n";
        aux=aux->siguiente;
    }
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

float calcularPromedio(nodo *&inicioLista){
    float promedio=0.0;
    int cantidadDatos=0;
    nodo *aux=inicioLista;
    while(aux){
        promedio=promedio+aux->valorVariable*aux->frecuencia;
        cantidadDatos+=aux->frecuencia;
        aux=aux->siguiente;
    }
    promedio/=cantidadDatos;
    return promedio;
}

float obtenerModa(nodo *&inicioLista){
    nodo *aux=inicioLista;
    float moda=-999.999;
    int frecuenciaModa=-999;
    while(aux){
        if(aux->frecuencia>frecuenciaModa){
            moda=aux->valorVariable;
            frecuenciaModa=aux->frecuencia;
        }
        aux=aux->siguiente;
    }
    return moda;
}

float calcularMediana(nodo *&inicioLista){
    float mediana=0.0;
    int frecuenciaAcumulada=0;
    nodo *aux=inicioLista;
    while(aux){
        frecuenciaAcumulada+=aux->frecuencia;
        aux=aux->siguiente;
    }
    aux=inicioLista;
    mediana=(frecuenciaAcumulada+1)/2;//Posición de la mediana
    return mediana;
}

float calcularVariabilidad(nodo *&inicioLista){
    nodo *aux=inicioLista;
    float promedio=calcularPromedio(inicioLista), variabilidad=0.0, varianza=0.0;
    int frecuenciaAcumulada=0;
    while(aux){
        frecuenciaAcumulada+=aux->frecuencia;
        aux=aux->siguiente;
    }
    aux=inicioLista;
    while(aux){
        varianza+=(pow(aux->valorVariable-promedio, 2)*aux->frecuencia)/(frecuenciaAcumulada-1);
        aux=aux->siguiente;
    }
    variabilidad=sqrt(varianza)/promedio;
    return variabilidad;
}
