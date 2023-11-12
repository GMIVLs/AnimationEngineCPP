// ////////////////////////////////////
// This class is part of the Graphic //
// engine using the c++ with the SDL //
// libraray.                         //
// vect.h                            //
// is a header file for the vector   //
// math, this file contain a define  //
// of vect class define some methods //
// that will inherited by other lib  //
// in the engine like vector 2d & 3d //
///////////////////////////////////////

#ifndef _VECT_H_
#define _VECT_H_
//
// vector base class definition
//
#include <ostream>
template <class Gtype>
class vect
{
  friend std::ostream& operator<<(std::ostream& os, const vect& v)
  {
    if (v.verbose)
      os << "Vector:[" << v.id << "] " << v.get_x() << "i+" << v.get_y() << "j";
    else
      os << "Vector:[" << v.id << "] <" << v.get_x() << "," << v.get_y() << ">";
    return os;
  }

 public:
  // class constructors definitaion
  vect();
  vect(Gtype, Gtype);

  // class destructor definition
  ~vect();

  // public getters methods for x and y
  Gtype get_x() const;
  Gtype get_y() const;
  int get_counter() const;
  int get_id() const;

  // public setters methods for x and y
  void set_x(Gtype);
  void set_y(Gtype);
  void set_active();
  void set_id(int);

  // virtual display method may re-
  // define by other vectors class
  virtual void display() const;

 protected:
  Gtype x{};           // x coordinate of the vector
  Gtype y{};           // y coordinate of the vector
  static int counter;  // Created Objects Counter
  int id{0};
  bool verbose{false};  // var to indicate object active or inactive
};

#endif  // !_VECT_H_
