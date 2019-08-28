#ifndef ARESTA_H
#define ARESTA_H

using namespace std;

class Aresta
{
    public:
        Aresta(int idAlvo);
        ~Aresta();
        int getIdAlvo();
        Aresta* getProxAresta();
        float getPeso();
        void setProxAresta(Aresta* aresta);
        void setPeso(float peso);

    private:
        int idAlvo;
        Aresta* proxAresta;
        float peso;

};

#endif // ARESTA_H
