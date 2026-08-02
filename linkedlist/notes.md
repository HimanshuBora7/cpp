# Linked List in C++ (Revision Notes)

## 1. Why do we need a Linked List?

### Arrays

- Fixed size.
- Contiguous memory allocation.
- Insertion/deletion in the middle requires shifting elements.
- Random access is O(1).

### Linked List

- Dynamic size.
- Nodes can be anywhere in memory.
- Each node stores:
  - Data
  - Address of the next node

Random access is **not possible** because nodes are connected through pointers.

---

# 2. Structure of a Node

Unlike Java, C++ doesn't have a built-in class object allocation on the heap unless you explicitly request it.

A node typically contains:

- Data
- Pointer to the next node

Conceptually:

```text
+-------+-----------+
| data  | next      |
+-------+-----------+
```

Example:

```text
10 -> 20 -> 30 -> NULL
```

Memory might actually look like:

```text
Address      Data      Next

1000         10        2050
2050         20        8090
8090         30        NULL
```

Notice that nodes are **not contiguous**.

---

# 3. Java vs C++

Java:

- Garbage Collector manages memory.
- Objects are created with `new`.
- Memory is automatically reclaimed.

C++:

- You allocate memory using `new`.
- You must release memory using `delete`.
- Forgetting `delete` causes memory leaks.

This is one of the biggest differences.

---

# 4. Understanding pointers

Suppose:

```text
int x = 10;
```

Memory:

```text
Address     Value

1000        10
```

Pointer:

```text
ptr
```

contains:

```text
1000
```

So:

```text
ptr -----> x
```

Important operators:

```text
&
```

Address-of operator.

Returns the address.

---

```text
*
```

Dereference operator.

Returns the value stored at the address.

---

Example:

```text
x = 10

&x = 1000

ptr = &x

*ptr = 10
```

---

# 5. Pointer to a Node

Instead of pointing to an integer:

```text
ptr -> int
```

we point to a Node.

Conceptually:

```text
head
 |
 |
 v

+------+------+
| 10   | ---- |---->
+------+------+
```

---

# 6. Why use `->` instead of `.`?

This confuses almost everyone initially.

Suppose:

```text
Node node;
```

You have an object.

Use:

```text
node.data
```

Now suppose:

```text
Node* head;
```

`head` is **not a node**.

It is a pointer.

It stores an address.

To access members through a pointer:

```text
head->data
```

Think of:

```text
head->data
```

as shorthand for:

```text
(*head).data
```

Both mean exactly the same thing.

---

# 7. Typical Linked List Operations

You should implement each of these yourself:

### Basic

- Create a node
- Print list
- Count nodes
- Search element

---

### Insertions

- Beginning
- End
- Position
- Before value
- After value

---

### Deletions

- Beginning
- End
- Position
- By value

---

### Advanced

- Reverse list
- Middle node
- Detect cycle
- Merge sorted lists

---

# 8. Time Complexity

| Operation                             | Complexity |
| ------------------------------------- | ---------- |
| Access by index                       | O(n)       |
| Search                                | O(n)       |
| Insert at head                        | O(1)       |
| Insert at tail (without tail pointer) | O(n)       |
| Delete head                           | O(1)       |
| Delete tail                           | O(n)       |

---

# 9. Common beginner mistakes

### Forgetting to update head

Very common.

---

### Losing the next pointer

If you overwrite the pointer before saving the next node, the rest of the list becomes unreachable.

---

### Dereferencing NULL

Never access:

```text
head->next
```

without ensuring `head` isn't `NULL`.

---

### Forgetting `delete`

Every `new` should eventually have a corresponding `delete`.

---

# 10. Java vs C++ Linked List

| Java                  | C++                      |
| --------------------- | ------------------------ |
| References            | Raw pointers             |
| Garbage Collector     | Manual memory management |
| `null`                | `nullptr`                |
| Automatic cleanup     | `delete` required        |
| No pointer arithmetic | Full pointer support     |

---

Excellent first attempt. You're thinking in the right direction, but there's one important C++ concept to understand.

---

# Your code

```cpp
Node node1 = new Node(10);
```

This line is incorrect.

The reason is that **`new Node(10)` returns a pointer (`Node*`)**, not a `Node` object.

Think about it:

```text
new Node(10)

↓

Allocate memory on the heap

↓

Return the ADDRESS of that memory

↓

Type = Node*
```

So you're trying to do:

```text
Node = Node*
```

which are different types.

---

# Stack vs Heap

This is one of the biggest conceptual differences from Java.

## 1. Stack Allocation

When you write something like:

```text
Node node1(...)
```

the object itself lives on the **stack**.

Memory:

```text
Stack

+-----------+
| node1     |
| data=10   |
| next=NULL |
+-----------+
```

No `delete` is needed.

When `main()` finishes, the object is destroyed automatically.

---

## 2. Heap Allocation

When you use:

```text
new Node(...)
```

the object is stored on the **heap**.

Memory looks like:

```text
Stack                     Heap

node1  ------------->   +-----------+
(pointer)               | data = 10 |
                         | next=NULL |
                         +-----------+
```

Notice:

The variable on the stack only stores the **address**.

The actual object is on the heap.

---

# So what should the variable type be?

Ask yourself:

> If `new` returns a `Node*`, what type should `node1` be?

That's the answer.

I'm intentionally not writing the corrected line because I want you to get used to reasoning about types.

---

# Another thing

Your constructor is good:

```cpp
Node(int data1){
    data = data1;
    next = nullptr;
}
```

Later, once you're comfortable with C++, we'll write it in the more idiomatic style using an **initializer list**, because that's what you'll see in professional C++ code.

For now, your constructor is perfectly fine.

---

# Mini Quiz

Tell me the type of each variable.

### A

```cpp
Node node1(10);
```

Type of `node1` = ?

---

### B

```cpp
Node* node1 = new Node(10);
```

Type of `node1` = ?

---

### C

```cpp
Node* ptr = &node1;
```

(Assume `node1` is from part A.)

Type of `ptr` = ?

---

# One more interview concept

Can you tell me **which of these requires `delete`** before the program ends?

1.

```cpp
Node node1(10);
```

2.

```cpp
Node* node1 = new Node(10);
```

Understanding this distinction is fundamental to writing correct C++ code, especially for linked lists where almost every node is allocated dynamically.

---

Good attempt! You got **2 out of 3**.

## Quiz Review

### A)

```cpp
Node node1(10);
```

Type of `node1`?

✅ **Correct:** `Node`

It is an actual object.

Memory:

```text
Stack

+-----------+
| node1     |
| data=10   |
| next=NULL |
+-----------+
```

---

### B)

```cpp
Node* node1 = new Node(10);
```

Type?

✅ **Correct:** `Node*`

`node1` is a **pointer** that stores the address of a `Node`.

Memory:

```text
Stack                     Heap

node1 --------->        +-----------+
(pointer)               | data=10   |
                        | next=NULL |
                        +-----------+
```

---

### C)

```cpp
Node* ptr = &node1;
```

You answered **Node**, but it's actually:

❌ **Type = `Node*`**

Why?

The `&` operator returns the **address** of a variable.

If `node1` is a `Node`, then:

```cpp
&node1
```

has type:

```cpp
Node*
```

So:

```cpp
Node* ptr = &node1;
```

means:

```text
ptr
 |
 v

node1
```

---

# Why `struct` instead of `class`?

This is one of the nicest differences between Java and C++.

In Java, you only have:

```java
class Node {
    int data;
    Node next;
}
```

Everything is a class.

---

## In C++, there are **two** ways:

```cpp
struct Node
```

and

```cpp
class Node
```

Both can have:

- Variables
- Constructors
- Functions
- Destructors
- Inheritance

This surprises many Java developers.

---

## Then what's the difference?

There is only **one major default difference**.

### `struct`

Members are **public by default**.

Example:

```cpp
struct Node {
    int data;
};
```

is equivalent to:

```cpp
class Node {
public:
    int data;
};
```

---

### `class`

Members are **private by default**.

Example:

```cpp
class Node {
    int data;
};
```

Here,

```cpp
node.data
```

will give an error because `data` is private unless you explicitly write:

```cpp
public:
```

---

# Then why does everyone use `struct` for linked lists?

Because a node is simply a **data container**.

It stores:

- data
- next pointer

Nothing more.

So writing:

```cpp
struct Node
```

is shorter and more natural.

You'll see this in competitive programming and interview code.

---

# When should I use `class`?

When you're designing an object with:

- private members
- encapsulation
- member functions
- abstractions

For example:

```text
Car
Student
BankAccount
Drone
Robot
```

These are good candidates for classes.

---

# When should I use `struct`?

When it's just a container.

Examples:

```text
Node
Point
Edge
Coordinate
RGB
EmployeeRecord
```

---

# Java vs C++

| Java                                   | C++                         |
| -------------------------------------- | --------------------------- |
| Only `class`                           | `class` and `struct`        |
| Members are package-private by default | `struct`: public by default |
| No pointers                            | Pointers available          |
| Garbage collection                     | Manual memory management    |

---

## Interview fact

Many beginners think:

> "`struct` is only for variables."

❌ That's from C.

In **modern C++**, a `struct` can have:

- Constructors
- Functions
- Static members
- Inheritance
- Templates

It's almost identical to a `class`; the default access level is the main distinction.

---

### Before we move to insertion in a linked list, I have one question for you:

Suppose you create a node like this:

```cpp
Node* head = new Node(10);
```

How would you access:

1. `data`
2. `next`

Would you use:

- `head.data`
- `head->data`
- `(*head).data`

Which ones are correct, and **why**? This understanding is essential because you'll use it in almost every linked list operation.

---

Exactly! That's the understanding I wanted you to reach.

> **Rule:** Use `.` with an object and `->` with a pointer to an object.

Let's refine your explanation a little because this wording will help in interviews and your notes.

---

# Accessing Members in C++

## Case 1: We have an object

```cpp
Node node1(10);
```

`node1` **is the actual object**.

Memory:

```text
node1
+--------+---------+
| data   | next    |
+--------+---------+
```

Since it's an object, access members using:

```cpp
node1.data
node1.next
```

---

## Case 2: We have a pointer

```cpp
Node* head = new Node(10);
```

`head` is **not** the object.

It only stores the address.

Memory:

```text
Stack                     Heap

head --------------->   +--------+---------+
(pointer)               | data   | next    |
                        +--------+---------+
```

So writing

```cpp
head.data
```

is wrong because `head` itself doesn't have a member named `data`.

Instead, first dereference the pointer:

```cpp
(*head).data
```

Since this is very common, C++ provides a shorthand:

```cpp
head->data
```

These are exactly equivalent:

```cpp
head->data
```

=

```cpp
(*head).data
```

---

# A small trick to remember

Whenever you see:

```cpp
Node* something;
```

ask yourself:

> **Is `something` the node?**

No.

It's just the **address** of a node.

So you'll almost always use:

```cpp
something->
```

---

# Compare with Java

In Java, you write:

```java
Node head = new Node(10);

head.data;
```

Why isn't there an arrow operator?

Because Java hides pointers from you.

`head` is technically a **reference**, but Java automatically dereferences it whenever you write:

```java
head.data
```

C++ gives you explicit control, which is why you have to write:

```cpp
head->data
```

---

# One subtle point

You said:

> "we don't have real object"

Almost correct. Here's the more precise wording:

- ❌ The object **does exist**.
- ✅ But the variable you're holding is **not the object**—it's a **pointer to the object**.

For example:

```cpp
Node* head = new Node(10);
```

There **is** a real `Node` object on the heap.

The variable `head` simply points to it.

---

# Interview Tip ⭐

Whenever you're writing a linked list function, mentally check these three cases **before** writing any pointer logic:

```text
1. Empty list
2. Single-node list
3. Normal list
```

If your function handles all three, you're already ahead of many candidates.

---

# Let's move FAST ⚡

Only two important singly linked list topics remain.

## 1. Search

Logic?

```text
Start from head

↓

Compare current->data with key

↓

If found → return

↓

Else move to next

↓

Reach NULL → not found
```

Time: `O(n)`

Nothing new here.

---

## 2. Count Nodes

Exactly the same traversal.

```text
count = 0

↓

Visit node

↓

count++

↓

Move ahead

↓

Return count
```

Time: `O(n)`

---

# 3. Reverse Linked List ⭐⭐⭐⭐⭐ (Most Important)

This is the only operation I **don't** want you to rush.

It is asked everywhere.

Suppose:

```text
10 -> 20 -> 30 -> NULL
```

You want:

```text
30 -> 20 -> 10 -> NULL
```

### Think first.

If you simply do:

```cpp
curr->next = prev;
```

What happens to the rest of the list?

Example:

```text
10 -> 20 -> 30
```

If you immediately reverse the first link:

```text
10 <- 20 -> 30
```

How will you ever reach `30`?

🤔

That's why we need **three pointers**, not two.

I want **you** to tell me:

1. Why do we need `next` (or `front`)?
2. What information would be lost if we didn't save it first?

Once you answer that, you'll never forget the reverse algorithm again, and then we'll jump straight into **Doubly Linked Lists**.
