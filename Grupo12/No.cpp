#include "No.h"
#include "Aresta.h"
#include <iostream>

using namespace std;

No::No(int id)
{
    this->id = id;      //ctor
    this->grauEntrada = 0;
    this->grauSaida = 0;
    this->peso = 0;
    this->primeiraAresta = nullptr;
    this->ultimaAresta = nullptr;
    this->proxNo = nullptr;
}

No::~No()
{
    Aresta* proxAresta = this->primeiraAresta;
    while(proxAresta != nullptr)
    {
        Aresta* auxAresta = proxAresta->getProxAresta();
        delete proxAresta;
        proxAresta = auxAresta;
    }
}

Aresta* No::getPrimeiraAresta()
{
    return this->primeiraAresta;
}

Aresta* No::getUltimaAresta()
{
    return this->ultimaAresta;
}

int No::getId()
{
    return this->id;
}

int No::getGrauEntrada()
{
    return this->grauEntrada;
}

int No::getGrauSaida()
{
    return this->grauSaida;
}

float No::getPeso()
{
    return this->peso;
}

No* No::getProxNo()
{
    return this->proxNo;
}

void No::setProxNo(No* proxNo)
{
    this->proxNo = proxNo;
}

void No::setPeso(float peso)
{
    this->peso = peso;
}

void No::inserirAresta(int idAlvo, float peso)
{
    if(this->primeiraAresta != nullptr)
    {
        Aresta* aresta = new Aresta(idAlvo);
        aresta->setPeso(peso);
        this->ultimaAresta->setProxAresta(aresta);
        this->ultimaAresta = aresta;
    }
    else
    {
        this->primeiraAresta = new Aresta(idAlvo);
        this->primeiraAresta->setPeso(peso);
        this->ultimaAresta = this->primeiraAresta;
    }
}

void No::removerTodasArestas()
{
    if(this->primeiraAresta != nullptr)
    {
        Aresta* proximo = nullptr;
        Aresta* aux = this->primeiraAresta;
        while(aux != nullptr)
        {
            proximo = aux->getproxAresta();
            delete aux;
        }
    }
    this->primeiraAresta = this->ultimaAresta = nullptr;
}

int No::removerAresta(int id, bool direcionado, No* idAlvo)
{
    if(this->procuraAresta(id))
    {
        Aresta* aux = this->primeiraAresta;
        Aresta* anterior = nullptr;
        while(aux->getIdAlvo() != id)
        {
            anterior = aux;
            aux = aux->getproxAresta();
        }
        if(anterior != nullptr)
            anterior->setProxAresta(aux->getproxAresta());

        else
            this->primeiraAresta = aux->getproxAresta();

        if(aux == this->ultimaAresta)
            this->ultimaAresta = anterior;

        if(aux->getproxAresta() == this->ultimaAresta)
            this->ultimaAresta = aux->getproxAresta();

        delete aux;

        if(direcionado)
            this->decrementaGSaida();

        else
        {
            this->decrementaGEntrada();
            idAlvo->decrementaGEntrada();
        }
        return 1;
    }
    return 0;
}

bool No::procuraAresta(int idAlvo)
{
    if(this->primeiraAresta != nullptr)
    {
        for(Aresta* aux = this->primeiraAresta; aux != nullptr; aux = aux->getproxAresta())
            if(aux->getIdAlvo() == idAlvo)
                return true;
    }
    return false;
}

void No::incrementaGEntrada()
{
    this->grauEntrada++;
}

void No::incrementaGSaida()
{
    this->grauSaida++;
}

void No::decrementaGEntrada()
{
    this->grauEntrada--;
}

void No::decrementaGSaida()
{
    this->grauSaida--;
}

Aresta* No::temAresta(int idAlvo)
{
    for(Aresta *auxAresta = this->primeiraAresta; auxAresta != nullptr; auxAresta->getproxAresta())
    {
        if(auxAresta->getIdAlvo() == idAlvo)
            return auxAresta;
    }
    return nullptr;
}


