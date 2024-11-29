
+++
authors = ["grid47"]
title = "Leetcode 581: Shortest Unsorted Continuous Subarray"
date = "2024-09-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 581: Shortest Unsorted Continuous Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Stack","Greedy","Sorting","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/581.webp"
youtube = "NzVaNmqPaSo"
youtube_upload_date="2021-02-25"
youtube_thumbnail="https://i.ytimg.com/vi/NzVaNmqPaSo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/581.webp" 
    alt="An array where the shortest unsorted subarray is found, each element softly glowing as it is highlighted."
    caption="Solution to LeetCode 581: Shortest Unsorted Continuous Subarray Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array, find the shortest continuous subarray such that, if you sort this subarray in non-decreasing order, the whole array will become sorted.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A list of integers, nums, representing the array to be considered.
- **Example:** `Input: nums = [3, 8, 6, 10, 12, 9, 14]`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- -10^5 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the shortest subarray that needs to be sorted in order to make the whole array sorted.
- **Example:** `Output: 4`
- **Constraints:**
	- The output must be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the shortest subarray that needs to be sorted to make the entire array sorted.

- Identify the part of the array that is out of order.
- Check for the leftmost and rightmost positions where elements are not in order.
- Find the subarray between these positions and calculate its length.
- Return the length of the shortest subarray that needs to be sorted.
{{< dots >}}
### Problem Assumptions ✅
- The input array is not empty.
- The array contains only integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, 8, 6, 10, 12, 9, 14]`  \
  **Explanation:** The subarray [8, 6, 10, 12] is the only part that is out of order, so sorting it will sort the entire array.

- **Input:** `Input: nums = [1, 2, 3, 4]`  \
  **Explanation:** The array is already sorted, so the length of the subarray to be sorted is 0.

{{< dots >}}
## Approach 🚀
The key idea is to find the positions where the array stops being sorted and then calculate the length of the subarray that needs to be sorted.

### Initial Thoughts 💭
- The problem boils down to finding where the array is unsorted, both from the left and right sides.
- We need to find the smallest subarray that, when sorted, sorts the entire array.
- We can scan the array from both ends to identify where the unsorted subarray starts and ends.
{{< dots >}}
### Edge Cases 🌐
- The input array is always non-empty according to the constraints.
- The input size can be as large as 10^4, so the solution needs to be efficient in time and space.
- If the array is already sorted, return 0.
- The solution must run in O(n) time.
{{< dots >}}
## Code 💻
```cpp
int findUnsortedSubarray(vector<int>& nums) {
    
    int mn = 0, mx = 0, n = nums.size();
    
    
    vector<pair<int, int>> tmp(n);
    
    for(int i = 0; i < n; i++)
    tmp[i] = make_pair(nums[i], i);
    
    sort(tmp.begin(), tmp.end());
    
    int start = -1, end = -1;
    
    for(int i = 0; i < n; i++) {
        if(i != tmp[i].second)
            if (start == -1) start = i;
            else               end = i;
    }
    
    if(start == -1) return 0;
    return end - (start - 1);
}
```

This function finds the shortest unsorted subarray that, when sorted, results in the entire array being sorted. The function uses sorting and compares the sorted array's indices with the original array's indices to identify the unsorted subarray.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int findUnsortedSubarray(vector<int>& nums) {
	```
	Declares the function `findUnsortedSubarray`, which takes a vector of integers as input and returns the length of the shortest unsorted subarray.

2. **Variable Initialization**
	```cpp
	    int mn = 0, mx = 0, n = nums.size();
	```
	Initializes variables `mn`, `mx`, and `n`. `mn` and `mx` will be used to track the minimum and maximum values within the subarray, while `n` holds the size of the input array.

3. **Temporary Array Initialization**
	```cpp
	    vector<pair<int, int>> tmp(n);
	```
	Creates a temporary vector `tmp` of pairs, where each pair contains an element from the `nums` array and its corresponding index. This will help track the original order of elements while sorting.

4. **Array Population**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Starts a loop to populate the `tmp` vector with pairs. Each pair consists of an element from `nums` and its corresponding index.

5. **Pair Assignment**
	```cpp
	    tmp[i] = make_pair(nums[i], i);
	```
	For each element in `nums`, assigns a pair containing the element and its index to `tmp[i]`.

6. **Array Sorting**
	```cpp
	    sort(tmp.begin(), tmp.end());
	```
	Sorts the `tmp` vector based on the element values. This is essential to compare the original order with the sorted order and identify the subarray that is out of order.

7. **Variable Initialization for Indices**
	```cpp
	    int start = -1, end = -1;
	```
	Initializes two variables `start` and `end` to -1. These will be used to track the first and last indices of the unsorted subarray.

8. **Subarray Identification Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to compare the indices of the original array (`nums`) with those in the sorted `tmp` array. If the indices don't match, it identifies the unsorted subarray.

9. **Index Comparison**
	```cpp
	        if(i != tmp[i].second)
	```
	Compares the current index `i` with the index in the sorted `tmp` array. If they don't match, it indicates that this element is part of the unsorted subarray.

10. **Start Index Assignment**
	```cpp
	            if (start == -1) start = i;
	```
	If `start` is still -1 (not yet set), assigns the current index `i` as the `start` of the unsorted subarray.

11. **End Index Assignment**
	```cpp
	            else               end = i;
	```
	Once `start` is assigned, sets the current index `i` as the `end` of the unsorted subarray.

12. **Check for Already Sorted Array**
	```cpp
	    if(start == -1) return 0;
	```
	Checks if the array is already sorted. If `start` is still -1, it means no unsorted subarray was found, so it returns 0.

13. **Return Subarray Length**
	```cpp
	    return end - (start - 1);
	```
	Calculates and returns the length of the unsorted subarray by subtracting `start` from `end`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We scan the array once to find the leftmost and rightmost out-of-order elements, resulting in O(n) time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution only requires a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/)

---
{{< youtube NzVaNmqPaSo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
