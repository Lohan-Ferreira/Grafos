#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Grafo.h"

using namespace std;

int main(){
    Grafo *grafo = new Grafo(true);
    string temp;
    float arestemp[3];

    ifstream file;
    file.open("name.txt");


   getline(file, temp);
   for(int i = 1; i <= atoi(temp.c_str()); i++)
        grafo->addVertice();

    while(!file.eof())
    {
        file>>arestemp[0]>>arestemp[1]>>arestemp[2];


        //for(int i = 0; i < 3; i++)
          cout<<arestemp[0]<<arestemp[1]<<arestemp[2]<<endl; //salvar os 3 valores do arquivo no vetor como float
        grafo->addAresta(arestemp[0], arestemp[1], arestemp[2]);
    }


    file.close();
    grafo->sequenciaGraus();
    //grafo->caminhoMinimo(1,3,1);

    cout<<"COMPILOU \\O/"<<endl;
    return 0;
}
