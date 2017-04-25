#ifndef GRAFO_H
#define GRAFO_H
#include "Lista.h"

class Grafo{
    public:
        Grafo(bool dig){
            Lista_vertice = new ListaVertice();
            digrafo = dig;
            gera_id_v=0;
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
    int menor(float v[], int n)
    {
        float menor = v[0];
        int indice=0;
        for(int i=1;i<n;i++)
            if(menor>v[i])
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

    void caminhoMinimo(int a, int b, bool dijskra)
    {
         limpaVert();
        if(dijskra)
        {
            std::cout<<"Procurando o menor caminho pelo metodo de Dijkstra"<<std::endl;
            // 0 = S' && 1 = S //
            float pi[num_nos];
            int seletor;
            Vertice* va = Lista_vertice->buscaVertice(a)->getVertice();
            va->setFlag(1);
            NoListaAresta *tmp=va->getArestas()->getraiz();
            while(tmp!=NULL)
            {
                pi[tmp->getAresta()->getProximo()->getId()]=tmp->getAresta()->getPeso();
                tmp=tmp->getProximo();
            }

            seletor = menor(pi,num_nos);
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
            seletor = menor(pi,num_nos);
            //PRECISO CONSERTAR O SELETOR
            va=Lista_vertice->buscaVertice(seletor)->getVertice();
            va->setFlag(1);

            }




        }
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
            NoListaVertice * aux_ver = Lista_vertice->Getraiz();
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
