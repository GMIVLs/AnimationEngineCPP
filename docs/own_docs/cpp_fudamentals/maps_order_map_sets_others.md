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

1. **std::map**: A balanced binary tree (usually a red-black tree) that keeps
   its keys in sorted order.
2. **std::unordered_map**: A hash table. It doesn't keep its keys in any
   specific order, but can be faster for certain operations due to average
   constant-time complexity.

**Storage Notes**:

- **Stack**: These instances are automatically destroyed when they go out of
  scope. They're suitable for relatively smaller maps or when the map's lifetime
  is tied to a specific scope.
- **Heap**: These instances need to be managed manually or via smart pointers.
  Suitable for larger maps or when the map needs to be shared or outlive the
  current scope.

For both `std::map` and `std::unordered_map`, you'll need to include the appropriate headers (`<map>` and `<unordered_map>` respectively).

## How to use Hash Table (map)

C++ provides data structures for key-value pairs in the form of associative
containers. Here are a few examples:

1. **std::map**: It's an ordered associative container that stores elements
   formed by the combination of a key value and a mapped value, following a
   specific order. The key values are unique.

   ```cpp
   std::map<std::string, int> myMap;
   myMap["apple"] = 1;
   myMap["banana"] = 2;
   ```

2. **std::multimap**: It's similar to std::map, but allows for multiple values
   with the same key.

   ```cpp
   std::multimap<std::string, int> myMultimap;
   myMultimap.insert(std::make_pair("apple", 1));
   myMultimap.insert(std::make_pair("apple", 2));
   ```

3. **std::unordered_map**: It's an associative container that stores elements
   formed by the combination of a key value and a mapped value. It uses a hash
   table for internal organization of elements. The key values are unique.

   ```cpp
   std::unordered_map<std::string, int> myUnorderedMap;
   myUnorderedMap["apple"] = 1;
   myUnorderedMap["banana"] = 2;
   ```

4. **std::unordered_multimap**: It's similar to std::unordered_map, but allows
   for multiple values with the same key.

   ```cpp
   std::unordered_multimap<std::string, int> myUnorderedMultimap;
   myUnorderedMultimap.insert(std::make_pair("apple", 1));
   myUnorderedMultimap.insert(std::make_pair("apple", 2));
   ```

Each of these container types has its use cases, advantages, and disadvantages.
Which one you choose to use largely depends on the specific requirements of
your application.

## What is the difference between multi map and map in CPP give example for each ?

In C++, both `std::map` and `std::multimap` are associative containers that
store elements in a mapped fashion, where each element has a key value and a
mapped value. The primary difference between them is that `std::map` doesn't
allow duplicate keys, whereas `std::multimap` does.

Here's an example of a `std::map`:

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap.insert(std::make_pair(1, "Apple"));
    myMap.insert(std::make_pair(2, "Banana"));
    // this will not insert a new element as key 1 already exists
    myMap.insert(std::make_pair(1, "Mango"));

    for (const auto &pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
```

And here's an example of a `std::multimap`:

```cpp
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> myMultiMap;
    myMultiMap.insert(std::make_pair(1, "Apple"));
    myMultiMap.insert(std::make_pair(2, "Banana"));
    // this will insert a new element even though key 1 already exists
    myMultiMap.insert(std::make_pair(1, "Mango"));

    for (const auto &pair : myMultiMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
```

With a `std::map`, each key must be unique and for any given key, there is a
single associated value. In contrast, with a `std::multimap`, the same key can
be associated with multiple values.
