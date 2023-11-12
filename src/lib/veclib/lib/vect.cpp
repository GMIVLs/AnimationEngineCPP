//////////////////////////////////////////
// vect.cpp file implementation for the//
// vect.h header file of the engine of //
// graphic project by the sdl library //
///////////////////////////////////////

#include "../include/vect.h"

#include <iostream>

// objects counter initializing
template <class Gtype>
int vect<Gtype>::counter = 0;

// defenetion of the vect constructors
template <class Gtype>
vect<Gtype>::vect()
    : x{},
      y{} {
    ++counter;
    id = counter;
    verbose = false;
}
template <class Gtype>
vect<Gtype>::vect(Gtype x, Gtype y)
    : x{x},
      y{y} {
    ++counter;
    id = counter;
    verbose = false;
}
// defenetion of the class destructor
template <class Gtype>
vect<Gtype>::~vect() {
    if (verbose)
        std::cout << "Vector:[" << id << "]"
                  << ", was deleted successfully" << '\n';
}
// defenetion of the getters methods
template <class Gtype>
Gtype vect<Gtype>::get_x() const {
    return this->x;
}
template <class Gtype>
Gtype vect<Gtype>::get_y() const {
    return this->y;
}

template <class Gtype>
int vect<Gtype>::get_counter() const {
    return this->counter;
}

template <class Gtype>
int vect<Gtype>::get_id() const {
    return this->id;
}
// define of the setters methods
template <class Gtype>
void vect<Gtype>::set_x(Gtype x_cord) {
    this->x = x_cord;
}
template <class Gtype>
void vect<Gtype>::set_y(Gtype y_cord) {
    this->y = y_cord;
}

template <class Gtype>
void vect<Gtype>::set_active() {
    verbose = true;
}

template <class Gtype>
void vect<Gtype>::set_id(int new_id) {
    this->id = new_id;
}
// defenetion of the display method of the vector
template <class Gtype>
void vect<Gtype>::display() const {
    std::cout << "Vector is [ " << this->get_x() << " : " << this->get_y() << " ]" << std::endl;
}

// instantation of the class to work with different primetive data type
template class vect<double>;
template class vect<float>;
template class vect<int>;
