#include "curvahilbert.hpp"
#include <math.h>
#include <algorithm>

using namespace std;

Curvahilbert::Curvahilbert() { }

Curvahilbert::~Curvahilbert() { }

double coordenadasHilbert(int coordenadaMax, int x, int y) {
        
    int mascara = (1 << coordenadaMax) - 1;
    int hilbertImpar = 0;
    int hilbertPar = x ^ y;
    int negX = ~x & mascara;
    int negY = ~y & mascara;

    int tmp = negX^y;

    int v0 = 0;
    int v1 = 0;
    
    for(int i = 1; i < coordenadaMax; i++) {
        v1 = ((v1 & hilbertPar) | ((v0 ^ negY) & tmp)) >> 1;
        v0 = ((v0 & (v1 ^ negX)) | (~v0 & (v1 ^ negY))) >> 1;
    }

    hilbertImpar = (~v0 & (v1 ^ x)) | (v0 & (v1 ^ negY));

    return intercalarBitsHilbert(hilbertImpar, hilbertPar);

}

double intercalarBitsHilbert(int impar, int par) {

    int val = 0;
    int maximo = max(impar, par);
    int n = 0;
    while (maximo > 0) {
        n++;
        maximo >>= 1;
    }

    for (int i = 0; i < n; i++) {
        int mascara = 1 << i;
        int a = (par & mascara) > 0 ? (1 << (2*i)) : 0;
        int b = (impar & mascara) > 0 ? (1 << (2*i+1)) : 0;
        val += a + b;
    }

    return val;

}
