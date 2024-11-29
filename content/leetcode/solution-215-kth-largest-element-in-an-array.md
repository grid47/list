
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
comments = true
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
Given an array of integers, find the kth largest element without sorting the entire array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums and an integer k. The array contains n integers, and k is an integer specifying the rank of the largest element to find.
- **Example:** `[7, 2, 5, 8, 3, 9], k = 3`
- **Constraints:**
	- 1 <= k <= nums.length <= 10^5
	- -10^4 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the kth largest element from the array.
- **Example:** `For input [7, 2, 5, 8, 3, 9] and k = 3, the output is 7.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Efficiently find the kth largest element in the array.

- Use a priority queue (min-heap) to keep track of the k largest elements encountered so far.
- Iterate through the array, pushing each element into the heap. If the heap exceeds size k, remove the smallest element.
- After processing the array, the root of the heap will contain the kth largest element.
{{< dots >}}
### Problem Assumptions ✅
- k will always be a valid number, such that 1 <= k <= nums.length.
- The array will not be empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this example, the 3rd largest element is 7. After sorting the array in descending order, the array becomes [9, 8, 7, 5, 3, 2]. The 3rd largest element is 7.

- **Input:** `Example 2`  \
  **Explanation:** In this example, the 2nd largest element is 8. The sorted array is [10, 8, 6, 4, 2, 1]. The 2nd largest element is 8.

{{< dots >}}
## Approach 🚀
Use a heap (priority queue) to maintain the k largest elements efficiently without sorting the entire array.

### Initial Thoughts 💭
- Sorting the entire array would be inefficient for large arrays. A heap can help achieve this in O(n log k) time.
- The heap's size will be kept at k, and we will only insert new elements into the heap when necessary.
{{< dots >}}
### Edge Cases 🌐
- The array will not be empty.
- Ensure that the solution works for arrays up to size 10^5.
- If the array contains duplicate elements, the algorithm will still correctly identify the kth largest element.
- Handle cases where all elements in the array are the same.
{{< dots >}}
## Code 💻
```cpp
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
```

This function finds the kth largest element in an unsorted array using a priority queue (max heap). The heap is filled with the elements, and then we pop elements until the kth largest is found.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	int findKthLargest(vector<int>& nums, int k) {
	```
	The method definition for the 'findKthLargest' function, which takes a vector of integers 'nums' and an integer 'k' as input.

2. **Priority Queue Initialization**
	```cpp
	    priority_queue<int> pq;
	```
	Initializes a priority queue 'pq' (a max heap by default in C++) to store the elements of the array 'nums'.

3. **Loop Iteration**
	```cpp
	    for(int x: nums)
	```
	Iterates over each element 'x' in the 'nums' vector.

4. **Priority Queue Insertion**
	```cpp
	        pq.push(x);
	```
	Pushes each element 'x' from the 'nums' vector into the priority queue 'pq'.

5. **Variable Declaration**
	```cpp
	    int x;
	```
	Declares an integer variable 'x' to store the current top element from the priority queue.

6. **While Loop**
	```cpp
	    while(k-->0) {
	```
	A loop that runs 'k' times, each time removing the largest element from the priority queue.

7. **Priority Queue Access**
	```cpp
	        x = pq.top();
	```
	Accesses the top (largest) element of the priority queue and assigns it to the variable 'x'.

8. **Priority Queue Removal**
	```cpp
	        pq.pop();
	```
	Removes the top element from the priority queue.

9. **Return Statement**
	```cpp
	    return x;
	```
	Returns the 'kth' largest element (the last element 'x' retrieved from the priority queue).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log k), where n is the length of the array.
- **Average Case:** O(n log k), as we iterate through the array and perform heap operations.
- **Worst Case:** O(n log k), since each heap operation takes O(log k) time, and we do this for each of the n elements.

The time complexity is proportional to the number of elements in the array, with the log k factor accounting for the heap operations.

### Space Complexity 💾
- **Best Case:** O(k), since the heap size is always k.
- **Worst Case:** O(k), as we store at most k elements in the heap.

The space complexity is dominated by the size of the heap, which is k.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

---
{{< youtube ZmGk7h8KZLs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
