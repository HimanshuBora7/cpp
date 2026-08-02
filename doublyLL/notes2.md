## What is `std::vector` and Why Do We Use It?

In C++, **`std::vector` is a dynamic array** provided by the C++ Standard Template Library (STL).

If you already know Java, **`vector<int>` in C++ is identical to `ArrayList<Integer>` in Java.**

### Why use `vector` over raw arrays?

1. **Automatic Memory Management:** With raw heap arrays (`new int[n]`), you must manually call `delete[]` to avoid memory leaks. A `vector` automatically frees its memory when it goes out of scope.
2. **Dynamic Resizing:** Unlike fixed static arrays (`int arr[5]`), a vector grows or shrinks dynamically as you insert or remove items (`arr.push_back(10)`).
3. **Self-Awareness (Knows Its Size):** A raw array loses its size metadata when passed to a function. A vector always retains its size, which you can check anytime using `arr.size()`.

---

## How Functions Accept a Vector as a Parameter

In C++, there are **three distinct ways** to pass a vector to a function, depending on whether you want to copy it, modify it, or just read it efficiently.

### 1. Pass by Const Reference (`const vector<int>&`) — **Gold Standard for Reading**

Use this when your function only needs to **read/print** data without modifying the vector. The `&` symbol avoids copying the vector, making it $O(1)$ fast, while `const` prevents accidental changes.

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Fast & safe: No copy is made, and the vector cannot be modified
void printVector(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    printVector(arr); // Read-only access
    return 0;
}

```

---

### 2. Pass by Reference (`vector<int>&`) — **Best for Modifying In-Place**

Use this when you want the function to **modify the original vector** in `main`. The `&` connects the function parameter directly to the original memory address.

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Modifies the original vector directly
void doubleElements(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i] *= 2; // Multiplies each element by 2
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    doubleElements(arr);

    // Original vector is now {2, 4, 6, 8, 10}
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

```

---

### 3. Pass by Value (`vector<int>`) — **Avoid Unless a Copy is Needed**

If you omit the `&` symbol, C++ creates a **complete duplicate** of the vector in memory.

```cpp
// ❌ SLOW for large data: Makes an expensive copy of the entire vector!
void processVector(vector<int> arr) {
    arr[0] = 99; // Only modifies the COPY, original vector remains unchanged
}

```

---

### Summary Cheat Sheet for Functions

| Function Signature              | Memory Cost              | Modifies Original? | Primary Use Case                         |
| ------------------------------- | ------------------------ | ------------------ | ---------------------------------------- |
| `void fn(const vector<int>& v)` | **$O(1)$ (No copy)**     | No (Protected)     | Printing, searching, computing sums      |
| `void fn(vector<int>& v)`       | **$O(1)$ (No copy)**     | **Yes**            | Sorting, reversing, modifying elements   |
| `void fn(vector<int> v)`        | $O(N)$ (Duplicates data) | No (Modifies copy) | When you explicitly need a isolated copy |
