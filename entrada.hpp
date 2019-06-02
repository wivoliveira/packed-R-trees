#ifndef __Entrada_HPP__
#define __Entrada_HPP__

class Entrada
{
    public:

        Entrada(float x, float y, float largura, float altura, int dado);
        
        ~Entrada();
        
    private:

        float x_;

        float y_;

        float largura_;

        float altura_;

        int dado_;

};

#endif // __Entrada_HPP__