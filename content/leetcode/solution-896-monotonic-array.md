
+++
authors = ["grid47"]
title = "Leetcode 896: Monotonic Array"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 896: Monotonic Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "stkYclqstaA"
youtube_upload_date="2023-09-30"
youtube_thumbnail="https://i.ytimg.com/vi/stkYclqstaA/maxresdefault.jpg"
comments = true
+++



---
An array is said to be monotonic if it is either monotonically increasing or monotonically decreasing. A monotonically increasing array is one where each element is greater than or equal to the previous one, and a monotonically decreasing array is one where each element is less than or equal to the previous one. Given an integer array, return true if the array is monotonic, and false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers, nums, and you need to determine if the array is monotonic.
- **Example:** `Input: nums = [3, 3, 4, 5]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^5 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean value, true if the array is monotonic, and false otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- The output is either true or false based on whether the array is monotonic.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check whether the given array is either monotonically increasing or decreasing.

- 1. Initialize two boolean variables, inc and dec, to true. These will track whether the array is monotonically increasing or decreasing.
- 2. Traverse the array and check if each pair of adjacent elements follows the increasing or decreasing pattern.
- 3. If any element fails to maintain the increasing pattern, set inc to false; if it fails to maintain the decreasing pattern, set dec to false.
- 4. After traversing the array, if either inc or dec remains true, return true. Otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The input array will contain at least one element.
- The array may contain negative, zero, or positive values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, 3, 4, 5]`  \
  **Explanation:** This array is monotonically increasing because each element is greater than or equal to the one before it.

- **Input:** `Input: nums = [5, 4, 4, 3]`  \
  **Explanation:** This array is monotonically decreasing because each element is less than or equal to the one before it.

- **Input:** `Input: nums = [1, 3, 2]`  \
  **Explanation:** This array is neither increasing nor decreasing, so the output is false.

{{< dots >}}
## Approach 🚀
To determine if the array is monotonic, we check if it is either monotonically increasing or decreasing by comparing adjacent elements. This can be done efficiently in a single pass through the array.

### Initial Thoughts 💭
- We need to ensure that we only traverse the array once to keep the solution efficient.
- The problem can be solved by maintaining two boolean variables to track if the array is increasing or decreasing.
- Using a single pass and two boolean flags allows us to solve this problem in linear time.
{{< dots >}}
### Edge Cases 🌐
- If the array contains only one element, it is trivially monotonic.
- For large arrays, the solution should still work efficiently within the time constraints.
- Arrays with all identical elements are considered monotonic.
- The solution must handle large inputs up to the constraint limits efficiently.
{{< dots >}}
## Code 💻
```cpp
bool isMonotonic(vector<int> A) {
    bool inc = true, dec = true;
    for (int i = 1; i < A.size(); ++i)
        inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
    return inc || dec;
}
```

This function checks if an array is monotonic, meaning it is either entirely non-increasing or non-decreasing.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isMonotonic(vector<int> A) {
	```
	This line declares a function `isMonotonic` that takes a vector of integers `A` as input and returns a boolean value.

2. **Variable Initialization**
	```cpp
	    bool inc = true, dec = true;
	```
	Two boolean variables `inc` and `dec` are initialized to `true`. These will be used to track whether the array is non-decreasing (`inc`) or non-increasing (`dec`).

3. **Loop Initialization**
	```cpp
	    for (int i = 1; i < A.size(); ++i)
	```
	A `for` loop is started, iterating through the vector `A` starting from index 1. This loop checks the relationship between consecutive elements.

4. **Condition Update**
	```cpp
	        inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
	```
	The boolean variables `inc` and `dec` are updated. The `&=` operator ensures that `inc` remains true if each pair of consecutive elements is non-decreasing, and `dec` remains true if the elements are non-increasing.

5. **Return Statement**
	```cpp
	    return inc || dec;
	```
	The function returns `true` if either `inc` or `dec` is true, meaning the array is monotonic (non-decreasing or non-increasing).

6. **Function End**
	```cpp
	}
	```
	The function ends here.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we traverse the array once, where n is the number of elements in the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a constant amount of extra space to store the two boolean flags.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/monotonic-array/description/)

---
{{< youtube stkYclqstaA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
