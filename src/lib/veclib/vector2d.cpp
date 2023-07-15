#include<iostream>
#include"vector2d.h"
using namespace std;

namespace vector_engine
{
    vector2d::vector2d(V* x_coordinate = NULL,  V* y_coordinate = NULL)
    {
        this->x_coordinate = x_coordinate;
        this->y_coordinate = y_coordinate;
    }
    vector2d::vector2d operator+(vector2d vector1)
    {
        vector2d* sum(0,0);
        sum.x_coordinate = this->x_coordinate + vector1.x_coordinate;
        sum.y_coordinate = this->y_coordinate + vector1.y_coordinate;
        return sum;
    }
    vector2d::~vector2d()
    {
        delete (x_coordinate);
        delete (y_coordinate);
    }
}