#ifndef ESTADO_H
#define ESTADO_H

#include <map>
#include <vector>
#include "Arista.h"


using namespace std;

class Arista;

class Estado
{
    public:
        Estado(int nombre,bool estFinal);
        virtual ~Estado();

        void addAristas(char i, Estado *est);

        int getNombre();
        bool isEstadoFinal();

        void setEstadoFinal(bool estFinal);

        vector<Arista*> getAristas();


    protected:

    private:
        int nombreEstado;
        bool estadoFinal;
        vector<Arista*> aristas;
};

#endif // ESTADO_H
