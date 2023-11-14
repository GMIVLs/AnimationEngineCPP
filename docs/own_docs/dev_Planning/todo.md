# To do list

<!-- vim-markdown-toc GitLab -->

* [1. Math Module](#1-math-module)
    * [1.2 Vector in 2D space](#12-vector-in-2d-space)
        * [1.2.1 Computional vector](#121-computional-vector)
            * [1.2.1.1 Requirements](#1211-requirements)
            * [1.2.1.2 Example](#1212-example)
        * [1.2.2 Display Vector - later](#122-display-vector-later)

<!-- vim-markdown-toc -->

## 1. Math Module

### 1.2 Vector in 2D space

#### 1.2.1 Computional vector

- [x] Finish from your previous constructed class.
  - [ ] length : length of a vector in given units.
  - [ ] magnitude : (i.e., similar to length)
  - [ ] normalize : (vector lentgh = 1 unit)
  - [ ] rotate : (accept rotation)
  - [ ] dot product: (scalar value)
  - [ ] orthogonal : (the perpendicular component vector of a given 2d vector)
  - [ ] projection : (the horizontal component vector of a given 2d vector)
  - [ ] transition : (moving) (moving a vector **origin** from point A to point B)
  - [ ] refelction : given a vector angle create the refelection.
  - [ ] need for vector print operator (<<).

##### 1.2.1.1 Requirements

1. The object should be constructed either on the heap or stack, using smart
   pointers is recommended.
2. It should allow for creating a new vector through an operation. Each method
   that requires this operation should have a distinguishable name, either
   `immutable::add` to create a new vector, or `in_place` to alter the input vector
   (usually the first vector if two vector inputs are required).

##### 1.2.1.2 Example

- For just sharing the idea, we don't follow this style, as we will focus more
  on `template` 2d vector.

```cpp
// Our regular class in 2d-space,
class Vector2D {
private:
    double x;
    double y;

public:
    // Constructor
    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {
        std::cout << "Vector constructed.\n";
    }

    // Destructor
    ~Vector2D() {
        std::cout << "Vector destructed.\n";
    }

    // Getter methods
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    // Setter methods
    void setX(double x_val) {
        x = x_val;
    }

    void setY(double y_val) {
        y = y_val;
    }

    // Method to add another vector and alter this vector
    void add(const Vector2D& other) {
        x += other.x;
        y += other.y;
    }
};

namespace immutable {
    class Vector2D {
    private:
        double x;
        double y;

    public:
        // Constructor
        Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

        // Getter methods
        double getX() const {
            return x;
        }

        double getY() const {
            return y;
        }

        // Static method to add two vectors and return a new one
        static Vector2D add(const Vector2D& a, const Vector2D& b) {
            return Vector2D(a.x + b.x, a.y + b.y);
        }
    };
}


int main(){
    // mutable class
    Vector2D vec1(1.0, 2.0);
    // Immutable
    // Creating a new vector by adding two immutable vectors
    immutable::Vector2D vec3(1.0, 2.0);
    }

```

#### 1.2.2 Display Vector - later

In this case, let's create a new class that inherits from the `basics` class to
construct another class called `Computational2DVector`. This class will allow
us to display an arrow in two-dimensional space.
