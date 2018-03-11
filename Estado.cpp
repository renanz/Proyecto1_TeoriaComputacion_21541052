#include "Estado.h"

Estado::Estado(int n, bool estFinal)
{
    this->nombreEstado = n;
    this->estadoFinal = estFinal;
}

Estado::~Estado()
{
    //dtor
}

void Estado::addAristas(char i, Estado *est)
{
    this->aristas.push_back(new Arista(i,est));
}

vector<Arista*> Estado::getAristas()
{
    return this->aristas;
}

int Estado::getNombre()
{
    return this->nombreEstado;
}
bool Estado::isEstadoFinal()
{
    return this->estadoFinal;
}

void Estado::setEstadoFinal(bool estFinal)
{
    this->estadoFinal = estFinal;
}
