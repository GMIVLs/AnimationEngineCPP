#pragma once

namespace vector_engine
{
template<class V>
class vector2d
{
    private:
    V* x_coordinate, y_coordinate;
    public:
    vector2d(V*,V*);
    vector2d operator+(V*);
};
}