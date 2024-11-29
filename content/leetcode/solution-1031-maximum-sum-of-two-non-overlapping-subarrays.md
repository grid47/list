
+++
authors = ["grid47"]
title = "Leetcode 1031: Maximum Sum of Two Non-Overlapping Subarrays"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1031: Maximum Sum of Two Non-Overlapping Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YAcHH5AVsZg"
youtube_upload_date="2019-07-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/YAcHH5AVsZg/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers `nums` and two integers `firstLen` and `secondLen`. Your task is to find the maximum sum of elements from two non-overlapping subarrays of lengths `firstLen` and `secondLen`. The subarrays can appear in any order, but they must not overlap.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums` and two integers `firstLen` and `secondLen`, representing the lengths of the two subarrays.
- **Example:** `nums = [1, 2, 9, 5, 6, 3, 8, 7], firstLen = 2, secondLen = 3`
- **Constraints:**
	- 1 <= firstLen, secondLen <= 1000
	- 2 <= firstLen + secondLen <= 1000
	- firstLen + secondLen <= nums.length <= 1000
	- 0 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum of the elements of the two non-overlapping subarrays.
- **Example:** `Output: 30`
- **Constraints:**
	- The sum of the elements from the two non-overlapping subarrays must be maximized.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find two non-overlapping subarrays whose sum is as large as possible.

- 1. Use a sliding window to calculate the sum of every subarray of length `firstLen` and `secondLen`.
- 2. Track the maximum sum of subarrays of length `firstLen` up to each index.
- 3. Track the maximum sum of subarrays of length `secondLen` starting from each index.
- 4. Combine the results to maximize the sum of the two non-overlapping subarrays.
{{< dots >}}
### Problem Assumptions ✅
- The input array always has enough elements for both subarrays.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 9, 5, 6, 3, 8, 7], firstLen = 2, secondLen = 3`  \
  **Explanation:** The optimal choice is to take the subarray [9, 5] with length 2 and [6, 3, 8] with length 3. The sum is 9 + 5 + 6 + 3 + 8 = 30.

- **Input:** `Input: nums = [3, 8, 1, 5, 2, 9], firstLen = 2, secondLen = 2`  \
  **Explanation:** One optimal choice is the subarray [8, 1] with length 2 and [5, 2] with length 2. The sum is 8 + 1 + 5 + 2 = 16.

{{< dots >}}
## Approach 🚀
We can solve this problem using dynamic programming or sliding windows. The idea is to maintain a rolling sum of the two subarrays and track the best possible combination of the two sums.

### Initial Thoughts 💭
- This problem is a typical example of maximizing the sum of non-overlapping subarrays.
- We need to efficiently calculate the sum of different subarrays using sliding windows and then combine them to find the maximum sum.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least two subarrays, so empty arrays are not possible.
- The algorithm must efficiently handle arrays with a size of up to 1000 elements.
- If all elements are zero, the result will be zero.
- The length of both subarrays will be less than or equal to the total length of the array.
{{< dots >}}
## Code 💻
```cpp

int maxTwoNoOverlap(vector<int>& A, int L, int M, int sz, int res = 0) {
    vector<int> left(sz+1), right(sz+1);

    for (int i = 0, j = sz - 1, s_r = 0, s_l = 0; i < sz; ++i, --j) {
        s_l += A[i], s_r += A[j];
        left[i + 1] = max(left[i], s_l);
        right[j] = max(right[j + 1], s_r);
        if (i + 1 >= L) s_l -= A[i + 1 - L];
        if (i + 1 >= M) s_r -= A[j + M - 1];
    }

    for (auto i = 0; i < A.size(); ++i) {
        res = max(res, left[i] + right[i]);
    }
  
    return res;

}

int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    return max(maxTwoNoOverlap(nums, firstLen, secondLen, nums.size()),
               maxTwoNoOverlap(nums, secondLen, firstLen, nums.size()));
}
```

This code calculates the maximum sum of two non-overlapping subarrays of given lengths using a two-pass approach with prefix sums.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxTwoNoOverlap(vector<int>& A, int L, int M, int sz, int res = 0) {
	```
	Define the helper function `maxTwoNoOverlap` that calculates the maximum sum of two non-overlapping subarrays of lengths L and M.

2. **Initialize Vectors**
	```cpp
	    vector<int> left(sz+1), right(sz+1);
	```
	Initialize two vectors `left` and `right` to store maximum prefix sums from left to right and right to left.

3. **Iterate Over Array**
	```cpp
	    for (int i = 0, j = sz - 1, s_r = 0, s_l = 0; i < sz; ++i, --j) {
	```
	Iterate over the array from both ends to calculate prefix sums for the left and right vectors.

4. **Update Prefix Sums**
	```cpp
	        s_l += A[i], s_r += A[j];
	```
	Update the running sums for the left-to-right and right-to-left prefix sums.

5. **Store Maximum Prefix**
	```cpp
	        left[i + 1] = max(left[i], s_l);
	```
	Store the maximum prefix sum for the left-to-right traversal.

6. **Store Maximum Suffix**
	```cpp
	        right[j] = max(right[j + 1], s_r);
	```
	Store the maximum prefix sum for the right-to-left traversal.

7. **Adjust Window L**
	```cpp
	        if (i + 1 >= L) s_l -= A[i + 1 - L];
	```
	Adjust the left-to-right window by subtracting the element that moves out of the L-sized window.

8. **Adjust Window M**
	```cpp
	        if (i + 1 >= M) s_r -= A[j + M - 1];
	```
	Adjust the right-to-left window by subtracting the element that moves out of the M-sized window.

9. **Calculate Result**
	```cpp
	    for (auto i = 0; i < A.size(); ++i) {
	```
	Iterate through the array to calculate the maximum sum of two non-overlapping subarrays.

10. **Update Result**
	```cpp
	        res = max(res, left[i] + right[i]);
	```
	Update the result with the maximum sum of the two non-overlapping subarrays at each point.

11. **Return Helper Result**
	```cpp
	    return res;
	```
	Return the calculated result for the helper function `maxTwoNoOverlap`.

12. **Main Function Definition**
	```cpp
	int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
	```
	Define the main function `maxSumTwoNoOverlap` that computes the maximum sum using the helper function.

13. **Call Helper Function**
	```cpp
	    return max(maxTwoNoOverlap(nums, firstLen, secondLen, nums.size()),
	```
	Call the helper function with both possible orderings of the subarray lengths and return the maximum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only iterate through the array a few times.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the sliding window sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/)

---
{{< youtube YAcHH5AVsZg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
