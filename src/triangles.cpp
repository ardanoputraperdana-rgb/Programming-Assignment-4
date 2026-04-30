#include <iostream>
#include <math.h>

#include "include/triangles.hpp"

namespace sim {

    
    float jarak(Point2D a, Point2D b) {
        float dx = a.GetX() - b.GetX();
        float dy = a.GetY() - b.GetY();
        float dz = a.GetZ() - b.GetZ();
        return sqrt(dx*dx + dy*dy + dz*dz);
    }

    Triangle::Triangle() { }

    Triangle::Triangle(Point2D t1, Point2D t2, Point2D t3) {
        _t1 = t1;
        _t2 = t2;
        _t3 = t3;
    }

    void Triangle::SetT1(Point2D t1) { _t1 = t1; }
    void Triangle::SetT2(Point2D t2) { _t2 = t2; }
    void Triangle::SetT3(Point2D t3) { _t3 = t3; }

    void Triangle::TriangleType() {
        float a = jarak(_t1, _t2);
        float b = jarak(_t2, _t3);
        float c = jarak(_t1, _t3);

        auto hampirSama = [](float x, float y) {
            return abs(x - y) < 0.001f;
        };

        if (hampirSama(a, b) && hampirSama(b, c)) {
            std::cout << "sama sisi" << std::endl;
        }
       
        else if (abs(a*a + b*b - c*c) < 0.001 ||
                abs(a*a + c*c - b*b) < 0.001 ||
                abs(b*b + c*c - a*a) < 0.001) {
            std::cout << "siku-siku" << std::endl;
        }
        
        else if (hampirSama(a, b) || hampirSama(b, c) || hampirSama(a, c)) {
            std::cout << "sama kaki" << std::endl;
        }
        
        else {
            std::cout << "sembarang" << std::endl;
        }
    }

}