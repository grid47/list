
+++
authors = ["grid47"]
title = "Leetcode 2104: Sum of Subarray Ranges"
date = "2024-04-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2104: Sum of Subarray Ranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "sMFAjHe3kkw"
youtube_upload_date="2021-12-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/sMFAjHe3kkw/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `nums`. A subarray of `nums` is a contiguous sequence of elements. The *range* of a subarray is defined as the difference between the maximum and minimum elements within that subarray.

Your task is to calculate the sum of the ranges for all possible subarrays in the given array `nums`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 1D array of integers `nums` of length n, where each element nums[i] represents an integer in the array.
- **Example:** `nums = [1, 2, 3]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of all subarray ranges of `nums`.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the sum of all subarray ranges efficiently.

- Iterate over each subarray of nums.
- For each subarray, find the minimum and maximum values.
- Calculate the range of the subarray as the difference between the maximum and minimum values.
- Sum up the ranges for all subarrays.
{{< dots >}}
### Problem Assumptions ✅
- You are given a valid array nums.
- The input is non-empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 3]`  \
  **Explanation:** The subarrays are [1], [2], [3], [1, 2], [2, 3], and [1, 2, 3]. The ranges of these subarrays are 0, 0, 0, 1, 1, and 2, respectively. The sum of these ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we will calculate the range for each subarray and sum them up. An optimal approach may involve iterating over each subarray in a nested loop and calculating its range.

### Initial Thoughts 💭
- The brute-force solution is to find the range for every subarray by iterating through the entire array for each subarray, which is O(n^2).
- We should try to optimize this solution, possibly using a sliding window or other techniques to calculate the range more efficiently.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one element.
- The approach should be efficient enough to handle arrays up to the maximum length of 1000.
- Arrays with all identical elements will have zero range for all subarrays.
- The algorithm should work within the time limit for n up to 1000.
{{< dots >}}
## Code 💻
```cpp
long long subArrayRanges(vector<int>& nums) {
    
    long long res = 0, n = nums.size();
    
    for(int i = 0; i < n - 1; i++) {
        
        int mini = nums[i], maxi = nums[i];
        
        for(int j = i + 1; j < n; j++) {
            
            if(nums[j] < mini) mini = nums[j];
            if(nums[j] > maxi) maxi = nums[j];
            res += maxi - mini;
        }
    }
    
    return res;
}
```

This is a function that computes the sum of the differences between the maximum and minimum elements in all subarrays of a given array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long subArrayRanges(vector<int>& nums) {
	```
	Declares the function that computes the sum of the ranges (max - min) of all subarrays.

2. **Variable Initialization**
	```cpp
	    long long res = 0, n = nums.size();
	```
	Initializes `res` to store the result and `n` to store the size of the array.

3. **Outer Loop**
	```cpp
	    for(int i = 0; i < n - 1; i++) {
	```
	Starts a loop that iterates over each element of the array, except the last one.

4. **Variable Initialization**
	```cpp
	        int mini = nums[i], maxi = nums[i];
	```
	Sets the initial values of mini and maxi to the current element in the outer loop.

5. **Inner Loop**
	```cpp
	        for(int j = i + 1; j < n; j++) {
	```
	Starts the inner loop that iterates over all elements after the current outer loop element.

6. **Condition for Mini Update**
	```cpp
	            if(nums[j] < mini) mini = nums[j];
	```
	If the current element is smaller than mini, it updates mini.

7. **Condition for Maxi Update**
	```cpp
	            if(nums[j] > maxi) maxi = nums[j];
	```
	If the current element is larger than maxi, it updates maxi.

8. **Result Calculation**
	```cpp
	            res += maxi - mini;
	```
	Calculates the range (maxi - mini) for the current subarray and adds it to the result.

9. **Return Statement**
	```cpp
	    return res;
	```
	Returns the accumulated result from the sum of ranges.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The worst case time complexity occurs when the array length is at its maximum.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we are only storing a few variables for calculation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-subarray-ranges/description/)

---
{{< youtube sMFAjHe3kkw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
