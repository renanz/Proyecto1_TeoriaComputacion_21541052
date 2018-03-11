#include "NFA.h"

NFA::NFA(vector<char> alf, int cantEst, vector<int> estFinales)
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
}

NFA::~NFA()
{
    //dtor
}
void NFA::setTransiciones()
{
    cout<<"Estados: ";
    for (int i=0; i< estados.size(); i++)
    {
        printf("%d-",estados[i]->getNombre());
    }
    cout<<endl;
    for (int i=0; i<estados.size(); i++)
    {
        Estado *temp = estados[i];
        printf("Transiciones con el estado %d.\n",temp->getNombre());
        for (int j=0; j<alfabeto.size(); j++)
        {
            int choice;
            printf("El estado %d tiene transicion con'%c'?\n\t1.-Si\n\t2.-No\nSu eleccion: ",temp->getNombre(),alfabeto[j]);
            cin >>choice;
            if(choice == 1)
            {
                printf("Cuantas trancisiones tiene el estado %d con'%c'? Su eleccion: ",temp->getNombre(),alfabeto[j]);
                cin >> choice;
                for(int k=0; k<choice; k++)
                {
                    printf("El estado %d con el caracter '%c' lleva al estado: ",temp->getNombre(),alfabeto[j]);
                    int opc;
                    cin >> opc;
                    temp->addAristas(alfabeto[j],estados[opc]);
                }
            }
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



//    estados[0]->addAristas(alfabeto[0],estados[1]);
//    estados[0]->addAristas(alfabeto[0],estados[2]);
//    estados[1]->addAristas(alfabeto[1],estados[2]);
//    estados[2]->addAristas(alfabeto[0],estados[1]);
//    estados[2]->addAristas(alfabeto[1],estados[2]);
//
//    for(int x=0; x<estados.size(); x++)
//    {
//        vector<Arista *> temp = estados[x]->getAristas();
//        for (int y=0; y<temp.size(); y++)
//        {
//            printf("El estado %d-%d lleva con %c al estado %d\n",estados[x]->getNombre(),estados[x]->isEstadoFinal(),temp[y]->getCaracter(),temp[y]->getEstado()->getNombre());
//        }
//    }
//
//    cout<<"\n\n";
//
//    resolver("ab");//aceptado
//    cout<<"\n\n";
//    resolver("abbbab");//aceptado
//    cout<<"\n\n";
//    resolver("aa");//no aceptacion
//    cout<<"\n\n";
//    resolver("abaa");//sin camino
}

void NFA::resolver(char* str)
{
    Estado * estadoTemp = estadoInicial;
    vector<Arista *> aristasTemp = estadoTemp->getAristas();
    int res = check(estadoTemp,aristasTemp,str,0,0,NULL);
    if(res == 0)
        cout<<str << " es aceptado"<<endl;
    else if(res == 1)
        cout<<str << " no es aceptado NSC"<<endl;
    else if(res == 3)
        cout<<str << " no es aceptado"<<endl;
}


//0 - estado aceptacion
//1 - estado no aceptacion
//3 - se quedo sin camino
int NFA::check(Estado * estado, vector<Arista *> aristas, char* cadena, int indexAristas, int indexCadena, Estado *anterior)
{
    //printf("Cadena: %s, Estado: %d, arista[%d] '%c'->%d, indexCadena%d '%c'\n",cadena,estado->getNombre(),indexAristas,aristas[indexAristas]->getCaracter(),aristas[indexAristas]->getEstado()->getNombre(),indexCadena,cadena[indexCadena]);
    if(strlen(cadena) == indexCadena)
    {
        if(estado->isEstadoFinal())
            return 0;
        else
            return 1;
    }
    for(int i=indexAristas; i<aristas.size(); i++)
    {
        int sePudo = 10;
        if(aristas[i]->getCaracter() == cadena[indexCadena])
        {
            sePudo = check(aristas[i]->getEstado(),aristas[i]->getEstado()->getAristas(),cadena,0,(indexCadena+1),estado);
            if(sePudo == 3)
                continue;
            else if(sePudo == 1)
                continue;
            else if(sePudo == 0)
                return sePudo;
        }
    }
    return 3;
}
