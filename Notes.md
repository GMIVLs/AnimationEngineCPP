# _C++ Programming Code Improving Notes_.
## __Keep these notes in mind when write code in cpp__.
- __General Notes__:
    - Do not use standard namespace like:

      
    ```cpp
        using namespace std;
    ```
    
     in head of your code or at the begging header-file, consider use the specific one like
    
    ```cpp
        using std::cout;
        using std::vector;
        }
    ```
    - Consider not use endl at end of cout especially in a loop because its flush the buffer and take extra time, consider use '\n'.
    - Consider not use a for loop by index because you make a lot of errors, use a range-based loop insteded.
    - Do not using a loop to do some algorithm process while there is a standard library can do that for you
