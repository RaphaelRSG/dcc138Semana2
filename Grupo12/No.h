#ifndef NO_H
#define NO_H
#include "Aresta.h"

using namespace std;

class No
{
    public:
        No(int id);   // construtor
        ~No();  // destrutor
        int getId();
        int getGrauEntrada();
        int getGrauSaida();
        float getPeso();
        No* getProxNo();
        Aresta* getPrimeiraAresta();
        Aresta* getUltimaAresta();

        void setProxNo(No* no);
        void setPeso(float peso);

        bool procuraAresta(int idAlvo);
        void inserirAresta(int idAlvo, float peso);
        void removerTodasArestas();
        int removerAresta(int id,bool direcionado, No* noAlvo);
        void incrementaGSaida();
        void incrementaGEntrada();
        void decrementaGSaida();
        void decrementaGEntrada();
        Aresta* temAresta(int idAlvo);

    private:
        int id;
        unsigned int grauEntrada;
        unsigned int grauSaida;
        float peso;
        No* proxNo;
        Aresta* primeiraAresta;
        Aresta* ultimaAresta;
};

#endif // NO_H
