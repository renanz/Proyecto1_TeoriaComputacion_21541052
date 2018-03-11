#ifndef DFA_H
#define DFA_H

#include "Estado.h"
#include "Arista.h"
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>


using namespace std;


class DFA
{
    public:
        DFA(vector<char> alf, int cantEst, vector<int> estFinales);
        virtual ~DFA();

        void setTransiciones();
        void resolver(char * str);


    protected:

    private:
        vector<int> estadosFinales;
        vector<char> alfabeto;
        vector<Estado *> estados;
        int cantEstados;
        Estado * estadoInicial;
};

#endif // DFA_H
