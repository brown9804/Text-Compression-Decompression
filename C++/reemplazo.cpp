#include "reemplazo.h"

Reemplazo::Reemplazo(string filePath, string tab_path ,int entradas){
    this->filePath=filePath; //direccion de in.txt
    this->entradas=entradas; //cantidad de lineas en in.tab
    this->tab_path=tab_path; //direccion de in.tab
    };

void Reemplazo::reemplazar(){
    ifstream archivo1;
    archivo1.open(tab_path, ios::in);
    string texto1;
    string palabras[entradas] {}; //arreglo donde se guardaran las palabras a reemplazar guardadas en in.tab
    string reemplazos[entradas] {}; //arreglo donde se guardaran las palabras de reemplazo guardadas en in.tab
    int iter = 0;
    int otro =0;
    while(!archivo1.eof()){
        getline(archivo1, texto1);
        istringstream isstream(texto1);
        int k = 0;
        while(!isstream.eof()){
            string tempStr;
            isstream >> tempStr;
            if (k ==0 && iter<entradas && tempStr != "." && tempStr != ","   ){
                palabras[iter]=tempStr; //va guardando en un arreglo las palabras a reemplazar guardadas en in.tab
            }
            if (k==2 && iter<entradas && tempStr != "." && tempStr != ","  ){
                reemplazos[iter]=tempStr; //va guardando en un arreglo las palabras de reemplazo guardadas en in.tab
            }
            k=k+1;
        }
        iter=iter+1; //lleva el conteo de las palabras totales
        int otro = otro +1;
        if (iter == 10000){
            cout<< "Llevo revisando 10000 palabras mil más" <<endl;
            otro =0;
        }
        
    }

    archivo1.close();
    cout<<"palabras a reemplazar: " <<endl;
    for (int i=0; i<entradas; i++){
        cout<<palabras[i]<< " reemplazo: "<< reemplazos[i] << endl;
    }
    ifstream archivo2;
    archivo2.open(filePath, ios::in);
    string texto2;
    ofstream salida;
    salida.open("in.rep", ios::ate);
    while(!archivo2.eof()){
        getline(archivo2, texto2); //divide el texto en lineas
        istringstream isstream(texto2);
        string nuevo = {};
        while(!isstream.eof()){ //divide las lineas en palabras
            string tempStr;
            isstream >> tempStr;
            for (int j=0; j<entradas; j++){
                if (tempStr==palabras[j] && tempStr != " . " && tempStr != " , " ){
                    tempStr=reemplazos[j]; //va comparando si la palabra debe ser guardada
                }
            }
            nuevo.append(tempStr); //se agrega cada palabra para formar la linea
            nuevo.append(" ");
            }
        salida<<nuevo<<endl; //se escribe cada linea del texto con las palabras cambiadas
        }
    archivo2.close();
    salida.close();
}

void Reemplazo::descomprimir (){
    ifstream archivo1;
    archivo1.open(tab_path, ios::in);
    string texto1;
    string palabras[entradas] {}; //arreglo donde se guardaran las palabras a reemplazar guardadas en in.tab
    string reemplazos[entradas] {}; //arreglo donde se guardaran las palabras de reemplazo guardadas en in.tab
    int iter = 0;
    int otro =0;
    while(!archivo1.eof()){
        getline(archivo1, texto1);
        istringstream isstream(texto1);
        int k = 0;
        while(!isstream.eof()){
            string tempStr;
            isstream >> tempStr;
            if (k ==2 && iter<entradas && tempStr != "." && tempStr != ","   ){
                palabras[iter]=tempStr; //va guardando en un arreglo las palabras a reemplazar guardadas en in.tab
            }
            if (k==0 && iter<entradas && tempStr != "." && tempStr != ","  ){
                reemplazos[iter]=tempStr; //va guardando en un arreglo las palabras de reemplazo guardadas en in.tab
            }
            k=k+1;
        }
        iter=iter+1; //lleva el conteo de las palabras totales
        int otro = otro +1;
        if (iter == 10000){
            cout<< "Llevo revisando 10000 palabras mil más" <<endl;
            otro =0;
        }
        
    }

    archivo1.close();
    cout<<"palabras a reemplazar: " <<endl;
    for (int i=0; i<entradas; i++){
        cout<<palabras[i]<< " reemplazo: "<< reemplazos[i] << endl;
    }
    ifstream archivo2;
    archivo2.open(filePath, ios::in);
    string texto2;
    ofstream salida;
    salida.open("in-des.rep", ios::ate);
    while(!archivo2.eof()){
        getline(archivo2, texto2); //divide el texto en lineas
        istringstream isstream(texto2);
        string nuevo = {};
        while(!isstream.eof()){ //divide las lineas en palabras
            string tempStr;
            isstream >> tempStr;
            for (int j=0; j<entradas; j++){
                if (tempStr==palabras[j] && tempStr != " . " && tempStr != " , " ){
                    tempStr=reemplazos[j]; //va comparando si la palabra debe ser guardada
                }
            }
            nuevo.append(tempStr); //se agrega cada palabra para formar la linea
            nuevo.append(" ");
            }
        salida<<nuevo<<endl; //se escribe cada linea del texto con las palabras cambiadas
        }
    archivo2.close();
    salida.close();
}

Reemplazo::Reemplazo(){};