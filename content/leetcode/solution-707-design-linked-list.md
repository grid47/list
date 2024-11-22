
+++
authors = ["grid47"]
title = "Leetcode 707: Design Linked List"
date = "2024-08-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 707: Design Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/707.webp"
youtube = "Wf4QhpdVFQo"
youtube_upload_date="2023-01-10"
youtube_thumbnail="https://i.ytimg.com/vi/Wf4QhpdVFQo/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/707.webp" 
    alt="A glowing linked list where each node is linked and highlighted softly as it’s connected."
    caption="Solution to LeetCode 707: Design Linked List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Node {
    public:
        int val;
        Node* next;
    Node(int x): val(x), next(nullptr) {}
};
class MyLinkedList {
    int sz;
    Node* head;

public:
    MyLinkedList(): sz(0), head(nullptr) { }
    
    int get(int index) {
        if(index < 0 || index >= sz)
        return -1;
        else {
            Node* curr = head;
            for(int i = 0; i < index;i++)
            curr = curr->next;
            return curr->val;
        }
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(sz, val);        
    }
    
    void addAtIndex(int index, int val) {
        if(index > sz || index < 0) return;
        Node* cur = head;
        Node* new_node = new Node(val);
        if(index == 0) {
            new_node->next = head;
            head = new_node;
        } else {
            for(int i = 0; i < index - 1; i++)
                cur = cur->next;
            new_node->next = cur->next;
            cur->next = new_node;
        }
        sz++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= sz || index < 0) return;

        if(index == 0) {
            Node* nxt = head->next;
            delete head;
            head = nxt;
        } else {
            Node* cur = head;
            for(int i = 0; i < index - 1; i++)
                cur = cur->next;
            Node* nxt = cur->next->next;
            delete cur->next;
            cur->next = nxt;
        }
        sz--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
{{< /highlight >}}
---

### Problem Statement:
The problem involves implementing a singly linked list class, `MyLinkedList`, that supports the following operations:

1. **get(index)**: Returns the value at the given index of the linked list. If the index is invalid, return `-1`.
2. **addAtHead(val)**: Adds a new node with the value `val` at the beginning of the linked list.
3. **addAtTail(val)**: Adds a new node with the value `val` at the end of the linked list.
4. **addAtIndex(index, val)**: Adds a new node with the value `val` at the given index in the linked list. If the index is greater than the size of the list, the node is not added.
5. **deleteAtIndex(index)**: Deletes the node at the given index. If the index is invalid, do nothing.

Your task is to implement this linked list class efficiently with constant-time operations for certain tasks.

### Approach:
The approach to solving this problem involves using a **singly linked list** data structure. A linked list is a dynamic data structure where each element (node) stores both the data and a reference (or pointer) to the next element in the list. 

- **Head Node**: The list will have a reference to its first node, known as the head node.
- **Singly Linked List**: Each node points only to the next node and does not have a reference to its previous node. This simplifies the structure but requires traversal for certain operations.
  
The operations to be implemented require careful handling of pointers (next references) to ensure that elements are added, retrieved, and deleted in constant time when possible. The key operations include:

- **Traversal**: For adding or deleting nodes at a specific index, we must traverse the list to the required position, which takes linear time in the worst case.
- **Edge Cases**: We must handle cases where the list is empty or when the index is out of bounds.

### Code Breakdown (Step by Step):

#### Step 1: Define the Node Class
```cpp
class Node {
public:
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};
```
- The `Node` class represents an individual node in the linked list. It stores an integer value (`val`) and a pointer to the next node (`next`).
- The constructor initializes the node with a given value (`x`) and sets `next` to `nullptr`, indicating that this node does not point to any other node when it is created.

#### Step 2: Define the `MyLinkedList` Class
```cpp
class MyLinkedList {
    int sz;
    Node* head;

public:
    MyLinkedList(): sz(0), head(nullptr) { }
```
- `sz` stores the size of the linked list, initialized to `0`.
- `head` points to the first node in the linked list. Initially, it is set to `nullptr`, indicating that the list is empty.

#### Step 3: Implement the `get` Function
```cpp
int get(int index) {
    if(index < 0 || index >= sz)
        return -1;
    else {
        Node* curr = head;
        for(int i = 0; i < index; i++)
            curr = curr->next;
        return curr->val;
    }
}
```
- **Index Validation**: First, we check if the index is within the bounds of the list. If the index is negative or greater than or equal to the size of the list, return `-1`.
- **Traversal**: If the index is valid, we traverse the list by moving through `next` pointers until we reach the desired index, and return the value of the node at that index.

#### Step 4: Implement the `addAtHead` Function
```cpp
void addAtHead(int val) {
    addAtIndex(0, val);
}
```
- To add a node at the head, we simply call `addAtIndex` with `index = 0` and the given `val`. This ensures that the node is inserted at the beginning of the list.

#### Step 5: Implement the `addAtTail` Function
```cpp
void addAtTail(int val) {
    addAtIndex(sz, val);
}
```
- To add a node at the tail (end), we call `addAtIndex` with the current size of the list (`sz`) as the index, and the given value `val`. This appends the node to the end of the list.

#### Step 6: Implement the `addAtIndex` Function
```cpp
void addAtIndex(int index, int val) {
    if(index > sz || index < 0) return;
    Node* cur = head;
    Node* new_node = new Node(val);
    if(index == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        for(int i = 0; i < index - 1; i++)
            cur = cur->next;
        new_node->next = cur->next;
        cur->next = new_node;
    }
    sz++;
}
```
- **Index Validation**: If the `index` is greater than the size of the list (`sz`) or negative, we simply return without adding anything.
- **Inserting at Head**: If the `index` is `0`, we insert the new node at the beginning by pointing its `next` to the current head and updating `head` to point to the new node.
- **Inserting at Other Indexes**: For other indexes, we traverse the list to find the node just before the insertion point (index - 1). Then, we adjust the `next` pointers: the new node's `next` points to the current node's `next`, and the previous node's `next` points to the new node.
- Finally, we increment the size (`sz`).

#### Step 7: Implement the `deleteAtIndex` Function
```cpp
void deleteAtIndex(int index) {
    if(index >= sz || index < 0) return;

    if(index == 0) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    } else {
        Node* cur = head;
        for(int i = 0; i < index - 1; i++)
            cur = cur->next;
        Node* nxt = cur->next->next;
        delete cur->next;
        cur->next = nxt;
    }
    sz--;
}
```
- **Index Validation**: If the `index` is out of bounds (greater than or equal to the size of the list or negative), we return without doing anything.
- **Deleting Head Node**: If the `index` is `0`, we delete the head node by updating `head` to point to the next node (`head->next`) and deleting the current head.
- **Deleting Other Nodes**: For other indexes, we traverse the list to find the node just before the one to be deleted (index - 1). We update the previous node's `next` pointer to skip the node to be deleted and free the memory of the node.

### Complexity Analysis:

#### Time Complexity:
- **get(index)**: O(n), where `n` is the number of nodes in the list. In the worst case, we might need to traverse the entire list to find the element at the given index.
- **addAtHead(val)**: O(1). Adding a node at the head involves constant time operations.
- **addAtTail(val)**: O(n). In the worst case, we need to traverse the entire list to find the tail.
- **addAtIndex(index, val)**: O(n). We may need to traverse the list to find the insertion point, especially if the index is near the end.
- **deleteAtIndex(index)**: O(n). We may need to traverse the list to find the node just before the deletion point.

#### Space Complexity:
- **O(n)**, where `n` is the number of nodes in the list. Each node requires space to store its value and pointer to the next node.

### Conclusion:
The `MyLinkedList` class implements a basic singly linked list with efficient operations for adding, deleting, and accessing nodes at specific positions. The key operations are **addAtHead** (O(1)), **addAtTail** (O(n)), **addAtIndex** (O(n)), and **deleteAtIndex** (O(n)). The space complexity is proportional to the number of elements stored in the list. This implementation provides a simple and efficient way to manipulate a linked list while handling edge cases like invalid indices and empty lists.

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-linked-list/description/)

---
{{< youtube Wf4QhpdVFQo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
