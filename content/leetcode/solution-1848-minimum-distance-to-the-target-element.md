
+++
authors = ["grid47"]
title = "Leetcode 1848: Minimum Distance to the Target Element"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1848: Minimum Distance to the Target Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "eAA1gS_2QwY"
youtube_upload_date="2021-05-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/eAA1gS_2QwY/maxresdefault.webp"
comments = true
+++



---
You are given an array nums, along with two integers target and start. Your task is to find an index i such that nums[i] == target, and the absolute difference between i and start is minimized. Return abs(i - start), where abs(x) is the absolute value of x.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums, an integer target, and an integer start.
- **Example:** `[10, 20, 30, 40, 50], target = 40, start = 2`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 10^4
	- 0 <= start < nums.length
	- target is in nums

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum absolute difference abs(i - start) for the index i where nums[i] == target.
- **Example:** `1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the index of target in nums that minimizes the absolute difference with the start index.

- Iterate through the array to find all indices where nums[i] equals target.
- Calculate the absolute difference between each index and the start index.
- Return the minimum of these differences.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains at least one element.
- The target value is guaranteed to be present in the array.
{{< dots >}}
## Examples 🧩
- **Input:** `[10, 20, 30, 40, 50], target = 40, start = 2`  \
  **Explanation:** The element 40 is located at index 3, and the minimum distance to the start index (2) is 1.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the array to find all indices where nums[i] equals target and then calculating the minimum distance between the indices and the start index.

### Initial Thoughts 💭
- Iterating through the array once is sufficient to find all occurrences of target.
- By keeping track of the minimum distance while iterating, we can achieve an optimal solution.
{{< dots >}}
### Edge Cases 🌐
- The array will never be empty, as the input length is guaranteed to be at least 1.
- Ensure that the algorithm handles arrays with the maximum length of 1000 efficiently.
- Consider arrays where the target appears multiple times, or where the target is at the start or end of the array.
- The approach needs to efficiently handle arrays of size up to 1000.
{{< dots >}}
## Code 💻
```cpp
int getMinDistance(vector<int>& nums, int target, int start) {
int res = INT_MAX;
for (int i = 0; i < nums.size() && res > abs(start - i); ++i)
    if (nums[i] == target)
        res = abs(start - i);
return res;
}
```

This function calculates the minimum distance between a target element in the `nums` array and the given starting index. It returns the minimum distance from the start index to the closest occurrence of the target value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int getMinDistance(vector<int>& nums, int target, int start) {
	```
	Defines the function `getMinDistance`, which takes a vector `nums`, a target value, and a start index, returning the minimum distance to the target.

2. **Variable Initialization**
	```cpp
	int res = INT_MAX;
	```
	Initializes a variable `res` to store the minimum distance, starting with the maximum possible value, `INT_MAX`.

3. **Loop Initialization**
	```cpp
	for (int i = 0; i < nums.size() && res > abs(start - i); ++i)
	```
	Begins a loop that iterates through the array `nums`. It also ensures that the loop continues until the distance becomes smaller than `res`.

4. **Condition Check**
	```cpp
	    if (nums[i] == target)
	```
	Checks if the current element in the array `nums[i]` is equal to the `target`.

5. **Distance Update**
	```cpp
	        res = abs(start - i);
	```
	Updates the value of `res` with the absolute difference between the current index `i` and the start index, which represents the distance.

6. **Return Statement**
	```cpp
	return res;
	```
	Returns the minimum distance found during the iteration.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, O(n), where n is the length of the array, as we need to check each element in the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), as we only need a few variables to track the minimum distance.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-distance-to-the-target-element/description/)

---
{{< youtube eAA1gS_2QwY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
