#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


class Archivo
{
    public:
        Archivo(char * nombre);
        virtual ~Archivo();

        void abrir();
        const char * getLine();


    protected:

    private:
        char * nombre;
        int cantWords;
        ifstream file;
};

#endif // ARCHIVO_H
