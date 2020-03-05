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

//Metodo para agregar la arista
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
void insertar_arista(){
    //varibles para el nodo inicial y final
    int ini,fin;

    Tarista nuevo=new struct arista;
    Tnodo aux,aux2;

    if(puntero==NULL){ //Verificamos que el grafo no este vacio
        cout<<"ERROR: No hay un grafo"<<endl;
        return;
    }
    nuevo->next=NULL;

    //Se solicitan el nodo inicial y el final
    cout<<"Ingrese el nodo inicial:";cin>>ini;
    cout<<"Ingrese el nodo final:";cin>>fin;

    aux=puntero;
    aux2=puntero;

    //Vemos si el aux2 tiene algo
    while(aux2!=NULL){
        if(aux2->numero==fin){ //vemos si tiene el puntero final
            break;
        }

        //Si no le llevamos el valor de next
        aux2=aux2->next;
    }

    //Ingresamos la arista al primer puntero
    while (aux!=NULL) {
        if(aux->numero==ini){ //si aux es igual a la arista del puntero 1 agrega la arista
            agregar_arista(aux,aux2, nuevo);
            return;
        }
        //Si no pasa al siguiente
        aux=aux->next;
    }

}











