
+++
authors = ["grid47"]
title = "Leetcode 155: Min Stack"
date = "2024-10-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 155: Min Stack in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/155.webp"
youtube = "RfMroCV17-4"
youtube_upload_date="2024-02-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/RfMroCV17-4/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/155.webp" 
    alt="A stack where each layer gently illuminates, showing the minimum value glowing at the bottom."
    caption="Solution to LeetCode 155: Min Stack Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sequence of operations performed on a MinStack object. Operations include push, pop, top, and getMin.
- **Example:** `[[], [-2], [0], [-3], [], [], [], []]`
- **Constraints:**
	- -231 <= val <= 231 - 1
	- pop, top, and getMin operations will always be called on non-empty stacks.
	- At most 3 * 10^4 calls will be made to push, pop, top, and getMin.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output will be the results of the getMin, top, and pop operations, in sequence, as requested in the input.
- **Example:** `[null, null, null, null, -3, null, 0, -2]`
- **Constraints:**
	- The result of each method call will be part of the output sequence.

{{< dots >}}
### Core Logic 🔍
**Goal:** To implement the stack operations with constant time complexity.

- Use a linked list node to store each element and the minimum element at that point in the stack.
- Each node should hold the current element and the minimum value up to that element.
- The push operation should update the minimum if the current element is smaller than the current minimum.
- The pop operation should simply remove the top node from the stack.
- The top operation should return the value of the top node.
- The getMin operation should return the minimum value stored in the top node.
{{< dots >}}
### Problem Assumptions ✅
- The stack is non-empty when pop, top, and getMin are called.
{{< dots >}}
## Examples 🧩
- **Input:** `[[], [-2], [0], [-3], [], [], [], []]`  \
  **Explanation:** This series of operations initializes the MinStack and performs various operations on it. The stack changes as elements are pushed and popped, and getMin returns the current minimum element after each operation.

{{< dots >}}
## Approach 🚀
A linked list approach is used where each node holds the element and the minimum value up to that point in the stack. This allows constant-time retrieval of the minimum element.

### Initial Thoughts 💭
- The stack needs to support constant-time retrieval of the minimum element.
- Each node should store the current minimum value to achieve O(1) retrieval time for getMin.
{{< dots >}}
### Edge Cases 🌐
- The stack will never be empty when pop, top, or getMin are called.
- The solution must efficiently handle up to 30,000 operations.
- Handle large and negative values for stack elements.
- Each operation must run in O(1) time.
{{< dots >}}
## Code 💻
```cpp
int val;
int mn;
Node* node;
Node(int val, int mn, Node* node) {
    this->val = val;
    this->mn = mn;
    this->node = node;
}
};

class MinStack {
public:
Node* head;
MinStack() {
    head = NULL;
}

void push(int val) {
    if(!head) {
        head = new Node(val, val, NULL);
    } else {
        head = new Node(val, min(head->mn, val), head);
    }
}

void pop() {
    head = head->node;
}

int top() {
    return head->val;
}

int getMin() {
    return head->mn;
}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
```

This code defines a class MinStack that supports operations to push, pop, retrieve the top element, and get the minimum element in a stack.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int val;
	```
	Declare an integer 'val' to store the current value pushed to the stack.

2. **Variable Declaration**
	```cpp
	int mn;
	```
	Declare an integer 'mn' to store the minimum value in the stack at the current point.

3. **Pointer Declaration**
	```cpp
	Node* node;
	```
	Declare a pointer 'node' that will point to the next node in the linked list.

4. **Constructor**
	```cpp
	Node(int val, int mn, Node* node) {
	```
	Constructor for Node which initializes 'val', 'mn', and 'node' fields.

5. **Constructor Initialization**
	```cpp
	    this->val = val;
	```
	Set the value 'val' of the current node.

6. **Constructor Initialization**
	```cpp
	    this->mn = mn;
	```
	Set the minimum value 'mn' of the current node.

7. **Constructor Initialization**
	```cpp
	    this->node = node;
	```
	Set the 'node' pointer to point to the next node in the stack.

8. **Class Declaration**
	```cpp
	class MinStack {
	```
	Define the MinStack class, which represents the stack with operations to push, pop, and retrieve minimum values.

9. **Pointer Declaration**
	```cpp
	Node* head;
	```
	Declare a pointer 'head' to the top node of the stack.

10. **Constructor**
	```cpp
	MinStack() {
	```
	Constructor for MinStack class, initializing the stack.

11. **Initialization**
	```cpp
	    head = NULL;
	```
	Initialize the 'head' pointer to NULL, indicating the stack is empty.

12. **Function Definition**
	```cpp
	void push(int val) {
	```
	Define the push function to add a new element to the stack.

13. **Conditional Check**
	```cpp
	    if(!head) {
	```
	Check if the stack is empty (head is NULL).

14. **Node Creation**
	```cpp
	        head = new Node(val, val, NULL);
	```
	Create a new node with the value 'val', setting its minimum to 'val' and pointing to NULL.

15. **Else Block**
	```cpp
	    } else {
	```
	Else block executed when the stack is not empty.

16. **Node Creation**
	```cpp
	        head = new Node(val, min(head->mn, val), head);
	```
	Create a new node with the value 'val', updating the minimum to be the smaller of the current minimum and 'val'.

17. **Function Definition**
	```cpp
	void pop() {
	```
	Define the pop function to remove the top element from the stack.

18. **Pointer Update**
	```cpp
	    head = head->node;
	```
	Update the 'head' pointer to point to the next node in the stack, effectively removing the current top node.

19. **Function Definition**
	```cpp
	int top() {
	```
	Define the top function to return the value of the current top element of the stack.

20. **Return Statement**
	```cpp
	    return head->val;
	```
	Return the value of the top node in the stack.

21. **Function Definition**
	```cpp
	int getMin() {
	```
	Define the getMin function to retrieve the minimum value in the stack.

22. **Return Statement**
	```cpp
	    return head->mn;
	```
	Return the minimum value of the top node in the stack.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

Each operation (push, pop, top, getMin) runs in constant time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

In the worst case, the space complexity is O(n) due to the linked list nodes storing each element in the stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/min-stack/description/)

---
{{< youtube RfMroCV17-4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
