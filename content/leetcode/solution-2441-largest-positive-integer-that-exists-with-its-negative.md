
+++
authors = ["grid47"]
title = "Leetcode 2441: Largest Positive Integer That Exists With Its Negative"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2441: Largest Positive Integer That Exists With Its Negative in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ec0T3so3m2Y"
youtube_upload_date="2022-10-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Ec0T3so3m2Y/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `nums` where each element is non-zero. Your task is to find the largest positive integer `k` such that its negative counterpart `-k` also exists in the array. Return the largest such `k`. If no such integer exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a non-empty array `nums` of integers, where each integer is non-zero.
- **Example:** `nums = [4, -2, -4, 5, 1]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- -1000 <= nums[i] <= 1000
	- nums[i] != 0

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest integer `k` such that `-k` exists in the array. If no such `k` exists, return -1.
- **Example:** `Output: 4`
- **Constraints:**
	- The returned result must be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the largest integer `k` such that `-k` exists in the array.

- 1. Iterate through the array and store the presence of each number in a hash map.
- 2. For each positive integer `k` in the array, check if its negative counterpart `-k` is also present.
- 3. Track the largest valid `k` found during the iteration and return it.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain at least one element.
- There will be no zeroes in the input array.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, -2, -4, 5, 1]`  \
  **Explanation:** Here, the number `4` has its negative counterpart `-4` in the array. The number `2` has `-2`, but the largest such integer is `4`. Hence, the output is 4.

- **Input:** `nums = [-6, -3, 5, 2]`  \
  **Explanation:** There is no positive integer `k` such that `-k` is present in the array. Therefore, the output is -1.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to efficiently check for each number if its negative counterpart exists in the array. Using a hash map allows us to check for presence in constant time.

### Initial Thoughts 💭
- We can use a hash set to track the numbers that we encounter in the array.
- After processing all numbers, we can iterate through the positive numbers and check if their negatives exist.
- A direct approach using a hash set will be both time-efficient and simple to implement.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one non-zero element in the input array, so empty arrays are not a concern.
- The solution should be able to handle arrays with up to 1000 elements efficiently.
- When the array contains both positive and negative numbers, the solution should correctly identify pairs such as `3` and `-3`.
- The solution must check for both positive and negative values in the array.
{{< dots >}}
## Code 💻
```cpp
int findMaxK(vector<int>& nums) {
int arr[2001] = {}, res = -1;
for (int n : nums) {
    if (arr[-n + 1000])
        res = max(res, abs(n));
    ++arr[n + 1000];        
}
return res;
}
```

This code defines a function `findMaxK` that finds the largest integer `k` in the array `nums` such that both `k` and `-k` exist in the array. It uses an auxiliary array to keep track of the integers encountered during the iteration.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findMaxK(vector<int>& nums) {
	```
	Defining the function `findMaxK`, which takes a vector `nums` and returns an integer representing the largest `k` such that both `k` and `-k` are present in the array.

2. **Variable Initialization**
	```cpp
	int arr[2001] = {}, res = -1;
	```
	Initializing an auxiliary array `arr` of size 2001 to track the occurrence of integers from -1000 to 1000 (mapped to indices 0 to 2000). `res` is initialized to -1, which will store the result.

3. **Loop**
	```cpp
	for (int n : nums) {
	```
	Iterating through each integer `n` in the `nums` array.

4. **Condition Check**
	```cpp
	    if (arr[-n + 1000])
	```
	Checking if the corresponding negative integer `-n` has already appeared in the array by using the auxiliary array `arr`. The `-n + 1000` adjusts for negative indices.

5. **Mathematical Operation**
	```cpp
	        res = max(res, abs(n));
	```
	If both `n` and `-n` are found, update the result `res` to be the maximum of the current `res` and the absolute value of `n`.

6. **Array Update**
	```cpp
	    ++arr[n + 1000];
	```
	Incrementing the value at the index corresponding to `n` in the auxiliary array `arr` to mark that `n` has been encountered.

7. **Return Statement**
	```cpp
	return res;
	```
	Returning the result `res`, which holds the largest integer `k` such that both `k` and `-k` are present in the array, or -1 if no such pair exists.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the array, since we perform constant-time operations for each element.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the hash set used to store the elements of the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/)

---
{{< youtube Ec0T3so3m2Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
