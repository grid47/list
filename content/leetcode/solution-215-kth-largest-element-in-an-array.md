
+++
authors = ["grid47"]
title = "Leetcode 215: Kth Largest Element in an Array"
date = "2024-10-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 215: Kth Largest Element in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Sorting","Heap (Priority Queue)","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/215.webp"
youtube = "ZmGk7h8KZLs"
youtube_upload_date="2024-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/ZmGk7h8KZLs/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/215.webp" 
    alt="An array of glowing elements with the kth largest element glowing brighter than the others."
    caption="Solution to LeetCode 215: Kth Largest Element in an Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int x: nums)
            pq.push(x);
        
        int x;
        while(k-->0) {
            x = pq.top();
            pq.pop();
        }
        return x;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

Hey there! 👋 In this problem, you're asked to find the `k`-th largest element in an unsorted array of integers. 📊 The number `k` represents the position of the largest element you're after, and your task is to return that element when the list is sorted in descending order.

---

### 🧠 Approach

To solve this efficiently, we’re going to use a **priority queue**. 🔑 This clever data structure will allow us to always access the largest element in constant time while keeping track of the order of the elements. It’s like having a trusty sidekick that can instantly give you the biggest treasure in the pile! 🏆

#### Key Concepts:
1. **Priority Queue (Max-Heap)**: A priority queue is a special data structure that lets us efficiently get the largest or smallest element. Here, we’ll use a **max-heap**, which ensures that the largest element is always at the top of the heap.
   
2. **Heap Property**: In a heap, each parent node is greater than or equal to its children (for a max-heap). So, the root always holds the largest element. 🌳

3. **How to Find the k-th Largest Element**: 
   - Insert all the elements of the array into the priority queue (max-heap).
   - Then, extract the largest element `k` times (first the largest, then the second largest, and so on).
   - After `k` extractions, the top element will be our `k`-th largest element!

---

### 🔨 Step-by-Step Code Breakdown

Let’s break this down and make sure we understand every part! 🔍

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;  // Step 1: Initialize a max-heap priority queue
        for(int x: nums)         // Step 2: Insert all elements from nums into the priority queue
            pq.push(x);
        
        int x;
        while(k-->0) {           // Step 3: Extract the top element k times
            x = pq.top();        // Get the largest element from the heap
            pq.pop();            // Remove the largest element
        }
        return x;                // Step 4: Return the k-th largest element
    }
};
```

#### Step-by-Step Explanation:
1. **Initialize the Priority Queue:**
   ```cpp
   priority_queue<int> pq;
   ```
   - We create a **max-heap** priority queue. In C++, `priority_queue` is a max-heap by default, so the largest element is always at the top! 🔝

2. **Insert Elements into the Priority Queue:**
   ```cpp
   for(int x: nums) 
       pq.push(x);
   ```
   - Here, we loop through each element `x` in the `nums` array and push it into the priority queue. Each insertion maintains the heap property, so the largest element always stays at the top. 💥

3. **Extract the Largest Element `k` Times:**
   ```cpp
   while(k-->0) { 
       x = pq.top(); 
       pq.pop();
   }
   ```
   - The `top()` function gives us the largest element at the root of the heap.
   - We then `pop()` it off the heap, and the next largest element moves to the top.
   - We repeat this process `k` times to find the `k`-th largest element.

4. **Return the k-th Largest Element:**
   ```cpp
   return x;
   ```
   - After the loop, `x` holds the value of the `k`-th largest element. That’s the one we return! 🎯

---

### 📈 Complexity Analysis

Let’s take a quick look at how efficient this solution is! 📊

#### Time Complexity:
- **Inserting all elements into the priority queue**: Each `push` operation in the priority queue takes `O(log n)` time, where `n` is the number of elements in the array.
  - So, inserting all `n` elements into the heap takes `O(n log n)` time.

- **Extracting the top element `k` times**: Each `pop` operation takes `O(log n)` time. Since we perform `k` extractions, the time complexity for this part is `O(k log n)`.

Therefore, the **total time complexity** is:
\[
O(n \log n) + O(k \log n) = O(n \log n)
\]
In most cases, `k <= n`, so the time complexity is dominated by the heap insertions, which is **O(n log n)**.

#### Space Complexity:
- We store all `n` elements in the priority queue, so the **space complexity** is `O(n)`.

---

### 🏁 Conclusion

And there you have it! 🎉 This solution is an efficient and intuitive way to find the `k`-th largest element in an unsorted array. By using a **max-heap**, we can efficiently track and extract the largest elements.

- **Time Complexity**: `O(n log n)`, which is great for handling even large arrays!
- **Space Complexity**: `O(n)`, due to storing the array in the priority queue.

This approach is clear, efficient, and works wonders for problems where we need to find the largest or smallest elements. 🚀 Keep this trick in your toolbox for future problems—it's a real lifesaver! 😎

[`Link to LeetCode Lab`](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

---
{{< youtube ZmGk7h8KZLs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
