#include "../include/vector2d.h"

#include <iostream>

#include "../include/vect.h"

template <class Gtype>
vector2d<Gtype>::vector2d()
    : vect<Gtype>() {}

template <class Gtype>
vector2d<Gtype>::vector2d(Gtype x, Gtype y)
    : vect<Gtype>(x, y) {}

template <class Gtype>
vector2d<Gtype>::vector2d(const vector2d<Gtype>& v)
    : vect<Gtype>(v.x, v.y) {}

template <class Gtype>
vector2d<Gtype>::~vector2d() {}

template <class Gtype>
vector2d<Gtype> vector2d<Gtype>::operator+(vector2d<Gtype>& v) {
    return vector2d<Gtype>(this->x + v.x, this->y + v.y);
}

template <class Gtype>
vector2d<Gtype> vector2d<Gtype>::add(const vector2d<Gtype>& v) {
    return vector2d<Gtype>(this->x + v.x, this->y + v.y);
}

template <class Gtype>
vector2d<Gtype> vector2d<Gtype>::sub(const vector2d<Gtype>& v) {
    return vector2d<Gtype>(this->x - v.x, this->y - v.y);
}

template <class Gtype>
vector2d<Gtype> vector2d<Gtype>::multi(const Gtype& scaler) {
    return vector2d<Gtype>(this->x * scaler, this->y * scaler);
}

template <class Gtype>
vector2d<Gtype> vector2d<Gtype>::divide(const Gtype& scaler) {
    return vector2d<Gtype>(this->x / scaler, this->y / scaler);
}

template <class Gtype>
vector2d<Gtype> vector2d<Gtype>::divide(const vector2d<Gtype>& v) {
    return vector2d<Gtype>(this->x / v.x, this->y / v.y);
}

template <class Gtype>
Gtype vector2d<Gtype>::dot(const vector2d<Gtype>& v) {
    return (this->x * v.x + this->y * v.y);
}
template class vector2d<double>;
template class vector2d<float>;
template class vector2d<int>;
