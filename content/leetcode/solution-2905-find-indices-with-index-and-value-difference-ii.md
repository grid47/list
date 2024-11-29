
+++
authors = ["grid47"]
title = "Leetcode 2905: Find Indices With Index and Value Difference II"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2905: Find Indices With Index and Value Difference II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TZFQMCeNEho"
youtube_upload_date="2023-10-15"
youtube_thumbnail="https://i.ytimg.com/vi/TZFQMCeNEho/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array nums of size n, an integer indexDifference, and an integer valueDifference. Your task is to find two indices i and j that satisfy the following conditions:

- abs(i - j) >= indexDifference,
- abs(nums[i] - nums[j]) >= valueDifference.

Return the indices [i, j] if such a pair exists, or [-1, -1] if no such pair exists. If there are multiple pairs, any valid pair is acceptable.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array nums, a positive integer indexDifference, and a positive integer valueDifference.
- **Example:** `nums = [7, 3, 8, 2], indexDifference = 2, valueDifference = 4`
- **Constraints:**
	- 1 <= n == nums.length <= 10^5
	- 0 <= nums[i] <= 10^9
	- 0 <= indexDifference <= 10^5
	- 0 <= valueDifference <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a two-element array [i, j] if there are indices i and j that satisfy the conditions. If no such pair exists, return [-1, -1].
- **Example:** `[0, 3]`
- **Constraints:**
	- The answer should contain two indices, either valid or [-1, -1].

{{< dots >}}
### Core Logic 🔍
**Goal:** To find indices i and j such that the absolute differences between their indices and values meet the specified conditions.

- 1. Iterate through the array with two pointers (i and j).
- 2. Check if the difference between the indices and the values meets the criteria.
- 3. Return the valid indices as soon as found, otherwise return [-1, -1].
{{< dots >}}
### Problem Assumptions ✅
- The input will always be a valid array with non-negative integers.
- Both indexDifference and valueDifference are non-negative.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [7, 3, 8, 2], indexDifference = 2, valueDifference = 4`  \
  **Explanation:** The pair (0, 3) satisfies abs(i - j) >= 2 and abs(nums[i] - nums[j]) >= 4, hence the valid pair is [0, 3].

{{< dots >}}
## Approach 🚀
The problem can be approached by iterating through the array with two pointers, keeping track of the indices that satisfy the difference conditions.

### Initial Thoughts 💭
- We need to check if both the index difference and value difference conditions are met.
- It’s crucial to maintain two pointers to check for the conditions efficiently.
{{< dots >}}
### Edge Cases 🌐
- Input arrays of size 1.
- Input arrays of size 10^5.
- IndexDifference or ValueDifference being 0.
- Both nums[i] and indexDifference can have very large values.
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

This function finds and returns the indices of two elements in the vector `nums` such that the difference between them is at least `vdif`. The starting index for the search is provided by `idif`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findIndices(vector<int>& nums, int idif, int vdif) {
	```
	Defines the function `findIndices` which takes a vector `nums`, an index `idif`, and a difference value `vdif`, and returns a pair of indices where the absolute difference between the values at those indices is at least `vdif`.

2. **Variable Initialization**
	```cpp
	    int mn = 0, mx = 0;
	```
	Initializes two integer variables `mn` and `mx` to store the indices of the minimum and maximum values in the window being examined.

3. **Loop Initialization**
	```cpp
	    for (int i = idif, j = 0; i < nums.size(); ++i, ++j) {
	```
	Starts a loop to iterate through the `nums` vector, with `i` as the index starting from `idif`, and `j` as the index of the current element in the window.

4. **Compare Min**
	```cpp
	        mn = nums[mn] < nums[j] ? mn : j;
	```
	Updates the `mn` variable to the index of the smaller value between the current `mn` and `j`. This tracks the minimum value in the window.

5. **Compare Max**
	```cpp
	        mx = nums[mx] > nums[j] ? mx : j;
	```
	Updates the `mx` variable to the index of the larger value between the current `mx` and `j`. This tracks the maximum value in the window.

6. **Condition Check for Min**
	```cpp
	        if (abs(nums[i] - nums[mn]) >= vdif)
	```
	Checks if the absolute difference between the current element `nums[i]` and the minimum value `nums[mn]` is greater than or equal to `vdif`.

7. **Return Indices for Min**
	```cpp
	            return {mn, i};
	```
	If the condition is true, returns the indices of the minimum value and the current index `i`.

8. **Condition Check for Max**
	```cpp
	        if (abs(nums[i] - nums[mx]) >= vdif)
	```
	Checks if the absolute difference between the current element `nums[i]` and the maximum value `nums[mx]` is greater than or equal to `vdif`.

9. **Return Indices for Max**
	```cpp
	            return {mx, i};
	```
	If the condition is true, returns the indices of the maximum value and the current index `i`.

10. **Return Default Indices**
	```cpp
	    return {-1, -1};        
	```
	If no valid pair of indices is found, returns `{-1, -1}` to indicate no solution.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We iterate through the array once, so the time complexity is O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We use a constant amount of space to store variables for tracking the indices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-indices-with-index-and-value-difference-ii/description/)

---
{{< youtube TZFQMCeNEho >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
