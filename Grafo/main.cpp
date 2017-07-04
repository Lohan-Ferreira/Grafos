#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Grafo.h"
#define max_iter 11
#define max_iter_rand 100
#define room 10

using namespace std;

int main(){

    /** Variáveis */
    Grafo* grafo;
    string temp;
    string grafos[10],g_terminais[10];
    grafos[0]= "64-1.txt";
    grafos[1]= "64-2.txt";
    grafos[2]= "64-3.txt";
    grafos[3]= "64-4.txt";
    grafos[4]= "256-1.txt";
    grafos[5]= "256-2.txt";
    grafos[6]= "256-3.txt";
    grafos[7]= "512-1.txt";
    grafos[8]= "512-2.txt";
    grafos[9]= "512-3.txt";

    g_terminais[0]= "64-1t.txt";
    g_terminais[1]= "64-2t.txt";
    g_terminais[2]= "64-3t.txt";
    g_terminais[3]= "64-4t.txt";
    g_terminais[4]= "256-1t.txt";
    g_terminais[5]= "256-2t.txt";
    g_terminais[6]= "256-3t.txt";
    g_terminais[7]= "512-1t.txt";
    g_terminais[8]= "512-2t.txt";
    g_terminais[9]= "512-3t.txt";

    float arestemp[3];
    int no;
    float alfa_reativo[10]={0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5};
    float alfa_randomizado[4]={0.05,0.1,0.15,0.2};


    /** Tratamento de arquivo e construção do grafo*/
    ifstream file;

    for(int t=0;t<10;t++)
    {
    grafo = new Grafo(false);
    cout<<"Abrindo arquivo:"<<grafos[t].c_str()<<endl;
    file.open(grafos[t].c_str());



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
    file.open(g_terminais[t].c_str());
    while(!file.eof())
    {
        file>>no;
        grafo->setSteiner(no);
        c++;
    }
    file.close();
    grafo->reativo(alfa_reativo,10,max_iter_rand,max_iter,10,t);
    delete grafo;

    }
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
