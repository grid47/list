
+++
authors = ["grid47"]
title = "Leetcode 1670: Design Front Middle Back Queue"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1670: Design Front Middle Back Queue in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Design","Queue","Data Stream"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HSOiUhfXUTg"
youtube_upload_date="2020-11-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HSOiUhfXUTg/maxresdefault.webp"
comments = true
+++



---
Design a queue that supports operations at the front, middle, and back. Implement the `FrontMiddleBackQueue` class with methods for adding and removing elements from these positions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a series of commands to initialize the queue and perform operations on it.
- **Example:** `["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[ ], [10], [20], [30], [40], [], [], [], [], []]`
- **Constraints:**
	- 1 <= val <= 10^9
	- At most 1000 calls will be made to pushFront, pushMiddle, pushBack, popFront, popMiddle, and popBack.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of the results of the `pop` operations. For each `pop` operation, return the value removed from the queue or `-1` if the queue is empty.
- **Example:** `[null, null, null, null, null, 10, 30, 40, 20, -1]`
- **Constraints:**
	- Each `pop` operation returns the element removed or `-1` if the queue is empty.

{{< dots >}}
### Core Logic 🔍
**Goal:** Implement a queue that allows insertion and removal of elements at the front, middle, and back efficiently.

- Use two deques to manage the front and back operations efficiently.
- The middle position is calculated dynamically based on the size of the deques.
- For each `pop` operation, handle the front, middle, or back removal appropriately based on the current state of the queue.
{{< dots >}}
### Problem Assumptions ✅
- The input will always follow the format specified in the examples.
- All input values are valid and within the specified constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `[null, null, null, null, null, 10, 30, 40, 20, -1]`  \
  **Explanation:** This example demonstrates how each of the operations behaves, including adding elements to the front, middle, and back, and removing them from the front, middle, and back.

{{< dots >}}
## Approach 🚀
The solution uses two deques to manage the queue's operations efficiently. One deque handles the front and the other handles the back. The middle element is adjusted dynamically based on the size of the two deques.

### Initial Thoughts 💭
- Operations on the front and back are easy to handle using deques.
- The middle element needs dynamic management to ensure efficient insertion and removal.
- Use two deques to split the queue and balance the middle position.
{{< dots >}}
### Edge Cases 🌐
- Ensure that `pop` operations return `-1` when the queue is empty.
- Ensure that the solution performs efficiently with up to 1000 operations.
- Ensure correct behavior when performing operations on a queue of size 1.
- Handle up to 1000 operations.
{{< dots >}}
## Code 💻
```cpp

void a2b() {
    if (a.size() <= b.size()) return;
    b.push_front(a.back());
    a.pop_back();
}
/* keep operations around front of b and back of a */
void b2a() {
    if (b.size() <= a.size() + 1) return;
    a.push_back(b.front());
    b.pop_front();
}

public:
FrontMiddleBackQueue() {}

void pushFront(int val) {
    a.push_front(val);
    a2b();
}

void pushMiddle(int val) {
    a.push_back(val);
    a2b();
}

void pushBack(int val) {
    b.push_back(val);
    b2a();
}

int popFront() {
    if(a.empty() && b.empty()) return -1;
    int ans;
    if(a.empty()) {
        ans = b.front();
        b.pop_front();
    } else {
        ans = a.front();
        a.pop_front();
        b2a();          
    }
    return ans;
}

int popMiddle() {
    if(a.empty() && b.empty()) return -1;
    int ans;
    if(a.size() == b.size()) {
        ans = a.back();
        a.pop_back();
    } else {
        ans = b.front();
        b.pop_front();      
    }
    return ans;        
}

int popBack() {
    if(a.empty() && b.empty()) return -1;
    int ans = b.back();
    b.pop_back();
    a2b();
    return ans;       
}
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
```

This code defines the `FrontMiddleBackQueue` class, which supports inserting elements at the front, middle, or back of the queue and removing elements from those positions. The class uses two deques (`a` and `b`) to manage the data and ensure balanced operations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Helper Functions**
	```cpp
	void a2b() {
	```
	Helper function that moves elements from the back of `a` to the front of `b` to balance the size of the deques.

2. **Helper Functions**
	```cpp
	    if (a.size() <= b.size()) return;
	```
	Checks if the size of `a` is less than or equal to the size of `b`. If true, no operation is performed.

3. **Helper Functions**
	```cpp
	    b.push_front(a.back());
	```
	Moves an element from the back of `a` to the front of `b`.

4. **Helper Functions**
	```cpp
	    a.pop_back();
	```
	Removes the element that was just moved from the back of `a`.

5. **Helper Functions**
	```cpp
	void b2a() {
	```
	Helper function that moves elements from the front of `b` to the back of `a`.

6. **Helper Functions**
	```cpp
	    if (b.size() <= a.size() + 1) return;
	```
	Checks if the size of `b` is less than or equal to the size of `a` plus 1. If true, no operation is performed.

7. **Helper Functions**
	```cpp
	    a.push_back(b.front());
	```
	Moves an element from the front of `b` to the back of `a`.

8. **Helper Functions**
	```cpp
	    b.pop_front();
	```
	Removes the element that was just moved from the front of `b`.

9. **Constructor**
	```cpp
	public:
	```
	Access specifier indicating that the following methods are public and can be accessed outside the class.

10. **Constructor**
	```cpp
	FrontMiddleBackQueue() {}
	```
	Constructor for the `FrontMiddleBackQueue` class, initializes the deques `a` and `b`.

11. **Push Operations**
	```cpp
	void pushFront(int val) {
	```
	Method that adds a value to the front of the queue.

12. **Push Operations**
	```cpp
	    a.push_front(val);
	```
	Adds the value `val` to the front of deque `a`.

13. **Push Operations**
	```cpp
	    a2b();
	```
	Calls the `a2b` helper function to balance the deques.

14. **Push Operations**
	```cpp
	void pushMiddle(int val) {
	```
	Method that adds a value to the middle of the queue.

15. **Push Operations**
	```cpp
	    a.push_back(val);
	```
	Adds the value `val` to the back of deque `a`.

16. **Push Operations**
	```cpp
	    a2b();
	```
	Calls the `a2b` helper function to balance the deques.

17. **Push Operations**
	```cpp
	void pushBack(int val) {
	```
	Method that adds a value to the back of the queue.

18. **Push Operations**
	```cpp
	    b.push_back(val);
	```
	Adds the value `val` to the back of deque `b`.

19. **Push Operations**
	```cpp
	    b2a();
	```
	Calls the `b2a` helper function to balance the deques.

20. **Pop Operations**
	```cpp
	int popFront() {
	```
	Method that removes a value from the front of the queue.

21. **Pop Operations**
	```cpp
	    if(a.empty() && b.empty()) return -1;
	```
	Checks if both `a` and `b` are empty. If true, returns -1 to indicate that the queue is empty.

22. **Pop Operations**
	```cpp
	    int ans;
	```
	Declares a variable `ans` to store the value being removed from the queue.

23. **Pop Operations**
	```cpp
	    if(a.empty()) {
	```
	Checks if `a` is empty. If true, removes the front element from `b`.

24. **Pop Operations**
	```cpp
	        ans = b.front();
	```
	Assigns the front element of `b` to `ans`.

25. **Pop Operations**
	```cpp
	        b.pop_front();
	```
	Removes the front element from `b`.

26. **Pop Operations**
	```cpp
	    } else {
	```
	If `a` is not empty, removes the front element from `a`.

27. **Pop Operations**
	```cpp
	        ans = a.front();
	```
	Assigns the front element of `a` to `ans`.

28. **Pop Operations**
	```cpp
	        a.pop_front();
	```
	Removes the front element from `a`.

29. **Pop Operations**
	```cpp
	        b2a();
	```
	Calls the `b2a` helper function to balance the deques.

30. **Pop Operations**
	```cpp
	    return ans;
	```
	Returns the value removed from the front of the queue.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for operations when the size of the queue is small.
- **Average Case:** O(1) for `push` and `pop` operations, as deques allow constant time insertions and deletions.
- **Worst Case:** O(1) for all operations.

The time complexity for each operation is O(1), making the solution highly efficient.

### Space Complexity 💾
- **Best Case:** O(n), as the space complexity depends on the total number of elements.
- **Worst Case:** O(n), where n is the number of elements in the queue.

The space complexity is linear in terms of the number of elements in the queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-front-middle-back-queue/description/)

---
{{< youtube HSOiUhfXUTg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
