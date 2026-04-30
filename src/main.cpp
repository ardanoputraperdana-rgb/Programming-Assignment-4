#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "include/point2d.hpp"
#include "include/triangles.hpp"

using namespace std;
using namespace sim;

int main(int argc, char ** argv)
{
    vector<Triangle> triangles;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        float x1, y1, z1;
        float x2, y2, z2;
        float x3, y3, z3;

        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        cin >> x3 >> y3 >> z3;

        Point2D t1(x1, y1, z1);
        Point2D t2(x2, y2, z2);
        Point2D t3(x3, y3, z3);

        Triangle tri(t1, t2, t3);
        triangles.push_back(tri);
    }

    for (int i = 0; i < triangles.size(); i++) {
        triangles[i].TriangleType();
    }

    return 0;
}