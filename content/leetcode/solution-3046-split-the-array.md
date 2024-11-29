
+++
authors = ["grid47"]
title = "Leetcode 3046: Split the Array"
date = "2024-01-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3046: Split the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ItimQQYIHEw"
youtube_upload_date="2024-02-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ItimQQYIHEw/maxresdefault.webp"
comments = true
+++



---
You are given an integer array 'nums' of even length. Your task is to determine whether it is possible to divide the array into two subarrays, 'nums1' and 'nums2', such that both subarrays have distinct elements and the same length. Each subarray must contain half of the total elements from the original array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers nums.
- **Example:** `nums = [5, 6, 7, 7, 8, 8]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- nums.length % 2 == 0
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it's possible to split the array into two subarrays with distinct elements, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if it's possible to split the given array into two subarrays with distinct elements.

- Count the frequency of each number in the array.
- If any number appears more than twice, return false.
- If all numbers appear at most twice, return true.
{{< dots >}}
### Problem Assumptions ✅
- The array has an even number of elements.
- The array elements are within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [5, 6, 7, 7, 8, 8]`  \
  **Explanation:** In this case, we can split the array into nums1 = [5, 6, 7] and nums2 = [7, 8, 8]. Both subarrays have distinct elements, so the result is true.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to check if it's possible to split the array into two subarrays with distinct elements.

### Initial Thoughts 💭
- We need to check the frequency of each number in the array.
- If a number appears more than twice, it would be impossible to split the array.
{{< dots >}}
### Edge Cases 🌐
- If nums is empty, we can return false.
- If nums has 100 elements, we need to handle it efficiently.
- Arrays where all numbers are the same will return false.
- The array must have an even length.
{{< dots >}}
## Code 💻
```cpp
bool isPossibleToSplit(vector<int>& nums) {
    map<int, int> mp;
    for(int x: nums) {
        mp[x]++;
        if(mp[x] > 2) return false;
    }
    return true;
}
```

This function checks if it's possible to split the given `nums` array such that no element appears more than twice. It uses a map to count the occurrences of each element in the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isPossibleToSplit(vector<int>& nums) {
	```
	Defines the function `isPossibleToSplit` which accepts a vector of integers `nums` and returns a boolean indicating whether the array can be split with the restriction that no number appears more than twice.

2. **Variable Initialization**
	```cpp
	    map<int, int> mp;
	```
	Declares a map `mp` to track the frequency of each element in the `nums` array.

3. **Loop**
	```cpp
	    for(int x: nums) {
	```
	Iterates through each element `x` in the `nums` array.

4. **Map Update**
	```cpp
	        mp[x]++;
	```
	Increments the count of the element `x` in the map `mp`.

5. **Condition Check**
	```cpp
	        if(mp[x] > 2) return false;
	```
	Checks if any element in the array appears more than twice by comparing its count in `mp`. If true, returns `false`.

6. **Return Statement**
	```cpp
	    return true;
	```
	If no element appears more than twice, returns `true` indicating the array can be split as required.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the array, as we are iterating over the array once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for counting the frequency of elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/split-the-array/description/)

---
{{< youtube ItimQQYIHEw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
