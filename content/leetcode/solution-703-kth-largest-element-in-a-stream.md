
+++
authors = ["grid47"]
title = "Leetcode 703: Kth Largest Element in a Stream"
date = "2024-08-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 703: Kth Largest Element in a Stream in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Design","Binary Search Tree","Heap (Priority Queue)","Binary Tree","Data Stream"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/703.webp"
youtube = "hOjcdrqMoQ8"
youtube_upload_date="2021-10-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/hOjcdrqMoQ8/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/703.webp" 
    alt="A stream of numbers where the kth largest element is identified, glowing brightly as it’s found."
    caption="Solution to LeetCode 703: Kth Largest Element in a Stream Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto x: nums) {
            pq.push(x);
            if(pq.size() > k) {
                cout << pq.top();
                pq.pop();
            }

        }

    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
{{< /highlight >}}
---

### Problem Statement:
The problem is to design a class `KthLargest` that efficiently supports two operations:
1. **Initialization**: It should accept an integer `k` and a list of integers `nums`. The class should store the k-th largest element from the list of numbers provided.
2. **Addition**: Given a number `val`, it should be added to the list, and the class should return the k-th largest number after this insertion.

This problem typically involves using a data structure like a heap (or priority queue) to efficiently manage and retrieve the k-th largest element. The solution should be optimized for both the initial list and future additions.

### Approach:
The most efficient way to solve this problem is to use a **min-heap** (priority queue). The idea is to maintain a heap of size `k`, where:
- The root of the heap is the k-th largest element in the current list of numbers.
- As we add new numbers, if the size of the heap exceeds `k`, we remove the smallest element (i.e., the root of the heap).

This approach ensures that after every insertion, the heap always maintains the k largest elements, and the root will represent the k-th largest element in the array.

### Code Breakdown (Step by Step):

#### Step 1: Define the Data Members
```cpp
priority_queue<int, vector<int>, greater<int>> pq;  // Min-heap to store the k largest elements
int k;  // The k-th largest element to track
```
- `pq` is a priority queue (min-heap) implemented using a vector. The third argument `greater<int>` ensures that the priority queue behaves as a min-heap (i.e., the smallest element is at the top).
- `k` stores the value of `k`, indicating the k-th largest element that we need to track.

#### Step 2: Constructor to Initialize the KthLargest Object
```cpp
KthLargest(int k, vector<int>& nums) {
    this->k = k;  // Set the value of k
    for(auto x: nums) {  // Iterate over each number in the input list
        pq.push(x);  // Add the number to the heap
        if(pq.size() > k) {  // If the heap size exceeds k, remove the smallest element
            cout << pq.top();  // Debugging line to print the top element (not part of the final solution)
            pq.pop();  // Remove the smallest element
        }
    }
}
```
- **Initialization**: The constructor accepts an integer `k` and a vector `nums` containing the initial list of numbers.
- We iterate over each element in `nums` and insert it into the min-heap.
- After inserting each number, we check if the heap size exceeds `k`. If it does, we remove the smallest element (`pq.pop()`), ensuring that the heap always stores only the k largest elements. The root of the heap (`pq.top()`) will always be the k-th largest element.
- The `cout` statement prints the current smallest element in the heap for debugging purposes.

#### Step 3: Add Method to Insert New Elements
```cpp
int add(int val) {
    pq.push(val);  // Add the new value to the heap
    if(pq.size() > k) {  // If the heap size exceeds k, remove the smallest element
        pq.pop();  // Remove the smallest element to maintain the heap size as k
    }
    return pq.top();  // Return the k-th largest element (the root of the min-heap)
}
```
- The `add()` function accepts an integer `val` and inserts it into the min-heap.
- After inserting the new value, we check if the heap size exceeds `k`. If it does, we remove the smallest element (i.e., the root of the heap) to ensure that the heap size remains `k`.
- Finally, we return the root of the heap (`pq.top()`), which represents the current k-th largest element.

#### Step 4: Notes on `cout` in the Constructor
The line `cout << pq.top();` inside the constructor is not necessary for the final solution. It seems like a debugging step to print the k-th largest element during the initialization phase. This should be removed in the production version to avoid unnecessary output.

### Complexity Analysis:

#### Time Complexity:
- **Constructor (`KthLargest`)**: 
  - Inserting an element into the min-heap takes **O(log k)** time.
  - Since there are `n` elements in `nums`, the total time for the constructor is **O(n log k)**, where `n` is the size of the input array `nums`.
  
- **Add Method (`add`)**:
  - Inserting a new element into the min-heap takes **O(log k)** time.
  - If the size of the heap exceeds `k`, we remove the smallest element, which also takes **O(log k)** time.
  - Therefore, the time complexity of the `add` method is **O(log k)**.

#### Space Complexity:
- **O(k)**: The priority queue stores at most `k` elements at any given time. Hence, the space complexity is **O(k)**, where `k` is the size of the heap.

### Conclusion:

The solution efficiently manages the k-th largest element using a min-heap (priority queue). This ensures that:
- Insertion of elements and maintaining the heap is done in **O(log k)** time.
- The space used by the heap is proportional to `k`, making it scalable even for large values of `n` (the number of elements to be processed).
  
This approach is highly efficient for problems involving dynamic insertion of elements while keeping track of the k-th largest value. The use of a min-heap ensures that the algorithm remains optimal, making it a preferred solution for similar problems in competitive programming and real-world applications.

[`Link to LeetCode Lab`](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)

---
{{< youtube hOjcdrqMoQ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
