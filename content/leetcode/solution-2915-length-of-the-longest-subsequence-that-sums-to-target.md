
+++
authors = ["grid47"]
title = "Leetcode 2915: Length of the Longest Subsequence That Sums to Target"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2915: Length of the Longest Subsequence That Sums to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NNSzElew804"
youtube_upload_date="2023-10-28"
youtube_thumbnail="https://i.ytimg.com/vi/NNSzElew804/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers `nums` and a target sum `target`. Your task is to find the length of the longest subsequence from `nums` that sums up to `target`. A subsequence can be derived by deleting some or no elements from `nums` while maintaining the original order of the remaining elements. If no such subsequence exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums` and an integer `target`.
- **Example:** `nums = [2, 3, 5, 7], target = 10`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 1000
	- 1 <= target <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest subsequence of `nums` that sums up to `target`. If no such subsequence exists, return -1.
- **Example:** `For `nums = [2, 3, 5, 7]` and `target = 10`, the output is 3.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the longest subsequence that sums up to the target, we use dynamic programming to store the length of the subsequence at each sum.

- Create a 2D array `dp` where each entry `dp[i][j]` represents the length of the longest subsequence that sums up to `j` using the first `i` elements of `nums`.
- Initialize `dp[i][0] = 0` for all `i`, as a sum of 0 can be achieved with an empty subsequence.
- For each element `nums[i]`, update the `dp` table for all sums from `target` down to `nums[i]`. If adding `nums[i]` to a previous subsequence results in a valid subsequence, update the length.
- Return `dp[n][target]`, where `n` is the size of `nums`. If no valid subsequence exists, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The target is always a positive integer.
- The input array contains only positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2, 3, 5, 7], target = 10`  \
  **Explanation:** One of the longest subsequences that sum to 10 is [3, 7], which has a length of 2. Another valid subsequence is [2, 3, 5], which also sums to 10 and has a length of 3. The longest subsequence is [2, 3, 5], so the answer is 3.

- **Input:** `nums = [1, 2, 3, 4], target = 6`  \
  **Explanation:** The subsequences that sum to 6 are [2, 4], [1, 3], and [1, 2, 3]. The longest subsequence is [1, 2, 3], which has a length of 3.

- **Input:** `nums = [1, 1, 1, 1], target = 5`  \
  **Explanation:** It is impossible to form a subsequence that sums to 5 since the sum of all elements is 4. Therefore, the answer is -1.

{{< dots >}}
## Approach 🚀
The approach uses dynamic programming to calculate the longest subsequence for each possible sum. By iterating through the array and updating the `dp` table, we can determine the longest subsequence that sums up to the target.

### Initial Thoughts 💭
- We can use dynamic programming to keep track of the longest subsequence for each sum.
- If we find a subsequence that sums to the target, we can return its length.
- This problem is a variation of the knapsack problem where instead of maximizing the sum, we maximize the subsequence length.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty.
- The solution must handle arrays of size up to 1000 efficiently.
- When the target is larger than the sum of all elements, return -1.
- All numbers in the array are positive integers.
- The target is also a positive integer.
{{< dots >}}
## Code 💻
```cpp
int lengthOfLongestSubsequence(vector<int>& nums, int sum) {
    int n = nums.size();
    // Create a 2D array to store the dynamic programming results.
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0; // Longest subsequence when the target sum is 0.

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            // Initially, set the result to be the same as the result for the previous element.
            dp[i][j] = dp[i - 1][j];

            // Check if the current element can contribute to the current sum.
            if (j >= nums[i - 1] && dp[i - 1][j - nums[i - 1]] != -1)
                dp[i][j] = max(1 + dp[i - 1][j - nums[i - 1]], dp[i][j]);
        }
    }

    return dp[n][sum]; // Return the result for the entire array with the target sum.
}
```

This function implements a dynamic programming approach to find the length of the longest subsequence of a given array `nums` that sums to the specified value `sum`. The result is stored in a 2D DP array, where the value at `dp[i][j]` represents the length of the longest subsequence using the first `i` elements of `nums` that sums to `j`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int lengthOfLongestSubsequence(vector<int>& nums, int sum) {
	```
	Defines the function `lengthOfLongestSubsequence` that takes an array `nums` and a target sum `sum`, and returns the length of the longest subsequence that sums to the target value.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes the variable `n` to store the size of the input array `nums`.

3. **Array Initialization**
	```cpp
	    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
	```
	Initializes a 2D vector `dp` of size `(n+1) x (sum+1)` to store the dynamic programming results. Initially, all values are set to -1 to indicate that the corresponding subproblems have not been solved yet.

4. **Loop**
	```cpp
	    for (int i = 0; i < n + 1; i++)
	```
	Starts a loop that iterates over all the rows of the 2D array `dp`.

5. **Array Initialization**
	```cpp
	        dp[i][0] = 0; // Longest subsequence when the target sum is 0.
	```
	Sets the first column of the `dp` array to 0, because the longest subsequence that sums to 0 is always 0 (empty subsequence).

6. **Loop**
	```cpp
	    for (int i = 1; i < n + 1; i++) {
	```
	Starts another loop that iterates over each element of the array `nums`.

7. **Loop**
	```cpp
	        for (int j = 1; j < sum + 1; j++) {
	```
	Starts a nested loop that iterates over all possible sum values from 1 to `sum`.

8. **Dynamic Programming Update**
	```cpp
	            dp[i][j] = dp[i - 1][j];
	```
	Sets `dp[i][j]` to the value of `dp[i - 1][j]`, meaning that if the current element cannot contribute to the sum, the result is the same as for the previous element.

9. **Conditional Check**
	```cpp
	            if (j >= nums[i - 1] && dp[i - 1][j - nums[i - 1]] != -1)
	```
	Checks if the current element `nums[i - 1]` can be part of the subsequence to reach the sum `j`. If so, and if the previous subproblem is valid, it proceeds to update the result.

10. **Dynamic Programming Update**
	```cpp
	                dp[i][j] = max(1 + dp[i - 1][j - nums[i - 1]], dp[i][j]);
	```
	Updates the value of `dp[i][j]` to the maximum of its current value and the value obtained by including the current element `nums[i - 1]` in the subsequence.

11. **Return Statement**
	```cpp
	    return dp[n][sum]; // Return the result for the entire array with the target sum.
	```
	Returns the final result from `dp[n][sum]`, which represents the length of the longest subsequence that sums to the target value `sum`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * target)
- **Average Case:** O(n * target)
- **Worst Case:** O(n * target)

The time complexity is O(n * target) because we iterate over the array `nums` and for each element, we update the `dp` table for each possible sum.

### Space Complexity 💾
- **Best Case:** O(n * target)
- **Worst Case:** O(n * target)

The space complexity is O(n * target) due to the storage of the `dp` table.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/description/)

---
{{< youtube NNSzElew804 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
