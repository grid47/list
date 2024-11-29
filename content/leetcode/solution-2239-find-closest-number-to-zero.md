
+++
authors = ["grid47"]
title = "Leetcode 2239: Find Closest Number to Zero"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2239: Find Closest Number to Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "dLlKA5DQKYs"
youtube_upload_date="2024-07-03"
youtube_thumbnail="https://i.ytimg.com/vi/dLlKA5DQKYs/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers, find the number closest to 0. If there are multiple numbers equally close, return the largest number among them.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer array nums of size n where each element can be negative, positive, or zero.
- **Example:** `Input: nums = [-7, 2, 3, -3, 5]`
- **Constraints:**
	- 1 <= n <= 1000
	- -105 <= nums[i] <= 105

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the integer from the array that is closest to 0. If multiple numbers are equally close, return the largest value.
- **Example:** `Output: -3`
- **Constraints:**
	- The output must be a single integer from the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the number closest to 0 based on its absolute value. If two numbers have the same absolute value, select the larger one.

- 1. Iterate through all elements in the array.
- 2. Compare the absolute values of each number to determine the closest to 0.
- 3. If two numbers have the same absolute value, select the one with the larger value.
- 4. Return the resulting number.
{{< dots >}}
### Problem Assumptions ✅
- The input array will never be empty.
- All values in the array are integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [-7, 2, 3, -3, 5]`  \
  **Explanation:** The absolute values are [7, 2, 3, 3, 5]. Both 3 and -3 are equally close to 0, but 3 is larger. So, the output is 3.

- **Input:** `Input: nums = [4, -4, 1]`  \
  **Explanation:** The absolute values are [4, 4, 1]. Both 4 and -4 are equally close to 0, but 4 is larger. So, the output is 4.

{{< dots >}}
## Approach 🚀
Use a simple comparison of absolute values with a condition to handle ties for equally close numbers.

### Initial Thoughts 💭
- The absolute value comparison is key to determining closeness to 0.
- Handling ties by choosing the larger number ensures uniqueness in the output.
- Iterating through the array while maintaining a variable for the current closest value is efficient for solving the problem.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as input size is guaranteed to be at least 1.
- An array with 1000 elements containing a mix of large positive and negative numbers, e.g., nums = [-105, 105, -50, 50].
- Array contains zeros, e.g., nums = [0, -1, 1].
- Array contains duplicate values, e.g., nums = [-5, 5, -5].
- All integers in the array should be within the range -105 to 105.
{{< dots >}}
## Code 💻
```cpp
  int findClosestNumber(vector<int>& nums) {
return *min_element(begin(nums), end(nums), [](int a, int b) {
    return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
});
  }
```

This function finds the integer in the list that is closest to zero. If there are multiple closest numbers, the larger one is chosen.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	  int findClosestNumber(vector<int>& nums) {
	```
	This is the definition of the 'findClosestNumber' function that takes a vector of integers and returns an integer, which is the closest to zero.

2. **Finding Minimum Element**
	```cpp
	return *min_element(begin(nums), end(nums), [](int a, int b) {
	```
	This line uses the 'min_element' algorithm to find the closest number to zero in the array, using a lambda function to compare absolute values.

3. **Comparison Logic**
	```cpp
	    return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
	```
	The lambda function compares two integers by their absolute value. If the absolute values are equal, it returns the larger number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear since the array is traversed once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

No additional space is used beyond a few variables for tracking the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-closest-number-to-zero/description/)

---
{{< youtube dLlKA5DQKYs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
