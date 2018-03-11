#ifndef INTERMEDIADOR_H
#define INTERMEDIADOR_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include "DFA.h"
#include "NFA.h"

using namespace std;

class Intermediador
{
    public:
        Intermediador();
        virtual ~Intermediador();

        void menu();
        void test();

    protected:

    private:
        int eleccion;
        DFA * _dfa;
        NFA * _nfa;

};

#endif // INTERMEDIADOR_H
