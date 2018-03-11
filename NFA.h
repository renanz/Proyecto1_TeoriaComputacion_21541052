#ifndef NFA_H
#define NFA_H

#include "Estado.h"
#include "Arista.h"
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

class NFA
{
    public:
        NFA(vector<char> alf, int cantEst, vector<int> estFinales);
        virtual ~NFA();

        void setTransiciones();
        void resolver(char * str);

        int check(Estado * estado, vector<Arista *> aristas, char* cadena, int indexAristas, int indexCadena, Estado* anterior);

    protected:

    private:
        vector<int> estadosFinales;
        vector<char> alfabeto;
        vector<Estado *> estados;
        int cantEstados;
        Estado * estadoInicial;


};

#endif // NFA_H
