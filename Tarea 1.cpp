#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
    struct Aregistro
{   
    string nombre;
    string apellido;
    int paralelo;
    int dia;
    int mes;
    int anio;
    string rol;
    int ppm;
    float precision;
};


    struct registro
{
    int dia;
    int mes;
    int anio;
    char rol[12];
    int ppm;
    float precision;
};
    Aregistro re[1000];
    char c;
    int recorredor = 0;
    ifstream fp;
    char rol[12];
    string  nombre, apellido;
    int paralelo;
    fp.open("estudiantes.txt");
    if (!fp.is_open()){
        cerr << " el archvio no se pudo abrir " << endl;
        return 1 ;
    }
    while((c= fp.tellg()) != EOF ){ 
        fp >> rol;
        fp >> nombre;
        fp >> apellido;
        fp >> paralelo;
        re[recorredor].nombre = nombre;
        re[recorredor].apellido = apellido;
        re[recorredor].rol = rol;
        re[recorredor].paralelo = paralelo;
        cout << " nombre del estudiante = " << re[recorredor].nombre << " "  << re[recorredor].apellido << " rol del estudiante =  " << re[recorredor].rol << "  paralelo: " << re[recorredor].paralelo << endl;  
        recorredor = recorredor + 1;
        };

                                     //lee el binario 
   registro Re;
   int i, j, q, t, d, m, a, cont;
   string NomMax;
   ifstream in;
   in.open("registros.dat", ios::binary);
   if(!in.is_open()){
    cerr <<  "error no se pudo abrir el archivo registro.dat" << endl;
    exit(1);
   }
   in.read((char*)&i,sizeof(int));
   cout << "cantidad de registros = " << i << endl;
   cout << "ingrese cantidad de consultas" << endl;
   cin >> q;
   string* Nombres = new string[q];

   for( j = 0; j < q; j++)
   {
         cout << "ingrese consulta" << endl;
         cin >> t;
        cin >> d;
        cin >> m;
        cin >> a;
        int maximo = -1;
        string rolm;
        while(in.read((char*)&Re,sizeof(registro))){

        cout<<" dia = " << Re.dia << " , mes =  " << Re.mes << " anio = " << Re.anio << " rol = " << Re.rol << " ppm = " << Re.ppm << " precision =  " << Re.precision << endl;
        if (d == -1 && t == -1) 
        {
            if (Re.ppm > maximo)
            {
            maximo = Re.ppm;
            rolm = Re.rol;
            }
        
        }
        else if (d !=-1 && t == -1)
        {
            if (Re.anio == a && Re.mes == m && Re.dia == d)
            {
                if (Re.ppm > maximo)
                {
                maximo = Re.ppm;
                rolm = Re.rol;
                }
            }
            
        }
        else if (d == -1 && t == 0)
        {
            if (/* condition */) 
            {
                
                rolm = Re.rol;
            }
            
        }
        /* se podria abrir el txt aqui y buscar directamente */
        for ( cont = 0; cont < recorredor; cont++)
        {
            if (rolm == re[cont].rol)
            {
                NomMax = re[cont].nombre + " " + re[cont].apellido;
                break;
            }   
        }
        Nombres[j] = NomMax;
        }
    }
   
    in.close();


return 0;
 }