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
    int peso;
};

//se instancia la arista con un puntero
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
void agregar_arista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo, int aux_peso){
    //Hacemos otro puntero apartir del puntero de la arista
    Tarista q;
    if(aux->ady==NULL){ // si la esta vacia se crea la arista
        aux->ady=nuevo;
        nuevo->destino=aux2;
        nuevo->peso=aux_peso;
    }else{ //Si no lo recorre hasta que pueda crearla
        q=aux->ady;
        while(q->next!=NULL){
            q=q->next;
        }
        nuevo->destino = aux2;
        nuevo->peso=aux_peso;
        q->next=nuevo;
        cout<<"Arista creada"<<endl;
    }
}

// metodo para insertar la arista
void insertar_arista(){
    //varibles para el nodo inicial y final
    int ini,fin,peso = 0;

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
    cout<<"Ingrese el peso:";cin>>peso;

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
            agregar_arista(aux,aux2, nuevo,peso);
            return;
        }
        //Si no pasa al siguiente
        aux=aux->next;
    }

}

//Metodo que muestra el grafo
void mostrar_grafo(){
    Tnodo ptr;
    Tarista ar;

    ptr=puntero;
    cout<<"Nodo : Adyacencia"<<endl;

    while (ptr!=NULL) {

        cout<<"   "<<ptr->numero<<"|"; //Muestra el dato del puntero

        if(ptr->ady!=NULL){
            ar=ptr->ady;
            while (ar!=NULL) { //Muestra todas las aristas de ese puntero
                cout<<"   "<<ar->destino->numero<<"("<<ar->peso<<")";
                ar=ar->next;
            }

        }
        ptr=ptr->next;
        cout<<endl;
    }
}


//Metodo que muestra las aristas de un nodo especifico
void mostrar_aristas(){
    Tnodo aux;
    Tarista ar;
    int var;

    cout<<"Mostrar arista del nodo"<<endl;
    cout<<"Ingrese el nodo:"<<endl;;cin>>var;

    aux= puntero;
    while (aux!=NULL) {
        if(aux->numero==var){ // revisamos si ya hay un puntero definido
            if(aux->ady==NULL){
                cout<<"El nodo no tiene aristas"<<endl;
                return;
            }else{ //imprime las aristas del nodo
                cout<<"Nodo : Adyacencia"<<endl;
                cout<<"   "<<aux->numero<<"|";
                ar=aux->ady;

                //pasa al siguiente para mostrar sus aristas
                while (ar!=NULL) {
                    cout<<ar->destino->numero<<" ";
                    ar=ar->next;
                }
                cout<<endl;
                return;
            }

        }else{
            aux=aux->next;
        }


    }
}


int crear_menu(){
    cout<<"              Grafos"<<endl;
    cout<<"Digite el numero de la accion que desea"<<endl;
    cout<<"1) Insertar un nodo"<<endl;
    cout<<"2) Insertar una arista"<<endl;
    cout<<"3) Mostrar el grafo"<<endl;
    cout<<"4) Mostrar las aristas de un nodo"<<endl;
    cout<<"5) Salir"<<endl;

}

int main(){
    puntero = NULL; //inicializamos el puntero

    //Ciclo para ejecutar el menu

    volver='s';
    while(volver=='s'){
        //Llamamos el menu
        crear_menu();
        cin>>opc;

        switch (opc) {
        case '1':
            insertar_nodo();break;
        case '2':
            insertar_arista();break;
        case '3':
            mostrar_grafo();break;
        case '4':
            mostrar_aristas();break;
        case '5':
            cout<<"Salir"<<endl;
            return 0;break;
        default:
            cout<<"Opcion no valida"<<endl;
        }
        cout<<"Desea volver al menu principal (s/n)"<<endl;
        cin>>volver;
    }
    return 0;
}








