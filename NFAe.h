#ifndef NFAE_H
#define NFAE_H

#include "Estado.h"
#include "Arista.h"
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>

class NFAe
{
        public:
        NFAe(vector<char> alf, int cantEst, vector<int> estFinales);
        virtual ~NFAe();

        void setTransiciones();
        void convertir(char * str);


    protected:

    private:
        int convertir(Estado * estado, vector<Arista *> aristas, char* cadena, int indexAristas, int indexCadena);
        vector<int> estadosFinales;
        vector<char> alfabeto;
        vector<Estado *> estados;
        int cantEstados;
        Estado * estadoInicial;

};

#endif // NFAE_H
