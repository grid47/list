
+++
authors = ["grid47"]
title = "Leetcode 2270: Number of Ways to Split Array"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2270: Number of Ways to Split Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XdsMrB7WRUw"
youtube_upload_date="2022-05-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XdsMrB7WRUw/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `nums` of length `n`. The task is to find how many valid splits exist in `nums`. A valid split is defined as an index `i` such that the sum of the first `i + 1` elements is greater than or equal to the sum of the remaining elements from index `i + 1` to the end. The split must be at an index where at least one element exists on the right side of `i`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `nums` of integers.
- **Example:** `nums = [5, 3, -2, 4]`
- **Constraints:**
	- 2 <= nums.length <= 10^5
	- -10^5 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of valid splits in `nums`.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the number of valid splits where the sum of elements from index 0 to `i` is greater than or equal to the sum of elements from index `i + 1` to the end of the array.

- Compute the prefix sum array to track cumulative sums from the start.
- Check each potential split point `i` from 0 to `n - 2` to see if the sum of the first `i + 1` elements is greater than or equal to the sum of the remaining elements.
- Count the number of valid splits where the condition holds.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` will always contain at least two elements.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [5, 3, -2, 4]`  \
  **Explanation:** There are three possible splits: at index 0, index 1, and index 2. The valid splits occur at index 0 and 1, because the sum of elements before these indices is greater than or equal to the sum of elements after them.

- **Input:** `nums = [1, 2, 3, 4, 5]`  \
  **Explanation:** Valid splits happen at indices 0, 1, 2, and 3 because the sums of the first `i+1` elements at each of these indices are greater than or equal to the sums of the elements after them.

{{< dots >}}
## Approach 🚀
The approach uses a prefix sum array to efficiently calculate the sum of elements on the left and right sides of each potential split point. By comparing the sum of elements before the split with the sum of elements after the split, we can determine if a split is valid.

### Initial Thoughts 💭
- The problem involves comparing sums at each index, so calculating cumulative sums can speed up the solution.
- Prefix sum arrays allow us to compute the sum of elements efficiently without recalculating sums repeatedly.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the length of `nums` will always be at least 2.
- Ensure the solution can handle large input arrays up to 100,000 elements.
- Arrays with all elements being the same value.
- The solution should handle both positive and negative integers efficiently.
{{< dots >}}
## Code 💻
```cpp
int waysToSplitArray(vector<int>& in) {
    
    
    // partial_sum(nums.begin(), nums.end(), nums.begin());
    
    int n = in.size(), res = 0;

    vector<long long> nums(n, 0);
    
    for(int i = 0; i < n; i++)
    nums[i] = (i == 0) ? in[0] : nums[i - 1] + in[i];
    
    for(int i = 0; i < n - 1; i++) {
        if(nums[i] >= nums[n - 1] - nums[i]) res++;
    }
    
    return res;
}
```

This function calculates how many ways the given array can be split into two parts such that the sum of the left part is greater than or equal to the sum of the right part. It uses a prefix sum array to track the cumulative sum from the start of the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int waysToSplitArray(vector<int>& in) {
	```
	This is the function header for `waysToSplitArray`, which takes a vector of integers `in` and returns the number of valid splits where the sum of the left part is greater than or equal to the sum of the right part.

2. **Variable Initialization**
	```cpp
	    int n = in.size(), res = 0;
	```
	Initializes `n` to store the size of the input array `in` and `res` to store the count of valid splits.

3. **Prefix Sum Array Initialization**
	```cpp
	    vector<long long> nums(n, 0);
	```
	Creates a vector `nums` of size `n` to store the prefix sum values of the array.

4. **Prefix Sum Calculation**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Starts a loop to calculate the prefix sum of the input array and store it in the `nums` vector.

5. **Prefix Sum Calculation Logic**
	```cpp
	    nums[i] = (i == 0) ? in[0] : nums[i - 1] + in[i];
	```
	Calculates the prefix sum for each index `i`. If `i` is 0, `nums[i]` is just the first element of `in`. Otherwise, it adds the current element of `in` to the previous value in `nums`.

6. **Loop Start for Checking Splits**
	```cpp
	    for(int i = 0; i < n - 1; i++) {
	```
	Starts a loop to check possible splits of the array from index `0` to `n-2`.

7. **Split Condition Check**
	```cpp
	        if(nums[i] >= nums[n - 1] - nums[i]) res++;
	```
	Checks if the sum of the left part of the array (i.e., `nums[i]`) is greater than or equal to the sum of the right part (i.e., `nums[n - 1] - nums[i]`). If the condition is true, increments `res`.

8. **Return Statement**
	```cpp
	    return res;
	```
	Returns the result `res`, which is the total number of valid splits where the left sum is greater than or equal to the right sum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where `n` is the length of the input array `nums`. We only need one pass to compute the prefix sum and another pass to count valid splits.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we need to store the prefix sum array of length `n`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-ways-to-split-array/description/)

---
{{< youtube XdsMrB7WRUw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
