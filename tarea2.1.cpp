#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef int tElemLista;

//Implementación de nodo
struct tNodo
{
    char info;
    tNodo* sig;
    tNodo* ant;
};

//Implementación TDA lista doblemente enlazada
class tLista
{
private:
    tNodo* head;
    tNodo* tail;
    tNodo* curr;
    unsigned int listSize;
    unsigned int pos;

public:
    tLista();
    ~tLista();
    int insert(char item);
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    void moveToPos(unsigned int posicion);
    string printForward();
    void clear();

};

//Implementación de las operaciones

/*
NombreFuncion: clear
Resumen: Reinicia la lista como vacía
Sin parametros,tipo void
*/
void tLista::clear()
{
    head = tail = curr = NULL;
}

/*
NombreFuncion: tLista
Resumen: Constructor,genera la lista
Sin parametros
*/
tLista::tLista()
{
    head = tail = curr = new tNodo;
    listSize=0;
    pos=0;
}
/*
NombreFuncion: ~tLista
Resumen: Destructor, elimina la lista
Sin parametros
*/
tLista::~tLista()
{
}

/*
NombreFuncion: insert
Resumen: Inserta item en la lista
el parametro es item(elemento a insertar)
return tipo int
*/
int tLista::insert(char item){
    tNodo* aux = curr;
    tNodo* next;
    if (curr == tail)
    {
        next = NULL;
    }
    else
    {
        next=curr->sig;
    }
    curr->sig = new tNodo;
    curr = curr->sig;
    curr->info = item;
    curr->sig=next;
    curr->ant = aux;
    if (tail==aux)
    {
        tail=curr;
    }
    listSize++;
    return pos;
}

/*
NombreFuncion: moveToStart
Resumen: Mueve la posicion al inicio de la lista
Sin parametros,tipo void
*/
void tLista::moveToStart(){
    curr = head;
    pos = 0;
}

/*
NombreFuncion: moveToEnd
Resumen: Mueve la posicion al final de la lista
Sin parametros,tipo void
*/
void tLista:: moveToEnd(){
    curr = tail; 
    pos = listSize;
}

/*
NombreFuncion: prev
Resumen: Mueve la posicion a la anterior
Sin parametros,tipo void
*/
void tLista::prev(){
    if (curr->ant !=NULL)
    {
        curr=curr->ant;
    }
    
}

/*
NombreFuncion: next
Resumen: Mueve la posicion a la siguiente
Sin parametros,tipo void
*/
void tLista:: next(){
    if (curr != tail)
    {
        curr = curr->sig;
        pos++;
    }
}

/*
NombreFuncion: printForward
Resumen: Genera el string que será añadido al archivo "teclado-salida.txt"
Sin parametros
retorna el string a insertar
*/

string tLista:: printForward()
{
    tNodo* nd = head->sig;
    string n="";
    while (nd != NULL)
    {
        n += nd->info;
        nd = nd->sig;
    }
    return n;
}

/*
NombreFuncion: moveToPos
Resumen: Mueve la posición hacia una determinada
Parametro: posicion a la cual mover, tipo void
*/
void tLista::moveToPos(unsigned int posicion){
    unsigned int i;
    if (posicion < 0 || posicion > listSize )
    {
        return;
    }
    curr = head;
    pos= 0;
    for (int i = 0; i < posicion; i++)
    {
        curr = curr->sig;
        pos++;
    }
}

//main

int main(){

    ifstream file;
    string line;
    ofstream filee;

    //Contar número de lineas del archivo "teclado-entrada.txt"
    int numLineas = 0;
    ifstream in("teclado-entrada.txt");
    string x;
    while ( getline(in, x) )
        ++numLineas;
    

    
    int a=0;
    file.open("teclado-entrada.txt");             //SE ABRE EL ARCHIVO "teclado-entrada.txt"
    if(!file.is_open()){
        cout << "Error al abrir el archivo \n";
        exit(1);
    };
    filee.open("teclado-salida.txt");             //SE ABRE EL ARCHIVO "teclado-salida.txt"
    if(!filee.is_open()){
        cout << "Error al abrir el archivo \n";
        exit(1);
    };

    /*Se genera un ciclo, en el cual se obtiene cada linea del archivo "teclado-entrada.txt"
    y según las distintas condiciones y parametros, se van insertando los char a la lista,
    posteriormente, se agrega el texto resultante en el archivo "teclado-salida.txt"*/
    while (a<=numLineas)
    {
        tLista L= tLista();
        getline(file,line);
        for (int i = 0; i <line.length() ; i++)
        {        
            if (line[i]=='[')
            {
                L.moveToStart();
            }
            if (line[i]==']')
            {
                L.moveToEnd();
            }
            if (line[i] == '<')
            {
                L.prev();
            }
            if (line[i]=='>')
            {
                L.next();
            }
            
            if (line[i] != '[' && line[i] != ']' && line[i] != '>' && line[i] != '<')
            {
                L.insert(line[i]);
                
                
            }    
            
        }
    filee << L.printForward()<< endl;
    L.clear();
    
    a++;
    }

    file.close();
    filee.close();
    return 0;
};