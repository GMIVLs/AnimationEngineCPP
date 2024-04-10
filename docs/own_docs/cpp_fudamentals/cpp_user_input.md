# CPP User Input

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [CPP User Input](#cpp-user-input)
    - [Quick Notes](#quick-notes)
    - [Basics I/O](#basics-io)
    - [Flushing the buffer](#flushing-the-buffer)
        - [What is an Input Buffer?](#what-is-an-input-buffer)
        - [Why and When to Flush the Input Buffer?](#why-and-when-to-flush-the-input-buffer)
        - [How to Flush the Input Buffer in C++?](#how-to-flush-the-input-buffer-in-c)
        - [Important Notes](#important-notes)
        - [Common use cases:](#common-use-cases)
        - [Common Usage Scenarios in Programs:](#common-usage-scenarios-in-programs)
        - [Best Practices:](#best-practices)

<!-- markdown-toc end -->

There are several ways to obtain user input values (Read `CHAPTER 13`
DEMYSTIFYING C++ I/O - Marc Gregoire - Professional C++ 2021).

## Quick Notes
- It seems the std::getline is the better and more efficient wayt to handle the
  user's input. It offers a good way to flush the buffer and remove unwanted
  characters.

## Basics I/O

- In C++, obtaining user input values from the command line is a common line
  crucial operation. There are several ways to do this, depending on the
  complexity and requirements of your program. The most straightforward and widely
  used method is through the standard input stream `std::cin`. However, there are
  other methods as well, especially when dealing with specific situations or more
  advanced programming scenarios. Here's a table summarizing some of the possible
  ways to obtain user input values in C++:

| Method/Function                            | Description                                                                                | Use Case                                                                           |
| ------------------------------------------ | ------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------- |
| `std::cin`                                 | Standard input stream in C++. Used to read data from the standard input device (keyboard). | Basic and most common method for reading input.                                    |
| `std::getline`                             | Function to read a line of text from an input stream (like `std::cin`).                    | Useful for reading a whole line of input, including spaces.                        |
| `scanf` or `fscanf`                        | C-style input functions. Provide formatted input reading.                                  | Useful when you need to read formatted data or when integrating with C-style code. |
| `std::stringstream`                        | Stream class in the C++ Standard Library. Used for parsing and formatting string data.     | Ideal for complex parsing of string input into different data types.               |
| Command Line Arguments (`argv` and `argc`) | Arguments passed to the main function of a C++ program.                                    | Best for retrieving parameters provided at the start of the program execution.     |
| `boost::program_options`, `getopt`         | Libraries for parsing command line options.                                                | Useful for complex command-line argument parsing in larger applications.           |
| File input (using `std::ifstream`)         | Reading input from a file.                                                                 | When input is to be read from a file rather than the standard input.               |
| `std::cin.get()`                           | Reads the next character from `std::cin`, but doesn't remove it from the input buffer.     | Useful for reading single characters, including whitespace.                        |
| `std::cin.peek()`                          | Returns the next character in the input sequence, without extracting it.                   | Useful for checking what the next character is without actually reading it.        |

Please note that `get_value` is not a standard C++ function or method for input.
The primary and most straightforward way to read input in a C++ program is using
`std::cin`, along with operators `>>` for formatted input or `std::getline` for
unformatted input (like full lines with spaces).

Here's a simple example of using `std::cin`:

```cpp
#include <iostream>
#include <string>

int main() {
    int number;
    std::string name;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cin.ignore(); // Clear the buffer before reading a line
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Number: " << number << ", Name: " << name << std::endl;
    return 0;
}
```

In this example, `std::cin >> number` is used to read an integer, and
`std::getline(std::cin, name)` is used to read a string that may contain spaces.
The `std::cin.ignore()` call is important to clear the newline character from
the buffer after reading the integer.

## Flushing the buffer

"Flushing the input" or "flushing the buffer" in the context of C++ input/output
(I/O) refers to the process of clearing the input buffer. This is an important
concept in stream handling, especially when dealing with user inputs.

### What is an Input Buffer?

In C++, when you read input from the user using `std::cin` or similar methods,
the entered data first goes into an input buffer - a temporary storage area in
memory. This buffer holds the input until your program processes it.

### Why and When to Flush the Input Buffer?

You might need to flush this buffer in certain situations, for example:

1. **After Reading a Numeric Value**: If you read a numeric value (like `int`,
   `float`) and then try to read a string or a line of text, there's often a
   newline character (`\n`) left in the buffer. This newline character can cause
   the next input operation to behave unexpectedly.
2. **Before Reading New Input**: Sometimes you want to ensure that the buffer is
   clean before you read a new input, to avoid processing leftover data from
   previous inputs.

### How to Flush the Input Buffer in C++?

In C++, flushing the input buffer typically involves removing unwanted
characters up to a certain point. Here's how you can do it:

1. **Using `std::cin.ignore()`**: This method is used to ignore characters in
   the buffer. For example,
   `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');` ignores
   characters until a newline is encountered or the maximum stream size is
   reached. This is often used after reading a numeric input to remove the
   leftover newline character before reading a string or line input.

   ```cpp
   int number;
   std::cin >> number;

   // Flush the buffer
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   std::string line;
   std::getline(std::cin, line);
   ```

2. **Using `std::cin.get()` in a loop**: This is a more manual way, where you
   read and discard characters until you reach the newline character.

   ```cpp
   char ch;
   while ((ch = std::cin.get()) != '\n' && ch != EOF);
   ```

### Important Notes

- Flushing the input buffer is generally not needed (and not recommended) after
  calling `std::getline`, as `std::getline` reads until a newline character and
  consumes it.
- Overusing buffer flushing can lead to inefficient code, especially if done
  unnecessarily. It's best used when there's a known issue with leftover
  characters in the buffer.

Understanding when and how to flush the input buffer is crucial for handling
user inputs correctly in C++ and avoiding common pitfalls in input processing.


### Common use cases:
The most common use for user input in C++ typically involves reading data from
the user via the command line. This can include a wide range of applications,
from simple command-line utilities to complex interactive programs. The standard
methods for reading input in C++ are `std::cin` and `std::getline()`, each
having specific use cases:

1. **Using `std::cin` for Formatted Input:**
   - **Purpose:** `std::cin`, combined with the extraction operator `>>`, is
     commonly used for reading formatted input. It's particularly suitable for
     reading single values of built-in data types like `int`, `double`, `char`,
     etc.
   - **Use Cases:**
     - **Numeric Inputs:** For example, reading integers, floating-point
       numbers, etc., for mathematical computations or processing.
     - **Single Word Strings:** Reading a single word (without spaces) as a
       string input.
   - **Advantages:** It automatically handles type conversion (e.g., from string
     to integer) and skips whitespaces.
   - **Example Usage:**
     ```cpp
     int age;
     std::cout << "Enter your age: ";
     std::cin >> age;
     ```

2. **Using `std::getline()` for Unformatted Input:**
   - **Purpose:** `std::getline()` is used for reading a line of text from an
     input stream (like `std::cin`). It reads characters until a newline
     (`'\n'`) is found.
   - **Use Cases:**
     - **Full Line Input:** Reading an entire line of input, including spaces,
       which is useful for sentences or paragraphs.
     - **String Inputs with Spaces:** When the input includes spaces (e.g., a
       full name).
   - **Advantages:** It can read strings containing spaces and provides more
     control over input, including the delimiter character.
   - **Example Usage:**
     ```cpp
     std::string name;
     std::cout << "Enter your full name: ";
     std::getline(std::cin, name);
     ```

### Common Usage Scenarios in Programs:

- **Interactive Programs:** Where users input data for processing (e.g.,
  calculators, form submissions).
- **Command-Line Tools:** Where inputs are provided for specific operations
  (e.g., file processing tools).
- **Games:** Simple text-based games or quizzes.
- **Educational Tools:** Like programming exercises or interactive learning
  applications.
- **Data Entry Applications:** For entering and processing data records.

### Best Practices:

- **Know Your Input Type:** Use `std::cin >>` for single values and
  `std::getline()` for full lines.
- **Input Validation:** Always validate user inputs for correctness and errors.
- **Buffer Flushing:** Use `std::cin.ignore()` when switching between `std::cin
  >>` and `std::getline()` to avoid issues with leftover newline characters in
  the buffer.

Choosing between `std::cin` and `std::getline()` depends on the specific
requirements of your input - whether you need to read a single word/value or an
entire line including spaces.k
