# How to create a matrix on stack

<!-- vim-markdown-toc GitLab -->

* [All matrix elements combination](#all-matrix-elements-combination)
* [Matrix multiplication and matrix element wise operations](#matrix-multiplication-and-matrix-element-wise-operations)
* [List libraries to deal with linear algebra and vectors, matrices in cpp](#list-libraries-to-deal-with-linear-algebra-and-vectors-matrices-in-cpp)
* [How about optimization libraries that has algorithms to maximize the likelihood for login model for example ?](#how-about-optimization-libraries-that-has-algorithms-to-maximize-the-likelihood-for-login-model-for-example-)
* [Request](#request)
* [A basic implementation of Linear Regression using Eigen.](#a-basic-implementation-of-linear-regression-using-eigen)
* [Maximum Likelihood Estimation](#maximum-likelihood-estimation)
* [Optimization Techniques to Estimate The Maximum Likelihood Parameters](#optimization-techniques-to-estimate-the-maximum-likelihood-parameters)

<!-- vim-markdown-toc -->

In C++, you can create a matrix (2D array) on the stack using fixed sizes. Here's an example:

```cpp
#include <iostream>

int main() {
    // Create a 3x3 matrix
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Print the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

This will print:

```
1 2 3
4 5 6
7 8 9
```

This approach works for small fixed-size matrices. If you're not sure about the
size at compile time, or if the matrix can be large, you may consider using the
heap or utilizing data structures like `std::vector` for dynamic sizing.

## All matrix elements combination

Like diagonal, lower tringle, upper triangle, off diagonal and all other variations dont skip anything

Certainly! Let's go through each of the combinations of matrix elements you mentioned:

Assuming we have an \(n \times n\) matrix named `matrix`:

1. **Main Diagonal**:
   Elements for which row index is equal to column index.

   ```cpp
   for (int i = 0; i < n; i++) {
       std::cout << matrix[i][i] << " ";
   }
   ```

2. **Secondary Diagonal** (or anti-diagonal):
   Elements for which row index and column index sum up to \(n-1\).

   ```cpp
   for (int i = 0; i < n; i++) {
       std::cout << matrix[i][n - i - 1] << " ";
   }
   ```

3. **Upper Triangle**:
   Elements for which row index is less than column index.

   ```cpp
   for (int i = 0; i < n; i++) {
       for (int j = i + 1; j < n; j++) {
           std::cout << matrix[i][j] << " ";
       }
   }
   ```

4. **Lower Triangle**:
   Elements for which row index is greater than column index.

   ```cpp
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < i; j++) {
           std::cout << matrix[i][j] << " ";
       }
   }
   ```

5. **Off Diagonal**:
   Every element that is not on the main diagonal.

   ```cpp
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           if (i != j) {
               std::cout << matrix[i][j] << " ";
           }
       }
   }
   ```

6. **Strict Upper Triangle**:
   Upper triangle excluding the main diagonal.

   ```cpp
   for (int i = 0; i < n; i++) {
       for (int j = i + 1; j < n; j++) {
           std::cout << matrix[i][j] << " ";
       }
   }
   ```

7. **Strict Lower Triangle**:
   Lower triangle excluding the main diagonal.
   ```cpp
   for (int i = 1; i < n; i++) {
       for (int j = 0; j < i; j++) {
           std::cout << matrix[i][j] << " ";
       }
   }
   ```

All the above combinations are for square matrices (where number of rows equals
number of columns). Some of these terms might differ slightly depending on
context or literature, but these are the general definitions and
implementations in C++.

## Matrix multiplication and matrix element wise operations

Sure, let's walk through matrix multiplication and element-wise operations:

1. **Matrix Multiplication**:
   For two matrices `A` and `B` to be multiplied, the number of columns in `A`
   must be equal to the number of rows in `B`. The result of the multiplication is
   a matrix `C` with the number of rows of `A` and the number of columns of `B`.

For matrices:
`A` of dimension \(m \times n\)
`B` of dimension \(n \times p\)
The resultant matrix `C` will be of dimension \(m \times p\).

```cpp
// Assuming A is of dimension m x n and B is of dimension n x p
for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
        C[i][j] = 0;
        for (int k = 0; k < n; k++) {
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
```

2. **Element-wise Operations**:

   - **Addition**:

     ```cpp
     for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
             C[i][j] = A[i][j] + B[i][j];
         }
     }
     ```

   - **Subtraction**:

     ```cpp
     for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
             C[i][j] = A[i][j] - B[i][j];
         }
     }
     ```

   - **Multiplication** (Element-wise/Hadamard product):

     ```cpp
     for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
             C[i][j] = A[i][j] * B[i][j];
         }
     }
     ```

   - **Division**:
     ```cpp
     for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
             C[i][j] = A[i][j] / B[i][j];  // Make sure to handle the case when B[i][j] = 0
         }
     }
     ```

For the element-wise operations, matrices `A` and `B` should have the same
dimensions (both \(m \times n\)), otherwise the operations are not defined. The
resultant matrix `C` will also be of the same dimension \(m \times n\).

Note: Error handling (like checking for matrix dimensions compatibility) is
omitted for simplicity. In a real-world application, you would need to add
those checks before performing these operations.

## List libraries to deal with linear algebra and vectors, matrices in cpp

Here is a list of some popular C++ libraries used for dealing with linear
algebra, vectors, and matrices:

1. **Eigen**: This is probably one of the most widely used C++ libraries for
   linear algebra. It provides various operations for manipulating matrices,
   vectors, and numerical solvers. It is both high-performance and easy to use.
2. **Armadillo**: Armadillo is a high-quality C++ linear algebra library,
   aiming towards a good balance between speed and ease of use. The syntax is
   deliberately similar to Matlab.
3. **BLAS (Basic Linear Algebra Subprograms)**: This is a standard library that
   provides efficient operations for many kinds of vector and matrix
   operations. Although it's a low-level library and may be more complex to use,
   it is very fast due to hardware optimizations.
4. **LAPACK (Linear Algebra PACKage)**: This is a standard library for
   performing more advanced linear algebra operations, such as decompositions
   and eigenvalue calculations. LAPACK interfaces well with BLAS for efficient
   computations.
5. **Boost uBLAS**: This is part of the larger Boost library collection. It
   provides classes for vectors and matrices and operations for linear algebra.
6. **GSL (GNU Scientific Library)**: It provides a wide range of mathematical
   routines such as random number generators, special functions, and
   least-squares fitting. It has a CBLAS interface which provides basic routines
   for vector and matrix operations.
7. **GLM (OpenGL Mathematics)**: This is a header only C++ mathematics library
   for graphics software based on the OpenGL Shading Language (GLSL)
   specifications. It's commonly used in computer graphics tasks.

Remember to choose the library that best fits your needs and requirements. Some
are easier to use and have more features, while others are more minimal but may
offer better performance.

## How about optimization libraries that has algorithms to maximize the likelihood for login model for example ?

There are several libraries in C++ that can help you with optimization tasks
such as maximizing the likelihood for a logistic model:

1. **NLopt**: NLopt is a library for nonlinear optimization, providing a common
   interface for a number of different free optimization routines available
   online as well as original implementations of various other algorithms. It
   provides capabilities for global optimization, local optimization, and
   constrained optimization.
2. **Ceres Solver**: Ceres Solver is an open-source C++ library for modeling
   and solving large, complicated optimization problems. It can be used to
   solve Non-linear Least Squares problems with bounds constraints and general
   unconstrained optimization problems.
3. **Optimization with Ipopt and CppAD**: Ipopt (Interior Point OPTimizer) is a
   software package for large-scale nonlinear optimization. CppAD is a C++
   library that computes derivatives. Together they provide a powerful tool for
   optimization.
4. **Dlib**: Dlib is a modern C++ toolkit containing machine learning
   algorithms and tools for creating complex software in C++ to solve
   real-world problems. It provides a number of optimization algorithms, including
   for numerical optimization.
5. **GSL - GNU Scientific Library**: The library provides a broad set of
   mathematical routines such as random number generators, special functions,
   and least-squares fitting. The multi-dimensional minimization algorithms might
   be helpful for your purpose.

The choice of library depends heavily on the specifics of your problem and your specific use case.

## Request

Give me linear regression class that has optimization for estimating the
parameters assume computing the parameters numerically don’t use other
libraries use only CPP standard The estimation should has option either compute
using least square method or using maximum likelihood method, both cases should
the derivative computed numerically

- Implementing numerical methods for optimization, such as gradient descent,
  from scratch requires careful consideration due to the numerous pitfalls of
  numerical computation. Here's a very basic and rough implementation of a Linear
  Regression class using least squares and gradient descent for Maximum
  Likelihood Estimation. Please note that these implementations are very
  rudimentary and should be enhanced for robustness and performance before use in
  any kind of production or research code.

```cpp
#include <vector>
#include <numeric>
#include <cmath>

class LinearRegression {
    double slope;
    double intercept;

public:
    // Estimate parameters using least squares method
    void least_squares(const std::vector<double>& x, const std::vector<double>& y) {
        double x_mean = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
        double y_mean = std::accumulate(y.begin(), y.end(), 0.0) / y.size();

        double num = 0.0;
        double den = 0.0;

        for (size_t i = 0; i < x.size(); i++) {
            num += (x[i] - x_mean) * (y[i] - y_mean);
            den += (x[i] - x_mean) * (x[i] - x_mean);
        }

        slope = num / den;
        intercept = y_mean - slope * x_mean;
    }

    // Estimate parameters using gradient descent (Maximum Likelihood Estimation)
    void gradient_descent(const std::vector<double>& x, const std::vector<double>& y, double alpha = 0.01, int iterations = 1000) {
        slope = 0.0;
        intercept = 0.0;

        for(int i = 0; i < iterations; i++) {
            double slope_grad = 0.0;
            double intercept_grad = 0.0;
            double N = x.size();

            for(size_t j = 0; j < N; j++) {
                slope_grad += -(2/N) * x[j] * (y[j] - (slope * x[j] + intercept));
                intercept_grad += -(2/N) * (y[j] - (slope * x[j] + intercept));
            }

            slope = slope - alpha * slope_grad;
            intercept = intercept - alpha * intercept_grad;
        }
    }

    // Make prediction
    double predict(double x) {
        return slope * x + intercept;
    }
};
```

- The `least_squares` method implements the analytical solution to the least
  squares problem for linear regression, while the `gradient_descent` method
  implements a basic gradient descent algorithm for Maximum Likelihood Estimation
  (assuming normally distributed errors).
- These methods will set the slope and intercept parameters of the class, which
  can then be used to make predictions with the `predict` method.
- Note that this code does not include any error checking or handling,
  and the gradient descent method may not converge if the learning rate (`alpha`)
  is not properly set or the number of iterations is insufficient. The
  performance of this gradient descent implementation will also not be very good
  on large datasets, as it uses a simple loop to compute the gradient at each
  step. For larger datasets, a more efficient implementation would be required,
  possibly involving parallel computation.

## A basic implementation of Linear Regression using Eigen.

Note that this is a rudimentary implementation that doesn't include features
such as regularization or interaction terms, but it should give you a starting
point for your own work.

This code doesn't include the maximization of the likelihood function for MLE,
as this is a bit more complex and depends heavily on the specificities of your
problem.

```cpp

#include <iostream>
#include <Eigen/Dense>

class LinearRegression
{
public:
    LinearRegression() {}

    void train(const Eigen::MatrixXd &X, const Eigen::VectorXd &y)
    {
        // Add a column of ones for the bias term
        Eigen::MatrixXd Xb = Eigen::MatrixXd::Ones(X.rows(), X.cols() + 1);
        Xb.block(0, 1, X.rows(), X.cols()) = X;

        // Compute the weights using the normal equation
        weights = (Xb.transpose() * Xb).ldlt().solve(Xb.transpose() * y);
    }

    Eigen::VectorXd predict(const Eigen::MatrixXd &X)
    {
        // Add a column of ones for the bias term
        Eigen::MatrixXd Xb = Eigen::MatrixXd::Ones(X.rows(), X.cols() + 1);
        Xb.block(0, 1, X.rows(), X.cols()) = X;

        return Xb * weights;
    }

private:
    Eigen::VectorXd weights;
};

int main()
{
    // Create a simple dataset
    Eigen::MatrixXd X(100, 1);
    X << Eigen::VectorXd::Random(100);
    Eigen::VectorXd y = 2.0 * X.array() + 0.5 + Eigen::VectorXd::Random(100) / 10;

    // Train the model
    LinearRegression model;
    model.train(X, y);

    // Predict the output for the training data
    Eigen::VectorXd y_pred = model.predict(X);

    // Print the first 10 predictions
    std::cout << y_pred.head(10) << std::endl;

    return 0;
}
```

- This code first prepares the feature matrix X by adding a column of ones.
  This is done because the bias term (often called "intercept") in linear
  regression can be included as an extra feature that is always set to one. The
  weights are then computed using the normal equation, which is a simple and
  efficient way to find the least squares solution for linear regression.
- To implement linear regression with MLE, you will need to set up the
  likelihood function for the Gaussian distribution (which is the usual
  assumption for the error term in linear regression), and then use an
  optimization algorithm to find the parameters that maximize this function. This
  is more involved and requires the use of a nonlinear optimization library.
- Please note that to run this program, you need to link the Eigen library. If
  you're using CMake, add find_package(Eigen3 REQUIRED) in your CMakeLists.txt
  file and link it with target_link_libraries(your_target Eigen3::Eigen).

## Maximum Likelihood Estimation

Maximum likelihood estimation (MLE) in linear regression is a bit more
complicated than the least squares method because it involves an optimization
problem. You would typically use an optimization library to solve it.

- A key thing to understand about MLE in linear regression is that if the errors are
  normally distributed, then the maximum likelihood estimates for the regression
  coefficients are the same as the least squares estimates.
- That said, here's a basic example of a linear regression class where we use
  MLE for estimation assuming a normal distribution of errors. For simplicity, we
  will use the numerical optimization method provided by Eigen, Newton's method:

```cpp
#include <Eigen/Dense>

class LinearRegressionMLE
{
public:
    LinearRegressionMLE() {}

    void train(const Eigen::MatrixXd &X, const Eigen::VectorXd &y)
    {
        // Add a column of ones for the bias term
        Eigen::MatrixXd Xb = Eigen::MatrixXd::Ones(X.rows(), X.cols() + 1);
        Xb.block(0, 1, X.rows(), X.cols()) = X;

        // initialize coefficients with Least Squares Estimation
        coefficients = (Xb.transpose() * Xb).ldlt().solve(Xb.transpose() * y);

        // use newton's method to find coefficients that maximize log-likelihood
        for (int i = 0; i < 100; ++i) // arbitrary number of steps
        {
            Eigen::VectorXd h = Xb * coefficients;
            Eigen::VectorXd p = 1 / (1 + (-h.array()).exp()); // logistic function
            Eigen::VectorXd w = p.array() * (1 - p.array());
            Eigen::VectorXd z = h + (y - p).array() / w.array();
            coefficients = (Xb.transpose() * w.asDiagonal() * Xb).ldlt().solve(Xb.transpose() * w.asDiagonal() * z);
        }
    }

    Eigen::VectorXd predict(const Eigen::MatrixXd &X)
    {
        // Add a column of ones for the bias term
        Eigen::MatrixXd Xb = Eigen::MatrixXd::Ones(X.rows(), X.cols() + 1);
        Xb.block(0, 1, X.rows(), X.cols()) = X;

        return Xb * coefficients;
    }

private:
    Eigen::VectorXd coefficients;
};
```

This example sets up a logistic regression problem and uses Newton's method to
find the maximum likelihood estimate of the parameters. Please note that this
implementation is a simplification and doesn't include many things that you
would typically want in a machine learning algorithm, such as regularization,
error checking, or a stopping criterion for the optimization process. It is
provided as a simple starting point for your own work.

## Optimization Techniques to Estimate The Maximum Likelihood Parameters

There are several optimization techniques that can be used to estimate the
parameters in a maximum likelihood model. These techniques are designed to find
the parameters that maximize the likelihood function, often iteratively
improving the estimates. Here are a few key methods:

1. **Gradient Descent:** This is a first-order iterative optimization algorithm
   for finding the minimum of a function. In the context of maximum likelihood
   estimation (MLE), we would find the maximum by using the negative of the
   function (or equivalently, minimize the negative log-likelihood). It is based
   on the observation that if a multivariable function is defined and
   differentiable in a neighborhood of a point, then the function decreases
   fastest if one goes in the direction of the negative gradient.
2. **Stochastic Gradient Descent (SGD):** It's a version of gradient descent,
   but instead of calculating the gradient on the entire dataset, it estimates
   the gradient on a subset (batch) of data. SGD is useful when dealing with large
   datasets.
3. **Newton's Method (also called the Newton-Raphson method):** This method
   uses the second-order Taylor series expansion to approximate the objective
   function, leading to faster convergence compared to gradient descent. However,
   this requires calculation of the second derivative (Hessian matrix), which can
   be computationally intensive for high-dimensional data.
4. **Quasi-Newton Methods (BFGS, L-BFGS):** These methods also approximate the
   objective function using the second-order Taylor series expansion, but they
   update an estimate of the Hessian matrix iteratively, which is less
   computationally intensive than directly calculating the Hessian matrix.
5. **Expectation-Maximization (EM) Algorithm:** This is particularly useful
   when the model depends on some hidden or latent variables. The EM algorithm
   iteratively performs an expectation (E) step, which creates a function for the
   expectation of the log-likelihood evaluated using the current estimate for the
   parameters, and a maximization (M) step, which computes parameters maximizing
   the expected log-likelihood found on the E step.
6. **Conjugate Gradient Method:** This is an algorithm for the numerical
   solution of particular systems of linear equations, namely those whose
   matrix is symmetric and positive-definite. The conjugate gradient method is
   often implemented as an iterative algorithm, applicable to sparse systems that
   are too large to be handled by a direct implementation or other direct methods
   such as the Cholesky decomposition.

It should be noted that the best method to use for a given problem depends on
many factors, including the structure of the likelihood function, the number of
parameters, the size of the dataset, and the specifics of the computing
environment.
