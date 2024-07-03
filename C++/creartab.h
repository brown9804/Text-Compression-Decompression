#ifndef CREARTAB_H
#define CREARTAB_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>


using namespace std;

class CrearTab {
    public:
        string filePath;
        int umbral;

        CrearTab();
        CrearTab(string filePath, int umbral);
        int count_words(int longitud, string entrada);
        int frecuencia_palabra(string* palabras, int* frecuencia, int num, string word);
        int creacion_tab();
    };
#endif