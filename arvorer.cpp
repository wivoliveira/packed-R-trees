#include "arvorer.hpp"
#include "retangulo.hpp"
#include "curvahilbert.hpp"
#include <limits>
#include <math.h>
#include <algorithm>

using namespace std;

const double MAX = numeric_limits<double>::max();

ArvoreR::ArvoreR(int maxNodes) {

	Retangulo raiz; 

}

ArvoreR::~ArvoreR() {

}

vector<Retangulo> ArvoreR::buscaRecursiva(Retangulo retBusca, Retangulo no) {

	if (retBusca.contem(no) || no.noFolha()) {
		return no.obterSubArvore();
	} else {		
		
		for (int i = 0; i <= no.filhos_.size(); i++) {
			if (retBusca.sobrepoe(no.filhos_[0])) {
				buscaRecursiva(retBusca, no.filhos_[i]);
			}
		}

	}

}

vector<Retangulo> ArvoreR::busca(Entrada buscaFronteira) {
	
	Retangulo buscaRet = Retangulo(buscaFronteira.obterX(), buscaFronteira.obterY(), buscaFronteira.obterLargura(), buscaFronteira.obterAltura(), 0);
	
	return buscaRecursiva(buscaRet, raiz_);

}

void ArvoreR::inserir(Entrada dadoEntrada) {
	
	Retangulo ret = Retangulo(dadoEntrada.obterX(), dadoEntrada.obterY(), dadoEntrada.obterLargura(), dadoEntrada.obterAltura(), dadoEntrada.obterDado());

	Retangulo no = raiz_;

	while(!no.temNoFolha()) {
		no.aumentaRetangulo(ret);
		int min = MAX;
		for (int i = 0; i < no.filhos_.size(); i++) {
			int area = ret.acrescimoArea(no.filhos_[i]);
			if (area < min) {
				no = no.filhos_[i];
			}
		}
	}
			
	no.inserirFilho(ret);

	caminhoArvoreBalanceado(ret);

}

vector<Retangulo> ArvoreR::camadaRecursivaArvore(vector<Retangulo> retLista, int nivel) {
	
	int numeroPais =  ceil(retLista.size() / maxNos_);
	vector<Retangulo> nivelNo;
	int contFilho = 0;

	for (int i = 0; i < numeroPais; i++) {
		Retangulo pai = Retangulo();
		contFilho = min(maxNos_, retLista.size());			
		for (int j = 0; j < contFilho; j++) {
			Retangulo aux = retLista.back();
			retLista.pop_back();
			pai.inserirFilho(aux);
		}
		nivelNo.push_back(pai);
	}
		
	if (numeroPais > 1) {
		return camadaRecursivaArvore(nivelNo, nivel + 1);
	} else {
		return nivelNo;
	}

}

vector<Entrada> ArvoreR::inserirLote(vector<Entrada> entLista) {
		
	vector<Retangulo> retLista; 
	
	for (int i = 0; i <= entLista.size(); i++)
		retLista.push_back(Retangulo(entLista[i].obterX(), entLista[i].obterY(), entLista[i].obterLargura(), entLista[i].obterAltura(), entLista[i].obterDado()));	

	int coordenadaMax = -MAX;
	int coordenadaMin = MAX;
	int x, y;

	for (int j = 0; j <= retLista.size(); j++) {
		x = ceil(retLista[j].obterX() + retLista[j].obterLargura()*0.5);
		y = ceil(retLista[j].obterY() + retLista[j].obterAltura()*0.5);
		coordenadaMax = max(coordenadaMax, max(x, y));
		coordenadaMin = min(coordenadaMin, min(x, y));
	}

	vector<Retangulo> ordenado; 
	Curvahilbert ch;
	for (int k = 0; k <= retLista.size(); k++) {
		int idx = ch.coordenadasHilbert(coordenadaMax-coordenadaMin, ceil(retLista[k].obterX() + retLista[k].obterLargura()*0.5) - coordenadaMin, ceil(retLista[k].obterY() + retLista[k].obterAltura()*0.5) - coordenadaMin);

	}
	
	vector<Retangulo> aux = camadaRecursivaArvore(ordenado, 1);

	raiz_ = aux[0];

}

void ArvoreR::caminhoArvoreBalanceado(Retangulo folha) {
	
	Retangulo no = folha;
	Retangulo* ptr = no.pai_;
	
	while ((!ptr) && (ptr->numeroFilhos() > maxNos_)) {
		
		no = *ptr;

		if (no != raiz_){
			ptr->removerFilho(no);
			vector<Retangulo> aux = no.dividirIrmaos();
			for (int i = 0; i < aux.size(); i++) {
				ptr->inserirFilho(aux[i]);
			}
		} else 
			if (no == raiz_) {
				vector<Retangulo> aux = no.dividirIrmaos();
				for (int i = 0; i < aux.size(); i++) {
					ptr->inserirFilho(aux[i]);
				}
			}
	}
}