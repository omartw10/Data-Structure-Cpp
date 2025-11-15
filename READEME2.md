
---

# 📚 Data Structures in C++ — Full Educational Documentation

This repository provides a complete educational implementation of **core Data Structures in C++**, written manually without STL, for the purpose of understanding how each structure works internally — including memory layout, pointers, node manipulation, shifting logic, and time complexity.

This README is designed to be a **fully detailed documentation**, explaining:

* every file
* every class
* every function
* every attribute
* internal workflow
* memory model
* complexity analysis
* diagrams & conceptual understanding

---

# 📌 Included Files (Current Status)

| Data Structure      | Status      | File           |
| ------------------- | ----------- | -------------- |
| Array               | Completed   | Array.cpp      |
| Singly Linked List  | Completed   | linkedList.cpp |
| Stack (Linked List) | Completed   | Stack.cpp      |
| Queue (Linked List) | Completed   | Queue.cpp      |
| Trees               | Coming Soon | —              |

---

# 1. Overview of All Concepts

Before diving into each implementation file, here is a conceptual overview:

### **1. Array**

A contiguous memory block.
Fast random access O(1).
Insert/Delete expensive due to shifting.
Fixed size unless resized manually.

### **2. Singly Linked List**

A chain of nodes, where each node has:

* data
* pointer to next

Flexible size, fast insertion anywhere (O(1) if position known), but slow searching (O(n)).

### **3. Stack (LIFO)**

Implemented using Linked List.
Fast operations: push/pop are O(1).

### **4. Queue (FIFO)**

Implemented using Linked List.
Maintains `front` and `rear` pointers for O(1) enqueue/dequeue.

---

# 2. Array.cpp — Full Documentation

## 2.1 Purpose

The **Array** class manually manages a block of memory using `new int[size]`.
It replicates basic functionality of a simplified array/vector without using STL.

---

## 2.2 Attributes (Variables)

Inside the class:

* `int* arr` → pointer to the allocated memory.
* `int size` → the total allocated capacity.
* `int length` → how many elements are currently stored.

**Memory layout example:**

```
Index: 0   1   2   3   4
Value: 10  25  7   X   X
                 ↑
           unused memory
```

---

## 2.3 Constructor

**Purpose:** allocate a new integer array and initialize counters.

```
Array(int s) {
    size = s;
    arr = new int[size];
    length = 0;
}
```

### Explanation:

* `size` stores the maximum capacity.
* `new int[size]` allocates contiguous memory.
* `length = 0` because the array is empty initially.

---

## 2.4 Functions — Full Explanation

### **void fill()**

Fills the array with user input.

* Prompts user for `length`
* Ensures `length <= size`
* Reads each value into `arr[i]`

Used for testing and practice.

---

### **void append(int value)**

Adds a new element at the end *if capacity allows*.

Logic:

* If `length < size`, write element at `arr[length]`.
* Increment `length`.

---

### **void insert(int index, int value)**

Inserts at a specific index by shifting elements.

Steps:

1. Validate index
2. Shift elements one step to the right
3. Insert value at index
4. Increase `length`

Memory shift example:

Before:

```
10 20 30 40 X
    ↑ insert here
```

After:

```
10 20 99 30 40
```

---

### **void Delete(int index)**

Removes element by shifting left.

Before:

```
10 20 30 40
       ↑ delete index 2
```

After:

```
10 20 40 X
```

---

### **int search(int key)**

Linear search → returns index or -1.

---

### **void display()**

Print all elements up to `length`.

---

## 2.5 Time Complexity

| Operation | Complexity      |
| --------- | --------------- |
| Access    | O(1)            |
| Search    | O(n)            |
| Insert    | O(n) (shifting) |
| Delete    | O(n)            |
| Append    | O(1)            |

---

# 3. linkedList.cpp — Full Documentation (Singly Linked List)

## 3.1 Node Structure

Each node contains:

```
int data;
Node* next;
```

Memory representation:

```
[data | next] → [data | next] → [data | next]
```

---

## 3.2 Class Attributes

* `Node* head` → pointer to the first node in the list.

If list is empty:

```
head = NULL
```

---

## 3.3 Functions — Full Breakdown

---

### **bool isEmpty()**

Checks whether `head == NULL`.

---

### **void insertFirst(int newItem)**

Creates a new node and inserts it at the beginning.

Steps:

1. Allocate node
2. Set `data = newItem`
3. Point `newNode->next` to current head
4. Update `head`

Memory:

Before:

```
head → A → B → C
```

After:

```
new → A → B → C
↑
head
```

---

### **void insertLast(int newItem)**

If list is empty: becomes head.
Otherwise, traverse until last node (`next == NULL`), then attach new node.

---

### **void insertAfter(int oldItem, int newItem)**

Find node with value = oldItem
Insert new node after it by adjusting pointers:

```
old → next becomes new
new → next becomes old->next
```

---

### **void deleteNode(int item)**

Handles three cases:

1. Delete head
2. Delete middle
3. Delete last

Pointer adjustments:

```
prev->next = temp->next
delete temp
```

---

### **Node* search(int item)**

Linear traversal until match.

---

### **void display()**

Prints all nodes.

---

## 3.4 Time Complexity

| Operation      | Complexity |
| -------------- | ---------- |
| Insert at head | O(1)       |
| Insert at end  | O(n)       |
| Search         | O(n)       |
| Delete         | O(n)       |
| Traverse       | O(n)       |

---

# 4. Stack.cpp — Full Documentation

Stack is implemented using Linked List for fast push/pop.

## 4.1 Attributes

* `Node* top` → pointer to the top of the stack.

---

## 4.2 Functions

### **void push(int item)**

Creates a new node, inserts it at the top.

### **int pop()**

Removes top node, returns its value.

### **bool isEmpty()**

Checks top == NULL.

### **int peek()**

Returns top’s data without removing it.

---

## 4.3 Time Complexity

All operations O(1).

---

# 5. Queue.cpp — Full Documentation

Queue implemented using Linked List.

## 5.1 Attributes

* `Node* front`
* `Node* rear`

---

## 5.2 Functions

### **void enqueue(int item)**

Attach new node at rear.

Memory:

```
front → A → B → C ← rear
```

### **int dequeue()**

Remove node from front.

### **bool isEmpty()**

`front == NULL`

### **int getFront()**

Returns front item.

---

## 5.3 Time Complexity

All ops O(1).

---

# 6. Cross-Structure Memory Explanation

### Arrays

* Contiguous memory
* Fast access
* Expensive shifting

### Linked Lists

* Non-contiguous nodes
* Cheap insert/delete
* Slow search

### Stacks and Queues

* Special behaviors built on linked list mechanics

---

# 7. Summary Table

| Structure   | Memory Type     | Strength             | Weakness       | Complexity |
| ----------- | --------------- | -------------------- | -------------- | ---------- |
| Array       | contiguous      | fast access          | slow shifting  | mix        |
| Linked List | scattered nodes | fast insert/delete   | slow search    | linear     |
| Stack       | linked          | fast push/pop        | limited access | O(1)       |
| Queue       | linked          | fast enqueue/dequeue | none major     | O(1)       |

---

# 8. Notes & Recommendations

* Consider adding a destructor in each file to free memory.
* You may extend the Array with resizing (like vector).
* Add error-checking for robustness.
* Trees & Graphs may be added later.

---
