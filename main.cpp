#include <iostream>
#include <ctime>

/*#include "arvorer.hpp"*/
#include "retangulo.hpp"
#include "entrada.hpp"

using namespace std;

int main() {

    cout << "Inicializar Entrada!" << endl;

    // Definindo a interface de entrada um a um
    clock_t beginEnA = clock();
    Entrada enA = Entrada(1, 1, 2, 2, 4);
    clock_t endEnA = clock();
    double elapsedSecsEnA = double(endEnA - beginEnA) / CLOCKS_PER_SEC;
    cout << "Entrada A - tempo: " << elapsedSecsEnA << " segundos!" << endl;

    clock_t beginEnB = clock();
    Entrada enB = Entrada(2, 4, 1, 4, 4);
    clock_t endEnB = clock();
    double elapsedSecsEnB = double(endEnB - beginEnB) / CLOCKS_PER_SEC;
    cout << "Entrada B - tempo: " << elapsedSecsEnB << " segundos!" << endl;

    clock_t beginEnC = clock();
    Entrada enC = Entrada(5, 3, 3, 2, 6);
    clock_t endEnC = clock();
    double elapsedSecsEnC = double(endEnC - beginEnC) / CLOCKS_PER_SEC;
    cout << "Entrada C - tempo: " << elapsedSecsEnC << " segundos!" << endl;

    clock_t beginEnD = clock();
    Entrada enD = Entrada(6, 0, 1, 1, 1);
    clock_t endEnD = clock();
    double elapsedSecsEnD = double(endEnD - beginEnD) / CLOCKS_PER_SEC;
    cout << "Entrada D - tempo: " << elapsedSecsEnD << " segundos!" << endl;

    cout << "Entrada - tempo médio: " << (elapsedSecsEnA+elapsedSecsEnB+elapsedSecsEnC+elapsedSecsEnD)/4 << " segundos!" << endl;

    // Definindo tipo de entrada para a RTree um a um
    clock_t beginRetA = clock();
    Retangulo retA = Retangulo(enA.obterX(), enA.obterY(), enA.obterLargura(), enA.obterAltura(), enA.obterDado());
    clock_t endRetA = clock();
    double elapsedSecsRetA = double(endRetA - beginRetA) / CLOCKS_PER_SEC;
    cout << "Retangulo A - tempo: " << elapsedSecsRetA << " segundos!" << endl;

    clock_t beginRetB = clock();
    Retangulo retB = Retangulo(enB.obterX(), enB.obterY(), enB.obterLargura(), enB.obterAltura(), enB.obterDado());
    clock_t endRetB = clock();
    double elapsedSecsRetB = double(endRetB - beginRetB) / CLOCKS_PER_SEC;
    cout << "Retangulo B - tempo: " << elapsedSecsRetB << " segundos!" << endl;

    clock_t beginRetC = clock();
    Retangulo retC = Retangulo(enC.obterX(), enC.obterY(), enC.obterLargura(), enC.obterAltura(), enC.obterDado());
    clock_t endRetC = clock();
    double elapsedSecsRetC = double(endRetC - beginRetC) / CLOCKS_PER_SEC;
    cout << "Retangulo C - tempo: " << elapsedSecsRetC << " segundos!" << endl;

    clock_t beginRetD = clock();
    Retangulo retD = Retangulo(enD.obterX(), enD.obterY(), enD.obterLargura(), enD.obterAltura(), enD.obterDado());
    clock_t endRetD = clock();
    double elapsedSecsRetD = double(endRetD - beginRetD) / CLOCKS_PER_SEC;
    cout << "Retangulo D - tempo: " << elapsedSecsRetD << " segundos!" << endl;

    cout << "Retangulo - tempo médio: " << (elapsedSecsRetA+elapsedSecsRetB+elapsedSecsRetC+elapsedSecsRetD)/4 << " segundos!" << endl;

    

    return 0;
}