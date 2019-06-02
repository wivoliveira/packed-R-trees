#ifndef __Entrada_HPP__
#define __Entrada_HPP__

class Entrada
{
    public:

        Entrada(float x, float y, float width, float height, int data);
        
        ~Entrada();
        
    private:

        float x_;

        float y_;

        float width_;

        float height_;

        int data_;

};

#endif // __Entrada_HPP__