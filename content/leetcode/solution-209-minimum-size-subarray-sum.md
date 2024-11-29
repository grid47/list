
+++
authors = ["grid47"]
title = "Leetcode 209: Minimum Size Subarray Sum"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 209: Minimum Size Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/209.webp"
youtube = "RG17VCQOFpg"
youtube_upload_date="2024-06-21"
youtube_thumbnail="https://i.ytimg.com/vi/RG17VCQOFpg/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/209.webp" 
    alt="A glowing, shrinking subarray highlighting the smallest sum as it contracts into the minimal size."
    caption="Solution to LeetCode 209: Minimum Size Subarray Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of positive integers and a target value, find the minimal length of a contiguous subarray whose sum is greater than or equal to the target. If no such subarray exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of integers, `nums`, and an integer `target`.
- **Example:** `[target = 8, nums = [1, 4, 4, 2, 1, 5]]`
- **Constraints:**
	- The value of target is between 1 and 10^9.
	- The length of nums is between 1 and 100,000.
	- Each element of nums is between 1 and 10^4.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the minimal length of a subarray whose sum is greater than or equal to the target, or 0 if no such subarray exists.
- **Example:** `For target = 8 and nums = [1, 4, 4, 2, 1, 5], the output is 2.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently find the smallest subarray whose sum is greater than or equal to the target.

- Start iterating over the array while maintaining a running sum of the elements.
- If the sum becomes greater than or equal to the target, update the minimal subarray length and reduce the sum by removing elements from the start of the subarray.
- Repeat until you have considered all subarrays.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains only positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this example, the subarray `[4, 4]` is the smallest subarray whose sum is at least 8, and its length is 2.

- **Input:** `Example 2`  \
  **Explanation:** The subarray `[3, 4]` sums to 7, which is greater than or equal to the target 6, and it has the minimal length of 2.

- **Input:** `Example 3`  \
  **Explanation:** In this case, no subarray's sum can reach 12, so the answer is 0.

{{< dots >}}
## Approach 🚀
The approach uses a sliding window technique to find the minimal length of a subarray with a sum greater than or equal to the target.

### Initial Thoughts 💭
- Sliding window techniques are ideal for problems involving subarrays with conditions on their sum.
- By maintaining a running sum and sliding the window over the array, we can find the minimal subarray efficiently.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty or the target is very large, the result will be 0.
- For large arrays, ensure the solution handles up to 100,000 elements efficiently.
- If the target is 1 and the array contains only 1s, the smallest subarray will always have length 1.
- Ensure that the solution works within the time limits for large arrays (O(n) time complexity).
{{< dots >}}
## Code 💻
```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0, idx = 0, g = INT_MAX, bdx = 0;
    while(idx < nums.size()) {
        sum += nums[idx];

        while(sum >= target) {
            g = min(g, idx - bdx + 1);
            sum -= nums[bdx];
            bdx++;
        }
        idx++;
    }
    return g == INT_MAX? 0: g;
}

```

This code implements the sliding window technique to find the minimum length of a subarray whose sum is greater than or equal to the given target. It uses two pointers to dynamically adjust the window size.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minSubArrayLen(int target, vector<int>& nums) {
	```
	Define the function `minSubArrayLen` that takes a target sum and an array of integers, `nums`, and returns the minimum length of a subarray whose sum is at least equal to the target.

2. **Variable Initialization**
	```cpp
	    int sum = 0, idx = 0, g = INT_MAX, bdx = 0;
	```
	Initialize variables: `sum` to track the current sum of the window, `idx` as the right pointer of the window, `g` to store the minimum length of the subarray, and `bdx` as the left pointer of the window.

3. **Loop Iteration**
	```cpp
	    while(idx < nums.size()) {
	```
	Start a while loop that iterates through the array with the right pointer `idx`.

4. **Sum Update**
	```cpp
	        sum += nums[idx];
	```
	Add the current element of `nums` at index `idx` to the sum of the current subarray.

5. **Inner While Loop**
	```cpp
	        while(sum >= target) {
	```
	Start an inner while loop that checks if the sum of the current subarray is greater than or equal to the target. If true, try to shrink the window.

6. **Window Update**
	```cpp
	            g = min(g, idx - bdx + 1);
	```
	Update the minimum subarray length `g` with the current window length, which is `idx - bdx + 1`.

7. **Sum Update**
	```cpp
	            sum -= nums[bdx];
	```
	Shrink the window by subtracting the value at the left pointer `bdx` from the current sum.

8. **Left Pointer Move**
	```cpp
	            bdx++;
	```
	Move the left pointer `bdx` to the right to shrink the window.

9. **Right Pointer Move**
	```cpp
	        idx++;
	```
	Move the right pointer `idx` to the next element, expanding the window.

10. **Return Statement**
	```cpp
	    return g == INT_MAX? 0: g;
	```
	Return the minimum length of the subarray. If no valid subarray is found, return 0 (indicating no subarray meets the target sum).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), when the sum of elements exceeds the target early in the iteration.
- **Average Case:** O(n), as we process each element exactly once.
- **Worst Case:** O(n), in the worst case where the window moves across the entire array.

The sliding window technique ensures that we only iterate over the array once, making the time complexity linear.

### Space Complexity 💾
- **Best Case:** O(1), as no additional space is required.
- **Worst Case:** O(1), as the space complexity is constant, only requiring variables for sum and indexes.

The space complexity is constant because we are only using a few variables to keep track of the running sum and indices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-size-subarray-sum/description/)

---
{{< youtube RG17VCQOFpg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
