
+++
authors = ["grid47"]
title = "Leetcode 225: Implement Stack using Queues"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 225: Implement Stack using Queues in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Design","Queue"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/225.webp"
youtube = "rW4vm0-DLYc"
youtube_upload_date="2021-11-23"
youtube_thumbnail="https://i.ytimg.com/vi/rW4vm0-DLYc/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/225.webp" 
    alt="A series of glowing queues stacked neatly, showing elements being added and removed smoothly."
    caption="Solution to LeetCode 225: Implement Stack using Queues Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Design a stack that supports LIFO (Last In First Out) operations using only one queue. Implement standard stack operations: push, pop, top, and empty.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a series of commands and their corresponding arguments for stack operations.
- **Example:** `Input: ["MyStack", "push", "push", "top", "pop", "empty"], [[], [5], [7], [], [], []]`
- **Constraints:**
	- 1 <= x <= 9
	- At most 100 operations will be performed.
	- All pop and top operations will be valid (i.e., the stack will not be empty).

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an array of results corresponding to the executed operations.
- **Example:** `Output: [null, null, null, 7, 7, false]`
- **Constraints:**
	- The results must match the order of operations executed.

{{< dots >}}
### Core Logic 🔍
**Goal:** Simulate stack operations using only one queue and standard queue methods.

- Use a single queue to store stack elements.
- When pushing an element, enqueue it and then rotate the queue to maintain the LIFO order.
- For pop and top operations, return or remove the front element of the queue.
- Check if the queue is empty for the empty operation.
{{< dots >}}
### Problem Assumptions ✅
- The queue supports all required operations natively or through simulation.
- Input commands and arguments are always valid and within constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ["MyStack", "push", "push", "top", "pop", "empty"], [[], [3], [8], [], [], []]`  \
  **Explanation:** Commands initialize a stack, push 3 and 8, check the top element (8), pop the top (8), and check if the stack is empty (false). Output: [null, null, null, 8, 8, false]

- **Input:** `Input: ["MyStack", "push", "top", "pop", "empty"], [[], [6], [], [], []]`  \
  **Explanation:** Commands initialize a stack, push 6, check the top element (6), pop the top (6), and check if the stack is empty (true). Output: [null, null, 6, 6, true]

{{< dots >}}
## Approach 🚀
Use a single queue to simulate stack behavior. Maintain LIFO order by rotating the queue after each push operation.

### Initial Thoughts 💭
- A queue follows FIFO order, while a stack requires LIFO order.
- Rotating the queue ensures that the most recently added element is always at the front.
- By rotating elements after every push, the front of the queue will behave as the top of the stack.
- Pop and top operations can be handled directly via the queue's front method.
{{< dots >}}
### Edge Cases 🌐
- Operations on an empty stack (e.g., calling pop or top).
- Performing 100 operations (the maximum limit).
- Pushing and popping the same element repeatedly.
- Ensure the implementation works for all edge cases within the problem's constraints.
{{< dots >}}
## Code 💻
```cpp
queue<int> que;
MyStack() {
    
}

void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}        
}

int pop() {
    int x = que.front();
    que.pop();
    return x;
}

int top() {
    return que.front();
}

bool empty() {
    return que.empty();
}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
```

This code defines a custom stack class `MyStack` using a queue. It implements stack operations such as push, pop, top, and empty using a queue, mimicking stack behavior.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	queue<int> que;
	```
	Declares a queue of integers `que` to be used to store elements in the stack.

2. **Constructor**
	```cpp
	MyStack() {
	```
	Defines the constructor of the `MyStack` class, initializing the stack object. Here, no additional initialization is done.

3. **Push Method Start**
	```cpp
	void push(int x) {
	```
	Defines the `push` method, which inserts an element `x` onto the stack.

4. **Queue Push**
	```cpp
			que.push(x);
	```
	Pushes the element `x` onto the queue.

5. **Queue Rearrangement**
	```cpp
			for(int i=0;i<que.size()-1;++i){
	```
	This loop rearranges the queue so that the most recently added element appears at the front, mimicking stack behavior.

6. **Queue Rotation**
	```cpp
				que.push(que.front());
	```
	Moves the front element of the queue to the back.

7. **Queue Pop**
	```cpp
				que.pop();
	```
	Removes the front element from the queue, completing the rotation process.

8. **Pop Method Start**
	```cpp
	int pop() {
	```
	Defines the `pop` method, which removes and returns the top element from the stack.

9. **Pop Element**
	```cpp
	    int x = que.front();
	```
	Retrieves the front element of the queue, which corresponds to the top of the stack.

10. **Pop Operation**
	```cpp
	    que.pop();
	```
	Removes the front element from the queue.

11. **Pop Method End**
	```cpp
	    return x;
	```
	Returns the element `x` that was popped from the stack.

12. **Top Method Start**
	```cpp
	int top() {
	```
	Defines the `top` method, which returns the top element of the stack without removing it.

13. **Top Element**
	```cpp
	    return que.front();
	```
	Returns the front element of the queue, which is the top element of the stack.

14. **Empty Method Start**
	```cpp
	bool empty() {
	```
	Defines the `empty` method, which checks whether the stack is empty.

15. **Empty Check**
	```cpp
	    return que.empty();
	```
	Returns true if the queue is empty, meaning the stack is also empty.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for pop, top, and empty; O(n) for push.
- **Average Case:** O(n) for push due to rotation.
- **Worst Case:** O(n) for push when the queue has many elements.

Push operation requires rotating the queue, resulting in O(n) time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The queue stores all elements, requiring O(n) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/implement-stack-using-queues/description/)

---
{{< youtube rW4vm0-DLYc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
