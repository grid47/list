
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
**Code:**

{{< highlight cpp >}}
class MyCircularQueue {
    vector<int> q;
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
 */
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves implementing a **circular queue** data structure. A **circular queue** is a type of queue that efficiently handles the operations of adding and removing elements while maintaining a fixed size, such that the first element of the queue can wrap around and reuse space freed by dequeuing elements. The task is to design a class `MyCircularQueue` that supports the following operations:

1. **Enqueue (insert):** Adds an element to the rear of the queue.
2. **Dequeue (remove):** Removes an element from the front of the queue.
3. **Front:** Retrieves the element at the front of the queue without removing it.
4. **Rear:** Retrieves the element at the rear of the queue without removing it.
5. **isEmpty:** Returns whether the queue is empty or not.
6. **isFull:** Returns whether the queue is full or not.

### Approach

In a **circular queue**, instead of shifting the elements every time an element is dequeued, we use modular arithmetic to "wrap around" the queue’s array. The approach follows these steps:

1. **Initialization:**
   - We initialize a queue with a fixed size (`sz`) using a vector `q` of size `sz`.
   - We maintain two pointers: `frd` (front pointer) and `bck` (back pointer) to track the positions of the front and rear elements in the queue.
   - A counter `cnt` is used to track the current number of elements in the queue, ensuring that we can check if the queue is full or empty efficiently.

2. **Enqueue (Insert Operation):**
   - We first check if the queue is full using the `isFull()` function. If it is full, we return `false`.
   - If not full, we increment the rear pointer (`bck`) by 1 (with modulo operation to handle wrap-around) and add the element at that position in the array.
   - We increase the count `cnt` to reflect the new element.

3. **Dequeue (Remove Operation):**
   - We check if the queue is empty using the `isEmpty()` function. If the queue is empty, we return `false`.
   - If not empty, we increment the front pointer (`frd`) by 1 (again with modulo to handle wrap-around) and decrease the counter `cnt`.

4. **Front and Rear Operations:**
   - The `Front()` function simply returns the element at the front pointer `frd`, or `-1` if the queue is empty.
   - The `Rear()` function returns the element at the rear pointer `bck`, or `-1` if the queue is empty.

5. **isEmpty and isFull:**
   - The `isEmpty()` function returns `true` if `cnt == 0`, indicating that there are no elements in the queue.
   - The `isFull()` function returns `true` if `cnt == sz`, indicating that the queue has reached its maximum capacity.

### Code Breakdown (Step by Step)

#### Step 1: Class Initialization
```cpp
MyCircularQueue(int k): sz(k), frd(0), bck(-1), q(k, 0), cnt(0) {}
```
- **sz:** This is the size of the circular queue. We allocate a vector `q` with `k` elements initialized to zero.
- **frd:** The front pointer, initialized to 0. It tracks the front of the queue.
- **bck:** The back pointer, initialized to `-1`. It tracks the rear of the queue.
- **q:** The vector holding the actual elements of the queue.
- **cnt:** The counter for the number of elements in the queue, initialized to 0.

#### Step 2: Enqueue Operation
```cpp
bool enQueue(int value) {
    if(isFull()) return false;        
    bck = (bck + 1) % sz;
    q[bck] = value;
    cnt++;
    return true;
}
```
- **isFull():** Checks if the queue is full. If true, it returns `false`.
- **bck = (bck + 1) % sz:** This handles the circular nature of the queue. If the back pointer reaches the end of the queue, it wraps around to the beginning.
- **q[bck] = value:** Assigns the given value to the rear of the queue.
- **cnt++:** Increments the counter as we added a new element.

#### Step 3: Dequeue Operation
```cpp
bool deQueue() {
    if(isEmpty()) return false;        
    frd = (frd +1) % sz;
    cnt--;
    return true;        
}
```
- **isEmpty():** Checks if the queue is empty. If true, it returns `false`.
- **frd = (frd + 1) % sz:** This moves the front pointer forward, wrapping around if necessary.
- **cnt--:** Decreases the counter as we removed an element from the queue.

#### Step 4: Front Operation
```cpp
int Front() {
    if(isEmpty()) return -1;
    return q[frd];
}
```
- **isEmpty():** Checks if the queue is empty. If true, returns `-1` to indicate no elements.
- **q[frd]:** Returns the element at the front of the queue.

#### Step 5: Rear Operation
```cpp
int Rear() {
    if(isEmpty()) return -1;
    return q[bck];        
}
```
- **isEmpty():** Checks if the queue is empty. If true, returns `-1` to indicate no elements.
- **q[bck]:** Returns the element at the rear of the queue.

#### Step 6: isEmpty and isFull Operations
```cpp
bool isEmpty() {
    return cnt == 0;
}

bool isFull() {
    return cnt == sz;
}
```
- **isEmpty():** Returns `true` if `cnt == 0`, meaning the queue is empty.
- **isFull():** Returns `true` if `cnt == sz`, meaning the queue is full.

### Complexity

#### Time Complexity:
- **O(1)** for all operations: `enQueue`, `deQueue`, `Front`, `Rear`, `isEmpty`, and `isFull`. Each operation only involves constant-time arithmetic or indexing operations.

#### Space Complexity:
- **O(k):** We store the queue elements in a vector `q` of size `k`. Therefore, the space complexity is proportional to the size of the queue.

### Conclusion

The `MyCircularQueue` class effectively implements a circular queue with constant-time operations for enqueue, dequeue, checking the front, and checking the rear. The use of modular arithmetic for wrapping around the front and rear pointers ensures that the queue behaves circularly and efficiently manages memory usage. This implementation also handles edge cases such as empty or full queues, ensuring that the queue operates reliably under various conditions.

The solution is highly efficient, with **O(1)** time complexity for all major operations, making it suitable for real-time applications where performance and memory efficiency are critical. This approach ensures that the queue operates in a consistent and predictable manner even as elements are added and removed cyclically.

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-circular-queue/description/)

---
{{< youtube aBbsfn863oA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
