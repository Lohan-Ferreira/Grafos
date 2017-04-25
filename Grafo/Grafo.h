#ifndef GRAFO_H
#define GRAFO_H
#include "Lista.h"

class Grafo{
    public:
        Grafo(bool dig){
            Lista_vertice = new ListaVertice();
            digrafo = dig;
            gera_id_v=1;
            num_nos=0;
        }

        ~Grafo(){}

        int verifGrau(int id)
        {
            if(id<=gera_id_v)
                return Lista_vertice->buscaVertice(id)->getVertice()->getArestas()->getQuantidade();
            else
            {


                std::cout<<("Nó não pertence ao grafo!");
                return 0;
            }

        }
    int menorPi(float v[], int n)
    {
        int indice;
        float menor;
        NoListaVertice* tmp = Lista_vertice->Getraiz();

        while(tmp!=NULL)
        {
            if(tmp->getVertice()->getFlag()== 0)
            {
                indice=tmp->getVertice()->getId();
                break;
            }
            tmp=tmp->getProximo();

        }
         menor = v[indice];

        for(int i=0;i<n;i++)
            if(menor>v[i] && Lista_vertice->buscaVertice(i)->getVertice()->getFlag()== 0)
            {
                menor=v[i];
                indice=i;
            }

        return indice;
    }
        bool verificaKregular (int k)
        {
            if(num_nos>0)
            {


            NoListaVertice* tmp=Lista_vertice->Getraiz();
            while(tmp!= NULL)
            {
                if(verifGrau(tmp->getVertice()->getId()!= k))
                    return false;
                tmp=tmp->getProximo();
            }
            return true;
            }
            else return false;
        }

        bool verifica_multigrafo()
       {
            NoListaVertice * aux_ver = Lista_vertice->Getraiz();
            while(aux_ver != NULL){
                NoListaAresta * aux_ar1 = aux_ver->getVertice()->getArestas()->getraiz();
                while(aux_ar1 != NULL){
                    NoListaAresta * aux_ar2 = aux_ar1->getProximo();
                    while(aux_ar2 != NULL){
                        if(aux_ar1->getAresta()->getProximo()->getId() == aux_ar2->getAresta()->getProximo()->getId())
                            return true;
                        else
                            aux_ar2 = aux_ar2->getProximo();
                    }
                    aux_ar1 = aux_ar1->getProximo();
                }
                aux_ver = aux_ver->getProximo();
            }
            return false;
       }

        bool verifCompleto()
        {
            if(verifica_multigrafo()) return false;
            if(digrafo)
                if(num_arestas==num_nos*(num_nos-1))
                    return true;
                else return false;
            else
                if(num_arestas==num_nos*(num_nos-1)/2)
                    return true;
                else return false;


        }
/*
    void caminhoMinimo(int a, int b, bool dijskra)
    {

        //limpaVert();

        if(dijskra)
        {
            std::cout<<"Procurando o menor caminho pelo metodo de Dijkstra"<<std::endl;
            // 0 = S' && 1 = S //
            ListaVertice *lista=new ListaVertice();
            lista->addVertice(new Vertice(a,0,0,0));
            float pi[num_nos+1];
            for(int i=0;i<num_nos+1;i++)
                pi[i]=999999999999;
            int seletor,seletor_ant;
            Vertice* va = Lista_vertice->buscaVertice(a)->getVertice();
            va->setFlag(1);
            NoListaAresta *tmp=va->getArestas()->getraiz();
            while(tmp!=NULL)
            {
                pi[tmp->getAresta()->getProximo()->getId()]=tmp->getAresta()->getPeso();
                tmp=tmp->getProximo();
            }
            seletor_ant=a;
            seletor = menorPi(pi,num_nos+1);
            lista->addVertice(new Vertice(seletor,0,0,0));
            va=Lista_vertice->buscaVertice(seletor)->getVertice();
            va->setFlag(1);

            while(va!=Lista_vertice->buscaVertice(b)->getVertice())
            {
            NoListaAresta *tmp=va->getArestas()->getraiz();
                while(tmp!=NULL)
            {
                if(pi[seletor]+tmp->getAresta()->getPeso()< pi[tmp->getAresta()->getProximo()->getId()])
                pi[tmp->getAresta()->getProximo()->getId()]=pi[seletor]+tmp->getAresta()->getPeso();
                tmp=tmp->getProximo();
            }
            seletor_ant=seletor;
            seletor = menorPi(pi,num_nos+1);

            if(buscaAresta(seletor_ant,seletor)!=NULL)
            {
            lista->addVertice(new Vertice(seletor,0,0,0));
            va=Lista_vertice->buscaVertice(seletor)->getVertice();
            va->setFlag(1);
            }
            else
            {
                lista->deletaVertice(seletor_ant);
                lista->addVertice(new Vertice(seletor,0,0,0));
                va=Lista_vertice->buscaVertice(seletor)->getVertice();
                va->setFlag(1);
            }
            }
            NoListaVertice* imprime = lista->Getraiz();
            while(imprime!=NULL)
            {
            std::cout<<imprime->getVertice()->getId()<<"-->";
            imprime=imprime->getProximo();
            }

        }
    }


*/

 void floyd(int a , int b)
 {

     float matriz[gera_id_v][gera_id_v];
     NoListaAresta* aux_ar;
     NoListaVertice* aux_ver;
     aux_ver=Lista_vertice->Getraiz();

     for(int i=1;i<gera_id_v;i++)
        for(int j=1;j<gera_id_v;j++)
     {


            if(i==j)matriz[i][j]=0;
            else matriz[i][j]=9999;
     }
     while(aux_ver!=NULL)
     {
         aux_ar=aux_ver->getVertice()->getArestas()->getraiz();
         while(aux_ar!=NULL)
         {

             matriz[aux_ar->getAresta()->getAnterior()->getId()][aux_ar->getAresta()->getProximo()->getId()] = aux_ar->getAresta()->getPeso();
             std::cout<< matriz[aux_ar->getAresta()->getAnterior()->getId()][aux_ar->getAresta()->getProximo()->getId()] <<std::endl;
             aux_ar=aux_ar->getProximo();
         }
         aux_ver=aux_ver->getProximo();
     }
        std::cout<<a;
     for(int i=1;i<gera_id_v;i++)
     {
        for(int j=1;j<gera_id_v;j++)
        {
            for(int k=1;k<gera_id_v;k++)
            {
                if(matriz[i][j]>matriz[i][k]+matriz[k][j])
                {
                    matriz[i][j]=matriz[i][k]+matriz[k][j];
                    if(i==a&&j==b)std::cout<<"-->"<<k;
                }
            }
        }

     }
    std::cout<<"-->"<<b<<std::endl;

    /*IMPRIME TODA A MATRIZ!!
     for(int i=1;i<gera_id_v;i++)
     {
         for(int j=1;j<gera_id_v;j++)
            std::cout<<matriz[i][j]<<"\t";
         std::cout<<std::endl;
     }

    */
 }
void troca (int* vet, int a, int b){
    int aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;

}

void sorting(int *vet, int n)
{
    int iaux, i,j;

    for(i=0;i<n-1;i++)
    {
        iaux=i;
        for(j=i+1;j<n;j++){
            if(vet[j] <vet[iaux])
                iaux=j;
        }
        if(iaux != i)
            troca(vet,iaux,i);
    }
}
    void sequenciaGraus()
    {
        int graus[num_nos];
        for(int i=0;i<num_nos;i++)
            graus[i]=verifGrau(i+1);
        sorting(graus,num_nos);
        for(int i=0;i<num_nos;i++)
        std::cout<<graus[i];
    }

    Aresta* buscaAresta(int a, int b)
    {
        NoListaAresta* tmp=Lista_vertice->buscaVertice(a)->getVertice()->getArestas()->getraiz();
        while(tmp!=NULL)
        {
            if(tmp->getAresta()->getProximo()->getId()== b) return tmp->getAresta();
            tmp=tmp->getProximo();
        }
         return NULL;
    }
    bool verificaBipartido(){
            NoListaVertice* aux_ver = Lista_vertice->Getraiz();
            while(aux_ver != NULL){
                aux_ver->getVertice()->setVizitado(0);
                aux_ver->getVertice()->setFlag(0);
                aux_ver->getProximo();
            }
            aux_ver = Lista_vertice->Getraiz();
            for(int i = 0; i < Lista_vertice->Getquantidade(); i++){
                if(aux_ver->getVertice()->getVizitado() == 0)
                   {

                    Vertice* v = aux_ver->getVertice();
                    if(!verificaBiProf(v, v->getFlag(), v->getVizitado()))
                        return false;
                   }
            }
            return true;
        }

           bool verificaBiProf(Vertice* vertice, bool cor, bool viz){

            if((vertice->getVizitado() == 1) && (vertice->getFlag() != cor)){
                return false;
            }
            else{
                vertice->setFlag(cor);
                vertice->setVizitado(viz);
            }

            NoListaAresta * aux_ar = vertice->getArestas()->getraiz();
            while(aux_ar != NULL){
                if(vertice->getVizitado() == 0)
                    verificaBiProf(aux_ar->getAresta()->getProximo(), !cor, 1);
                aux_ar = aux_ar->getProximo();
            }
            return true;
        }






        int ordemGrafo()
        {
            return num_nos;
        }

        int grauGrafo()
        {   return grau;
        }

        void addVertice(float peso)
        {
            Lista_vertice->addVertice(new Vertice(gera_id_v,peso,0,0));
            gera_id_v++;
            num_nos++;
        }
        void addVertice()
        {
            Lista_vertice->addVertice(new Vertice(gera_id_v,0,0,0));
            gera_id_v++;
            num_nos++;
        }

      /*  void addVertice(float peso, int id)
        {
            Lista_vertice->addVertice(new Vertice(id,peso,0,0));
            num_nos++;
        }
     */
        void addAresta(int a , int b, float p)
        {   Vertice* ant;
            Vertice* prox;
            ant=Lista_vertice->buscaVertice(a)->getVertice();

            prox=Lista_vertice->buscaVertice(b)->getVertice();
            ant->getArestas()->addAresta(new Aresta(0,p,ant,prox));

            if(grau<verifGrau(a)) grau = verifGrau(a);
        }

        bool grafoTrivial ()
        {
            if(num_nos==1) return true;
            else return false;
        }

        bool grafoNulo ()

        {
            if(num_nos==0) return true;
            else return false;
        }

        void vizinhancaAberta(int id)
        {
            if(id<=num_nos&&id>0)
            {
                std::cout<<"A vizinhança aberta do nó:"<<id<<" Possui os nós:";
                NoListaAresta* tmp = Lista_vertice->buscaVertice(id)->getVertice()->getArestas()->getraiz();
                int qnt = Lista_vertice->buscaVertice(id)->getVertice()->getArestas()->getQuantidade();
                int v[qnt],i=0,j,k;
                while(tmp!=NULL)
                {
                    v[i]=tmp->getAresta()->getProximo()->getId();
                    std::cout<<v[i];
                    tmp=tmp->getProximo();
                    i++;
                }
                std::cout<<std::endl<<"Com as arestas:";
                for(j=0;j<qnt;j++)
                {

                    for( k=0;k<qnt;k++)
                    {
                        tmp = Lista_vertice->buscaVertice(v[j])->getVertice()->getArestas()->getraiz();
                        while(tmp!=NULL)
                        {
                            if(v[k] == tmp->getAresta()->getProximo()->getId())
                                std::cout<<v[j]<<"-->"<<v[k]<<" ";
                            tmp=tmp->getProximo();
                        }
                    }
                    std::cout<<std::endl;
                }

            }
        }



        void vizinhancaFechada(int id)
        {
            if(id<=num_nos&&id>0)
            {
                std::cout<<"A vizinhança fechada do nó:"<<id<<" Possui os nós:";
                NoListaAresta* tmp = Lista_vertice->buscaVertice(id)->getVertice()->getArestas()->getraiz();
                int qnt = Lista_vertice->buscaVertice(id)->getVertice()->getArestas()->getQuantidade() + 1;
                int v[qnt],i=1,j,k;
                v[0]= id;
                std::cout<<v[0];
                while(tmp!=NULL)
                {
                    v[i]=tmp->getAresta()->getProximo()->getId();
                    std::cout<<v[i];
                    tmp=tmp->getProximo();
                    i++;
                }
                std::cout<<std::endl<<"Com as arestas:";
                for(j=0;j<qnt;j++)
                {

                    for( k=0;k<qnt;k++)
                    {
                        tmp = Lista_vertice->buscaVertice(v[j])->getVertice()->getArestas()->getraiz();
                        while(tmp!=NULL)
                        {
                            if(v[k] == tmp->getAresta()->getProximo()->getId())
                                std::cout<<v[j]<<"-->"<<v[k]<<" ";
                            tmp=tmp->getProximo();
                        }
                    }
                    std::cout<<std::endl;
                }

            }
        }

        void limpaVert()
        {
            NoListaVertice* aux_ver = Lista_vertice->Getraiz();
            while(aux_ver != NULL){
                aux_ver->getVertice()->setFlag(0);
                aux_ver->getProximo();
            }
        }


    private:
        bool digrafo;
        int grau;
        int ordem;
        int num_arestas;
        int num_nos;
        int gera_id_v;
        int gera_id_a;
        ListaVertice * Lista_vertice;


};

#endif // GRAFO_H
