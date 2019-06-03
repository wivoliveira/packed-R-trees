#ifndef __Retangulo_HPP__
#define __Retangulo_HPP__

const unsigned int N = 100000;

class Retangulo
{
    public:

        Retangulo();
        
        Retangulo(int x, int y, int largura, int altura, int dado);
        
        ~Retangulo();

        vector <Retangulo> filhos_;

        Retangulo* pai_;

        bool operator==(const Retangulo &ret) const;

        bool operator!=(const Retangulo& ret) const;

        bool sobrepoe(Retangulo ret);

        bool contem(Retangulo ret);

        void aumentaRetangulo(Retangulo ret);

        double acrescimoArea(Retangulo ret);

        double obterArea();

        double obterX();

        double obterY();

        double obterLargura();

        double obterAltura();

        int obterDado();

        vector<Retangulo> dividirIrmaos();
        
        size_t numeroFilhos();

        bool noFolha();

        bool temNoFolha();

        void inserirFilho(Retangulo ret);

        void removerFilho(Retangulo ret);

        vector<Retangulo> obterSubArvore();

    private:

        int x_;

        int y_;

        int largura_;

        int altura_;

        int dado_;

};

#endif // __Retangulo_HPP__