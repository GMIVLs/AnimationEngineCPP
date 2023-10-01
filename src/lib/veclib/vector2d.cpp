//
//  vector2d.cpp
//  vector2d
//
//  Created by Mohammed A. Alameedi on 7/17/23.
//

#include "vector2d.h"

template <class Ttype> vector2d<Ttype>::vector2d(Ttype x_coord, Ttype y_coord) {
  this->x_coord = x_coord;
  this->y_coord = y_coord;
}
/*
    function temp
*/
template <class Ttype> vector2d<Ttype>::~vector2d() {}

template <class Ttype> void vector2d<Ttype>::set_x(Ttype x_coord) {
  this->x_coord = x_coord;
}

template <class Ttype> void vector2d<Ttype>::set_y(Ttype y_coord) {
  this->y_coord = y_coord;
}

template <class Ttype> Ttype vector2d<Ttype>::get_x() const { return x_coord; }

template <class Ttype> Ttype vector2d<Ttype>::get_y() const { return y_coord; }

template <class Ttype>
vector2d<Ttype> vector2d<Ttype>::operator+(vector2d<Ttype> vect) {
  return vector2d<Ttype>(this->x_coord + vect.x_coord,
                         this->y_coord + vect.y_coord);
}

template <class Ttype>
vector2d<Ttype> vector2d<Ttype>::operator-(vector2d<Ttype> vect) {
  return vector2d<Ttype>(this->x_coord - vect.x_coord,
                         this->y_coord - vect.y_coord);
}

template <class Ttype>
vector2d<Ttype> vector2d<Ttype>::operator*(Ttype scaler) {
  return vector2d<Ttype>(this->x_coord * scaler, this->y_coord * scaler);
}

template <class Ttype>
vector2d<Ttype> vector2d<Ttype>::add(vector2d<Ttype> vect) {
  return vector2d<Ttype>(this->x_coord + vect.x_coord,
                         this->y_coord + vect.y_coord);
}

template <class Ttype>
vector2d<Ttype> vector2d<Ttype>::sub(vector2d<Ttype> vect) {
  return vector2d<Ttype>(this->x_coord - vect.x_coord,
                         this->y_coord - vect.y_coord);
}

template <class Ttype> vector2d<Ttype> vector2d<Ttype>::multi(Ttype scaler) {
  return vector2d<Ttype>(this->x_coord * scaler, this->y_coord * scaler);
}
