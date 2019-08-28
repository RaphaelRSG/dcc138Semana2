#ifndef GRAFO_H
#define GRAFO_H
#include "No.h"
#include <fstream>
#include <stack>
#include <list>

using namespace std;

class Grafo
{
    public:
        Grafo(int ordem, bool direcionado, bool arestaComPeso, bool noComPeso);
        ~Grafo();
        int getOrdem();
        int getNumAresta();
        bool getDirecionado();
        bool getArestaComPeso();
        bool getNoComPeso();
        No* getPrimeiroNo();
        No* getUltimoNo();
        void insereNo(int id);
        void insereAresta(int id, int idAlvo, float peso);
        void removeNo (int id);
        void procuraNo (int id);
        No* getNo(int id);
        bool buscaEmProfundidade (int idInicial, int idAlvo);
        void larguraEmProfundidade (ofstream& arquivo_saida);
        Grafo* getComplemento();
        Grafo* getSubjacente();
        bool possuiCircuito();
        bool grafoConexo();
        float** floydMarshall();
        float* dijkstra(int id);



    private:
        int ordem;
        int numAresta;
        bool direcionado;
        bool arestaComPeso;
        bool noComPeso;
        No* primeiroNo;
        No* ultimoNo;

        // funcoes auxiliares
};

#endif // GRAFO_H
