# 🚀 DSA in C++

Welcome to my **DSA Journey in C++** 🎯  
This repository is my personal library of **Data Structures & Algorithms** solutions, written in C++ with clean code, explanations, and time/space complexity analysis.

I’m starting this repo as part of **Hacktoberfest 2025**, but it’s not limited to October — this will be a **long-term project** where I keep adding new problems, optimizations, and resources.

---

## 📂 Repository Structure

```

DSA-in-CPP/
│
├── Arrays/
├── Strings/
├── LinkedList/
├── Stack/
├── Queue/
├── Trees/
├── Graphs/
├── DynamicProgramming/
└── Sorting/

```

Each folder contains problems related to that topic, written in **C++** with:

- ✅ Problem statement (commented at the top)
- ✅ C++ implementation with proper explanations
- ✅ Time & Space Complexity

---

## 📝 Example File Structure

```cpp
/*
Problem: Reverse a Linked List
Link: https://leetcode.com/problems/reverse-linked-list/
Difficulty: Easy

Approach:
- Use iterative method with 3 pointers (prev, curr, next).
- Reverse links while traversing.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
```

---

## 🚀 How to Run

1. Clone the repo:

   ```
   git clone https://github.com/your-username/DSA-in-CPP.git
   cd DSA-in-CPP
   ```

2. Navigate to a problem folder:

   ```
   cd LinkedList
   g++ ReverseLinkedList.cpp -o reverse
   ./reverse
   ```
