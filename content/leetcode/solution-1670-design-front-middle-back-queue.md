
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
+++



---
**Code:**

{{< highlight cpp >}}
class FrontMiddleBackQueue {
    deque<int> a, b;
    
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
 */
{{< /highlight >}}
---

The `FrontMiddleBackQueue` class is a data structure that supports efficient insertion and removal of elements from both ends and the middle. This class is particularly useful in scenarios where operations on both ends of the queue and the middle are frequent. 

### Problem Statement
The challenge is to implement a queue that allows for insertion and removal of elements at the front, middle, and back. Traditional queues support insertion and removal only at the front and back, but this problem requires additional functionality to manage the middle efficiently.

### Approach
To achieve the desired functionality, the `FrontMiddleBackQueue` uses two deques, `a` and `b`. The idea is to maintain an invariant where `a` holds the first half of the elements and `b` holds the second half. This design allows for efficient operations as follows:

1. **Push Operations**:
   - **`pushFront(int val)`**: This method adds an element to the front of the queue. The element is first added to deque `a`. If deque `a` becomes larger than deque `b`, we move the last element of `a` to the front of `b` to maintain balance.
   - **`pushMiddle(int val)`**: To insert an element in the middle, we add the element to deque `a` and then ensure the sizes of `a` and `b` are balanced using the `a2b()` method.
   - **`pushBack(int val)`**: This method adds an element to the back of the queue by simply inserting it into deque `b`. After the insertion, the method checks if `b` has more than one element compared to `a`, and if so, it moves the front of `b` to the back of `a`.

2. **Pop Operations**:
   - **`popFront()`**: This method removes and returns the element from the front of the queue. If deque `a` is empty, it retrieves the front element from `b`. If `a` has elements, it pops from `a` and ensures that the sizes of the deques are balanced afterward.
   - **`popMiddle()`**: To remove the middle element, the method checks the sizes of both deques. If they are equal, it removes the last element from `a`. If `b` has more elements, it removes the front element from `b`.
   - **`popBack()`**: This method removes the last element from the queue. It pops from `b` and ensures the sizes are balanced by potentially moving an element from `a` to `b`.

### Code Breakdown (Step by Step)
1. **Data Structures**: The use of two deques (`a` and `b`) allows for efficient operations by keeping track of elements in a way that facilitates quick access and modification.
2. **Push Operations**:
   - Each push operation adjusts the deques' sizes to keep them balanced, ensuring that no more than one extra element is held in one deque compared to the other.
3. **Pop Operations**:
   - The pop methods also maintain the invariant by checking the sizes of the deques and making necessary adjustments after removing elements. This ensures that both deques remain balanced.

The implementation effectively combines the efficiency of deques with careful management of their sizes to allow for the required operations in constant time on average.

### Complexity
The average time complexity for all operations (`pushFront`, `pushMiddle`, `pushBack`, `popFront`, `popMiddle`, `popBack`) is O(1), thanks to the use of deques which provide efficient operations at both ends. The balancing operations (`a2b` and `b2a`) involve at most one element transfer, keeping the overall operations efficient.

### Conclusion
The `FrontMiddleBackQueue` is a well-designed data structure that effectively addresses the need for efficient insertions and deletions at the front, middle, and back of a queue. By leveraging two deques and ensuring their sizes remain balanced, this class provides a versatile and powerful solution for managing a collection of elements with varied access requirements. The careful consideration of operation efficiency makes it an excellent choice for applications that require dynamic and flexible queue management.

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-front-middle-back-queue/description/)

---
{{< youtube HSOiUhfXUTg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
