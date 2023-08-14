# C++ Programming Code Improving Notes.
## Please keep these notes in mind when write code in cpp.
_italic_
_bold_
- General Notes:
    - Do not use using namespace std in head of your code of in the headerfile, consider use the specific one like using std::cout;..etc.
    - Consider not use endl at end of cout especially in a loop because its flush the buffer and take extra time, consider use '\n'.
    - Consider not use a for loop by index because you make a lot of errors, use a range-based loop insteded. 
