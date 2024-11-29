
+++
authors = ["grid47"]
title = "Leetcode 2873: Maximum Value of an Ordered Triplet I"
date = "2024-01-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2873: Maximum Value of an Ordered Triplet I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "U0abRgobTKg"
youtube_upload_date="2023-10-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/U0abRgobTKg/maxresdefault.webp"
comments = true
+++



---
You are given an array nums of integers. Find the maximum value over all possible triplets of indices (i, j, k) such that i < j < k. The value of a triplet (i, j, k) is calculated as (nums[i] - nums[j]) * nums[k]. If all triplets have negative values, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums where 3 <= nums.length <= 100, and 1 <= nums[i] <= 10^6.
- **Example:** `nums = [10, 5, 3, 6, 9]`
- **Constraints:**
	- 3 <= nums.length <= 100
	- 1 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all values are negative, return 0.
- **Example:** `For input nums = [10, 5, 3, 6, 9], the output is 48.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the value of (nums[i] - nums[j]) * nums[k] for triplets (i, j, k) where i < j < k.

- Iterate through each element in the array.
- For each element, calculate the value of all possible triplets using it as i, j, or k.
- Track the maximum value found during the iteration.
- Return the maximum value or 0 if no non-negative triplet value exists.
{{< dots >}}
### Problem Assumptions ✅
- The array has at least 3 elements.
{{< dots >}}
## Examples 🧩
- **Input:** `For input nums = [10, 5, 3, 6, 9], the output is 48.`  \
  **Explanation:** The triplet (0, 2, 4) results in the maximum value (10 - 3) * 9 = 48.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to iterate through all possible triplets and calculate their values. The maximum value can then be returned.

### Initial Thoughts 💭
- The problem requires examining every triplet (i, j, k).
- The values of the triplets depend on the subtraction of nums[i] and nums[j] multiplied by nums[k].
- Instead of checking all triplets brute force, we can iterate through the array while keeping track of the maximum possible values efficiently.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least 3 elements, so no need to handle empty inputs.
- Ensure that the solution efficiently handles arrays with up to 100 elements.
- Consider cases where no valid triplet results in a non-negative value.
- The algorithm must run efficiently even for the largest inputs.
{{< dots >}}
## Code 💻
```cpp
long long maximumTripletValue(vector<int>& nums) {
    long res = 0, mxa = 0, mxab = 0;
    for(long a: nums) {
        res = max(res, mxab * a);
        mxab = max(mxab, mxa - a);
        mxa = max(mxa, a);
    }
    return res;
}
```

This function computes the maximum value of the triplet formed by three integers from the given array, using a combination of the current element and maximum values observed during the iteration.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long maximumTripletValue(vector<int>& nums) {
	```
	Function declaration that accepts a vector of integers and returns a long integer, representing the maximum triplet value.

2. **Variable Initialization**
	```cpp
	    long res = 0, mxa = 0, mxab = 0;
	```
	Initialize three variables: 'res' to store the result, 'mxa' for the maximum value encountered so far, and 'mxab' for the maximum value of (mxa - a).

3. **Loop Setup**
	```cpp
	    for(long a: nums) {
	```
	Start a loop to iterate over each element 'a' in the input array 'nums'.

4. **Max Calculation**
	```cpp
	        res = max(res, mxab * a);
	```
	Update 'res' by comparing its current value with the product of 'mxab' and 'a', ensuring that the largest product is kept.

5. **Update mxab**
	```cpp
	        mxab = max(mxab, mxa - a);
	```
	Update 'mxab' to store the maximum value between its current value and the difference between 'mxa' and 'a'.

6. **Update mxa**
	```cpp
	        mxa = max(mxa, a);
	```
	Update 'mxa' to store the maximum value encountered so far during the loop.

7. **Return Result**
	```cpp
	    return res;
	```
	Return the final result, which is the maximum triplet value computed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we are considering all possible triplets.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/)

---
{{< youtube U0abRgobTKg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
