
+++
authors = ["grid47"]
title = "Leetcode 622: Design Circular Queue"
date = "2024-09-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 622: Design Circular Queue in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Design","Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/622.webp"
youtube = "aBbsfn863oA"
youtube_upload_date="2022-02-19"
youtube_thumbnail="https://i.ytimg.com/vi/aBbsfn863oA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/622.webp" 
    alt="A circular queue with elements being added and removed, each action softly glowing as the queue operates."
    caption="Solution to LeetCode 622: Design Circular Queue Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Design and implement a Circular Queue. A circular queue is a linear data structure where the operations follow the FIFO principle, and the last position is connected to the first, forming a circle. This design allows better space utilization.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You will be provided with an integer `k`, the size of the circular queue. The operations available are enQueue, deQueue, Front, Rear, isEmpty, and isFull.
- **Example:** `['MyCircularQueue', 'enQueue', 'enQueue', 'deQueue', 'Front', 'Rear', 'isEmpty', 'isFull'] [[5], [1], [2], [], [], [], [], []]`
- **Constraints:**
	- 1 <= k <= 1000
	- 0 <= value <= 1000
	- At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.

{{< dots >}}
### Output Specifications 📤
- **Output:** For each operation, return the appropriate result: true/false for enQueue, deQueue, isEmpty, isFull; the element for Front and Rear operations.
- **Example:** `[null, true, true, true, false, 3, true, true, true, 4]`
- **Constraints:**
	- Return true if the operation is successful, otherwise false.
	- Return the front or rear element, or -1 if the queue is empty.

{{< dots >}}
### Core Logic 🔍
**Goal:** Implement a circular queue that efficiently reuses space when elements are dequeued.

- 1. Initialize the queue with size k.
- 2. Implement methods for enQueue, deQueue, Front, Rear, isEmpty, and isFull.
- 3. Use modular arithmetic to handle the circular behavior of the queue.
{{< dots >}}
### Problem Assumptions ✅
- The operations will be called within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `['MyCircularQueue', 'enQueue', 'enQueue', 'enQueue', 'enQueue', 'Rear', 'isFull', 'deQueue', 'enQueue', 'Rear']`  \
  **Explanation:** This example demonstrates the behavior of the queue when full, showing the operations enQueue, deQueue, and the correct handling of the queue size limit.

{{< dots >}}
## Approach 🚀
We will use a circular array with two pointers to track the front and rear of the queue, ensuring efficient insertion and removal of elements.

### Initial Thoughts 💭
- Circular queues provide better space utilization by reusing the front space once elements are dequeued.
- We will use modular arithmetic to wrap the indices around when the front or rear reaches the end of the array.
{{< dots >}}
### Edge Cases 🌐
- Trying to dequeue or get the front/rear of an empty queue should return -1.
- The queue size can go up to 1000, but the implementation should still be efficient.
- When the queue is full, trying to enqueue an element should return false.
- Ensure the number of operations does not exceed 3000.
{{< dots >}}
## Code 💻
```cpp
int frd, bck;
int sz, cnt;
public:
MyCircularQueue(int k): sz(k), frd(0), bck(-1), q(k, 0), cnt(0) {
    
}

bool enQueue(int value) {
    if(isFull()) return false;        
    bck = (bck + 1) % sz;
    q[bck] = value;
    
    cnt++;
    
    return true;
}

bool deQueue() {
    if(isEmpty()) return false;        

    frd = (frd +1) %sz;        
    cnt--;
    
    return true;        
}

int Front() {
    if(isEmpty()) return -1;
    
    return q[frd];
}

int Rear() {
    if(isEmpty()) return -1;
    
    return q[bck];        
}

bool isEmpty() {
    return cnt == 0;
}

bool isFull() {
    return cnt == sz;
}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
```

This code implements a circular queue with methods for enqueue, dequeue, checking the front and rear elements, and checking if the queue is empty or full.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declarations**
	```cpp
	int frd, bck;
	```
	Declares two integer variables, `frd` (front) and `bck` (back), which track the front and back indices of the circular queue.

2. **Variable Declarations**
	```cpp
	int sz, cnt;
	```
	Declares two integer variables, `sz` (size) for the capacity of the queue and `cnt` (count) for the current number of elements in the queue.

3. **Constructor Declaration**
	```cpp
	public:
	```
	Marks the start of the public member functions for the `MyCircularQueue` class.

4. **Constructor Implementation**
	```cpp
	MyCircularQueue(int k): sz(k), frd(0), bck(-1), q(k, 0), cnt(0) {
	```
	Constructor that initializes the circular queue with a given size `k`, setting the front index (`frd`) to 0, the back index (`bck`) to -1, and initializing the queue array `q` with `k` zeros. The element count (`cnt`) is also set to 0.

5. **Enqueue Method**
	```cpp
	bool enQueue(int value) {
	```
	Defines the `enQueue` method that adds an element to the circular queue if it's not full.

6. **Enqueue Check Full**
	```cpp
	    if(isFull()) return false;
	```
	Checks if the queue is full. If true, returns `false` to indicate the enqueue operation failed.

7. **Enqueue Update Back Index**
	```cpp
	    bck = (bck + 1) % sz;
	```
	Updates the back index (`bck`) to the next position in the circular queue, wrapping around if necessary.

8. **Enqueue Insert Value**
	```cpp
	    q[bck] = value;
	```
	Inserts the given value into the queue at the current back index.

9. **Enqueue Increment Count**
	```cpp
	    cnt++;
	```
	Increments the count (`cnt`) of elements in the queue after successfully inserting the value.

10. **Enqueue Return**
	```cpp
	    return true;
	```
	Returns `true` to indicate that the enqueue operation was successful.

11. **Dequeue Method**
	```cpp
	bool deQueue() {
	```
	Defines the `deQueue` method that removes an element from the front of the circular queue if it's not empty.

12. **Dequeue Check Empty**
	```cpp
	    if(isEmpty()) return false;
	```
	Checks if the queue is empty. If true, returns `false` to indicate the dequeue operation failed.

13. **Dequeue Update Front Index**
	```cpp
	    frd = (frd + 1) % sz;
	```
	Updates the front index (`frd`) to the next position in the circular queue, wrapping around if necessary.

14. **Dequeue Decrement Count**
	```cpp
	    cnt--;
	```
	Decrements the count (`cnt`) of elements in the queue after successfully removing an element.

15. **Dequeue Return**
	```cpp
	    return true;
	```
	Returns `true` to indicate that the dequeue operation was successful.

16. **Front Method**
	```cpp
	int Front() {
	```
	Defines the `Front` method that returns the element at the front of the circular queue, or -1 if empty.

17. **Front Check Empty**
	```cpp
	    if(isEmpty()) return -1;
	```
	Checks if the queue is empty. If true, returns `-1` to indicate there is no front element.

18. **Front Return**
	```cpp
	    return q[frd];
	```
	Returns the element at the front of the queue.

19. **Rear Method**
	```cpp
	int Rear() {
	```
	Defines the `Rear` method that returns the element at the rear of the circular queue, or -1 if empty.

20. **Rear Check Empty**
	```cpp
	    if(isEmpty()) return -1;
	```
	Checks if the queue is empty. If true, returns `-1` to indicate there is no rear element.

21. **Rear Return**
	```cpp
	    return q[bck];
	```
	Returns the element at the rear of the queue.

22. **isEmpty Method**
	```cpp
	bool isEmpty() {
	```
	Defines the `isEmpty` method that checks if the queue is empty.

23. **isEmpty Return**
	```cpp
	    return cnt == 0;
	```
	Returns `true` if the queue is empty, i.e., if the element count (`cnt`) is 0.

24. **isFull Method**
	```cpp
	bool isFull() {
	```
	Defines the `isFull` method that checks if the queue is full.

25. **isFull Return**
	```cpp
	    return cnt == sz;
	```
	Returns `true` if the queue is full, i.e., if the element count (`cnt`) is equal to the queue size (`sz`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

All operations (enQueue, deQueue, Front, Rear, isEmpty, isFull) take constant time.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

Space complexity is proportional to the size of the queue, which is `k`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-circular-queue/description/)

---
{{< youtube aBbsfn863oA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
