
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
comments = true
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
You are tasked with implementing a class that helps track the kth highest score in a dynamic list of test scores. Each time a new score is submitted, you need to return the kth highest score in the list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The class should be initialized with an integer k (the desired ranking) and a list of test scores. For each new score added to the stream, return the kth highest score in the list.
- **Example:** `KthLargest kthLargest = new KthLargest(2, [1, 3, 5, 7, 9]); kthLargest.add(6);`
- **Constraints:**
	- 0 <= nums.length <= 10^4
	- 1 <= k <= nums.length + 1
	- -10^4 <= nums[i] <= 10^4
	- -10^4 <= val <= 10^4
	- At most 10^4 calls will be made to the add method.

{{< dots >}}
### Output Specifications 📤
- **Output:** The method should return the kth largest number in the list after each new score is added.
- **Example:** `Output: [null, 5, 6, 7, 7]`
- **Constraints:**
	- The result after each call to add should be the kth largest score in the current list of test scores.

{{< dots >}}
### Core Logic 🔍
**Goal:** Track the kth largest score dynamically using a priority queue or a min-heap to efficiently maintain the list of the top k scores.

- 1. Initialize a priority queue (min-heap) to store the top k elements.
- 2. Add each score to the heap.
- 3. If the heap exceeds k elements, remove the smallest element.
- 4. After each addition, the top of the heap will be the kth largest score.
{{< dots >}}
### Problem Assumptions ✅
- The list will be dynamically updated with new scores.
- The kth largest element should be returned after each new score is added.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: KthLargest(2, [1, 3, 5, 7, 9])`  \
  **Explanation:** When the 2nd largest element is requested after each new score is added, the following occurs: add(6) => 6 becomes the 2nd largest number, add(8) => 7 becomes the 2nd largest number, etc.

{{< dots >}}
## Approach 🚀
The goal is to efficiently manage a dynamic list of scores and find the kth largest element after each insertion. A priority queue or min-heap can be used to keep track of the top k elements in the stream.

### Initial Thoughts 💭
- A heap is a good choice to manage a dynamic list of top k elements efficiently.
- Since we are only interested in the kth largest element, using a min-heap of size k ensures that the smallest element in the heap is always the kth largest.
{{< dots >}}
### Edge Cases 🌐
- The list of scores may be empty initially, but k will always be valid.
- If the number of scores is very large, ensure that the heap operations are optimized to handle up to 10,000 elements.
- If multiple scores have the same value, they should be treated as equal for the purposes of finding the kth largest score.
- Ensure the heap is only storing the top k elements at all times to maintain efficiency.
{{< dots >}}
## Code 💻
```cpp
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
```

This code defines a class KthLargest that finds the Kth largest element in a stream of integers. It uses a priority queue (min-heap) to keep track of the largest K elements, ensuring efficient updates as new values are added.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Priority Queue Initialization**
	```cpp
	priority_queue<int, vector<int>, greater<int>> pq;
	```
	A min-heap priority queue 'pq' is initialized to keep track of the K largest elements. The 'greater<int>' ensures the smallest element is at the top.

2. **Variable Declaration**
	```cpp
	int k;
	```
	The variable 'k' holds the value of K, which represents the number of largest elements to track.

3. **Constructor Definition**
	```cpp
	KthLargest(int k, vector<int>& nums) {
	```
	Constructor for the KthLargest class. It initializes 'k' and populates the priority queue 'pq' with the values from the input vector 'nums'.

4. **Variable Initialization**
	```cpp
	    this->k = k;
	```
	Assign the input value 'k' to the class variable 'k'.

5. **Loop Over Input Array**
	```cpp
	    for(auto x: nums) {
	```
	Iterate over each element in the input array 'nums' to populate the priority queue.

6. **Push to Priority Queue**
	```cpp
	        pq.push(x);
	```
	Push the current element 'x' from the input array into the priority queue.

7. **Check Priority Queue Size**
	```cpp
	        if(pq.size() > k) {
	```
	Check if the priority queue contains more than 'k' elements.

8. **Remove Smallest Element**
	```cpp
	            cout << pq.top();
	```
	Output the smallest element in the priority queue, which is at the top.

9. **Pop Top Element**
	```cpp
	            pq.pop();
	```
	Remove the smallest element from the priority queue to maintain only the K largest elements.

10. **Method Definition**
	```cpp
	int add(int val) {
	```
	Method that adds a new value 'val' to the priority queue and returns the current Kth largest element.

11. **Push Value to Queue**
	```cpp
	    pq.push(val);
	```
	Push the new value 'val' into the priority queue.

12. **Check Queue Size**
	```cpp
	    if(pq.size() > k) {
	```
	Check if the size of the priority queue exceeds 'k'.

13. **Pop Smallest Element**
	```cpp
	        pq.pop();
	```
	Pop the smallest element from the priority queue to ensure it only contains the largest 'k' elements.

14. **Return Kth Largest Element**
	```cpp
	    return pq.top();
	```
	Return the top element of the priority queue, which is the Kth largest element.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log k) for each add operation when the heap is not full.
- **Average Case:** O(log k) for each add operation.
- **Worst Case:** O(log k) for each add operation, where k is the number of elements in the heap.

The time complexity of adding a new score is logarithmic relative to k, the size of the heap.

### Space Complexity 💾
- **Best Case:** O(k), since the space required does not depend on the number of operations but only on k.
- **Worst Case:** O(k), as we only need to store the top k elements in the heap.

The space complexity is determined by the size of the heap, which stores the top k elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)

---
{{< youtube hOjcdrqMoQ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
