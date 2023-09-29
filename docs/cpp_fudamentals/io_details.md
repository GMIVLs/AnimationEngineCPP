# Input and Output in CPP

C++ provides a rich set of input-output operations through the `<iostream>` library. Let's break down the most commonly used IO objects and functions:

| **IO Type**      | **Description**                                                           | **Example**                                           |
| ---------------- | ------------------------------------------------------------------------- | ----------------------------------------------------- |
| **cin**          | Standard input stream object, commonly used for reading from the console. | `int n; cin >> n;`                                    |
| **cout**         | Standard output stream object, used for writing to the console.           | `cout << "Hello, World!" << endl;`                    |
| **cerr**         | Standard error stream, used for error messages. It's unbuffered.          | `cerr << "An error occurred!" << endl;`               |
| **clog**         | Used for logging. Buffered version of cerr.                               | `clog << "This is a log message." << endl;`           |
| **endl**         | Outputs a newline and flushes the stream.                                 | `cout << "End of line." << endl;`                     |
| **getline()**    | Reads an entire line from a stream.                                       | `string line; getline(cin, line);`                    |
| **stringstream** | Stream class to operate on strings. Useful to parse strings.              | `stringstream ss("42"); int num; ss >> num;`          |
| **ifstream**     | Input file stream, used for reading from files.                           | `ifstream file("input.txt"); file >> n;`              |
| **ofstream**     | Output file stream, used for writing to files.                            | `ofstream file("output.txt"); file << "Output text";` |
| **fstream**      | Stream class for both reading and writing to files.                       | `fstream file("data.txt", ios::in \| ios::out);`      |
| **ios::binary**  | IO Mode, used for reading or writing in binary mode.                      | `ofstream file("data.bin", ios::binary);`             |
| **ios::app**     | IO Mode, used to append to the file instead of overwriting it.            | `ofstream file("log.txt", ios::app);`                 |

**Notes**:

1. **cin** and **cout** are the most commonly used IO streams for standard input and output operations.
2. **cerr** and **clog** are used for error and log messages, respectively.
3. For file operations, one needs to include the `<fstream>` header.
4. Always remember to close file streams after operations using the `close()` method, although they usually close automatically upon destruction.
5. Use `stringstream` for parsing or composing complex strings.
6. Always check if a file stream was opened successfully before performing operations on it. You can use the `is_open()` method for this.

To utilize the above IO functions and classes, one would need to include the `<iostream>`, `<fstream>`, and `<sstream>` headers as required.
