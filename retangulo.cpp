#include "retangulo.hpp"
#include <limits>
#include <math.h>
#include <algorithm>  

using namespace std;

const double MAX = numeric_limits<double>::max();

Retangulo::Retangulo(double x, double y, double largura, double altura, int dado) {

    x_ = x;
    y_ = y;
    largura_ = largura;
    altura_ = altura;
    dado_ = dado;

}

Retangulo::~Retangulo() {
    
}

Retangulo Retangulo::gerarNoVazio()  {
    
    return Retangulo(MAX, MAX, 0, 0, 0);

}

bool Retangulo::sobrepoe(Retangulo ret) { 
    
    return x_ < ret.x_ + ret.largura_ && x_ + largura_ > ret.x_ && y_ + altura_ > ret.y_ && ret.y_ + ret.altura_ > y_;

}

bool Retangulo::contem(Retangulo ret) {
    
    return x_ <= ret.x_ && x_ + largura_ >= ret.x_ + ret.largura_ && y_ <= ret.y_ && y_ + altura_ >= ret.y_ + ret.altura_;

}

void Retangulo::aumentaRetangulo(Retangulo ret) {
    	
    if (x_ == MAX){
    	altura_ = ret.altura_;
	    largura_ = ret.largura_;
	    x_ = ret.x_;
	    y_ = ret.y_;
    } else {
        altura_ = max(y_ + altura_, ret.y_ + ret.altura_) - min(y_, ret.y_);
	    largura_ = max(x_ + largura_, ret.x_ + ret.largura_) - min(x_, ret.x_);
	    x_ = min(x_, ret.x_);
	    y_ = min(y_, ret.y_);
    }

}

double Retangulo::acrescimoArea(Retangulo ret) {

    if (x_ == MAX ){
        return ret.altura_ * ret.largura_;
    }
    else {
    	return (max(y_ + altura_, ret.y_ + ret.altura_) - min(y_, ret.y_)) * (max(x_ + largura_, ret.x_ + ret.largura_) - min(x_, ret.x_)) - getArea();
    }
    
}

double Retangulo::obterArea() {

    return altura_ * largura_;

}