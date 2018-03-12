#include "RandomTest.h"

RandomTest::RandomTest()
{
    vector<char> caracteres;
    caracteres.push_back('a');
    caracteres.push_back('b');
    caracteres.push_back('~');
    ofstream archivo;
    archivo.open("archivo.txt",ios::out);
    for (int i=0; i<WORD_COUNT; i++)
    {
        int length = rand()%MAX_LENGTH_STRING;
        //string cadena = "";
        string cadena = (length == 0) ? "~" : "~";
        for (int j=0; j<length; j++)
        {
            int car = rand()%caracteres.size();
            cadena += caracteres[car];
        }
        archivo << cadena;
        archivo << "\n";
    }
    archivo.close();
}

RandomTest::~RandomTest()
{
    //dtor
}
