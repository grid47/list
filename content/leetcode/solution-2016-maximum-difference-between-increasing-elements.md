
+++
authors = ["grid47"]
title = "Leetcode 2016: Maximum Difference Between Increasing Elements"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2016: Maximum Difference Between Increasing Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "OmNZRgKr7GQ"
youtube_upload_date="2021-09-26"
youtube_thumbnail="https://i.ytimg.com/vi/OmNZRgKr7GQ/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array nums of size n. Your task is to find the maximum difference between two elements in the array such that the element on the right is strictly greater than the element on the left. Specifically, you need to find the largest difference between nums[j] - nums[i] where 0 <= i < j < n and nums[i] < nums[j]. If no such valid pair exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array nums of size n, where each element is an integer.
- **Example:** `[8, 1, 6, 3]`
- **Constraints:**
	- 2 <= n <= 1000
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum difference between nums[j] - nums[i] where 0 <= i < j < n and nums[i] < nums[j]. If no such pair exists, return -1.
- **Example:** `5`
- **Constraints:**
	- The result should be an integer representing the maximum difference, or -1 if no valid pair exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to traverse through the array while keeping track of the minimum value seen so far. For each new element, calculate the difference with the minimum value and update the result if this difference is larger. If no valid difference is found, return -1.

- Initialize a variable to keep track of the minimum value seen so far.
- Iterate through the array, and for each element, compute the difference with the minimum value.
- Keep track of the largest difference found during the iteration.
- Return the largest difference if found, otherwise return -1.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always have at least two elements.
- The solution should handle arrays of varying sizes and values.
{{< dots >}}
## Examples 🧩
- **Input:** `[8, 1, 6, 3]`  \
  **Explanation:** The maximum difference occurs between 1 (at index 1) and 6 (at index 2), resulting in a difference of 5. No other valid pairs provide a larger difference.

- **Input:** `[7, 6, 5, 4]`  \
  **Explanation:** No valid pair exists where nums[i] < nums[j], so the result is -1.

- **Input:** `[1, 3, 2, 7]`  \
  **Explanation:** The maximum difference occurs between 1 (at index 0) and 7 (at index 3), giving a difference of 6.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the array while keeping track of the minimum element encountered so far. For each new element, we compute the difference with the minimum element and update the result if necessary.

### Initial Thoughts 💭
- The problem requires us to find the maximum difference between elements, but only if the element on the right is strictly greater.
- We can maintain a variable for the minimum element seen so far and compute the difference with each subsequent element.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty, as n is guaranteed to be at least 2.
- The algorithm should handle up to 1000 elements efficiently.
- If the array contains only decreasing values, return -1.
- The solution must run within time limits for arrays of size up to 1000.
{{< dots >}}
## Code 💻
```cpp
int maximumDifference(vector<int>& nums) {
    int mn = nums[0], res = -1;
    for (int i = 1; i < nums.size(); ++i) {
        res = max(res, nums[i] - mn);
        mn = min(mn, nums[i]);
    }
    return res == 0 ? -1 : res;
}
```

This code defines the function `maximumDifference` that calculates the maximum difference between elements in the `nums` array where the larger number appears after the smaller number.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumDifference(vector<int>& nums) {
	```
	This line defines the function `maximumDifference` that takes a reference to a vector of integers `nums` and returns the maximum difference between any two elements in the array, where the larger element comes after the smaller one.

2. **Variable Initialization**
	```cpp
	    int mn = nums[0], res = -1;
	```
	This line initializes two variables: `mn` is set to the first element of the array (used to track the minimum element encountered so far), and `res` is initialized to -1 to store the maximum difference.

3. **Loop Initialization**
	```cpp
	    for (int i = 1; i < nums.size(); ++i) {
	```
	This initiates a loop that starts from the second element of the `nums` vector (index 1) and iterates over the remaining elements.

4. **Calculation**
	```cpp
	        res = max(res, nums[i] - mn);
	```
	This line updates the variable `res` with the maximum difference found so far, comparing the current element `nums[i]` with the smallest element `mn` encountered up to that point.

5. **Update Minimum**
	```cpp
	        mn = min(mn, nums[i]);
	```
	This updates the variable `mn` to the smaller of the current `mn` and the current element `nums[i]`. This ensures that `mn` always holds the smallest value encountered up to that point.

6. **Return Statement**
	```cpp
	    return res == 0 ? -1 : res;
	```
	This returns the maximum difference stored in `res`. If no valid difference was found (i.e., `res` is still 0), it returns -1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We only need to iterate through the array once, making the time complexity O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because we only use a few variables to store the result and minimum element.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/)

---
{{< youtube OmNZRgKr7GQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
