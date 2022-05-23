#include <vector>
#include <cstdio>
#include <iostream>
#include "include/delaunator.hpp"

int main()
{
    std::vector<double> coords = {-1, 1, //x0,y0
                                   1,  1,
                                   1, -1,
                                  -1, -1};

    // Triangulation happens here
    delaunator::Delaunator delauney(coords);

    size_t triangleCount = 1;
    size_t pointCount = 0;
    for (const auto &triangle : delauney.triangles)
    {
        if (pointCount == 0)
        {
            std::cout << "Triangle #" << triangleCount << std::endl;
        }

        std::cout << "X =" << coords[2 * triangle] << " ; Y =" << coords[2 * triangle + 1] << std::endl;
        pointCount++;

        if (pointCount == 3)
        {
            triangleCount++;
            pointCount = 0;
            std::cout << "\n===========\n"
                      << std::endl;
        }
    }

    return 0;
}