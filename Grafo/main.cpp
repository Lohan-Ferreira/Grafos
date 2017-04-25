#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Grafo.h"

using namespace std;

int main(){
    Grafo *grafo = new Grafo(true);
    string temp;
    float arestemp[3];
    int num_nos;

    ifstream file;
    file.open("name.txt");


   getline(file, temp);
   for(int i = 1; i <= atoi(temp.c_str()); i++)
        grafo->addVertice();

    while(getline(file,temp))
        for(int i = 0; i < 3; i++)
        {
            cout<<temp<<endl; //salvar os 3 valores do arquivo no vetor como float
        grafo->addAresta(arestemp[0], arestemp[1], arestemp[2]);
        }
    file.close();

    cout<<"COMPILOU \\O/"<<endl;
    return 0;
}
