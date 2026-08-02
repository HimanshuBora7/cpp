In C and C++, creating, populating ("feeding"), and traversing arrays depends heavily on whether you allocate memory on the **Stack** (static array with a fixed size known at compile time) or on the **Heap** (dynamic array allocated at runtime).

Here is a complete breakdown for both C and C++.

---

## 1. Static Arrays (Stack Allocation)

Static arrays have a fixed size that must be known at compile time. They live on the Stack memory and are destroyed automatically when the function ends.

### In C

```c
#include <stdio.h>

int main() {
    int size = 5;
    int arr[5]; // 1. CREATE: Fixed-size array on the stack

    // 2. FEED (Populate): Using a loop and scanf
    printf("Enter 5 integers:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // Pass memory address using '&'
    }

    // 3. TRAVERSE: Using standard indexing
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

```

### In C++

In C++, feeding uses `cin` instead of `scanf`, and you can use modern **range-based `for` loops** to traverse static arrays cleanly.

```cpp
#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int arr[5]; // 1. CREATE

    // 2. FEED (Populate)
    cout << "Enter 5 integers:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // 3. TRAVERSE (Method A: Standard index loop)
    cout << "Traversing with index: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 3. TRAVERSE (Method B: Range-based loop - Modern C++)
    cout << "Traversing with range-based loop: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

---

## 2. Dynamic Arrays (Heap Allocation)

If you don't know the size of the array until runtime (e.g., getting $N$ from user input), you must allocate the array dynamically on the **Heap**.

### In C (`malloc` / `free`)

C uses `malloc` to request raw bytes from the Heap and `free` to return them.

```c
#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    // 1. CREATE: Allocate memory for 'n' integers on Heap
    int* arr = (int*) malloc(n * sizeof(int));

    // Safety check: Ensure heap memory allocation succeeded
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 2. FEED
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10; // e.g., 10, 20, 30...
    }

    // 3. TRAVERSE
    printf("Heap Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 4. CLEANUP: Always free heap memory in C!
    free(arr);
    return 0;
}

```

### In C++ (`new[]` / `delete[]`)

C++ introduces the `new[]` and `delete[]` operators, making heap allocation much cleaner than C's `malloc`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    // 1. CREATE: Allocate dynamic array on Heap
    int* arr = new int[n];

    // 2. FEED
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 3. TRAVERSE
    cout << "Heap Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 4. CLEANUP: Always release heap memory with delete[]
    delete[] arr;
    return 0;
}

```

---

## 3. Alternative Traversal: Pointer Arithmetic

Since arrays are stored contiguously in memory, the variable `arr` is actually a pointer to the **first element** (`&arr[0]`). In both C and C++, you can traverse arrays using pointer arithmetic instead of index brackets `[i]`:

```cpp
// Instead of arr[i], you can dereference the pointer offset
for (int i = 0; i < n; i++) {
    cout << *(arr + i) << " "; // *(arr + i) is identical to arr[i]
}

```

---

## 4. Modern C++ Standard: `std::vector` (For DSA Practice)

In actual C++ Data Structures and Algorithms (DSA) practice (like on LeetCode), raw dynamic arrays (`new int[n]`) are rarely used directly. Instead, programmers use **`std::vector`**, which is C++'s dynamic array (similar to Java's `ArrayList`):

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. CREATE: Dynamic vector of integers
    vector<int> arr;

    // 2. FEED: Adding elements dynamically (like ArrayList.add in Java)
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    // 3. TRAVERSE
    for (int val : arr) {
        cout << val << " ";
    }
    // Output: 10 20 30

    // No manual cleanup (delete) needed; vector manages its own memory!
    return 0;
}

```

---

To directly hardcode values into an array during initialization (without asking the user for input using `cin` or `scanf`), you can use **array initializer lists**.

Here is how to do it in C and C++ for static arrays, dynamic arrays, and vectors.

---

### 1. Static Arrays (Stack Memory)

If you know the values upfront, you can initialize the array using curly braces `{}` when you declare it.

#### In C and C++

```cpp
#include <iostream>
using namespace std;

int main() {
    // Option A: Specify the size explicitly
    int arr1[5] = {10, 20, 30, 40, 50};

    // Option B: Omit the size (Compiler automatically detects size is 5)
    int arr2[] = {10, 20, 30, 40, 50};

    // Traverse and print
    for (int val : arr2) {
        cout << val << " ";
    }
    // Output: 10 20 30 40 50

    return 0;
}

```

---

### 2. Dynamic Arrays (Heap Memory)

#### In Modern C++ (C++11 and newer)

You can use uniform initialization directly with the `new` keyword:

```cpp
#include <iostream>
using namespace std;

int main() {
    // Directly initialize dynamic heap array
    int* arr = new int[5]{10, 20, 30, 40, 50};

    // Traverse
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    // Output: 10 20 30 40 50

    // Cleanup
    delete[] arr;
    return 0;
}

```

#### In C

In standard C, `malloc` doesn't take initializer lists directly. You either assign them individually or copy from a temporary array:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int* arr = (int*) malloc(n * sizeof(int));

    // Assigning directly after allocation
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

```

---

### 3. Modern C++: `std::vector` (Recommended for DSA)

If you are using `std::vector`, direct initialization is very clean and resembles Java's `Arrays.asList()`:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Direct initialization
    vector<int> arr = {10, 20, 30, 40, 50};

    // Traverse using range-based loop
    for (int val : arr) {
        cout << val << " ";
    }
    // Output: 10 20 30 40 50

    return 0;
}

```
