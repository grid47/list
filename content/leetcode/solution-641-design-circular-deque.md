
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
**Code:**

{{< highlight cpp >}}
class MyCircularDeque {
    vector<int> buf;
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
 */
{{< /highlight >}}
---

### Problem Statement

The problem requires the implementation of a circular deque (double-ended queue), which allows insertion and deletion of elements from both the front and the rear of the deque. The deque must support the following operations:

1. **insertFront(value)**: Inserts an element at the front of the deque. Returns `true` if the operation is successful, otherwise `false`.
2. **insertLast(value)**: Inserts an element at the rear of the deque. Returns `true` if the operation is successful, otherwise `false`.
3. **deleteFront()**: Removes an element from the front of the deque. Returns `true` if the operation is successful, otherwise `false`.
4. **deleteLast()**: Removes an element from the rear of the deque. Returns `true` if the operation is successful, otherwise `false`.
5. **getFront()**: Returns the front element of the deque. If the deque is empty, it should return `-1`.
6. **getRear()**: Returns the rear element of the deque. If the deque is empty, it should return `-1`.
7. **isEmpty()**: Returns `true` if the deque is empty, otherwise `false`.
8. **isFull()**: Returns `true` if the deque is full, otherwise `false`.

The deque should have a fixed size `k`, and all operations must be implemented in constant time (`O(1)`).

### Approach

To implement a circular deque efficiently, we need a fixed-size array (`vector`) that can store the elements. We will also need two pointers, one to keep track of the front of the deque (`frd`), and the other to keep track of the rear (`bck`). These pointers will allow us to efficiently add and remove elements at both ends, wrapping around when necessary. The approach can be broken down as follows:

1. **Circular Buffer Mechanism**: The deque is implemented as a circular buffer, meaning that when the front or rear reaches the end of the array, it wraps around to the beginning. This can be achieved using modulo arithmetic to keep the indices within the bounds of the array.
   
2. **Tracking Size and Count**: We maintain a variable `cnt` to track the current number of elements in the deque, and a variable `sz` to store the size of the deque. This allows us to easily check if the deque is full or empty.

3. **Operations**:
   - For **insertFront** and **insertLast**, we check if the deque is full by comparing `cnt` to `sz`. If not full, we add the element at the corresponding index (front or rear), update the pointer (wrapping around using modulo), and increment the `cnt`.
   - For **deleteFront** and **deleteLast**, we check if the deque is empty by checking if `cnt` is zero. If not empty, we update the pointer to remove an element from the corresponding index and decrement `cnt`.
   - For **getFront** and **getRear**, we return the element at the front or rear index, respectively, considering the wrapping behavior.

4. **Edge Cases**:
   - The `getFront()` and `getRear()` methods handle the case where the deque is empty by returning `-1`.
   - The `isEmpty()` and `isFull()` methods return `true` or `false` based on the current number of elements.

### Code Breakdown (Step by Step)

Let’s now break down the code step by step to understand the implementation:

#### 1. **Class Initialization**:
```cpp
class MyCircularDeque {
    vector<int> buf;
    int frd, bck;
    int sz, cnt;
public:
    MyCircularDeque(int k) : sz(k), buf(k, 0), bck(0), frd(k - 1), cnt(0) {}
```
- The class `MyCircularDeque` uses a vector `buf` to store the elements of the deque.
- `frd` and `bck` are the indices for the front and rear of the deque. Initially, `frd` is set to `k-1` (end of the buffer) and `bck` is set to `0` (beginning of the buffer).
- `sz` is the size of the deque, and `cnt` is the current number of elements in the deque.

#### 2. **Insert Front**:
```cpp
    bool insertFront(int value) {
        if(isFull()) return false;
        buf[frd] = value;
        frd = (frd - 1 + sz) % sz;
        ++cnt;
        return true;
    }
```
- The `insertFront` method first checks if the deque is full using `isFull()`. If full, it returns `false`.
- If not full, the value is inserted at the current `frd` index.
- The front pointer `frd` is then moved one step backward, using modulo arithmetic to wrap around if necessary.
- The count `cnt` is incremented, and `true` is returned to indicate success.

#### 3. **Insert Last**:
```cpp
    bool insertLast(int value) {
        if(isFull()) return false;
        buf[bck] = value;
        bck = (bck + 1) % sz;
        ++cnt;
        return true;
    }
```
- The `insertLast` method behaves similarly to `insertFront`, but it inserts the element at the `bck` index (the rear of the deque).
- The rear pointer `bck` is then moved one step forward using modulo arithmetic.

#### 4. **Delete Front**:
```cpp
    bool deleteFront() {
        if(isEmpty()) return false;
        frd = (frd + 1) % sz;
        --cnt;
        return true;
    }
```
- The `deleteFront` method first checks if the deque is empty using `isEmpty()`. If empty, it returns `false`.
- If not empty, the front pointer `frd` is moved one step forward (deleting the front element).
- The count `cnt` is decremented, and `true` is returned to indicate success.

#### 5. **Delete Last**:
```cpp
    bool deleteLast() {
        if(isEmpty()) return false;
        bck = (bck - 1 + sz) % sz;
        --cnt;
        return true;
    }
```
- The `deleteLast` method behaves similarly to `deleteFront`, but it moves the rear pointer `bck` one step backward.

#### 6. **Get Front**:
```cpp
    int getFront() {
        if(isEmpty()) return -1;
        return buf[(frd + 1) % sz];
    }
```
- The `getFront` method returns the element at the front of the deque. If the deque is empty, it returns `-1`. The front pointer is wrapped around using modulo arithmetic.

#### 7. **Get Rear**:
```cpp
    int getRear() {
        if(isEmpty()) return -1;
        return buf[(bck - 1 + sz) % sz];
    }
```
- The `getRear` method returns the element at the rear of the deque. If the deque is empty, it returns `-1`. The rear pointer is wrapped around using modulo arithmetic.

#### 8. **Is Empty**:
```cpp
    bool isEmpty() {
        return cnt == 0;
    }
```
- The `isEmpty` method returns `true` if the deque has no elements (`cnt == 0`), otherwise `false`.

#### 9. **Is Full**:
```cpp
    bool isFull() {
        return cnt == sz;
    }
```
- The `isFull` method returns `true` if the deque is full (`cnt == sz`), otherwise `false`.

### Complexity

#### Time Complexity:
- **Insertions**: Both `insertFront` and `insertLast` run in constant time, `O(1)`, as they only involve checking if the deque is full, adding an element, and updating the pointers.
- **Deletions**: Both `deleteFront` and `deleteLast` run in constant time, `O(1)`, as they only involve checking if the deque is empty, removing an element, and updating the pointers.
- **Get Operations**: Both `getFront` and `getRear` run in constant time, `O(1)`, as they directly access the elements in the deque using the current pointers.
- **IsEmpty and IsFull**: Both operations run in constant time, `O(1)`, as they simply compare the count of elements with the size of the deque.

#### Space Complexity:
- The space complexity is `O(k)`, where `k` is the size of the deque, as we use a vector of size `k` to store the elements.

### Conclusion

This implementation of a circular deque provides efficient `O(1)` operations for insertion, deletion, and accessing elements from both ends of the deque. By utilizing a circular buffer and modulo arithmetic to handle wrapping around the array, the deque is able to make the most efficient use of the available space while maintaining constant-time operations. The space complexity is also optimal, using a fixed-size array to store the elements. This design ensures that all operations are performed efficiently, even as the size of the deque grows.

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-circular-deque/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
