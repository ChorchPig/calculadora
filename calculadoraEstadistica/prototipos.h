#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

struct nodo{
    nodo *siguiente;
    int frecuencia;
    float valorVariable;
};

void insertarNuevoNodoLista(nodo *&, nodo *&, int, float);
bool quitarLista(nodo *&, nodo *&);
void eliminarNodo(nodo *&, nodo *&);
void mostratLista(nodo *&);
void confirmarSalida(int *);
void verificarMemoria(void *, int);
float calcularPromedio(nodo *&);
float calcularMediana(nodo *&);
float obtenerModa(nodo *&);
float calcularVariabilidad(nodo *&);

#endif // PROTOTIPOS_H_INCLUDED
