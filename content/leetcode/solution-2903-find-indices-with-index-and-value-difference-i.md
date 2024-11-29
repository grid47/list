
+++
authors = ["grid47"]
title = "Leetcode 2903: Find Indices With Index and Value Difference I"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2903: Find Indices With Index and Value Difference I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "R731s1mHVWM"
youtube_upload_date="2023-10-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/R731s1mHVWM/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed array of integers `nums` of length `n`, along with two integers, `indexDifference` and `valueDifference`. Your task is to find two indices `i` and `j` such that the difference between the indices is greater than or equal to `indexDifference`, and the absolute difference between the values at the indices is greater than or equal to `valueDifference`. Return the indices `[i, j]` if such a pair exists, otherwise return `[-1, -1]`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three parts: the array `nums` of integers, the integer `indexDifference`, and the integer `valueDifference`. All are provided in a 0-indexed format.
- **Example:** `nums = [7, 2, 5, 1], indexDifference = 2, valueDifference = 3`
- **Constraints:**
	- 1 <= n == nums.length <= 100
	- 0 <= nums[i] <= 50
	- 0 <= indexDifference <= 100
	- 0 <= valueDifference <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array containing two indices `[i, j]` that satisfy both conditions or `[-1, -1]` if no such indices exist.
- **Example:** `[0, 3]`
- **Constraints:**
	- If multiple pairs satisfy the conditions, return any valid pair.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find two indices such that their difference in indices is at least `indexDifference` and their values have a difference of at least `valueDifference`.

- 1. Iterate through the array `nums` while keeping track of possible pairs of indices.
- 2. For each pair of indices, check the difference in indices and the difference in their values.
- 3. If both conditions are satisfied, return the pair of indices.
- 4. If no such pair is found after iterating through the array, return `[-1, -1]`.
{{< dots >}}
### Problem Assumptions ✅
- The input array `nums` is non-empty.
- The values of `indexDifference` and `valueDifference` are always valid.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [7, 2, 5, 1], indexDifference = 2, valueDifference = 3`  \
  **Explanation:** In this example, the pair of indices `[0, 3]` satisfies both conditions: the index difference is `3`, which is greater than or equal to `2`, and the absolute value difference is `6`, which is greater than or equal to `3`.

- **Input:** `Input: [9, 3], indexDifference = 1, valueDifference = 6`  \
  **Explanation:** In this case, the pair `[0, 1]` satisfies both conditions. The index difference is `1` (equal to `1`) and the absolute value difference is `6` (equal to `6`).

{{< dots >}}
## Approach 🚀
We need to iterate through the array and check each possible pair of indices. For each pair, check if the conditions are met. If they are, return the pair of indices. If no such pair is found, return `[-1, -1]`.

### Initial Thoughts 💭
- The problem requires checking pairs of indices with a certain index difference and value difference.
- We will iterate through the array using two pointers, ensuring that the required conditions are satisfied for each pair of indices.
{{< dots >}}
### Edge Cases 🌐
- If `nums` is empty, return `[-1, -1]`.
- Handle arrays of length up to 100 efficiently.
- Consider cases where the values of `indexDifference` and `valueDifference` are zero.
- Ensure that the indices and values are within the given constraints.
{{< dots >}}
## Code 💻
```cpp
vector<int> findIndices(vector<int>& nums, int idif, int vdif) {

    int mn = 0, mx = 0;
    for (int i = idif, j = 0; i < nums.size(); ++i, ++j) {
        mn = nums[mn] < nums[j] ? mn : j;
        mx = nums[mx] > nums[j] ? mx : j;
        if (abs(nums[i] - nums[mn]) >= vdif)
            return {mn, i};
        if (abs(nums[i] - nums[mx]) >= vdif)
            return {mx, i};
    }
    return {-1, -1};        

}
```

This function returns the indices of two numbers from the given array `nums` that have a difference greater than or equal to `vdif` compared to either the minimum or maximum values in the array starting from index `idif`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findIndices(vector<int>& nums, int idif, int vdif) {
	```
	Defines the function `findIndices` which takes in an array `nums`, and two integers `idif` and `vdif`. The function aims to find two indices where the absolute difference between the elements satisfies certain conditions.

2. **Variable Initialization**
	```cpp
	    int mn = 0, mx = 0;
	```
	Initializes two integer variables `mn` and `mx` to track the indices of the minimum and maximum values encountered during the iteration over the array.

3. **Loop Initialization**
	```cpp
	    for (int i = idif, j = 0; i < nums.size(); ++i, ++j) {
	```
	Starts a loop from index `idif` to the end of the array, using two indices `i` and `j`. The variable `j` runs from the beginning of the array while `i` runs from `idif`.

4. **Min Index Update**
	```cpp
	        mn = nums[mn] < nums[j] ? mn : j;
	```
	Updates the minimum index `mn` to be the index of the smaller of the two values at `mn` and `j`.

5. **Max Index Update**
	```cpp
	        mx = nums[mx] > nums[j] ? mx : j;
	```
	Updates the maximum index `mx` to be the index of the larger of the two values at `mx` and `j`.

6. **Condition Check for Min**
	```cpp
	        if (abs(nums[i] - nums[mn]) >= vdif)
	```
	Checks if the absolute difference between the current element `nums[i]` and the minimum element `nums[mn]` is greater than or equal to `vdif`.

7. **Return Statement for Min**
	```cpp
	            return {mn, i};
	```
	If the condition is satisfied, returns the indices of the minimum element and the current element `i`.

8. **Condition Check for Max**
	```cpp
	        if (abs(nums[i] - nums[mx]) >= vdif)
	```
	Checks if the absolute difference between the current element `nums[i]` and the maximum element `nums[mx]` is greater than or equal to `vdif`.

9. **Return Statement for Max**
	```cpp
	            return {mx, i};
	```
	If the condition is satisfied, returns the indices of the maximum element and the current element `i`.

10. **Return Statement for No Result**
	```cpp
	    return {-1, -1};        
	```
	If no indices satisfy the conditions, returns {-1, -1}, indicating no valid pair of indices was found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is quadratic in the worst case, as we check each pair of indices.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We only need constant extra space, as we only store the current indices and perform comparisons.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-indices-with-index-and-value-difference-i/description/)

---
{{< youtube R731s1mHVWM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
