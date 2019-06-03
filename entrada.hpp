#ifndef __Entrada_HPP__
#define __Entrada_HPP__

class Entrada
{
    public:

        Entrada(int x, int y, int largura, int altura, int dado);
        
        ~Entrada();

        int obterX();

        int obterY();

        int obterLargura();

        int obterAltura();

        int obterDado();
        
    private:

        int x_;

        int y_;

        int largura_;

        int altura_;

        int dado_;

};

#endif // __Entrada_HPP__