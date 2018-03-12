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
    cout << "Bienvenido\n\nPara salir presione el numero 9" <<endl;
    cout << "----------------------" <<endl;

    cout<< "Desea resolver un:\n";
    cout<< "\t1. DFA\n";
    cout<< "\t2. NFA\n";
    cout<< "\t3. NFAe\n";
    cout<< "Su eleccion: ";
    cin >> eleccion;
    while (eleccion != 1 || eleccion != 2 || eleccion != 3)
    {
        if(eleccion==1 || eleccion==2 || eleccion == 3)
            break;
        cout<< "Por favor elija 1, 2 o 3: ";
        cin >> eleccion;
    }
    cout << "\n----------------------\n\n" <<endl;
    //Alfabeto
    vector<char> alfabeto;
    (eleccion == 3) ? cout << "Favor ingrese cuantos elementos en el alfabeto (No necesita ingresar caracter para Epsilon): ": cout << "Favor ingrese cuantos elementos en el alfabeto: ";
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
    switch (eleccion)
    {
        case 1:
            {
                _dfa = new DFA(alfabeto, cantEstados, estadosFinales);
                _dfa->setTransiciones();
                break;
            }
        case 2:
            {
                _nfa = new NFA(alfabeto, cantEstados, estadosFinales);
                _nfa->setTransiciones();
                break;
            }
        case 3:
            {
                alfabeto.insert(alfabeto.begin(),'~');
                _nfae = new NFAe(alfabeto, cantEstados, estadosFinales);
                _nfae->setTransiciones();
                break;
            }
        default: break;
    }
    cout<< "Desea resolver otro automata?\n\t1.- Si\n\t2.- No\n\tSu eleccion:";
    cin >> eleccion;
    cout << "-------------------------\n\n\n" <<endl;
    if(eleccion == 1)
        menu();
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


