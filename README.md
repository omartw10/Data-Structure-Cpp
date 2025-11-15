# 🧩 Data Structures in C++

This repository contains implementations of fundamental **Data Structures** using **C++**, built manually without STL to help beginners understand how each structure behaves internally.

Each structure is coded using **Object-Oriented Programming (OOP)** and designed to be readable, clean, and easy for students to follow.

The project will continue to grow as more structures are completed.

---

## 📌 Included Data Structures (Status)

| Data Structure | Status | File |
|----------------|:------:|------|
| 🧮 Arrays | ✅ Completed | `array.cpp` |
| 🔗 Linked List (Singly) | ✅ Completed | `linked-list.cpp` |
| 📚 Stack (Linked Implementation) | ✅ Completed | `stack.cpp` |
| 🧾 Queue (Linked Implementation) | ✅ Completed | `queue.cpp` |
| 🌲 Trees | ⏳ Coming Soon | — |

---

## 🧮 Arrays (Completed)

Basic array functionality implemented manually:

- Fill  
- Display  
- Append  
- Insert  
- Delete  
- Search  

📄 File: `Array.cpp`

---

## 🔗 Linked List (Completed)

A singly linked list implementation covering:

- Insert at beginning  
- Append  
- Insert before a given value  
- Search  
- Delete item  
- Count items  
- Display the list  

📄 File: `LinkedList.cpp`

---

## 📚 Stack (Completed)

A **Stack** implemented using a linked list structure:

- `push()` — Add item to top  
- `pop()` — Remove and return top item  
- `peek()` — Read top item  
- `isEmpty()`  
- `isFound()` — Search for a value  
- `count()` — Total elements  
- `display()` — Visualize stack (top → bottom)  

This helps in understanding stack behavior (LIFO) with dynamic memory.

📄 File: `Stack.cpp`

---

## 🧾 Queue (Completed)

A **Queue** implemented using a linked list (FIFO behavior):

- `enqueue()` — Add item to rear  
- `dequeue()` — Remove front item  
- `peek()` — Read the front item  
- `isEmpty()`  
- `count()` — Number of elements  
- `getFront()` — Return front item  
- `getRear()` — Return rear item  
- `clear()` — Remove all items  

📄 File: `Queue.cpp`

---

## 🧑‍💻 How to Run

Compile any file using:

```bash
g++ filename.cpp -o output
./output
```

Example:

```bash
g++ Queue.cpp -o queue
./queue
```

---

## 💡 Recommended Extension (VS Code)

Install the extension:

> **Better Comments**

This improves readability of structured comments used throughout the code.

---

## 📘 Concepts Covered

- Fundamentals of Data Structures  
- Dynamic Memory Allocation  
- Pointers & Linked Nodes  
- OOP Structure for DS Implementation  
- Arrays vs Linked Structures  
- Stack (LIFO) Behavior  
- Queue (FIFO) Behavior  

---

## 📝 Source Acknowledgment

Parts of this project were inspired by tutorials from:

**Eng. Mohamed El-Desouki – YouTube**  
with minor modifications and improvements added for clarity and structure.

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
⏳ Trees  

All coded from scratch, without STL, to strengthen understanding of how each structure works internally.
