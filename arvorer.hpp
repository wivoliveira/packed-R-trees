#ifndef __ArvoreR_HPP__
#define __ArvoreR_HPP__

// incluir dependencias
#include "retangulo.hpp"
#include "entrada.hpp"

class ArvoreR
{
    public:

        Retangulo raiz_;

        size_t maxNos_;

        ArvoreR(int maxNos);
        
        ~ArvoreR();

        vector<Retangulo> busca(Entrada buscaFronteira);

        void inserir(Entrada pontoDado);

        vector<Entrada> inserirLote(vector<Entrada> entLista);

    private:

        vector<Retangulo> buscaRecursiva(Retangulo retBusca, Retangulo no);

        vector<Retangulo> camadaRecursivaArvore(vector<Retangulo> retLista, int nivel);

        void caminhoArvoreBalanceado(Retangulo folha);

};

#endif // __ArvoreR__