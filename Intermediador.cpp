#include "Intermediador.h"

Intermediador::Intermediador()
{
    eleccion = 0;
    _dfa = 0;
}

Intermediador::~Intermediador()
{
    //dtor
}

void Intermediador::menu()
{
    cout << "Bienvenido\n\n" <<endl;
    cout << "----------------------" <<endl;

    cout<< "Desea resolver un:\n";
    cout<< "\t1. DFA\n";
    cout<< "\t2. NFA\n";
    cout<< "Su eleccion: ";
    cin >> eleccion;
    while (eleccion != 1 || eleccion != 2)
    {
        if(eleccion==1 || eleccion==2)
            break;
        cout<< "Por favor elija 1 o 2: ";
        cin >> eleccion;
    }

    switch (eleccion)
    {
        case 1:
            {
                //Alfabeto
                vector<char> alfabeto;
                cout << "Favor ingrese cuantos elementos en el alfabeto: ";
                int cantElemAlf;
                cin >> cantElemAlf;
                for (int i=0; i<cantElemAlf; i++){
                    printf("\tCaracter%d:",i);
                    char caracter;
                    cin >> caracter;
                    alfabeto.push_back(caracter);
                }
                //Estados
                cout << "Favor ingrese la cantidad de estados: ";
                int cantEstados;
                cin >> cantEstados;
                cout<<"\tEstados: ";
                for (int i=0; i< cantEstados; i++)
                {
                    cout<<i;
                    (i+1 < cantEstados) ? cout<<"-" : false;
                }
                cout<<endl;
                //Estados Finales
                vector<int> estadosFinales;
                cout << "Favor ingrese cuantos estados finales hay: ";
                int cantEstadosFinales;
                cin >> cantEstadosFinales;
                for (int i=0; i<cantEstadosFinales; i++){
                    printf("Estado Final%d: ",i);
                    int estadoFinal;
                    cin >> estadoFinal;
                    estadosFinales.push_back(estadoFinal);
                }
                _dfa = new DFA(alfabeto, cantEstados, estadosFinales);
                _dfa->setTransiciones();
                break;
            }
        case 2:
            {
                //Alfabeto
                vector<char> alfabeto;
                cout << "Favor ingrese cuantos elementos en el alfabeto: ";
                int cantElemAlf;
                cin >> cantElemAlf;
                for (int i=0; i<cantElemAlf; i++){
                    printf("Caracter%d:",i);
                    char caracter;
                    cin >> caracter;
                    alfabeto.push_back(caracter);
                }
                //Estados
                cout << "Favor ingrese la cantidad de estados: ";
                int cantEstados;
                cin >> cantEstados;
                cout<<"Estados: ";
                for (int i=0; i< cantEstados; i++)
                {
                    printf("%d-",i);
                }
                cout<<endl;
                //Estados Finales
                vector<int> estadosFinales;
                cout << "Favor ingrese cuantos estados finales hay: ";
                int cantEstadosFinales;
                cin >> cantEstadosFinales;
                for (int i=0; i<cantEstadosFinales; i++){
                    printf("Estado Final%d: ",i);
                    int estadoFinal;
                    cin >> estadoFinal;
                    estadosFinales.push_back(estadoFinal);
                    cout<<"estfinal en i: "<<estadosFinales[i]<<endl;
                }

                cout<<"cant estfinal: "<<estadosFinales.size()<<endl;
                _nfa = new NFA(alfabeto, cantEstados, estadosFinales);
                _nfa->setTransiciones();
                break;
            }
        default: break;
    }
}
void Intermediador::test()
{
    cout<<"\ntest\n";
    vector<char> alfabeto;
    alfabeto.push_back('a');
    alfabeto.push_back('b');

    int cantEstados = 3;

    vector<int> estadosFinales;
    estadosFinales.push_back(2);

    _dfa = new DFA(alfabeto, cantEstados, estadosFinales);
    _dfa->setTransiciones();
}


