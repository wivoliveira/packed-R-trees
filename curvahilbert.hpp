#ifndef __Curvahilbert_HPP__
#define __Curvahilbert_HPP__

class Curvahilbert
{
    public:

        Curvahilbert();
        
        ~Curvahilbert();

        double intercalarBitsHilbert(int impar, int par);
        
        double coordenadasHilbert(int coordenadaMax, int x, int y);        

};

#endif // __Curvahilbert_HPP__