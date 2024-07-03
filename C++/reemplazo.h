#ifndef REEMPLAZO_H
#define REEMPLAZO_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>


using namespace std;

class Reemplazo {
    public:
        string filePath;
        string tab_path;
        int entradas;

        Reemplazo(string filePath, string tab_path ,int entradas);
        void reemplazar();
        void descomprimir ();

        Reemplazo();

        };
#endif