#ifndef __Entrada_HPP__
#define __Entrada_HPP__

class Entrada
{
    public:

        Entrada(double x, double y, double largura, double altura, int dado);
        
        ~Entrada();

        double obterX();

        double obterY();

        double obterLargura();

        double obterAltura();

        int obterDado();
        
    private:

        double x_;

        double y_;

        double largura_;

        double altura_;

        int dado_;

};

#endif // __Entrada_HPP__