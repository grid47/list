
+++
authors = ["grid47"]
title = "Leetcode 2874: Maximum Value of an Ordered Triplet II"
date = "2024-01-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2874: Maximum Value of an Ordered Triplet II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QBLw9bVFIDQ"
youtube_upload_date="2023-10-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QBLw9bVFIDQ/maxresdefault.webp"
comments = true
+++



---
You are given an array nums of integers. Find the maximum value over all possible triplets of indices (i, j, k) such that i < j < k. The value of a triplet (i, j, k) is calculated as (nums[i] - nums[j]) * nums[k]. If all triplets produce a negative value, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums where 3 <= nums.length <= 10^5, and 1 <= nums[i] <= 10^6.
- **Example:** `nums = [5, 3, 2, 4, 6]`
- **Constraints:**
	- 3 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all values are negative, return 0.
- **Example:** `For input nums = [5, 3, 2, 4, 6], the output is 24.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the value of (nums[i] - nums[j]) * nums[k] for triplets (i, j, k) where i < j < k.

- Iterate through each element in the array.
- For each element, calculate the value of all possible triplets using it as i, j, or k.
- Track the maximum value found during the iteration.
- Return the maximum value or 0 if no valid triplet exists.
{{< dots >}}
### Problem Assumptions ✅
- The array has at least 3 elements.
{{< dots >}}
## Examples 🧩
- **Input:** `For input nums = [5, 3, 2, 4, 6], the output is 24.`  \
  **Explanation:** The triplet (0, 2, 4) results in the maximum value (5 - 2) * 6 = 24.

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
- Ensure that the solution efficiently handles arrays with up to 100,000 elements.
- Consider cases where no valid triplet results in a non-negative value.
- The algorithm must run efficiently even for the largest inputs.
{{< dots >}}
## Code 💻
```cpp
long long maximumTripletValue(vector<int>& nums) {
    long res = 0, n = nums.size();
    long maxa = 0, maxab = 0;
    for(int a: nums) {
        res = max(res, 1L * maxab * a);
        maxab = max(maxab, (long) maxa - a);
        maxa = max(maxa, (long)a);
    }
    return res;
}
```

This function computes the maximum triplet value from the input array by iterating through it and updating the result based on the current element and maximum values seen so far.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long maximumTripletValue(vector<int>& nums) {
	```
	This line declares the function, which takes a vector of integers 'nums' as input and returns a long integer representing the maximum triplet value.

2. **Variable Initialization**
	```cpp
	    long res = 0, n = nums.size();
	```
	Here, 'res' is initialized to 0, which will store the maximum triplet value, and 'n' is set to the size of the input vector 'nums'.

3. **Variable Initialization**
	```cpp
	    long maxa = 0, maxab = 0;
	```
	'maxa' stores the maximum value seen so far during the iteration, and 'maxab' stores the maximum value of (maxa - current element). Both are initialized to 0.

4. **Loop Setup**
	```cpp
	    for(int a: nums) {
	```
	A for loop is initiated to iterate over each element 'a' in the input vector 'nums'.

5. **Max Calculation**
	```cpp
	        res = max(res, 1L * maxab * a);
	```
	The result 'res' is updated by comparing its current value with the product of 'maxab' and the current element 'a'. The multiplication is done with 1L to ensure that the result is calculated as a long integer.

6. **Update maxab**
	```cpp
	        maxab = max(maxab, (long) maxa - a);
	```
	The 'maxab' variable is updated to store the maximum value between its current value and the difference between 'maxa' and the current element 'a'. The cast to 'long' ensures proper handling of integer overflow.

7. **Update maxa**
	```cpp
	        maxa = max(maxa, (long)a);
	```
	'maxa' is updated to hold the maximum value encountered so far, which is the greater of its current value or the current element 'a'.

8. **Return Result**
	```cpp
	    return res;
	```
	After iterating through all elements, the final result 'res', which holds the maximum triplet value, is returned.

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


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/)

---
{{< youtube QBLw9bVFIDQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
