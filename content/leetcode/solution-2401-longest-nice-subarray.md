
+++
authors = ["grid47"]
title = "Leetcode 2401: Longest Nice Subarray"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2401: Longest Nice Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DJYpUQy3iME"
youtube_upload_date="2022-09-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/DJYpUQy3iME/maxresdefault.webp"
comments = true
+++



---
You are given an array `nums` consisting of positive integers. A subarray of `nums` is considered nice if the bitwise AND of every pair of elements, that are at different positions in the subarray, is equal to 0. Your task is to return the length of the longest nice subarray. A subarray is a contiguous part of an array, and subarrays of length 1 are always considered nice.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of positive integers `nums`.
- **Example:** `nums = [2, 4, 8, 16]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest nice subarray.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest subarray where the bitwise AND between every pair of different elements is 0.

- 1. Initialize variables for storing the result and the current bitwise AND of the subarray.
- 2. Iterate through the array while maintaining a sliding window to find the longest nice subarray.
- 3. For each element, check if the bitwise AND with the current subarray is 0. If it’s not 0, adjust the window to satisfy the condition.
- 4. Update the result with the length of the longest nice subarray found during the iteration.
{{< dots >}}
### Problem Assumptions ✅
- The input array is valid and contains only positive integers.
- The array may contain large numbers, so bitwise operations must be optimized.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1,3,8,48,10]`  \
  **Explanation:** The longest nice subarray is [3, 8, 48]. This subarray satisfies the conditions because the bitwise AND of every pair of different elements in the subarray is 0.

- **Input:** `nums = [1, 2, 3, 4]`  \
  **Explanation:** The longest nice subarray is [1], as any larger subarray will violate the condition that the bitwise AND of every pair of different elements is 0.

{{< dots >}}
## Approach 🚀
To solve this problem, we use a sliding window approach where we maintain a window of elements that form a nice subarray. We adjust the window size when the AND condition is violated.

### Initial Thoughts 💭
- The bitwise AND operation can be expensive, but the problem can be tackled efficiently using the sliding window technique.
- We need to find the longest subarray where the bitwise AND between every pair of distinct elements is 0.
{{< dots >}}
### Edge Cases 🌐
- This problem does not have an empty input case as the length of the array is guaranteed to be at least 1.
- For large arrays, the sliding window approach ensures that the solution runs efficiently with a time complexity of O(n).
- If the array contains only one element, the result is always 1, as any single element forms a valid nice subarray.
- The sliding window approach allows for efficient handling of large inputs within the given constraints.
{{< dots >}}
## Code 💻
```cpp
int longestNiceSubarray(vector<int>& nums) {
    int res = 1, AND = 0, n = nums.size(), j = 0;
    for(int i = 0; i < n; i++) {
        while(((AND & nums[i]) > 0)) {
            AND ^= nums[j++];
        }
        AND |= nums[i];
        res = max(res, i - j + 1);
    }
    return res;
}
```

This function calculates the length of the longest nice subarray, where a nice subarray is defined as one in which the bitwise AND of all its elements is greater than 0.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int longestNiceSubarray(vector<int>& nums) {
	```
	This is the function signature where we define the function `longestNiceSubarray` which takes a reference to a vector of integers `nums`.

2. **Variable Initialization**
	```cpp
	    int res = 1, AND = 0, n = nums.size(), j = 0;
	```
	We initialize variables: `res` to store the result (set to 1 initially), `AND` to perform bitwise operations (initialized to 0), `n` for the size of the array, and `j` as a pointer for the sliding window.

3. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A for-loop to iterate over the elements of the array `nums` from the first to the last element.

4. **While Loop for Sliding Window**
	```cpp
	        while(((AND & nums[i]) > 0)) {
	```
	This while-loop is used to shrink the sliding window by incrementing `j` while the bitwise AND of the current `AND` and `nums[i]` is greater than 0.

5. **Update AND**
	```cpp
	            AND ^= nums[j++];
	```
	Perform a bitwise XOR operation on `AND` with `nums[j]`, then increment `j` to shrink the window.

6. **Update AND**
	```cpp
	        AND |= nums[i];
	```
	Update the `AND` variable by performing a bitwise OR operation with `nums[i]`.

7. **Update Result**
	```cpp
	        res = max(res, i - j + 1);
	```
	Update the result `res` to the maximum of its current value and the current length of the sliding window (`i - j + 1`).

8. **Return Statement**
	```cpp
	    return res;
	```
	Return the final result `res` which is the length of the longest nice subarray.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the array, since the sliding window approach only requires a single pass through the array.
- **Average Case:** O(n), the sliding window approach maintains efficiency by ensuring each element is processed at most twice.
- **Worst Case:** O(n), as in the worst case, the window may shrink for each element in the array.

The solution runs in linear time, which is optimal for the problem's constraints.

### Space Complexity 💾
- **Best Case:** O(1), space usage remains constant even for the smallest inputs.
- **Worst Case:** O(1), as the solution only requires a constant amount of extra space beyond the input array.

The space complexity is constant, as we only need a few variables to track the window and the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-nice-subarray/description/)

---
{{< youtube DJYpUQy3iME >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
