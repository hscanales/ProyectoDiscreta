#include <iostream>
#include <string>
using namespace std;

struct nodo
{
    int dato;
    string nombre;
    nodo *sig;
};

class ListaSimple
{
private:
    nodo *inicio;

public:
    ListaSimple();
    nodo *CrearNodo(int,string);
    void insertarInicio(int,string);
    bool eliminar(string);
    void mostrar();
    void llenar();
};
ListaSimple::ListaSimple()
{
    this->inicio = NULL;
}

nodo *ListaSimple::CrearNodo(int dato,string nombre)
{
    /*Aca creamos el nodo para despues poder insertarlo*/
    nodo *nuevo = new (nodo);
    nuevo->dato = dato; //
    nuevo->nombre = nombre;
    nuevo->sig = NULL;
    return nuevo;
}

void ListaSimple::insertarInicio(int dato,string nombre)
{
    //insertar el elmento al incio
    nodo *nuevo = ListaSimple::CrearNodo(dato,nombre); /// creamos el nodo
    nuevo->sig = this->inicio;                  // su sig tiene que ser el inicio de la lista
    this->inicio = nuevo;                       // cambiamos la referencia
}


bool ListaSimple::eliminar(string dato)
{
    //creamos los punetero que nos serviran para borrar
    nodo *aux = this->inicio; // para buscar el nodo
    nodo *saltarin;           // estara una posicion adelante del nodo buscado
    nodo *salto;              //estara un nodo antes
    int cont = 0;             // si esta en uno significa que es el primer elemento de la lista

    while (aux && aux->nombre != dato)
    {
        aux = aux->sig;
        cont++;
    }

    //validamos si encontro el numero
    if (aux)
    {
        int cantidad = aux->dato;
        aux->dato = cantidad-1;
        return true;
    }
    else
    {
        return false; //retornamos false si no se encontro el nodo
    }
}

void ListaSimple::mostrar()
{
    nodo *salto = this->inicio;
    while (salto)
    {   
        cout << salto->nombre << ": ";
        cout << salto->dato << " ";
        salto = salto->sig;
    }
    cout << "\n";
}

void ListaSimple::llenar(){
    cout << "Ingrese la palabra exit en el nombre de color para dejar de llenar la tombola \n";
    while(true){
         cin>>ws;
        string str,c;
        int cantidad;
        cout<<"Ingrese nombre del color: ";
        getline(cin,str);
        for (auto & c: str) c = toupper(c);
        if(str=="EXIT"){
            break;
        };

        cout<<endl<<"Ingrese cantidad de bolitas: ";
        cin>>cantidad;
       
        insertarInicio(cantidad,str);
        
        
    };
};


int main(){
    ListaSimple l;
    l.llenar();
    l.eliminar("HOLA");

    l.mostrar();

    return 0;
}