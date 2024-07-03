/*!
    *\author Ruben Venegas , Carolina Urrutia, Belinda Brown
    *\version 1.0
    *\date 11/05/2019
    *\mainpage Compresion de texto
    *\section intro_sec Introduccion
    * Este codigo reemplaza palabras segun la cantidad de recurrencias que presente la palabra
    */


#include <iostream>
#include "reemplazo.h"
#include "creartab.h"

using namespace std;

int main(int argc , char* argv[]) {

    CrearTab tab1(argv[2], atoi(argv[1]));
    int lineas = tab1.creacion_tab();
    Reemplazo remp1(argv[2],"in.tab",  lineas);
    remp1.reemplazar();
    cout<<"Se reemplazaron: " <<lineas<<" palabras"<<endl;

    cout<<"Desea descomprimir el archivo ? s/n" <<endl;
    string entrada;
    cin >> entrada;
    if (entrada == "s"){
       remp1.descomprimir();
       cout << "El archivo descomprimido se llama in-des.rep" <<endl;
    }


   return 0;
}


