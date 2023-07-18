//
//  vector2d.h
//  vector2d
//
//  Created by Mohammed A. Alameedi on 7/17/23.
//

#ifndef vector2d_h
#define vector2d_h

template<class Ttype>
class vector2d
{
public:
    // Class Vector Definetion
    explicit vector2d(Ttype,Ttype);
    ~vector2d();
    //Vector set and get methods
    void set_x(Ttype);
    void set_y(Ttype);
    Ttype get_x() const;
    Ttype get_y() const;
    //Vector operator overload
    vector2d operator+(vector2d vector);
    vector2d operator-(vector2d vector);
    vector2d operator*(Ttype scaler);
    //Vector methods
    vector2d add(vector2d vector);
    vector2d sub(vector2d vector);
    vector2d multi(Ttype scaler);
private:
    //Definetion of Private Varibles of type Ttype
    Ttype x_coord;
    Ttype y_coord;
};
#endif /* vector2d_h */

