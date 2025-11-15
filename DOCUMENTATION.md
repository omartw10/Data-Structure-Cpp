

# 📘 **Documentation — Educational Guide to Core Data Structures in C++**

This document provides a structured, clear, and student-friendly explanation of all data structures implemented in this project.
It includes diagrams, workflow illustrations, and conceptual explanations suitable for university-level courses.

---

# **1. Array — Contiguous Memory Structure**

## **1.1 What an Array Looks Like in Memory**

```
+-----+-----+-----+-----+-----+
| 10  | 25  | 30  | 50  |  X  |
+-----+-----+-----+-----+-----+
  0     1     2     3     4   ← index
```

* Memory is **contiguous** (back-to-back blocks).
* Direct access via:
  `address = base + index * sizeof(int)`

---

## **1.2 Core Attributes**

| Attribute    | Meaning                       |
| ------------ | ----------------------------- |
| `int* arr`   | Pointer to first memory block |
| `int size`   | Total allocated capacity      |
| `int length` | Number of valid elements      |

---

## **1.3 Insert Operation (with shifting)**

### Before inserting `99` at index 2:

```
Index:   0     1     2     3     4
        +-----+-----+-----+-----+-----+
        | 10  | 25  | 30  | 50  |  X  |
        +-----+-----+-----+-----+-----+
                      ↑ insert here
```

### After shifting:

```
+-----+-----+-----+-----+-----+
| 10  | 25  | 30  | 50  | 50  |
+-----+-----+-----+-----+-----+
                      ↑ shifted
```

### Final result:

```
+-----+-----+-----+-----+-----+
| 10  | 25  | 99  | 30  | 50  |
+-----+-----+-----+-----+-----+
```

---

## **1.4 Time Complexity Summary**

| Operation | Complexity |
| --------- | ---------- |
| Access    | O(1)       |
| Insert    | O(n)       |
| Delete    | O(n)       |
| Append    | O(1)       |
| Search    | O(n)       |

---

# **2. Singly Linked List — Dynamic Node-Based Structure**

## **2.1 Node Representation**

```
+---------+-----------+
|  data   |   next →  |
+---------+-----------+
```

Nodes are scattered in memory, connected by pointers.

---

## **2.2 Linked List Visual Example**

```
head
 ↓
+----+----+     +----+----+     +----+----+
| 10 | o----→   | 20 | o----→   | 30 |NULL|
+----+----+     +----+----+     +----+----+
```

---

## **2.3 Insert at Beginning**

### Before:

```
head → [10] → [20] → NULL
```

### After inserting 5:

```
head
 ↓
[5] → [10] → [20] → NULL
```

Operation is **O(1)** because no traversal is needed.

---

## **2.4 Insert at End**

```
Traverse until next == NULL
Then attach new node
```

Diagram:

```
[10] → [20] → [30] → NULL
                      ↓
                    insert here
```

---

## **2.5 Delete Operation**

Deleting value 20:

### Before:

```
[10] → [20] → [30] → NULL
         ↑ delete
```

### After:

```
[10] → [30] → NULL
```

---

# **3. Stack — LIFO Structure (Linked List Implementation)**

## **3.1 Visual Understanding**

Stack top visually grows upward:

```
    top
     ↓
+---------+
|   40    |
+---------+
|   30    |
+---------+
|   10    |
+---------+
```

---

## **3.2 Push Operation**

### Before:

```
top → [30] → [10]
```

### After push(40):

```
top → [40] → [30] → [10]
```

**Always O(1)**

---

## **3.3 Pop Operation**

```
pop() removes the top node
```

### Before:

```
top → [40] → [30] → [10]
```

### After:

```
top → [30] → [10]
```

---

# **4. Queue — FIFO Structure (Linked List Implementation)**

## **4.1 Concept Visualization**

```
front → [oldest] → […] → [newest] ← rear
```

---

## **4.2 Enqueue Operation**

### Before:

```
front → [10] → [20] ← rear
```

### After enqueue(30):

```
front → [10] → [20] → [30] ← rear
```

---

## **4.3 Dequeue Operation**

### Before:

```
front → [10] → [20] → [30]
```

### After:

```
front → [20] → [30]
```

---

# **5. Binary Search Tree (BST) — Hierarchical Linked Structure**

## **5.1 Structure Overview**

```
        (40)
       /    \
    (20)    (60)
    /  \    /  \
 (10)(30)(50)(70)
```

BST Rules:

* Left child < parent
* Right child > parent

---

## **5.2 Insert Operation**

Inserting 25:

Path:

```
25 < 40 → go left
25 > 20 → go right
25 < 30 → insert as left child
```

```
      (40)
       |
      (20)
        \
        (30)
        /
      (25) ← new
```

---

## **5.3 Search Operation**

Searching for 30:

```
30 < 40 → left  
30 > 20 → right  
found
```

Visualization:

```
(40)
  ↓
(20)
  ↓
(30) ← found
```

---

## **5.4 Traversals (Tree Printing Orders)**

### **Inorder (L → Root → R)**

```
Outputs sorted values
```

Example:

```
10 20 25 30 40 50 60 70
```

### **Preorder (Root → L → R)**

Used for tree copying.

### **Postorder (L → R → Root)**

Used for tree deletion.

---

## **5.5 Delete Operation Overview**

Three major cases:

### **Case 1 — Leaf Node**

```
   (20)
     \
    (30) ← delete
```

Becomes:

```
(20)
```

---

### **Case 2 — One Child**

```
 (20)
   \
   (30)
     \
     (40)
```

Delete 30 → replace by its child.

---

### **Case 3 — Two Children**

Replace with **inorder successor** or **inorder predecessor**.

Visualization:

```
       (50)
      /    \
   (30)    (70)
          /
        (60)
```

Deleting 50:

* Successor = 60
* Replace 50 → 60

```
       (60)
      /    \
   (30)    (70)
```

---

# **6. Summary Comparison**

| Structure   | Best Use               | Weakness                  |
| ----------- | ---------------------- | ------------------------- |
| Array       | Fast indexing          | Slow shifting             |
| Linked List | Fast insert/delete     | Slow access               |
| Stack       | Expression evaluation  | Only top accessible       |
| Queue       | Scheduling & buffering | Cannot access middle      |
| BST         | Fast search (balanced) | Poor worst-case if skewed |

---

# **7. Final Notes for Students**

* Arrays are ideal when size is known.
* Linked Lists are ideal when size changes frequently.
* Stacks and Queues are special-purpose linear structures.
* Trees allow **hierarchical** organization and fast searching.
* BST efficiency depends heavily on shape (balanced vs skewed).

