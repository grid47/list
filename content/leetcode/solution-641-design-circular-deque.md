
+++
authors = ["grid47"]
title = "Leetcode 641: Design Circular Deque"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 641: Design Circular Deque in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Design","Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/641.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/641.webp" 
    alt="A circular deque with elements being added and removed, each operation glowing softly as it occurs."
    caption="Solution to LeetCode 641: Design Circular Deque Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Design a data structure that simulates a circular double-ended queue (deque) with a fixed maximum size. Implement the MyCircularDeque class with methods for inserting, deleting, and accessing elements at both ends of the deque.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of multiple operations to be executed on the deque. Each operation is an array with the first element being the method name and the following elements representing the arguments.
- **Example:** `["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]`
- **Constraints:**
	- 1 <= k <= 1000
	- 0 <= value <= 1000
	- At most 2000 calls will be made to the methods.

{{< dots >}}
### Output Specifications 📤
- **Output:** For each method call, return the result of the operation. If the operation is successful, return a boolean value. For 'getFront' and 'getRear', return the respective item, or -1 if the deque is empty.
- **Example:** `[null, true, true, true, false, 2, true, true, true, 4]`
- **Constraints:**
	- Each 'insert' and 'delete' operation is O(1).
	- The deque will only store integer values.

{{< dots >}}
### Core Logic 🔍
**Goal:** To simulate the operations of a circular double-ended queue and ensure the correct results are returned for each operation.

- Initialize the deque with a fixed size.
- Use two pointers (front and back) to track the positions of the front and rear elements.
- Ensure that operations like insertions, deletions, and retrievals are handled efficiently with modulo arithmetic to maintain the circular nature.
{{< dots >}}
### Problem Assumptions ✅
- The deque will always handle the insert and delete operations correctly based on its current state.
{{< dots >}}
## Examples 🧩
- **Input:** `["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]`  \
  **Explanation:** This example shows the correct sequence of operations on a circular deque, handling insertion, deletion, and retrieval of elements with a fixed size.

{{< dots >}}
## Approach 🚀
We can implement the circular deque using an array with two pointers (front and back), ensuring efficient insertions and deletions at both ends by updating the pointers using modulo arithmetic.

### Initial Thoughts 💭
- A circular array can efficiently handle the required operations.
- The modulo operation helps to wrap around the array when inserting or deleting elements.
- We can use a fixed-size array and two pointers to simulate the circular behavior.
{{< dots >}}
### Edge Cases 🌐
- Ensure that operations like 'getFront' and 'getRear' handle an empty deque correctly by returning -1.
- Ensure the solution works efficiently for the largest possible size of the deque and the maximum number of operations.
- Consider cases where the deque is full or empty before performing operations.
- The implementation should be able to handle up to 2000 operations efficiently.
{{< dots >}}
## Code 💻
```cpp
int frd, bck;
int sz, cnt;
public:
MyCircularDeque(int k) : sz(k), buf(k, 0), bck(0), frd(k - 1), cnt(0) {
    
}

bool insertFront(int value) {
    if(isFull()) return false;
    
    buf[frd] = value;
    frd = (frd -1 + sz) % sz;
    
    ++cnt;
    return true;
}

bool insertLast(int value) {
    if(isFull()) return false;
    
    buf[bck] = value;        
    bck = (bck + 1) % sz;
    
    ++cnt;
    return true;        
}

bool deleteFront() {
    if(isEmpty()) return false;
    
    frd = (frd + 1) % sz;
    
    --cnt;
    return true;        
}

bool deleteLast() {
    if(isEmpty()) return false;
    
    bck = (bck - 1 + sz) % sz;
    
    --cnt;
    return true;        
}

int getFront() {
    if(isEmpty()) return -1;
    
    return buf[(frd + 1) % sz];
    
}

int getRear() {
    if(isEmpty()) return -1;
    
    return buf[(bck - 1 + sz) % sz];
}

bool isEmpty() {
    return cnt == 0;
}

bool isFull() {
    return  cnt == sz;
}
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
```

This is the complete code for implementing a circular deque, with functions to insert elements at the front and back, delete elements from the front and back, and check if the deque is empty or full.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int frd, bck;
	```
	Declares the front and back indices for the circular deque.

2. **Variable Declaration**
	```cpp
	int sz, cnt;
	```
	Declares the size of the deque and the count of elements in the deque.

3. **Constructor**
	```cpp
	public:
	```
	Begins the public section of the class where methods and the constructor are defined.

4. **Constructor Initialization**
	```cpp
	MyCircularDeque(int k) : sz(k), buf(k, 0), bck(0), frd(k - 1), cnt(0) {
	```
	Constructor that initializes the circular deque with a given size 'k', setting the front and back indices, and initializing the count of elements to zero.

5. **Insert Front Method**
	```cpp
	bool insertFront(int value) {
	```
	Defines the 'insertFront' method that inserts an element at the front of the deque.

6. **Full Check**
	```cpp
	    if(isFull()) return false;
	```
	Checks if the deque is full before inserting a new element.

7. **Insert Element**
	```cpp
	    buf[frd] = value;
	```
	Inserts the value at the front of the deque.

8. **Update Front Index**
	```cpp
	    frd = (frd -1 + sz) % sz;
	```
	Updates the front index after inserting the element, wrapping it around if necessary.

9. **Increment Count**
	```cpp
	    ++cnt;
	```
	Increments the count of elements in the deque.

10. **Return True**
	```cpp
	    return true;
	```
	Returns true indicating the insertion was successful.

11. **Insert Last Method**
	```cpp
	bool insertLast(int value) {
	```
	Defines the 'insertLast' method that inserts an element at the back of the deque.

12. **Full Check**
	```cpp
	    if(isFull()) return false;
	```
	Checks if the deque is full before inserting a new element.

13. **Insert Element**
	```cpp
	    buf[bck] = value;
	```
	Inserts the value at the back of the deque.

14. **Update Back Index**
	```cpp
	    bck = (bck + 1) % sz;
	```
	Updates the back index after inserting the element, wrapping it around if necessary.

15. **Increment Count**
	```cpp
	    ++cnt;
	```
	Increments the count of elements in the deque.

16. **Return True**
	```cpp
	    return true;
	```
	Returns true indicating the insertion was successful.

17. **Delete Front Method**
	```cpp
	bool deleteFront() {
	```
	Defines the 'deleteFront' method that removes an element from the front of the deque.

18. **Empty Check**
	```cpp
	    if(isEmpty()) return false;
	```
	Checks if the deque is empty before attempting to delete an element.

19. **Update Front Index**
	```cpp
	    frd = (frd + 1) % sz;
	```
	Updates the front index after deleting the element, wrapping it around if necessary.

20. **Decrement Count**
	```cpp
	    --cnt;
	```
	Decrements the count of elements in the deque.

21. **Return True**
	```cpp
	    return true;
	```
	Returns true indicating the deletion was successful.

22. **Delete Last Method**
	```cpp
	bool deleteLast() {
	```
	Defines the 'deleteLast' method that removes an element from the back of the deque.

23. **Empty Check**
	```cpp
	    if(isEmpty()) return false;
	```
	Checks if the deque is empty before attempting to delete an element.

24. **Update Back Index**
	```cpp
	    bck = (bck - 1 + sz) % sz;
	```
	Updates the back index after deleting the element, wrapping it around if necessary.

25. **Decrement Count**
	```cpp
	    --cnt;
	```
	Decrements the count of elements in the deque.

26. **Return True**
	```cpp
	    return true;
	```
	Returns true indicating the deletion was successful.

27. **Get Front Method**
	```cpp
	int getFront() {
	```
	Defines the 'getFront' method that retrieves the element at the front of the deque.

28. **Empty Check**
	```cpp
	    if(isEmpty()) return -1;
	```
	Checks if the deque is empty before attempting to get an element.

29. **Return Front Element**
	```cpp
	    return buf[(frd + 1) % sz];
	```
	Returns the element at the front of the deque.

30. **Get Rear Method**
	```cpp
	int getRear() {
	```
	Defines the 'getRear' method that retrieves the element at the back of the deque.

31. **Empty Check**
	```cpp
	    if(isEmpty()) return -1;
	```
	Checks if the deque is empty before attempting to get an element.

32. **Return Rear Element**
	```cpp
	    return buf[(bck - 1 + sz) % sz];
	```
	Returns the element at the back of the deque.

33. **Is Empty Method**
	```cpp
	bool isEmpty() {
	```
	Defines the 'isEmpty' method that checks if the deque is empty.

34. **Return Empty Status**
	```cpp
	    return cnt == 0;
	```
	Returns true if the deque is empty.

35. **Is Full Method**
	```cpp
	bool isFull() {
	```
	Defines the 'isFull' method that checks if the deque is full.

36. **Return Full Status**
	```cpp
	    return  cnt == sz;
	```
	Returns true if the deque is full.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

Each operation (insert, delete, get) is performed in constant time due to the circular nature of the deque.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is O(k) where k is the maximum size of the deque, as we need to store up to k elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-circular-deque/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
