
+++
authors = ["grid47"]
title = "Leetcode 775: Global and Local Inversions"
date = "2024-08-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 775: Global and Local Inversions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/775.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/775.webp" 
    alt="A sequence where global and local inversions are counted, each inversion glowing softly as it's identified."
    caption="Solution to LeetCode 775: Global and Local Inversions Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array nums of length n, which is a permutation of all integers in the range [0, n - 1]. A global inversion is a pair of indices (i, j) such that 0 <= i < j < n and nums[i] > nums[j]. A local inversion is a pair where 0 <= i < n - 1 and nums[i] > nums[i + 1]. Return true if the number of global inversions is equal to the number of local inversions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array nums, which represents a permutation of integers in the range [0, n - 1].
- **Example:** `Input: nums = [2, 0, 1]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] < n
	- All elements in nums are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the number of global inversions is equal to the number of local inversions.
- **Example:** `Output: true`
- **Constraints:**
	- The number of global inversions must equal the number of local inversions.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the number of global inversions is equal to the number of local inversions.

- Iterate through the array, maintaining the current maximum value encountered.
- Check if any element is out of place beyond its local inversion (i.e., check for global inversions).
- If a global inversion is found that does not qualify as a local inversion, return false.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always be a valid permutation of integers from 0 to n-1.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: nums = [2, 0, 1]`  \
  **Explanation:** There is 1 global inversion (pair (0, 1)) and 1 local inversion (pair (1, 2)). Since the counts are equal, the result is true.

- **Input:** `Example 2: Input: nums = [3, 2, 1, 0]`  \
  **Explanation:** There are 3 global inversions (pairs (0, 1), (0, 2), (0, 3)) but only 2 local inversions (pairs (0, 1), (1, 2)). The counts are not equal, so the result is false.

{{< dots >}}
## Approach 🚀
The approach involves iterating over the array and comparing the elements to detect global inversions that are not local inversions. The maximum value encountered up to each index can be used to determine whether an inversion is a global or local one.

### Initial Thoughts 💭
- Global inversions can be detected by checking pairs (i, j) where i < j and nums[i] > nums[j].
- The maximum value encountered so far helps in identifying whether an inversion is local or global.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least one element, as n >= 1.
- Ensure the solution handles arrays with up to 10^5 elements.
- If the array is sorted, there are no inversions, hence the result will be true.
- The array is a permutation of integers from 0 to n-1.
{{< dots >}}
## Code 💻
```cpp
bool isIdealPermutation(vector<int>& nums) {
    int cmax = 0, n = nums.size();
    for(int i = 0; i < n - 2; i++) {
        cmax = max(cmax, nums[i]);
        if(cmax > nums[i + 2]) return false;
    }
    return true;
}
```

This function checks if the given permutation is 'ideal'. It iterates through the array, updating the maximum element and comparing it to the element two positions ahead, returning false if the condition is violated.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isIdealPermutation(vector<int>& nums) {
	```
	Define the function that checks whether a given permutation of integers is 'ideal'.

2. **Variable Initialization**
	```cpp
	    int cmax = 0, n = nums.size();
	```
	Initialize the 'cmax' variable to store the maximum value encountered so far and 'n' to store the size of the input array.

3. **Loop Start**
	```cpp
	    for(int i = 0; i < n - 2; i++) {
	```
	Start a loop that iterates through the array from index 0 to n-3.

4. **Max Update**
	```cpp
	        cmax = max(cmax, nums[i]);
	```
	Update the 'cmax' variable to hold the maximum value found so far between 'cmax' and the current element 'nums[i]'.

5. **Condition Check**
	```cpp
	        if(cmax > nums[i + 2]) return false;
	```
	Check if the maximum value encountered so far ('cmax') is greater than the element two positions ahead ('nums[i + 2]'). If true, return false, indicating the permutation is not ideal.

6. **Return Statement**
	```cpp
	    return true;
	```
	Return true, indicating the permutation is ideal if the loop completes without returning false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the array.
- **Average Case:** O(n), since we iterate over the array once.
- **Worst Case:** O(n), as we only perform one pass through the array.

The time complexity is linear because we only iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(1), since we only need constant space to track the maximum value.
- **Worst Case:** O(1), as no additional space is required except for the variables used in the logic.

The space complexity is constant because we only use a few variables for tracking.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/global-and-local-inversions/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
