#include "Evaluador.h"
#include <fstream>
#include <math.h>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
    ofstream out(nombre_archivo.c_str()); //se crea un tipo ofstream en el cual se llama al nombre del archivo
    out<<num;//escribimos la variable en el archivo
    out.close();//cerramos la escritura
}
int leerNumeroTexto(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//creamos un tipo ifstream en el cual llamamos al archivo por medio d euna variable
    int leido;//creamos la variable para guardar lo que leamos
    in>>leido;//leemos l oque hay en la variable
    return leido;//la devolvemos

}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str());//se crea un tipo ofstream en el cual se llama al nombre del archivo
    out<<str;//escribimos la string del archivo
    out.close();//cerramos la escritura
}
string leerStringTexto(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//se crea un tipo ifstream en el cual se llama al nombre del archivo
    string leido;//se crea la variable para guardar lo que leamos
    in>>leido;//damos el valor a la variable
    return leido;//devolvemos la string
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
    ofstream out(nombre_archivo.c_str());//se crea un tipo ofstream en el cual se llama al nombre del archivo
    out.write((char*)&num,4);//hay que convertirlo a char para que lo lea, y utilizamos write para escribir en el archivo una variable
    out.close();//cerramos la escritura con close
}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//se crea un tipo iftream en el cual se llama a la variable que contiene el nombtr de el archivo
    int leido;//creamos una variable en la que guardamos lo que hemos leido
    in.read((char*)&leido,4);//leemos y lo almacenamos
    return leido;//devolvemos la variable que contiene lo leido
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str());//se crea un tipo ofstream en el cual se llama al nombre del archivo
    out.write(str.c_str(),4);//escribimos la variable en el archivo con el write
    out.close();//cerramos la escritura
}
string leerStringBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//se crea un tipo iftream en el cual se llama a la variable que contiene el nombre de el archivo
    char cadena [4];//creamos una variable en la que guardaremos lo que hemos leido en este caso una cadena de char
    string chain;//cremos una string que es la que devolveremos
    in.read(cadena,4);//llenamos nuestro archivo
    chain = cadena;//el valor de la cadena char se lo asignamos al string
    return cadena;//se devuelve la string
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    ifstream in(nombre_archivo.c_str());//se crea un tipo ifstream con nombre in para llamar la variable
    int cant=0;//La primera variable almacenara la cantidad, la segunda sera un string vacio que usara despues
    string word;
    for(int i=0;i<cant;i++)
    {
        in>>word;// apunta a lo que tenga word
        if(word == str)//si word es igual a lo que tenga cadena entonces devolvera true
            {
                return true;
            }
        return false;//de lo contrario sera false
    }
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
    ifstream in(nombre.c_str());//se crea un tipo ffstream en el cual se llama al nombre del archivo
    in.seekg(0,ios::end);//nos movemos a la posicion final
    int cant=in.tellg();//guardamos en tamaño en una varibale
    in.seekg(0,ios::beg);//devoolvemos el cursor al inicio
    int mayor=-99999;//creamos la varibale limitante

     for(int i=in.tellg();i<cant;i++)//con el for nos moveremos por l archivo e iremos leendo cada uno de sus datos
    {
        int num;//creamos la variable en la que iremos guardando lo que lemaos
        in.read((char*)&num,4);//leemos y lo guardamos en la varable creada
        if(mayor<num)//lo comparamos para ver si el mayor
        {
            mayor=num;//si cumple se asigna el valor de num a la variable mayor
        }
    }
    return mayor;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
