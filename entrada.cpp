#include "entrada.hpp"

using namespace std;

Entrada::Entrada(double x, double y, double largura, double altura, int dado) {

    x_ = x;
    y_ = y;
    largura_ = largura;
    altura_ = altura;
    dado_ = dado;

}

Entrada::~Entrada() {
    
}

double Entrada::obterX() {
    return x_;
}

double Entrada::obterY() {
    return y_;
}

double Entrada::obterLargura() {
    return largura_;
}

double Entrada::obterAltura() {
    return altura_;
}

int Entrada::obterDado() {
    return dado_;
}