#ifndef ARISTA_H
#define ARISTA_H

#include "Estado.h"

class Estado;

class Arista
{
    public:
        Arista(char caracter, Estado *sig);
        virtual ~Arista();

        char getCaracter();
        Estado *getEstado();

        void setEstado(Estado *est);
        char setCaracter(char car);
    protected:

    private:
        char caracter;
        Estado *next;
};

#endif // ARISTA_H
