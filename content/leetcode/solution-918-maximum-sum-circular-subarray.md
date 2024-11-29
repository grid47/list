
+++
authors = ["grid47"]
title = "Leetcode 918: Maximum Sum Circular Subarray"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 918: Maximum Sum Circular Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Dynamic Programming","Queue","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aLMZIfhhdMg"
youtube_upload_date="2020-05-15"
youtube_thumbnail="https://i.ytimg.com/vi/aLMZIfhhdMg/maxresdefault.jpg"
comments = true
+++



---
You are given a circular integer array `nums` of length `n`. A circular array means that the end of the array connects back to the beginning. Your task is to find the maximum possible sum of a non-empty subarray of `nums`, which can wrap around the array. Formally, you need to find the maximum sum of a subarray where the subarray can either be within the linear array or it can wrap around from the end to the beginning.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums` representing the circular array.
- **Example:** `Input: nums = [2, -1, 3, -2]`
- **Constraints:**
	- 1 <= n <= 3 * 10^4
	- -3 * 10^4 <= nums[i] <= 3 * 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible sum of a non-empty subarray of `nums`. The subarray can wrap around from the end of the array to the beginning.
- **Example:** `Output: 5`
- **Constraints:**
	- The input array will have at least one element.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum sum of a subarray that can be either a linear subarray or one that wraps around the end and the start of the array.

- First, compute the maximum sum subarray for the normal linear case using Kadane's algorithm.
- Then, compute the minimum sum subarray for the array, and subtract it from the total sum of the array to account for the case where the subarray wraps around.
- The result is the maximum of the linear subarray sum and the wrapped subarray sum (only if the array contains at least one non-negative element).
{{< dots >}}
### Problem Assumptions ✅
- We assume that the input array contains valid integers and is not empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [2, -1, 3, -2]`  \
  **Explanation:** In this example, the maximum sum subarray that can be found is [3], which has a sum of 3. The subarray [2, -1, 3] is also valid, but its sum is smaller (4). The array does not contain any subarrays that wrap around, so the final result is 3.

- **Input:** `Input: nums = [5, -3, 5]`  \
  **Explanation:** In this example, the best subarray is [5, 5], which wraps around and sums to 10. The maximum sum subarray without wrapping would be [5], summing to 5. Therefore, the result is 10.

{{< dots >}}
## Approach 🚀
The problem can be solved by finding two possible cases for the maximum sum: one where the subarray is within the array, and one where it wraps around the end and the beginning of the array. To handle both cases, we use Kadane’s algorithm for the linear case and compute the total sum minus the minimum subarray sum for the circular case.

### Initial Thoughts 💭
- We need to compute the maximum subarray sum for both linear and circular subarrays.
- Kadane's algorithm is a good fit for finding the maximum sum subarray in a linear array. To handle the circular case, we can compute the total sum of the array and subtract the minimum subarray sum.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the array will contain at least one element, so we do not need to handle empty inputs.
- The solution should be efficient enough to handle large arrays with up to 30,000 elements.
- If the array consists entirely of negative numbers, the best solution is just the single largest negative number.
- The solution should work within the given constraints for both time and space.
{{< dots >}}
## Code 💻
```cpp
int maxSubarraySumCircular(vector<int>& nums) {
    int lmax = nums[0], lmin = nums[0];
    int gmax = nums[0], gmin = nums[0];
    int sum = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        sum += nums[i];
        lmax = max(nums[i], lmax + nums[i]);
        gmax = max(lmax, gmax);
        lmin = min(nums[i], lmin + nums[i]);
        gmin = min(lmin, gmin);
    }
    return gmax > 0? max(gmax, sum - gmin): gmax;
}
```

The function 'maxSubarraySumCircular' calculates the maximum sum of a subarray in a circular array. It considers both the case where the subarray is contained within the array and the case where it wraps around to the beginning.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxSubarraySumCircular(vector<int>& nums) {
	```
	Define the function 'maxSubarraySumCircular' which takes a vector of integers 'nums' and returns an integer representing the maximum sum of a subarray in a circular array.

2. **Variable Initialization**
	```cpp
	    int lmax = nums[0], lmin = nums[0];
	```
	Initialize 'lmax' and 'lmin' to the first element of the array, representing the current maximum and minimum subarray sums respectively.

3. **Variable Initialization**
	```cpp
	    int gmax = nums[0], gmin = nums[0];
	```
	Initialize 'gmax' and 'gmin' to the first element of the array, representing the global maximum and minimum subarray sums respectively.

4. **Variable Initialization**
	```cpp
	    int sum = nums[0];
	```
	Initialize 'sum' to the first element of the array, which will store the total sum of all elements in the array.

5. **Looping**
	```cpp
	    for(int i = 1; i < nums.size(); i++) {
	```
	Start a loop from the second element to the end of the array to compute the maximum and minimum subarray sums dynamically.

6. **Accumulate Sum**
	```cpp
	        sum += nums[i];
	```
	Add the current element 'nums[i]' to the 'sum' to keep track of the total sum of the array.

7. **Max Subarray Calculation**
	```cpp
	        lmax = max(nums[i], lmax + nums[i]);
	```
	Update 'lmax' to be the maximum of the current element 'nums[i]' or the sum of the previous maximum subarray and the current element.

8. **Max Subarray Update**
	```cpp
	        gmax = max(lmax, gmax);
	```
	Update 'gmax' to the maximum value between 'lmax' and the global maximum subarray sum so far.

9. **Min Subarray Calculation**
	```cpp
	        lmin = min(nums[i], lmin + nums[i]);
	```
	Update 'lmin' to be the minimum of the current element 'nums[i]' or the sum of the previous minimum subarray and the current element.

10. **Min Subarray Update**
	```cpp
	        gmin = min(lmin, gmin);
	```
	Update 'gmin' to the minimum value between 'lmin' and the global minimum subarray sum so far.

11. **Return Statement**
	```cpp
	    return gmax > 0? max(gmax, sum - gmin): gmax;
	```
	Return the maximum value between 'gmax' and the difference between the total sum of the array and 'gmin' if 'gmax' is greater than 0. Otherwise, return 'gmax'. This step considers both circular and non-circular subarrays.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the array at most three times: once for the total sum, once for the maximum subarray sum, and once for the minimum subarray sum.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we use only a few extra variables to store the sum and intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-sum-circular-subarray/description/)

---
{{< youtube aLMZIfhhdMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
