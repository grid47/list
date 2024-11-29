
+++
authors = ["grid47"]
title = "Leetcode 769: Max Chunks To Make Sorted"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 769: Max Chunks To Make Sorted in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Greedy","Sorting","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/769.webp"
youtube = "b3Mf8c7hKjk"
youtube_upload_date="2024-02-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/b3Mf8c7hKjk/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/769.webp" 
    alt="A sequence where chunks are sorted, with each sorted chunk glowing softly as the process completes."
    caption="Solution to LeetCode 769: Max Chunks To Make Sorted Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array arr of length n, where the array is a permutation of integers in the range [0, n - 1]. Your task is to split this array into as many chunks (or partitions) as possible, where each chunk can be individually sorted. After sorting each chunk, when concatenated, the result should be the same as the fully sorted array. Return the largest number of chunks that you can create to achieve the sorted array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array arr, which represents a permutation of integers in the range [0, n - 1].
- **Example:** `Input: arr = [5, 3, 2, 1, 4]`
- **Constraints:**
	- 1 <= arr.length <= 10
	- arr is a permutation of integers in the range [0, arr.length - 1].

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest number of chunks that can be created such that after sorting each chunk individually, the resulting concatenated array is sorted.
- **Example:** `Output: 1`
- **Constraints:**
	- The array should be partitioned in such a way that the sorted chunks, when concatenated, form the fully sorted array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to partition the array into the maximum number of chunks such that after sorting each chunk, the concatenated result is sorted.

- Iterate through the array and track the maximum value encountered so far.
- At each index, if the maximum value is equal to the current index, increment the chunk count.
- Return the total number of chunks.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always be a valid permutation of integers from 0 to n-1.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: arr = [5, 3, 2, 1, 4]`  \
  **Explanation:** In this case, the array is not easily separable into smaller chunks that would result in the sorted array, so the maximum number of chunks is 1.

- **Input:** `Example 2: Input: arr = [1, 0, 2, 3, 4]`  \
  **Explanation:** In this case, the array can be split into 4 chunks: [1, 0], [2], [3], [4], all of which are sorted when processed separately.

{{< dots >}}
## Approach 🚀
To solve this problem, we can iterate through the array while keeping track of the maximum value encountered so far. When the maximum value equals the current index, it indicates a valid chunk boundary. We can increment the chunk count and continue.

### Initial Thoughts 💭
- We need to partition the array into chunks where each chunk can be sorted independently and when combined, it forms the fully sorted array.
- Tracking the maximum value up to each index helps in determining the correct chunk boundaries.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least one element, as n >= 1.
- Ensure the solution handles the maximum constraint, where the array size is 10.
- If the array is already sorted, each element can be its own chunk.
- The array is a permutation of integers from 0 to n-1.
{{< dots >}}
## Code 💻
```cpp
int maxChunksToSorted(vector<int>& arr) {
    
    int n = arr.size();

    int res = 0, mx = arr[0];

    for(int i = 0; i < n; i++) {
        
        mx = max(mx, arr[i]);
        res += (mx == i);
        
    }
    
    return res;
}
```

This function takes a vector of integers as input and returns the maximum number of chunks (subarrays) that can be sorted independently to form the entire sorted array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxChunksToSorted(vector<int>& arr) {
	```
	Define the function that takes a vector of integers as input.

2. **Variable Declaration**
	```cpp
	    int n = arr.size();
	```
	Initialize the variable 'n' to store the size of the input array.

3. **Variable Initialization**
	```cpp
	    int res = 0, mx = arr[0];
	```
	Initialize 'res' (the result variable) to 0 and 'mx' (the maximum value seen so far) to the first element of the array.

4. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start iterating through the array from the first element.

5. **Max Update**
	```cpp
	        mx = max(mx, arr[i]);
	```
	Update the maximum value 'mx' by comparing it with the current element 'arr[i]'.

6. **Result Update**
	```cpp
	        res += (mx == i);
	```
	Increment 'res' by 1 if the maximum value matches the current index 'i'. This checks if the current subarray can be sorted independently.

7. **Return Value**
	```cpp
	    return res;
	```
	Return the final result, which is the number of chunks.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the array.
- **Average Case:** O(n), since we iterate over the array once.
- **Worst Case:** O(n), as we only perform one pass through the array.

The time complexity is linear because we only iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(1), since we only need constant space to track the maximum value and chunk count.
- **Worst Case:** O(1), as no additional space is required except for the variables used in the logic.

The space complexity is constant because we only use a few variables for tracking.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/max-chunks-to-make-sorted/description/)

---
{{< youtube b3Mf8c7hKjk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
