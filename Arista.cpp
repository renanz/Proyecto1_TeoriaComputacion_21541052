#include "Arista.h"

Arista::Arista(char caracter, Estado *sig)
{
    this->caracter = caracter;
    this->next = sig;
}

Arista::~Arista()
{
    //dtor
}
char Arista::getCaracter()
{
    return this->caracter;
}

Estado* Arista::getEstado()
{
    return this->next;
}

void Arista::setEstado(Estado *est)
{
    this->next = est;
}

char Arista::setCaracter(char car)
{
    this->caracter = car;
}
