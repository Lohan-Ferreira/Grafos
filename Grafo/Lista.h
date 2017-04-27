/** Arquivo de classes gerais */
/*  As classes nesse arquivo são classes dependentes entre si, por esse motivo se encontram no mesmo arquivo.
    Além disso, elas são a base para a criação da classe grafo */

//Classes abstraidas da teoria de Grafos.
class Vertice;
class Aresta;

//Classes referentes às listas encadeadas de Vertices e Arestas
class ListaAresta;
class NoListaAresta;
class NoListaVertice;
class ListaVertice;

//Implementações das classes

class NoListaAresta{

    private:
        Aresta *aresta;
        NoListaAresta *anterior;
        NoListaAresta *proximo;

    public:

        NoListaAresta(NoListaAresta *ant, Aresta *a, NoListaAresta *prox){
            anterior = ant;
            aresta = a;
            proximo = prox;
        }

        NoListaAresta* getProximo() { return proximo; }
        void setProximo(NoListaAresta *val) { proximo = val; }
        NoListaAresta* getAnterior() { return anterior; }
        void setAnterior(NoListaAresta *val) { anterior = val; }
        Aresta* getAresta() { return aresta; }
        void setAresta(Aresta *val) { aresta = val; }
};
class ListaAresta{
    private:
        NoListaAresta *raiz;
        int quantidade;

    public:
        ListaAresta()
        {
            quantidade=0;
            raiz=NULL;
        }

        NoListaAresta* getraiz() { return raiz; }
        void setRaiz(NoListaAresta* val) { raiz = val; }
        int getQuantidade() { return quantidade; }
        void setQuantidade(int val) { quantidade = val; }

        bool addAresta(Aresta *aresta){
            if(raiz==NULL) raiz = new NoListaAresta(NULL,aresta,NULL);
            NoListaAresta *noListaAresta = new NoListaAresta(NULL, aresta, raiz);
            raiz->setAnterior(noListaAresta);
            raiz = noListaAresta;
            quantidade++;
            return true;
        }

        NoListaAresta *buscaAresta(Aresta *aresta){
            NoListaAresta *tmp = raiz;
            while (tmp != NULL){
                if(tmp->getAresta()== aresta)
                    return tmp;
                tmp = tmp->getProximo();
            }
        return NULL;
        }

        bool deletaAresta(Aresta *aresta){
            NoListaAresta *tmp = buscaAresta(aresta);
            if(tmp == NULL) return false;
            tmp->getAnterior()->setProximo(tmp->getProximo());
            tmp->getProximo()->setAnterior(tmp->getAnterior());
            return true;
        }

};
class Vertice{

    public:
        Vertice(int ID,float p,bool f1,char f2){
            id=ID;
            flag=f1;
            flag2=f2;
            listaAresta = new ListaAresta();
            }
        int getId(){return id;}
        ListaAresta *getArestas() {return listaAresta;}
        void setFlag(bool b) {flag = b;}
        bool getFlag(){return flag;}
        void setVizitado(bool v){vizitado=v;}
        bool getVizitado(){return vizitado;}
    private:
        int id;
        float peso;
        bool flag;
        char flag2;
        bool vizitado;
        ListaAresta *listaAresta;

};
class Aresta{

    private:
    int id;
    float peso;
    Vertice *anterior;
    Vertice *proximo;

    public:
        Aresta(int ID,float p, Vertice *a, Vertice *b)
        {id=ID;
        peso=p;
        anterior=a;
        proximo=b;
        }
        Vertice* getProximo() {return proximo;}
        Vertice* getAnterior() {return anterior;}
        float getPeso() {return peso;}
};
class NoListaVertice{

    private:
        Vertice *vertice;
        NoListaVertice *anterior;
        NoListaVertice *proximo;

    public:

        NoListaVertice(NoListaVertice *ant, Vertice *v, NoListaVertice *prox){
            anterior = ant;
            vertice = v;
            proximo = prox;
        }

        NoListaVertice *getProximo() { return proximo; }
        void setProximo(NoListaVertice *val) { proximo = val; }
        NoListaVertice *getAnterior() { return anterior; }
        void setAnterior(NoListaVertice *val) { anterior = val; }
        Vertice *getVertice() { return vertice; }
        void setVertice(Vertice *val) { vertice = val; }
};
class ListaVertice{
    private:
        NoListaVertice *raiz;
        int quantidade;

    public:
        ListaVertice()
        {
            quantidade=0;
            raiz=NULL;
        }

        NoListaVertice* Getraiz() { return raiz; }
        void Setraiz(NoListaVertice val) { *raiz = val; }
        int Getquantidade() { return quantidade; }
        void Setquantidade(int val) { quantidade = val; }

        bool addVertice(Vertice *vertice){
            if(raiz==NULL) raiz = new NoListaVertice(NULL,vertice,NULL);
            NoListaVertice *noListaVertice = new NoListaVertice(NULL, vertice, raiz);
            raiz->setAnterior(noListaVertice);
            raiz = noListaVertice;
            quantidade++;
            return true;
        }

        NoListaVertice *buscaVertice(int id){
            NoListaVertice *tmp = raiz;
            while (tmp != NULL){
                if(tmp->getVertice()->getId() == id)
                    return tmp;
                tmp = tmp->getProximo();
            }
        return NULL;
        }

        bool deletaVertice(int id){

            NoListaVertice *tmp = buscaVertice(id);
            if(tmp == NULL) return false;
            if(tmp->getAnterior()!=NULL)
            tmp->getAnterior()->setProximo(tmp->getProximo());
            if(tmp->getProximo()!=NULL)
            tmp->getProximo()->setAnterior(tmp->getAnterior());
            delete tmp;
            return true;
        }

};
