#include "creartab.h"

using namespace std;



CrearTab::CrearTab(){};
CrearTab::CrearTab(string filePath, int umbral){

    cout << "\t\t\t: "<< filePath << " - " << umbral << endl;

    this->filePath=filePath;
    this->umbral=umbral;};
int CrearTab::count_words(int longitud, string entrada){ //cuenta las palabras en un string
    int i=0;
    int cont=0;
    while(i<longitud){
        while (i<longitud && entrada[i]==' '){
            i=i+1;
        }
        if(i<longitud){
            cont=cont+1;
        }
        while(i<longitud && entrada[i]!=' '){
            i=i+1;
        }
    }
    return cont;
    }
int CrearTab::frecuencia_palabra(string* palabras, int* frecuencia, int num, string word){
    bool condicion=false;
    if (num==0){ //Llena el primer elemento del arreglo con la primer palabra
        palabras[num]=word;
        frecuencia[num]=frecuencia[num]+1;
        num=num+1;
        
    }
    for (int i=0; i<=num; i++ ){
        if (palabras[i]==word && num>0){
            frecuencia[i]=frecuencia[i]+1;  //Si la palabra ya estaba guardada, aumenta su frecuencia
            condicion=true;
            }
        }
    if (condicion ==false && num>0) {
        palabras[num]=word;  //Si la palabra no es repetida la guarda
        frecuencia[num]=frecuencia[num]+1;
        num=num+1;
        
    }
    num=num;
    
    return num;
}
int CrearTab::creacion_tab(){
    int count =0;
    ifstream archivo1;
    archivo1.open(filePath, ios::in);
    string texto1;
    while(!archivo1.eof()){
        getline(archivo1, texto1); //Divide el texto en lineas
        int k = count_words(texto1.length(), texto1); //por cada linea cuenta las palabras
        count=count+k; //contador de palabras totales del texto
        }
    cout<<"Palabras contadas: "<<count<<endl;
    string palabras[count] {}; //crea un arreglo de strings con la cantidad de palabras tot del texto 
    int frecuencias[count] {}; //crea un arreglo de ints con la cantidad de palabras tot del texto  que se
                               //asociara a cada string del arreglo anterior (contara la frecuencia de cada palabra)
    archivo1.close();
    ifstream archivo2;
    archivo2.open(filePath, ios::in);
    string texto2;
    int m =0;
    int num=0;
    int otra = 0;
    while(!archivo2.eof()){
        getline(archivo2, texto2);
        istringstream isstream(texto2);
        bool condicion = false;
        while(!isstream.eof()){ //divide cada linea en palabras
            string tempStr; 
            isstream >> tempStr;
            otra = otra +1;
            if (otra >10000){
                cout<<"Creando in.tab, Voy revisando 10000 mas" <<endl;
                otra = 0;
            }
            if (num<count && tempStr != "." && tempStr != ","  ){ //se guarda cada palabra en el arreglo creado anteriormente
                int m = frecuencia_palabra(palabras, frecuencias, num, tempStr); 
                num=m;  
            }
        }
    }
    archivo2.close();
    int cant_entradas = 0 ;
    ofstream salida;
    salida.open("in.tab", ios::ate); //se usa ios::ate para escribir desde la ultima parte del texto
    for (int j=0; j<count; j++){
        if(frecuencias[j]>=umbral && palabras[j] !="" ){ //solo escribe las palabras que superen el rango de frecuencias
            cout << palabras[j]<< " freq:" << frecuencias[j]<<" &"<<j<<endl;
            salida<<palabras[j]<< " freq:" << frecuencias[j] <<" &"<<j<<endl;
            cant_entradas = cant_entradas +1; 
        }
    }
    
    salida.close();
    return cant_entradas; //cantidad de lineas escritas en in.tab
    }
