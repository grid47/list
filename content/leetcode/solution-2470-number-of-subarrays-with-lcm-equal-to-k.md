
+++
authors = ["grid47"]
title = "Leetcode 2470: Number of Subarrays With LCM Equal to K"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2470: Number of Subarrays With LCM Equal to K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xT-O9YJrwh4"
youtube_upload_date="2022-11-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/xT-O9YJrwh4/maxresdefault.webp"
comments = true
+++



---
Given an integer array `nums` and an integer `k`, return the number of subarrays where the Least Common Multiple (LCM) of all the elements in the subarray equals `k`. A subarray is a contiguous subsequence of elements in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums` and an integer `k`. The array contains integers and `k` is the target LCM value.
- **Example:** `nums = [2, 3, 6, 4, 1], k = 6`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i], k <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of subarrays where the LCM of the elements is equal to `k`.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be an integer count.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find subarrays where the LCM of the elements is exactly equal to `k`.

- Iterate over all possible subarrays of `nums`.
- For each subarray, calculate the LCM of its elements.
- If the LCM equals `k`, increase the count.
{{< dots >}}
### Problem Assumptions ✅
- The input array `nums` will not be empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [2, 3, 6, 4, 1], k = 6`  \
  **Explanation:** In this case, there are three subarrays where the LCM equals 6: [2, 3, 6], [3, 6], and [6].

{{< dots >}}
## Approach 🚀
To solve this problem, iterate through all possible subarrays and compute the LCM for each one, checking if it matches `k`.

### Initial Thoughts 💭
- We need to efficiently calculate the LCM of subarrays and check if it equals `k`.
- The LCM calculation for each subarray should be optimized to avoid redundant computations.
{{< dots >}}
### Edge Cases 🌐
- The input array `nums` will not be empty as per the problem constraints.
- For large input arrays, the solution should be efficient enough to avoid timeouts.
- If `k` is smaller than the smallest element in `nums`, the result should be 0.
- The solution should handle cases where `nums` contains a mix of large and small numbers efficiently.
{{< dots >}}
## Code 💻
```cpp
int subarrayLCM(vector<int>& nums, int k) {
    int n = nums.size(), cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n && k % nums[j] == 0; j++) {
            nums[i] = (nums[i] * nums[j] / __gcd(nums[i], nums[j]));
            cnt += nums[i] == k;
        }
    }
    return cnt;
}
```

This function calculates the number of subarrays whose least common multiple (LCM) equals the given integer `k`. It iterates through pairs of numbers, updating the LCM and counting when it matches `k`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int subarrayLCM(vector<int>& nums, int k) {
	```
	The function `subarrayLCM` is declared, taking a reference to a vector of integers `nums` and an integer `k`. It will return an integer representing the count of subarrays whose LCM equals `k`.

2. **Variable Initialization**
	```cpp
	    int n = nums.size(), cnt = 0;
	```
	The variable `n` stores the size of the `nums` vector, and `cnt` is initialized to zero to track the number of valid subarrays where the LCM equals `k`.

3. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	The outer loop starts, iterating through each element of the `nums` vector. The variable `i` represents the starting index of the subarray.

4. **Inner Loop**
	```cpp
	        for(int j = i; j < n && k % nums[j] == 0; j++) {
	```
	The inner loop starts at index `i` and continues as long as the condition `k % nums[j] == 0` is true, meaning the current number divides `k`. The variable `j` represents the ending index of the subarray.

5. **LCM Update**
	```cpp
	            nums[i] = (nums[i] * nums[j] / __gcd(nums[i], nums[j]));
	```
	This line calculates the LCM of `nums[i]` and `nums[j]` using the formula `LCM(a, b) = (a * b) / GCD(a, b)` and stores the result back in `nums[i]`.

6. **Count Match**
	```cpp
	            cnt += nums[i] == k;
	```
	If the LCM of the current subarray is equal to `k`, `cnt` is incremented by 1.

7. **Return Statement**
	```cpp
	    return cnt;
	```
	The function returns the final count `cnt`, which represents the number of subarrays whose LCM equals `k`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we check all subarrays, and for each subarray, we compute the LCM, which can take linear time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only need a few variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/description/)

---
{{< youtube xT-O9YJrwh4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
