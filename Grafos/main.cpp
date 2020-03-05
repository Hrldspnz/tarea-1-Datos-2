#include<iostream>
using namespace std;


//variables globales
char opc;
char volver;
char valor;

struct nodo{ //declaramos nodo que contiene un numero y dos punteros
    int numero; //numero del nodo
    struct nodo *next;
    struct arista *ady; //puntero para la primera arista dl nodo
};

//se instancia el nodo y se crea una variable puntero
typedef struct nodo *Tnodo;
Tnodo puntero; //puntero cabeza

struct arista{ //declaramos la arista su nodo destino y la arista siguiente
    struct nodo *destino;
    struct arista *next;
};

//se instancia la arista
typedef struct arista *Tarista;
