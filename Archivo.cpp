#include "Archivo.h"

Archivo::Archivo(char * nombre)
{
    this->nombre = nombre;
}

Archivo::~Archivo()
{
    //dtor
}

void Archivo::abrir()
{
    file.open(nombre);
}

const char * Archivo::getLine()
{
    string o = "##";
    if(!file.is_open())
       file.open(nombre);
    if(!this->file.eof())
        getline(file, o, '\n');
    cout<< o.c_str();
    return o.c_str();
}

