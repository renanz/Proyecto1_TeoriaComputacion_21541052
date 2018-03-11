#include "DFA.h"

DFA::DFA(vector<char>alf, int cantEst, vector<int>estFinales)
{
    this->alfabeto = alf;
    this->cantEstados = cantEst;
    this->estadosFinales = estFinales;
    bool estFin = false;
    for (int i = 0; i<cantEstados; i++)
    {
        this->estados.push_back(new Estado(i,estFin));
    }
    for (int i=0; i<estados.size(); i++)
    {
        for (int j=0; j<estadosFinales.size(); j++)
        {
            if(estados[i]->getNombre() == estadosFinales[j])
            {
                estados[i]->setEstadoFinal(true);
            }
        }
    }
    this->estadoInicial = estados[0];
    cout<<endl;
}


DFA::~DFA()
{
    //dtor
}

void DFA::setTransiciones()
{
    cout<<"\nEstados: ";
    for (int i=0; i< estados.size(); i++)
    {
        cout<<estados[i]->getNombre();
        ((i+1) < cantEstados) ? cout<<"-" : false;
    }
    cout<<endl;
    for (int i=0; i<estados.size(); i++)
    {
        Estado *temp = estados[i];
        printf("Transiciones con el estado %d.\n",temp->getNombre());
        for (int j=0; j<alfabeto.size(); j++)
        {
            printf("El estado %d con el caracter '%c' lleva al estado: ",temp->getNombre(),alfabeto[j]);
            int opc;
            cin >> opc;
            temp->addAristas(alfabeto[j],estados[opc]);
        }
        cout<<endl;
    }

    //File
    string str;
    ifstream file;
    if(!file.is_open())
       file.open("archivo.txt");
    while(!file.eof())
    {
        getline(file, str, '\n');
        char * cstr = new char [str.length()+1];
        strcpy(cstr,str.c_str());
        resolver(cstr);
    }
}



void DFA::resolver(char * str)
{
    Estado * estadoTemp = estadoInicial;
    vector <Arista *> vectorTemp = estadoTemp->getAristas();

    estadoTemp = estadoInicial;
    for (int x=0; x<strlen(str); x++)
    {
        vectorTemp = estadoTemp->getAristas();
        for(int y=0; y<vectorTemp.size();y++)
        {
            if(vectorTemp[y]->getCaracter() == str[x])
                estadoTemp = vectorTemp[y]->getEstado();
        }
    }
    if(estadoTemp->isEstadoFinal())
        cout<<str << "\t\tes aceptable"<<endl;
    else
        cout<<str << "\t\tno aceptable " <<endl;
}
