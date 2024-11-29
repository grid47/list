
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
comments = true
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
Design a custom linked list that supports multiple operations. You can choose to implement it using a singly or doubly linked list. Implement the following methods in the MyLinkedList class:
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the following method calls: 'MyLinkedList', 'addAtHead', 'addAtTail', 'addAtIndex', 'get', 'deleteAtIndex'. Each of these methods will take the necessary arguments as specified.
- **Example:** ``
- **Constraints:**

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of a series of responses to the methods called. For each 'get' operation, the value of the node at the specified index is returned, or -1 if the index is invalid. For other operations, the response is 'null'.
- **Example:** ``
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Implement a linked list with operations to retrieve, add, and delete nodes at specified indices.

- Initialize a linked list with a head pointer to track the first node.
- Implement methods to add nodes at the head, tail, or a specific index.
- Implement a method to retrieve the value of a node at a specific index.
- Implement a method to delete a node at a specific index.
{{< dots >}}
### Problem Assumptions ✅
- All operations are performed in constant time where possible.
{{< dots >}}
## Examples 🧩
- **Input:** `MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);
myLinkedList.get(1);
myLinkedList.deleteAtIndex(1);
myLinkedList.get(1);`  \
  **Explanation:** In this example, the linked list is initialized as an empty list. The sequence of operations adds elements at the head and tail, inserts an element at a specific index, retrieves an element at an index, deletes an element, and retrieves the element at that index again after deletion.

{{< dots >}}
## Approach 🚀
The approach involves maintaining a linked list with nodes containing a value and a reference to the next node. The operations modify or access nodes based on the index provided.

### Initial Thoughts 💭
- A singly linked list can efficiently handle these operations with proper indexing.
- Node insertion and deletion at specific indices require traversing the list, which is key to handling this problem.
- We will maintain a reference to the head of the linked list and adjust the pointers when adding or removing nodes.
{{< dots >}}
### Edge Cases 🌐
- Operations on an empty list (e.g., get, deleteAtIndex).
- Handling up to 2000 operations efficiently.
- When index equals 0 or the end of the list.
- Ensure that invalid indices are handled gracefully by returning -1 or skipping invalid operations.
{{< dots >}}
## Code 💻
```cpp
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
```

This is the implementation of a singly linked list, with methods to add, delete, and retrieve nodes at specified indices.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	    int val;
	```
	Declare a variable 'val' to store the value of the node.

2. **Node Declaration**
	```cpp
	    Node* next;
	```
	Declare a pointer 'next' to the next node in the list.

3. **Constructor**
	```cpp
	Node(int x): val(x), next(nullptr) {}
	```
	Constructor to initialize a node with a given value 'x' and set 'next' to nullptr.

4. **Class Declaration**
	```cpp
	class MyLinkedList {
	```
	Define the MyLinkedList class which holds the methods and variables related to the linked list.

5. **Variable Declaration**
	```cpp
	int sz;
	```
	Declare an integer variable 'sz' to store the size of the linked list.

6. **Node Declaration**
	```cpp
	Node* head;
	```
	Declare a pointer 'head' to point to the first node in the linked list.

7. **Public Access Modifier**
	```cpp
	public:
	```
	Indicates that the following methods and variables are accessible outside the class.

8. **Constructor**
	```cpp
	MyLinkedList(): sz(0), head(nullptr) { }
	```
	Constructor to initialize the linked list with size 0 and head as nullptr.

9. **Method Declaration**
	```cpp
	int get(int index) {
	```
	Define the 'get' method to retrieve the value of the node at the specified index.

10. **Edge Case Handling**
	```cpp
	    if(index < 0 || index >= sz)
	```
	Check if the index is valid. If not, return -1.

11. **Return Statement**
	```cpp
	    return -1;
	```
	Return -1 when the index is out of bounds.

12. **Conditional Branch**
	```cpp
	    else {
	```
	Start the else block to handle valid index.

13. **Node Traversal**
	```cpp
	        Node* curr = head;
	```
	Create a pointer 'curr' to traverse the linked list starting from the head.

14. **Loop**
	```cpp
	        for(int i = 0; i < index;i++)
	```
	Use a loop to traverse the list until the specified index.

15. **Pointer Update**
	```cpp
	        curr = curr->next;
	```
	Move the 'curr' pointer to the next node.

16. **Return Statement**
	```cpp
	        return curr->val;
	```
	Return the value of the node at the specified index.

17. **Method Declaration**
	```cpp
	void addAtHead(int val) {
	```
	Define the 'addAtHead' method to add a new node at the head of the list.

18. **Method Call**
	```cpp
	    addAtIndex(0, val);
	```
	Call 'addAtIndex' method to add the new node at index 0.

19. **Method Declaration**
	```cpp
	void addAtTail(int val) {
	```
	Define the 'addAtTail' method to add a new node at the end of the list.

20. **Method Call**
	```cpp
	    addAtIndex(sz, val);        
	```
	Call 'addAtIndex' method to add the new node at the tail (end of the list).

21. **Method Declaration**
	```cpp
	void addAtIndex(int index, int val) {
	```
	Define the 'addAtIndex' method to insert a node at a specific index.

22. **Edge Case Handling**
	```cpp
	    if(index > sz || index < 0) return;
	```
	Check if the index is valid. If not, do nothing.

23. **Node Creation**
	```cpp
	    Node* new_node = new Node(val);
	```
	Create a new node with the given value 'val'.

24. **Conditional Branch**
	```cpp
	    if(index == 0) {
	```
	Start the block to handle insertion at index 0.

25. **Node Update**
	```cpp
	        new_node->next = head;
	```
	Set the 'next' pointer of the new node to point to the current head.

26. **Pointer Update**
	```cpp
	        head = new_node;
	```
	Update the head pointer to point to the new node.

27. **End of Conditional Block**
	```cpp
	    } else {
	```
	Handle the insertion at other indices.

28. **Node Traversal**
	```cpp
	        for(int i = 0; i < index - 1; i++)
	```
	Traverse the list to find the node just before the insertion point.

29. **Pointer Update**
	```cpp
	            cur = cur->next;
	```
	Move the 'cur' pointer to the next node.

30. **Linking Nodes**
	```cpp
	        new_node->next = cur->next;
	```
	Set the 'next' pointer of the new node to point to the next node after 'cur'.

31. **Pointer Update**
	```cpp
	        cur->next = new_node;
	```
	Set the 'next' pointer of 'cur' to point to the new node.

32. **Size Update**
	```cpp
	    sz++;
	```
	Increment the size of the linked list after adding the new node.

33. **Method Declaration**
	```cpp
	void deleteAtIndex(int index) {
	```
	Define the 'deleteAtIndex' method to delete a node at a specified index.

34. **Edge Case Handling**
	```cpp
	    if(index >= sz || index < 0) return;
	```
	Check if the index is valid. If not, do nothing.

35. **Conditional Branch**
	```cpp
	    if(index == 0) {
	```
	Start block to delete the node at index 0.

36. **Pointer Update**
	```cpp
	        Node* nxt = head->next;
	```
	Store the pointer to the next node in 'nxt'.

37. **Node Deletion**
	```cpp
	        delete head;
	```
	Delete the current head node.

38. **Pointer Update**
	```cpp
	        head = nxt;
	```
	Update the head pointer to point to the next node.

39. **End of Conditional Block**
	```cpp
	    } else {
	```
	Handle the deletion for other indices.

40. **Node Traversal**
	```cpp
	        Node* cur = head;
	```
	Traverse the list to find the node just before the one to delete.

41. **Loop**
	```cpp
	        for(int i = 0; i < index - 1; i++)
	```
	Traverse through the nodes until reaching the desired index.

42. **Pointer Update**
	```cpp
	            cur = cur->next;
	```
	Move the 'cur' pointer to the next node.

43. **Link Update**
	```cpp
	        Node* nxt = cur->next->next;
	```
	Save the pointer to the next node after the one to delete.

44. **Node Deletion**
	```cpp
	        delete cur->next;
	```
	Delete the node at the specified index.

45. **Pointer Update**
	```cpp
	        cur->next = nxt;
	```
	Update the 'next' pointer of 'cur' to skip the deleted node.

46. **Size Update**
	```cpp
	    sz--;
	```
	Decrement the size of the linked list after deleting a node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for get, addAtHead, and addAtTail.
- **Average Case:** O(n) for addAtIndex and deleteAtIndex where n is the size of the list.
- **Worst Case:** O(n) for all operations where n is the size of the list.

The time complexity for operations like 'get', 'addAtHead', and 'addAtTail' is O(1), but for operations that require traversing the list (e.g., addAtIndex and deleteAtIndex), it is O(n).

### Space Complexity 💾
- **Best Case:** O(1), for an empty list or when minimal memory is used.
- **Worst Case:** O(n), where n is the number of nodes in the list.

Space complexity is proportional to the number of nodes in the list, as each node occupies space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-linked-list/description/)

---
{{< youtube Wf4QhpdVFQo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
