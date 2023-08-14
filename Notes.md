# _C++ Programming Code Improving Notes_.
## __Keep these notes in mind when write code in cpp__.
- __General Notes__:
    - Do not use <span style="color: red;">using namespace std;</span> in head of your code of in the headerfile, consider use the specific one like using std::cout;..etc.
    - Consider not use endl at end of cout especially in a loop because its flush the buffer and take extra time, consider use '\n'.
    - Consider not use a for loop by index because you make a lot of errors, use a range-based loop insteded.
    - Do not using a loop to do some algorithm process while there is a standard library can do that for you
