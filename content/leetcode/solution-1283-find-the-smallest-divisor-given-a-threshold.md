
+++
authors = ["grid47"]
title = "Leetcode 1283: Find the Smallest Divisor Given a Threshold"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1283: Find the Smallest Divisor Given a Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KGlnb3yT8iY"
youtube_upload_date="2020-11-06"
youtube_thumbnail="https://i.ytimg.com/vi/KGlnb3yT8iY/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers and a threshold, find the smallest divisor such that the sum of the division results (rounded up) is less than or equal to the threshold.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `nums` of integers and an integer `threshold`.
- **Example:** `Input: nums = [2,4,8,16], threshold = 8`
- **Constraints:**
	- 1 <= nums.length <= 5 * 10^4
	- 1 <= nums[i] <= 10^6
	- nums.length <= threshold <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest integer divisor such that the sum of the division results (rounded up) is less than or equal to the threshold.
- **Example:** `Output: 4`
- **Constraints:**
	- The divisor must be a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the smallest divisor such that the sum of the rounded-up division results is less than or equal to the threshold.

- Initialize a binary search range from 1 to max(nums).
- For each divisor in the range, calculate the sum of rounded-up division results of each element in `nums`.
- Check if the sum is less than or equal to the threshold. If it is, narrow the search range to smaller divisors. If it is greater, narrow the range to larger divisors.
{{< dots >}}
### Problem Assumptions ✅
- There will always be a valid solution for the given input.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [2,4,8,16], threshold = 8`  \
  **Explanation:** In this example, we need to select a divisor such that the sum of the results of dividing each number in `nums` by the divisor is less than or equal to 8. The smallest divisor that satisfies this condition is 4.

{{< dots >}}
## Approach 🚀
We can use binary search to find the smallest divisor. The binary search will help efficiently narrow down the possible divisors.

### Initial Thoughts 💭
- We need to minimize the divisor while ensuring the sum of the division results remains below the threshold.
- Binary search is a suitable approach to minimize the divisor because the sum decreases as the divisor increases.
{{< dots >}}
### Edge Cases 🌐
- If `nums` is empty, return 1 as the divisor, but this case is not expected to occur based on the problem constraints.
- Ensure that the binary search approach works efficiently even for the largest inputs (i.e., `nums.length` up to 50,000).
- If all elements in `nums` are equal, the divisor will likely be close to the value of each element for an optimal sum.
- The approach should work within the problem's time and space limits.
{{< dots >}}
## Code 💻
```cpp
int smallestDivisor(vector<int>& nums, int threshold) {
    int left = 1, right = 1e6, m , sum;
    while(left < right) {
        m = (left + right) / 2;
        sum = 0;
        for(int i: nums) sum += (i + m - 1)/m;
        if(sum > threshold) 
        left = m + 1;
        else right = m;
    }
    return left;
}
```

This function determines the smallest divisor such that the sum of all quotients does not exceed the given threshold, utilizing binary search for optimization.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int smallestDivisor(vector<int>& nums, int threshold) {
	```
	Defines the function to find the smallest divisor meeting the threshold constraint.

2. **Variable Initialization**
	```cpp
	    int left = 1, right = 1e6, m , sum;
	```
	Initializes the binary search bounds and other variables.

3. **Binary Search Loop**
	```cpp
	    while(left < right) {
	```
	Starts the binary search loop to find the smallest valid divisor.

4. **Midpoint Calculation**
	```cpp
	        m = (left + right) / 2;
	```
	Calculates the middle value between the binary search bounds.

5. **Reset Sum**
	```cpp
	        sum = 0;
	```
	Resets the sum for the current divisor.

6. **Sum Calculation**
	```cpp
	        for(int i: nums) sum += (i + m - 1)/m;
	```
	Calculates the sum of quotients for the current divisor.

7. **Condition Check**
	```cpp
	        if(sum > threshold) 
	```
	Checks if the sum exceeds the threshold.

8. **Update Left Bound**
	```cpp
	        left = m + 1;
	```
	Increases the lower bound of the binary search if the condition is met.

9. **Update Right Bound**
	```cpp
	        else right = m;
	```
	Decreases the upper bound of the binary search otherwise.

10. **Return Statement**
	```cpp
	    return left;
	```
	Returns the smallest divisor that satisfies the threshold condition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log(max(nums)))
- **Average Case:** O(n log(max(nums)))
- **Worst Case:** O(n log(max(nums)))

The time complexity is O(n log(max(nums))) because we perform binary search (log(max(nums))) and for each iteration, we sum the results of dividing each element in `nums` (O(n)).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage needed for the division results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/)

---
{{< youtube KGlnb3yT8iY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
