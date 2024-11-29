
+++
authors = ["grid47"]
title = "Leetcode 232: Implement Queue using Stacks"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 232: Implement Queue using Stacks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Design","Queue"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/232.webp"
youtube = "eanwa3ht3YQ"
youtube_upload_date="2024-01-29"
youtube_thumbnail="https://i.ytimg.com/vi/eanwa3ht3YQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/232.webp" 
    alt="A series of stacks transforming into a queue, with elements gently flowing between them."
    caption="Solution to LeetCode 232: Implement Queue using Stacks Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Design and implement a queue using only two stacks. The queue should support the basic operations of a normal queue: enqueue, dequeue, peek, and checking if the queue is empty.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of several function calls to manipulate the queue. Each call is an operation on the queue object.
- **Example:** `Input: ["MyQueue", "enqueue", "enqueue", "peek", "dequeue", "empty"]
[[], [5], [10], [], [], []]`
- **Constraints:**
	- 1 <= x <= 9
	- At most 100 calls will be made to enqueue, dequeue, peek, and empty.
	- All dequeue and peek operations are valid.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output will be the result of the operations performed on the queue.
- **Example:** `Output: [null, null, null, 5, 5, false]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to use two stacks to simulate the FIFO behavior of a queue.

- Use two stacks: s1 for enqueue operations and s2 for dequeue operations.
- For enqueue, push elements to s1.
- For dequeue and peek, transfer elements from s1 to s2 if s2 is empty, then perform the operation on s2.
{{< dots >}}
### Problem Assumptions ✅
- The input will consist of valid function calls for the queue.
- The operations enqueue, dequeue, peek, and empty will be called sequentially.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ["MyQueue", "enqueue", "enqueue", "peek", "dequeue", "empty"]
[[], [5], [10], [], [], []]`  \
  **Explanation:** After pushing 5 and 10, the queue is [5, 10]. Peek returns 5, dequeue returns 5, and empty returns false because the queue is not empty.

{{< dots >}}
## Approach 🚀
We will simulate the FIFO behavior of a queue using two stacks. The idea is to use one stack (s1) for storing incoming elements and the other stack (s2) for serving the front of the queue.

### Initial Thoughts 💭
- A queue is a FIFO data structure, which means the first element added is the first one to be removed.
- Stacks are LIFO, meaning the last element added is the first one to be removed.
- To simulate a queue, we can use two stacks: one to hold the incoming elements and the other to hold the elements in reverse order when needed for dequeue or peek.
{{< dots >}}
### Edge Cases 🌐
- The queue should handle the case where no elements are added and operations like pop or peek are called.
- The solution should be able to handle a maximum of 100 function calls efficiently.
- The queue will return null for push operations as they don't have an output.
- The operations must be implemented using only stack operations.
{{< dots >}}
## Code 💻
```cpp
stack<int> s1, s2;
MyQueue() {
    
}

void push(int x) {
    s1.push(x);
}

int pop() {
    if(s2.empty()) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int x = s2.top();
    s2.pop();
    return x;
    
}

int peek() {
    if(s2.empty()) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
}

bool empty() {
    return s1.empty() && s2.empty();
}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
```

This is a queue implementation using two stacks, which supports the operations: push, pop, peek, and empty.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Data Structures**
	```cpp
	stack<int> s1, s2;
	```
	Declares two stacks `s1` and `s2` to simulate the behavior of a queue. `s1` is used to push new elements, and `s2` is used for popping and peeking elements.

2. **Constructor**
	```cpp
	MyQueue() {
	```
	Constructor for the `MyQueue` class. Initializes the two stacks `s1` and `s2`.

3. **Push Operation**
	```cpp
	void push(int x) {
	```
	Defines the `push` function to insert an element into the queue.

4. **Push Logic**
	```cpp
	    s1.push(x);
	```
	Pushes the element `x` onto stack `s1`.

5. **Pop Operation**
	```cpp
	int pop() {
	```
	Defines the `pop` function to remove and return the front element of the queue.

6. **Pop Condition**
	```cpp
	    if(s2.empty()) {
	```
	Checks if `s2` is empty. If it is, we need to transfer elements from `s1` to `s2` to maintain the correct order.

7. **Transfer Elements**
	```cpp
	        while(!s1.empty()) {
	```
	Transfers all elements from `s1` to `s2`, reversing their order to simulate queue behavior.

8. **Move Element**
	```cpp
	            s2.push(s1.top());
	```
	Moves the top element from `s1` to `s2`.

9. **Pop Element**
	```cpp
	            s1.pop();
	```
	Pops the element from `s1` after moving it to `s2`.

10. **Pop Value**
	```cpp
	    int x = s2.top();
	```
	Gets the top element from `s2` (the front element of the queue).

11. **Pop Removal**
	```cpp
	    s2.pop();
	```
	Removes the top element from `s2`, effectively popping the front element of the queue.

12. **Return Pop Value**
	```cpp
	    return x;
	```
	Returns the popped element from the queue.

13. **Peek Operation**
	```cpp
	int peek() {
	```
	Defines the `peek` function to return the front element of the queue without removing it.

14. **Peek Condition**
	```cpp
	    if(s2.empty()) {
	```
	Checks if `s2` is empty. If so, we transfer elements from `s1` to `s2`.

15. **Peek Transfer**
	```cpp
	        while(!s1.empty()) {
	```
	Transfers elements from `s1` to `s2` to maintain the queue's order.

16. **Move Element for Peek**
	```cpp
	            s2.push(s1.top());
	```
	Moves the top element from `s1` to `s2`.

17. **Pop Element for Peek**
	```cpp
	            s1.pop();
	```
	Pops the element from `s1` after moving it to `s2`.

18. **Peek Value**
	```cpp
	    return s2.top();
	```
	Returns the top element from `s2`, which is the front element of the queue.

19. **Empty Operation**
	```cpp
	bool empty() {
	```
	Defines the `empty` function to check if the queue is empty.

20. **Check Empty**
	```cpp
	    return s1.empty() && s2.empty();
	```
	Returns `true` if both `s1` and `s2` are empty, indicating that the queue is empty.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(n) when transferring elements from s1 to s2 during pop or peek operations.

While the pop and peek operations may take O(n) in the worst case, the overall complexity is amortized to O(1) for each operation over time.

### Space Complexity 💾
- **Best Case:** O(1) when no elements are stored in the queue.
- **Worst Case:** O(n) because the queue can hold up to n elements.

The space complexity is O(n), where n is the number of elements in the queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/implement-queue-using-stacks/description/)

---
{{< youtube eanwa3ht3YQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
