
+++
authors = ["grid47"]
title = "Leetcode 1262: Greatest Sum Divisible by Three"
date = "2024-07-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1262: Greatest Sum Divisible by Three in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given an array of integers, find the maximum sum of any subsequence where the sum is divisible by 3.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array 'nums'.
- **Example:** `[2, 5, 8, 7, 3]`
- **Constraints:**
	- 1 <= nums.length <= 4 * 10^4
	- 1 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the maximum sum of any subsequence that is divisible by 3.
- **Example:** `21`
- **Constraints:**
	- The sum must be divisible by 3.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the maximum possible sum of a subsequence divisible by 3.

- 1. Initialize a dynamic programming array 'dp' to store the maximum sum for each remainder modulo 3.
- 2. Iterate through the numbers in 'nums' and update 'dp' based on the current number.
- 3. Return the value in 'dp[0]', which represents the maximum sum divisible by 3.
{{< dots >}}
### Problem Assumptions ✅
- The input is a valid integer array with values within the given constraints.
- A subsequence is any set of elements in the array, not necessarily contiguous.
{{< dots >}}
## Examples 🧩
- **Input:** `[2, 5, 8, 7, 3]`  \
  **Explanation:** The sum of the numbers 2, 5, 8, and 7 equals 21, which is divisible by 3. Thus, 21 is the maximum sum.

{{< dots >}}
## Approach 🚀
Use dynamic programming to track the maximum possible sum for each remainder when divided by 3.

### Initial Thoughts 💭
- The problem can be reduced to finding the maximum sum for each modulo 3 remainder.
- We can use dynamic programming to keep track of the best possible sums for remainders 0, 1, and 2.
{{< dots >}}
### Edge Cases 🌐
- The array is not empty based on the problem constraints.
- Ensure that the solution handles arrays with a size up to 40,000 efficiently.
- All numbers in the array could be divisible by 3, or none could be.
- The input array is guaranteed to have at least one element.
{{< dots >}}
## Code 💻
```cpp
int maxSumDivThree(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp(3, 0);

    for(int a : nums)
    for(int i : vector<int>(dp))
    dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);

    return dp[0];
}
```

This code defines a solution to find the maximum sum of elements from a given list of integers such that the sum is divisible by 3. It uses dynamic programming to track the maximum possible sum modulo 3.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxSumDivThree(vector<int>& nums) {
	```
	This defines the function `maxSumDivThree`, which takes a vector of integers `nums` and returns the maximum sum divisible by 3 that can be obtained by selecting elements from the list.

2. **Variable Declaration**
	```cpp
	    int n = nums.size();
	```
	This declares an integer `n` to store the size of the input array `nums`.

3. **Vector Initialization**
	```cpp
	    vector<int> dp(3, 0);
	```
	This initializes a vector `dp` of size 3, with all values set to 0. The vector will store the maximum sum possible for each remainder when divided by 3.

4. **Loop (Array Iteration)**
	```cpp
	    for(int a : nums)
	```
	This loop iterates over each element `a` in the input array `nums`.

5. **Loop (Dynamic Programming Update)**
	```cpp
	    for(int i : vector<int>(dp))
	```
	This loop iterates over the current values in the `dp` vector to update the possible sums with the current element `a`.

6. **Dynamic Programming Transition**
	```cpp
	    dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);
	```
	This updates the `dp` vector by calculating the maximum sum for each possible remainder modulo 3 after adding the current element `a`.

7. **Return Statement**
	```cpp
	    return dp[0];
	```
	This returns the value stored in `dp[0]`, which represents the maximum sum divisible by 3 after processing all elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N), where N is the number of elements in the array.
- **Average Case:** O(N) for each iteration over the array.
- **Worst Case:** O(N), where N is the number of elements in the array.

The time complexity is linear because we iterate over the array once.

### Space Complexity 💾
- **Best Case:** O(1), since the space usage does not depend on the input size.
- **Worst Case:** O(1), since we only store a fixed-size array (dp) of size 3.

The space complexity is constant because we only need a fixed amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/greatest-sum-divisible-by-three/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
