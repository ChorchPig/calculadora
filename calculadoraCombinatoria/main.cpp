#include <iostream>

double calcularCombinaciones(int, int);
double calcularVariaciones(int, int);
double factorial(int);
void confirmarSalida(int *);

int main(){
    int n=0 ,k=0, option=1; //esta versión no permite cambiar los valores de n y k en tiempo de ejecución
    double resultado=0;
    std::cout<<"Value of n: ";
    std::cin>>n;
    std::cout<<"\nValue of k: ";
    std::cin>>k;
     while(option){
        std::cout<<"Select an option \n\t";
        std::cout<<"1. Calculate combinations\n\t2. Calculate variations";
        std::cout<<"\n\t3. Calculate permutations\n\t0. Exit program \n";
        std::cin>>option;
        switch(option){
            case 0: confirmarSalida(&option); break;
            case 1: {
                resultado=calcularCombinaciones(n, k);
                std::cout<<"Total of combinations: "<<resultado<<"\n";
            } break;
            case 2: {
                resultado=calcularVariaciones(n, k);
                std::cout<<"Total of variations: "<<resultado<<"\n";
            } break;
            case 3: std::cout<<"Total of permutations: "<<factorial(n)<<"\n"; break;
            default : std::cout<<"No option selected\n";
        }
    }
    return 0;
}

double factorial(int n){
    double factorial=1;
    if(n==0)return 1;
    for(int i=1; i<=n; i++){
        factorial*=i;
    }
    return factorial;
}

double calcularCombinaciones(int n, int k){
    double variaciones=calcularVariaciones(n, k);
    double permutaciones=factorial(k);
    return variaciones/permutaciones;
}

double calcularVariaciones(int n, int k){
    double variaciones=0, aux=0;
    variaciones=factorial(n);
    aux=factorial(n-k);
    variaciones/=aux;
    return variaciones;
}

void confirmarSalida(int *option){
    std::cout<<"You are about to exit the program, to confirm this action press 0.\n";
    std::cin>>*option;
}
