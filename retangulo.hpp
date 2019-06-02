#ifndef __Retangulo_HPP__
#define __Retangulo_HPP__

class Retangulo
{
    public:

        Retangulo(double x, double y, double largura, double altura, int dado);
        
        ~Retangulo();

        Retangulo* filhos_;

        Retangulo* pai_;

        Retangulo gerarNoVazio();

        bool sobrepoe(Retangulo ret);

        bool contem(Retangulo ret);

        void aumentaRetangulo(Retangulo ret);

        double acrescimoArea(Retangulo ret);

        double obterArea();

        Retangulo* dividirIrmaos();
        
        int numeroFilhos();

        bool noFolha();

        bool temNoFolha();

        void inserirFilho(Retangulo ret);

        void removerFilho(Retangulo ret);

        Retangulo* obtemSubArvore();

    private:

        double x_;

        double y_;

        double largura_;

        double altura_;

        int dado_;

};

#endif // __Retangulo_HPP__