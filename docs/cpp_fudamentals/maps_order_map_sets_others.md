# Maps - Ordered and non-Ordered

## Maps types

`std::map` and `std::unordered_map` are associative containers in C++ that store elements as key-value pairs. Here's a table for various ways to construct them:

| **Type**                                  | **Storage Location** | **Description**                                            | **Example**                                                           |
| ----------------------------------------- | -------------------- | ---------------------------------------------------------- | --------------------------------------------------------------------- |
| **std::map (Stack)**                      | Stack                | Default construction on the stack.                         | `std::map<int, std::string> m;`                                       |
| **std::map (Heap)**                       | Heap                 | Dynamically allocated on the heap.                         | `auto m = new std::map<int, std::string>; ... delete m;`              |
| **std::map (Initializer List)**           | Stack                | Constructed with an initializer list.                      | `std::map<int, std::string> m = {{1, "one"}, {2, "two"}};`            |
| **std::unordered_map (Stack)**            | Stack                | Default construction on the stack for an unordered map.    | `std::unordered_map<int, std::string> um;`                            |
| **std::unordered_map (Heap)**             | Heap                 | Dynamically allocated unordered map on the heap.           | `auto um = new std::unordered_map<int, std::string>; ... delete um;`  |
| **std::unordered_map (Initializer List)** | Stack                | Constructed with an initializer list for an unordered map. | `std::unordered_map<int, std::string> um = {{1, "one"}, {2, "two"}};` |

**Description**:

1. **std::map**: A balanced binary tree (usually a red-black tree) that keeps its keys in sorted order.
2. **std::unordered_map**: A hash table. It doesn't keep its keys in any specific order, but can be faster for certain operations due to average constant-time complexity.

**Storage Notes**:

- **Stack**: These instances are automatically destroyed when they go out of scope. They're suitable for relatively smaller maps or when the map's lifetime is tied to a specific scope.
- **Heap**: These instances need to be managed manually or via smart pointers. Suitable for larger maps or when the map needs to be shared or outlive the current scope.

For both `std::map` and `std::unordered_map`, you'll need to include the appropriate headers (`<map>` and `<unordered_map>` respectively).
