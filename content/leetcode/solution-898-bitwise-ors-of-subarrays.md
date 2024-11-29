
+++
authors = ["grid47"]
title = "Leetcode 898: Bitwise ORs of Subarrays"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 898: Bitwise ORs of Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given an array of integers, return the number of distinct bitwise OR results from all the non-empty subarrays. A subarray is a contiguous sequence of elements from the array, and the bitwise OR of a subarray is the bitwise OR of each of the integers in that subarray.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers. Your task is to find the number of distinct bitwise OR results from all non-empty subarrays.
- **Example:** `Input: arr = [2, 4, 8]`
- **Constraints:**
	- 1 <= arr.length <= 50000
	- 0 <= arr[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the number of distinct bitwise OR results from all non-empty subarrays.
- **Example:** `Output: 6`
- **Constraints:**
	- The result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of distinct bitwise OR results from all the subarrays of the given array.

- 1. Use two sets: one to track the current bitwise OR results for each subarray, and another to store the final distinct results.
- 2. For each element in the array, calculate the bitwise OR with each element from the previous subarrays and update the results.
- 3. Add the new results to the set of distinct results.
- 4. After processing the entire array, return the size of the distinct results set.
{{< dots >}}
### Problem Assumptions ✅
- The input array will contain at least one element.
- The elements can be large integers, up to 10^9.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [2, 4, 8]`  \
  **Explanation:** The distinct bitwise OR results from all subarrays are: 2, 4, 8, 6 (2 | 4), 12 (4 | 8), and 14 (2 | 4 | 8). The result is 6 distinct values.

- **Input:** `Input: arr = [0]`  \
  **Explanation:** The only subarray is [0], and the result is 0. So the output is 1.

- **Input:** `Input: arr = [1, 1, 2]`  \
  **Explanation:** The subarrays and their results are: [1], [1], [2], [1, 1], [1, 2], [1, 1, 2]. These give the OR results: 1, 1, 2, 1, 3, 3. There are 3 distinct results.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the array and computing the bitwise OR for all possible subarrays. Using sets helps to track distinct results efficiently.

### Initial Thoughts 💭
- The bitwise OR of each subarray must be calculated and stored to ensure distinct results.
- Using a set will help in eliminating duplicates while keeping track of the results.
- The challenge is to efficiently compute the OR results for all subarrays without exceeding the time limits for large arrays.
{{< dots >}}
### Edge Cases 🌐
- An empty input array is not allowed based on the problem constraints.
- For large arrays, the solution must efficiently compute the OR results without exceeding time limits.
- Arrays with all elements as zero should still count as one distinct OR result (0).
- The solution must be optimized to handle arrays with up to 50,000 elements.
{{< dots >}}
## Code 💻
```cpp
int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> res, cur, cur2;

    for(int x : arr) {
        cur2 = { x };
        for(int i : cur)        cur2.insert(i | x);
        for(int j : cur = cur2)  res.insert(j);
    }

    return res.size();
}
```

This function calculates the number of unique results that can be obtained by applying the bitwise OR operation on all subarrays of the given array `arr`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int subarrayBitwiseORs(vector<int>& arr) {
	```
	The function `subarrayBitwiseORs` is defined, which takes a reference to a vector `arr` and returns an integer, representing the number of distinct bitwise OR results from all subarrays.

2. **Variable Initialization**
	```cpp
	    unordered_set<int> res, cur, cur2;
	```
	Three unordered sets are initialized: `res` will store the final distinct results, `cur` keeps track of the OR values of the current subarray, and `cur2` is used temporarily to hold new OR results during iteration.

3. ****
	```cpp
	
	```
	

4. **Main Loop**
	```cpp
	    for(int x : arr) {
	```
	The loop iterates through each element `x` of the array `arr`.

5. **Set Initialization**
	```cpp
	        cur2 = { x };
	```
	The set `cur2` is initialized with the current element `x`, starting a new subarray OR operation.

6. **Bitwise OR Update**
	```cpp
	        for(int i : cur)        cur2.insert(i | x);
	```
	For each element `i` in the `cur` set, the bitwise OR operation between `i` and the current element `x` is computed, and the result is inserted into `cur2`.

7. **Update Final Set**
	```cpp
	        for(int j : cur = cur2)  res.insert(j);
	```
	After updating `cur2`, the set `cur` is set to `cur2`, and the distinct results from `cur2` are inserted into the result set `res`.

8. **End of Loop**
	```cpp
	    }
	```
	The loop ends here, and the next element in the array will be processed.

9. ****
	```cpp
	
	```
	

10. **Return Statement**
	```cpp
	    return res.size();
	```
	The function returns the size of the set `res`, which represents the number of distinct bitwise OR results from all subarrays.

11. **Function End**
	```cpp
	}
	```
	The function ends here.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) in the worst case due to processing each element in all possible subarrays.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the use of sets to track the distinct OR results for subarrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/bitwise-ors-of-subarrays/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
