#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

struct nodo{
    nodo *siguiente;
    char operador;
    double valorVariable;
};

void insertarFila(nodo *&, nodo *&, char, double);
bool quitarLista(nodo *&, nodo *&);
void eliminarNodo(nodo *&, nodo *&);
void mostratFila(nodo *&);
void confirmarSalida(int *);
void verificarMemoria(void *, int);
double calcularResultado(nodo *&);
double calcularTermino(nodo *&);

#endif // PROTOTIPOS_H_INCLUDED
