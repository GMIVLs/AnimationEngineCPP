/********************************************
 * Vector_2d.cpp is an implementation file   *
 * of the class definetion of vector object  *
 * in 2d plane. This file written as a part  *
 * of 2d game-engine of Animation Project in *
 * github.                                   *
 * https://github/Ghasak/AnimationEngineCPP  *
 * (c) Copyright                             *
 ********************************************/
#include <iostream>
#include "Vector_2d.h"

/**
 * Constructor Part of the class Vector_2d
 */

template <class Ttype>
Vector_2d<Ttype>::Vector_2d()
    : x_coord{0}, y_coord{0} {}; // Default Constructor

template <class Ttype>
Vector_2d<Ttype>::Vector_2d(Ttype x_coord, Ttype y_coord)
    : x_coord(x_coord), y_coord(y_coord) {} // Constructor with Args

template <class Ttype>
Vector_2d<Ttype>::Vector_2d(const Vector_2d &lhs)
    : x_coord(lhs.x_coord), y_coord(lhs.y_coord) {} // Copy Constructor

template <class Ttype>
Vector_2d<Ttype>::Vector_2d(Vector_2d &&vect) noexcept
    : x_coord(vect.x_coord), y_coord(vect.y_coord) // Move Constructor
{
  vect.x_coord = 0;
  vect.y_coord = 0;
}

template <class Ttype> Vector_2d<Ttype>::~Vector_2d() {} // Destructor

/**
 * Sets, and Get2 methods part for Vector (x,y) Coordinates.
 */

template <class Ttype>
void Vector_2d<Ttype>::set_x(Ttype x_coord) { // X Setter Method
  this->x_coord = x_coord;
}

template <class Ttype>
void Vector_2d<Ttype>::set_y(Ttype y_coord) { // Y Setter Method
  this->y_coord = y_coord;
}

template <class Ttype> Ttype Vector_2d<Ttype>::get_x() const {
  return x_coord;
} // X Getter Method

template <class Ttype> Ttype Vector_2d<Ttype>::get_y() const {
  return y_coord;
} // Y Getter Method

/**
 * Operator Overloads part for 2d Vector
 */

template <class Ttype>
Vector_2d<Ttype> Vector_2d<Ttype>::operator+(
    const Vector_2d<Ttype> &vect) const { // (+) Operator Overload
  return Vector_2d<Ttype>(this->x_coord + vect.x_coord,
                          this->y_coord + vect.y_coord);
}

template <class Ttype>
Vector_2d<Ttype> Vector_2d<Ttype>::operator-(
    const Vector_2d<Ttype> &vect) const { // (-) Operator Overload
  return Vector_2d<Ttype>(this->x_coord - vect.x_coord,
                          this->y_coord - vect.y_coord);
}

template <class Ttype>
Vector_2d<Ttype> Vector_2d<Ttype>::operator*(
    const Ttype &scaler) const { // (x) Operator Overload
  return Vector_2d<Ttype>(this->x_coord * scaler, this->y_coord * scaler);
}

/**
 * add, sub, multi Methods part for the 2d Vector
 */

template <class Ttype>
Vector_2d<Ttype>
Vector_2d<Ttype>::add(const Vector_2d<Ttype> &vect) const { // (add) Method
  return Vector_2d<Ttype>(this->x_coord + vect.x_coord,
                          this->y_coord + vect.y_coord);
}

template <class Ttype>
Vector_2d<Ttype>
Vector_2d<Ttype>::sub(const Vector_2d<Ttype> &vect) const { // (sub) Method
  return Vector_2d<Ttype>(this->x_coord - vect.x_coord,
                          this->y_coord - vect.y_coord);
}

template <class Ttype>
Vector_2d<Ttype>
Vector_2d<Ttype>::multi(const Ttype &scaler) const { // (multi) Method
  return Vector_2d<Ttype>(this->x_coord * scaler, this->y_coord * scaler);
}

template <class Ttype> void Vector_2d<Ttype>::display() const {
  std::cout << "The Vector is: (" << this->get_x() << "," << this->get_y()
            << ")" << '\n';
}

// Explicit Template Instantiation
template class Vector_2d<int>;    // Integer Instantiation
template class Vector_2d<double>; // Double Instantiation
template class Vector_2d<float>;  // Float Instantiation

