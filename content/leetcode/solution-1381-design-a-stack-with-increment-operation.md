
+++
authors = ["grid47"]
title = "Leetcode 1381: Design a Stack With Increment Operation"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1381: Design a Stack With Increment Operation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Design a stack that supports increment operations on its elements. Implement the CustomStack class, which supports adding elements, popping the top element, and incrementing the bottom k elements.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a series of operations to be performed on the stack, such as push, pop, and increment.
- **Example:** `Input: ["CustomStack", "push", "push", "pop", "push", "push", "push", "increment", "increment", "pop", "pop", "pop", "pop"]
Input Data: [[3], [1], [2], [], [2], [3], [4], [5, 100], [2, 100], [], [], [], []]`
- **Constraints:**
	- The stack can have a maximum of 1000 operations.
	- The stack size will be between 1 and 1000 elements.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the results of each operation as a list. For 'push', the result is null, for 'pop', the result is the popped element, and for 'increment', the result is null.
- **Example:** `[null, null, null, 2, null, null, null, null, null, 103, 202, 201, -1]`
- **Constraints:**
	- Each output corresponds to the respective input operation.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to implement a stack with operations to push elements, pop elements, and increment the bottom k elements by a specified value.

- 1. Initialize the stack with a maximum size.
- 2. Implement push operation to add elements to the stack.
- 3. Implement pop operation to remove and return the top element.
- 4. Implement increment operation to increment the bottom k elements by a specified value.
{{< dots >}}
### Problem Assumptions ✅
- The stack will always have enough capacity to handle the specified operations.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ["CustomStack", "push", "push", "pop", "push", "push", "push", "increment", "increment", "pop", "pop", "pop", "pop"]`  \
  **Explanation:** The operations are performed on a stack with a maximum size of 3. The push operations add elements, pop operations remove elements, and the increment operations modify the bottom k elements by adding the specified value.

{{< dots >}}
## Approach 🚀
The approach is to implement a dynamic stack that supports the basic operations (push, pop) and an increment operation that modifies the bottom k elements.

### Initial Thoughts 💭
- The stack needs to handle an increment operation that modifies multiple elements efficiently.
- We can use an array to store the stack and perform the increment operation by directly modifying the bottom k elements.
{{< dots >}}
### Edge Cases 🌐
- If no operations are performed, the stack remains empty.
- Ensure the solution works for the maximum allowed size of the stack and number of operations.
- The increment value should be between 0 and 100, and the number of elements to increment should be within the size of the stack.
- The stack should never exceed the maximum size, and operations should be efficient.
{{< dots >}}
## Code 💻
```cpp
int ptr, m;
public:

CustomStack(int mx) {
    stk.resize(mx);
    ptr = -1;
    m = mx;
}

void push(int x) {
    if (ptr < m - 1) {
        ptr++;
        stk[ptr] = x;
    }
}

int pop() {
    if(ptr == -1) return -1;
    return stk[ptr--];
}

void increment(int k, int val) {
    
    for(int i = 0; i < min(m, k); i++)
        stk[i] += val;
}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
```

This is the complete code for implementing a custom stack. It includes methods for pushing elements onto the stack, popping elements, and incrementing elements up to a specified position in the stack.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int ptr, m;
	```
	Initialize the pointer `ptr` for stack manipulation and the maximum size `m` of the stack.

2. **Access Control**
	```cpp
	public:
	```
	Public access to the methods and constructor of the class.

3. **Constructor**
	```cpp
	CustomStack(int mx) {
	```
	Constructor to initialize the stack with a maximum size.

4. **Stack Initialization**
	```cpp
	    stk.resize(mx);
	```
	Resize the stack `stk` to the given size `mx`.

5. **Variable Initialization**
	```cpp
	    ptr = -1;
	```
	Initialize the pointer `ptr` to -1 to indicate the stack is empty.

6. **Variable Initialization**
	```cpp
	    m = mx;
	```
	Set the maximum size of the stack to the provided value `mx`.

7. **Method Definition**
	```cpp
	void push(int x) {
	```
	Define the `push` method to add an element to the stack.

8. **Conditional Check**
	```cpp
	    if (ptr < m - 1) {
	```
	Check if the stack is not full.

9. **Pointer Manipulation**
	```cpp
	        ptr++;
	```
	Increment the pointer `ptr` to add an element to the stack.

10. **Stack Operation**
	```cpp
	        stk[ptr] = x;
	```
	Assign the value `x` to the stack at position `ptr`.

11. **Method Definition**
	```cpp
	int pop() {
	```
	Define the `pop` method to remove an element from the stack.

12. **Conditional Check**
	```cpp
	    if(ptr == -1) return -1;
	```
	Check if the stack is empty and return -1 if true.

13. **Pointer Manipulation**
	```cpp
	    return stk[ptr--];
	```
	Return the top element of the stack and decrement the pointer `ptr`.

14. **Method Definition**
	```cpp
	void increment(int k, int val) {
	```
	Define the `increment` method to increment the first `k` elements by the value `val`.

15. **Looping**
	```cpp
	    for(int i = 0; i < min(m, k); i++)
	```
	Loop through the first `k` elements, but no more than the stack size `m`.

16. **Stack Manipulation**
	```cpp
	        stk[i] += val;
	```
	Increment each element in the stack by the value `val`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for push and pop operations.
- **Average Case:** O(k) for the increment operation, where k is the number of elements to increment.
- **Worst Case:** O(k) for the increment operation.

The increment operation has a time complexity of O(k) because we need to modify the bottom k elements.

### Space Complexity 💾
- **Best Case:** O(n) in all cases since we store the stack elements.
- **Worst Case:** O(n) where n is the maximum size of the stack.

The space complexity is O(n), where n is the number of elements in the stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-a-stack-with-increment-operation/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
