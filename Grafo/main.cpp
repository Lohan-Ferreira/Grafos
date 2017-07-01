#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Grafo.h"
#define max_iter 1000
#define max_iter_rand 100
#define room 10

using namespace std;

int main(){

    /** Variáveis */
    Grafo * grafo = new Grafo(false);
    string temp;
    float arestemp[3];
    int no;
    float alfa_reativo[10]={0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5};
    float alfa_randomizado[4]={0.05,0.1,0.15,0.2};


    /** Tratamento de arquivo e construção do grafo*/
    ifstream file;
    file.open("ins80g.txt");


    getline(file, temp);
    for(int i = 1; i <= atoi(temp.c_str()); i++)
        grafo->addVertice();

    //leitura de arquivo e contrução do grafo
    while(true)
    {
        file>>arestemp[0]>>arestemp[1]>>arestemp[2];
        if(file.eof()) break;

        //cout<<arestemp[0]<<arestemp[1]<<arestemp[2]<<endl; //salvar os 3 valores do arquivo no vetor como float
        grafo->addAresta(arestemp[0], arestemp[1], arestemp[2]);
    }
    file.close();
int c=0;
    file.open("ins80t.txt");
    while(!file.eof())
    {
        file>>no;
        grafo->setSteiner(no);
        c++;
    }
    grafo->reativo(alfa_reativo,10,max_iter_rand,max_iter,10);
   // grafo->gulosoRandSteiner(0.05,10000);

    /** Testes */
    /*cout<<endl;
    grafo->sequenciaGraus();
    cout<<endl;
    //if(grafo->verificaBipartido()) cout<<"Eh bi";
    grafo->menorCaminhoFloyd(4,2);
    grafo->fechoDireto(3);
    grafo->fechoIndireto(3);
    cout<<"Eh euleriano? "<<grafo->verificaEuleriano()<<endl;
    cout<<"Eh bipartido? "<<grafo->verificaBipartido()<<endl;
    int v[3] = {1,3,4};
    Grafo* sub = grafo->subgrafoInd(v,3);
    cout<<endl;
    sub->sequenciaGraus();


    cout<<endl;
    Grafo *gcomp = grafo->grafoComplementar(grafo);
    cout<<endl;
    Grafo* agm = grafo->AGM();*/



    return 0;
}
