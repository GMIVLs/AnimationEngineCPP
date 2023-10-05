 /********************************************
 * Vector_2d.h is a header file contain, a   *
 * the class definetion of vector object in  *
 * 2d plane. This header written as a part   *
 * of 2d game-engine of Animation Project in *
 * github.                                   *
 * https://github/Ghasak/AnimationEngineCPP  *
 * (c) Copyright                             *
 ********************************************/

#ifndef _VECTOR_2D_H_
#define _VECTOR_2D_H_

template <class Ttype> class Vector_2d {

public:
  Vector_2d();                                  // Vector 2d Default Constructor
  explicit Vector_2d(Ttype, Ttype);             // Vector 2d Constructor
  Vector_2d(const Vector_2d&);                  // Vector 2d Copy Constructor
  Vector_2d(Vector_2d&&) noexcept;              // Vector 2d Move Constructor
  ~Vector_2d();                                 // Vector 2d Destructor

  void set_x(Ttype);                            // X Coordinate Set Method
  void set_y(Ttype);                            // Y Coordinate Set Method
  Ttype get_x() const;                          // X Coordinate Get Method
  Ttype get_y() const;                          // Y Coordinate Get Method

  Vector_2d operator+(const Vector_2d&) const; // (+) Operator Overload
  Vector_2d operator-(const Vector_2d&) const; // (-) Operator Overload
  Vector_2d operator*(const Ttype&) const;     // (x) Operator Overload

  Vector_2d add(const Vector_2d&) const;       // Two Vectors (add) Method
  Vector_2d sub(const Vector_2d&) const;       // Two Vectors (sub) Method
  Vector_2d multi(const Ttype&)const;          // Two Vectors (multi) Method

  void display() const;

private:
  Ttype x_coord;                                // X Coordinate Value
  Ttype y_coord;                                // Y Coordinate Value
};

#endif // _VECTOR_2D_H_

// Explicit Template Instantiation
/* template class Vector_2d<int>;    // Integer Instantiation */
/* template class Vector_2d<double>; // Double Instantiation */
/* template class Vector_2d<float>;  // Float Instantiation */
