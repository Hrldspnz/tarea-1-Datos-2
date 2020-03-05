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

void insertar_nodo(){
    //instancia el nodo y crea un nuevo puntero
    Tnodo t, nuevo=new struct nodo;
    cout<<"Ingrese un numero para el nodo: "<<endl;
    //Se ingresa el numero del nodo
    cin>>nuevo->numero;
    nuevo->next=NULL;
    nuevo->ady=NULL;
    //Si no hay puntero lo crea
    if(puntero==NULL){
        puntero=nuevo;
        cout<<"Nodo creado"<<endl;
    }else{ //si no recorre el puntero para preguntar la variable vacia
        t = puntero;
        while(t->next!=NULL){
            t = t->next;
        }
        t->next = nuevo;
        cout<<"Nodo creado"<<endl;

    }

}

//Metodo para agregar la lista
void agregar_arista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo){
    //Hacemos otro puntero apartir del puntero de la arista
    Tarista q;
    if(aux->ady==NULL){ // si la esta vacia se crea la arista
        aux->ady=nuevo;
        nuevo->destino=aux2;
    }else{ //Si no lo recorre hasta que pueda crearla
        q=aux->ady;
        while(q->next!=NULL){
            q=q->next;
        }
        nuevo->destino = aux2;
        q->next=nuevo;
        cout<<"Arista creada"<<endl;
    }
}

// metodo para insertar la arista












