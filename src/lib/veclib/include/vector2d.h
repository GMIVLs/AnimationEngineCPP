//////////////////////////////////////
// vector2d.h header file is a part //
// of the graphic engine by use the //
//  SDL library and cpp. this file  //
//  will inherit from the vect.h    //
// templated type class can accepet //
// various type of primitive data.  //
//////////////////////////////////////

#ifndef _VECTOR_2D_H_
#define _VECTOR_2D_H_
// the base class for the vector2d header file.
#include "vect.h"
// using of templated type class
template <class Gtype>
class vector2d : public vect<Gtype> {
public:
    // vector2d class constructor
    vector2d();
    vector2d(Gtype, Gtype);
    // vector2d class destructor
    ~vector2d();
    // vector2d class copy constructor
    vector2d(const vector2d&);

    // class operator overload
    vector2d operator+(vector2d&);
    vector2d operator()(Gtype, Gtype);

    // class methods for vector 2D math
    vector2d add(const vector2d&);
    vector2d sub(const vector2d&);
    vector2d multi(const Gtype&);
    vector2d divide(const vector2d&);
    vector2d divide(const Gtype&);
    Gtype dot(const vector2d&);

private:
    // int id{};  // created objects ID#
};
#endif  // _VECTOR_2D_H_
