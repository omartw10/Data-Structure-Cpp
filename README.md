

# 🧩 Data Structures in C++

This repository contains implementations of fundamental **Data Structures** using **C++**, built manually without STL to help beginners understand how each structure behaves internally.

Each structure is coded using **Object-Oriented Programming (OOP)** and designed to be readable, clean, and easy for students to follow.

The project will continue to grow as more structures are completed.

---

## 📌 Included Data Structures (Status)

| Data Structure                   |    Status   | File              |
| -------------------------------- | :---------: | ----------------- |
| 🧮 Arrays                        | ✅ Completed | `array.cpp`       |
| 🔗 Linked List (Singly)          | ✅ Completed | `linked-list.cpp` |
| 📚 Stack (Linked Implementation) | ✅ Completed | `stack.cpp`       |
| 🧾 Queue (Linked Implementation) | ✅ Completed | `queue.cpp`       |
| 🌲 Binary Search Tree (BST)      | ✅ Completed | `tree-bst.cpp`    |

---

## 🧮 Arrays (Completed)

Basic array functionality implemented manually:

* Fill
* Display
* Append
* Insert
* Delete
* Search

📄 File: `Array.cpp`

---

## 🔗 Linked List (Completed)

A singly linked list implementation covering:

* Insert at beginning
* Append
* Insert before a given value
* Search
* Delete item
* Count items
* Display the list

📄 File: `LinkedList.cpp`

---

## 📚 Stack (Completed)

A **Stack** implemented using a linked list structure:

* `push()` — Add item to top
* `pop()` — Remove and return top item
* `peek()` — Read top item
* `isEmpty()`
* `isFound()` — Search for a value
* `count()` — Total elements
* `display()` — Visualize stack (top → bottom)

📄 File: `Stack.cpp`

---

## 🧾 Queue (Completed)

A **Queue** implemented using a linked list (FIFO behavior):

* `enqueue()` — Add item to rear
* `dequeue()` — Remove front item
* `peek()` — Read the front item
* `isEmpty()`
* `count()` — Number of elements
* `getFront()` — Return front item
* `getRear()` — Return rear item
* `clear()` — Remove all items

📄 File: `Queue.cpp`

---

## 🌲 Binary Search Tree (Completed)

A fully implemented **Binary Search Tree (BST)** with all essential operations:

### ✔ Node Structure

Each node contains:

* `data`
* `left`
* `right`

### ✔ Supported Operations

* **insert()** — Recursive insertion into left/right subtree
* **preorder()** — Root → Left → Right
* **inorder()** — Left → Root → Right
* **postorder()** — Left → Right → Root
* **search()** — Find a value recursively
* **findMin()** — Left-most node
* **findMax()** — Right-most node
* **deleteNode()** — Remove a node using BST replacement rules

### ✔ Behavior

This BST implementation is suitable for learning how recursive tree operations work, including deletion logic with:

* leaf node deletion
* deletion with one child
* deletion with two children (using max from left subtree)

📄 File: `tree-bst.cpp`

---

## 🧑‍💻 How to Run

Compile any file using:

```bash
g++ filename.cpp -o output
./output
```

Example:

```bash
g++ tree-bst.cpp -o tree
./tree
```

---

## 💡 Recommended Extension (VS Code)

Install:

> **Better Comments**

To improve readability of the structured comments in the source code.

---

## 📘 Concepts Covered

* Fundamentals of Data Structures
* Dynamic Memory Allocation
* Pointers & Linked Nodes
* Trees & Recursive Algorithms
* OOP Structure for DS Implementation
* Arrays vs Linked Structures
* Stack (LIFO) Behavior
* Queue (FIFO) Behavior
* Binary Search Tree Operations

---

## 📝 Source Acknowledgment

Parts of this project were inspired by:

**Eng. Mohamed El-Desouki – YouTube**
with improvements for clarity and structure.

---

## 🧔 Author

Developed by **Omar**
A progressive learning project focused on writing core data structures in C++ manually.

---

## 📅 Project Goal

Build a full educational set of manually implemented data structures:

✔ Arrays
✔ Linked Lists
✔ Stacks
✔ Queues
✔ Binary Search Tree

All written completely from scratch (no STL) to understand internal behavior of each structure.

