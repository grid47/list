
+++
authors = ["grid47"]
title = "Leetcode 1438: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit"
date = "2024-06-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1438: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Queue","Sliding Window","Heap (Priority Queue)","Ordered Set","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "V-ecDfY5xEw"
youtube_upload_date="2024-06-23"
youtube_thumbnail="https://i.ytimg.com/vi/V-ecDfY5xEw/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers `nums` and a positive integer `limit`, determine the length of the longest subarray where the absolute difference between the minimum and maximum elements is less than or equal to `limit`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers `nums` and an integer `limit`.
- **Example:** `nums = [6,3,5,8], limit = 3`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9
	- 0 <= limit <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the size of the longest subarray satisfying the given condition.
- **Example:** `2`
- **Constraints:**
	- The output is a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the size of the longest subarray where the absolute difference between the minimum and maximum elements is less than or equal to the given `limit`.

- Step 1: Use a multiset to track the current subarray's elements.
- Step 2: For every element in `nums`, add it to the multiset and check if the max difference exceeds the `limit`.
- Step 3: If the condition is violated, remove elements from the start of the current subarray until it satisfies the condition again.
- Step 4: Keep track of the maximum subarray size.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` contains at least one element.
- The input values are within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [6,3,5,8], limit = 3`  \
  **Explanation:** The longest subarray is [6,3] or [5,8], each with a size of 2.

- **Input:** `nums = [9,2,4,6], limit = 4`  \
  **Explanation:** The subarray [2,4,6] has a max difference of 4 and is the longest subarray with size 3.

{{< dots >}}
## Approach 🚀
Use a sliding window approach with a multiset to efficiently maintain the current subarray's minimum and maximum values.

### Initial Thoughts 💭
- The problem requires maintaining a subarray that satisfies a condition on the maximum and minimum values.
- A sliding window with dynamic size can help efficiently process the array.
- We can use a multiset or two deques to maintain the max and min values of the current window.
{{< dots >}}
### Edge Cases 🌐
- No empty input is allowed as `nums` will always have at least one element.
- The solution must handle arrays with up to 10^5 elements efficiently.
- Handle cases with `limit = 0` where only subarrays with identical elements are valid.
- Ensure the solution remains efficient even for extreme values of `limit` or `nums[i]`.
{{< dots >}}
## Code 💻
```cpp
int longestSubarray(vector<int>& nums, int limit) {
    multiset<int> ms;
    int res = 0, j = 0;
    for(int i = 0; i < nums.size(); i++) {
        ms.insert(nums[i]);
        while(!ms.empty() && *ms.rbegin() - *ms.begin() > limit) {
            ms.erase(ms.find(nums[j++]));
        }
        res = max(res, i - j + 1);
    }
    return res;
}
```

The `longestSubarray` function calculates the length of the longest subarray with the absolute difference between the maximum and minimum elements being less than or equal to a given limit. It uses a sliding window technique with a multiset to maintain the subarray in sorted order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestSubarray(vector<int>& nums, int limit) {
	```
	Defines the function `longestSubarray`, which takes a vector of integers `nums` and an integer `limit` as input. It returns the length of the longest subarray where the difference between the maximum and minimum elements is within the limit.

2. **Variable Initialization**
	```cpp
	    multiset<int> ms;
	```
	Initializes a `multiset` named `ms` to store elements of the subarray in sorted order. This allows efficient access to the minimum and maximum elements.

3. **Variable Initialization**
	```cpp
	    int res = 0, j = 0;
	```
	Initializes two variables: `res` to store the length of the longest valid subarray found and `j` to represent the starting index of the sliding window.

4. **Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Starts a loop where `i` iterates through each element of the `nums` vector. This loop represents the end of the sliding window.

5. **Insert Operation**
	```cpp
	        ms.insert(nums[i]);
	```
	Inserts the current element `nums[i]` into the `multiset` to maintain the sorted order of the subarray.

6. **Condition Check**
	```cpp
	        while(!ms.empty() && *ms.rbegin() - *ms.begin() > limit) {
	```
	Checks whether the difference between the maximum (`*ms.rbegin()`) and minimum (`*ms.begin()`) elements of the `multiset` exceeds the `limit`. If so, the subarray is invalid, and the sliding window is adjusted.

7. **Erase Operation**
	```cpp
	            ms.erase(ms.find(nums[j++]));
	```
	Erases the element at index `j` from the `multiset` and increments `j` to shrink the sliding window from the left side.

8. **Update Result**
	```cpp
	        res = max(res, i - j + 1);
	```
	Updates the result `res` with the length of the current valid subarray, which is `i - j + 1`, and stores the maximum length found.

9. **Return Statement**
	```cpp
	    return res;
	```
	Returns the value of `res`, which represents the length of the longest valid subarray found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of `nums`.
- **Average Case:** O(n) for maintaining the sliding window and set operations.
- **Worst Case:** O(n) for iterating through the array.

The time complexity is linear as each element is added and removed from the sliding window at most once.

### Space Complexity 💾
- **Best Case:** O(1) if subarrays are very small.
- **Worst Case:** O(n) for the multiset or deque in extreme cases.

The space complexity depends on the size of the sliding window and is O(n) in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/)

---
{{< youtube V-ecDfY5xEw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
