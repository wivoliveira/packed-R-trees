#include <iostream>
#include "entrada.hpp"

using namespace std;

Entrada::Entrada(int x, int y, int largura, int altura, int dado) {

    x_ = x;
    y_ = y;
    largura_ = largura;
    altura_ = altura;
    dado_ = dado;

}

Entrada::~Entrada() {

    cout << "Entrada destruida!" << endl;
    
}

int Entrada::obterX() {
    return x_;
}

int Entrada::obterY() {
    return y_;
}

int Entrada::obterLargura() {
    return largura_;
}

int Entrada::obterAltura() {
    return altura_;
}

int Entrada::obterDado() {
    return dado_;
}