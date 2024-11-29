
+++
authors = ["grid47"]
title = "Leetcode 2044: Count Number of Maximum Bitwise-OR Subsets"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2044: Count Number of Maximum Bitwise-OR Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "_wBj3IMV7tY"
youtube_upload_date="2024-10-18"
youtube_thumbnail="https://i.ytimg.com/vi/_wBj3IMV7tY/maxresdefault.jpg"
comments = true
+++



---
Given an integer array `nums`, find the maximum bitwise OR that can be achieved by any subset of `nums` and count how many different non-empty subsets yield this maximum value. A subset is defined as any combination of elements from the array, and subsets are considered different if their elements are selected from different indices.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an integer array `nums` representing the elements from which subsets can be formed. The goal is to determine the maximum bitwise OR and count subsets achieving it.
- **Example:** `Input: nums = [4, 2, 6]`
- **Constraints:**
	- 1 <= nums.length <= 16
	- 1 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the number of subsets that achieve the maximum bitwise OR value.
- **Example:** `Output: 3`
- **Constraints:**
	- The output is always a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the maximum bitwise OR value that can be obtained from any subset of `nums`, and count the subsets achieving this maximum.

- Iterate through all subsets of `nums` using a bitmask.
- Calculate the bitwise OR for each subset.
- Track the maximum bitwise OR value and count the subsets that achieve this value.
{{< dots >}}
### Problem Assumptions ✅
- The input array is non-empty.
- All elements in the array are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [4, 1, 7]`  \
  **Explanation:** The maximum possible bitwise OR is 7. There are 4 subsets achieving this: [7], [4, 7], [1, 7], and [4, 1, 7]. Thus, the output is 4.

- **Input:** `Input: nums = [1, 1, 1]`  \
  **Explanation:** The maximum possible bitwise OR is 1. All subsets are non-empty and achieve this value. Total subsets: 2^3 - 1 = 7. Output is 7.

{{< dots >}}
## Approach 🚀
Use dynamic programming to count subsets with a specific OR value while iterating through the array. This ensures efficient handling of overlapping subsets with similar OR results.

### Initial Thoughts 💭
- The maximum bitwise OR value is achieved by including specific elements in the subset.
- The problem can be solved efficiently by tracking the OR values dynamically instead of recalculating for each subset.
- Iterate through the elements of `nums`, updating the count of subsets for each OR value dynamically.
{{< dots >}}
### Edge Cases 🌐
- No empty input cases exist since nums is guaranteed to be non-empty.
- Handle cases where nums contains 16 elements, leading to 2^16 subsets.
- All elements in nums are the same, e.g., nums = [7, 7, 7].
- The array nums contains powers of 2, e.g., nums = [1, 2, 4, 8].
- Maximum bitwise OR value must be calculated for all combinations efficiently.
{{< dots >}}
## Code 💻
```cpp
int countMaxOrSubsets(vector<int>& nums) {
    int mx = 0;
    int dp[1 << 17] = {1};
    dp[0] = 1;
    for(int a : nums) {
        for(int i = mx; i >= 0; i--) {
            dp[i | a] += dp[i];
        }
        mx |= a;
    }
    return dp[mx];
}
```

This code implements a solution to find the number of subsets of a given list of integers `nums` such that the bitwise OR of all the elements in the subset is maximized.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int countMaxOrSubsets(vector<int>& nums) {
	```
	This is the function header that defines the `countMaxOrSubsets` function, which takes a vector of integers `nums` as input.

2. **Variable Initialization**
	```cpp
	    int mx = 0;
	```
	The variable `mx` is initialized to 0. It will keep track of the maximum bitwise OR of all elements encountered so far.

3. **Array Initialization**
	```cpp
	    int dp[1 << 17] = {1};
	```
	The array `dp` is initialized with size `1 << 17` (a large size to cover all possible OR results) and the first element set to 1.

4. **Array Initialization**
	```cpp
	    dp[0] = 1;
	```
	Sets the base case for the dynamic programming array, indicating that there is one way to form a subset with a bitwise OR of 0.

5. **Loop Start**
	```cpp
	    for(int a : nums) {
	```
	This loop iterates through each element `a` in the input vector `nums`.

6. **Nested Loop Start**
	```cpp
	        for(int i = mx; i >= 0; i--) {
	```
	This nested loop iterates backwards from the current maximum OR value `mx` to 0, ensuring all subsets are considered.

7. **Dynamic Programming Update**
	```cpp
	            dp[i | a] += dp[i];
	```
	This updates the dynamic programming array by adding the number of subsets that result in the OR value `i | a` to the current subset count.

8. **Nested Loop End**
	```cpp
	        }
	```
	End of the inner loop where all possible OR values with the current element `a` are processed.

9. **Update Maximum OR**
	```cpp
	        mx |= a;
	```
	Updates `mx` to reflect the maximum OR value encountered so far, combining it with the current element `a`.

10. **Return Statement**
	```cpp
	    return dp[mx];
	```
	Returns the value in `dp[mx]`, which represents the number of subsets with the maximum OR value.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * max_or_values) when elements overlap minimally.
- **Average Case:** O(n * max_or_values).
- **Worst Case:** O(n * max_or_values) for highly overlapping subsets.

The time complexity depends on the number of OR values dynamically tracked during the iterations.

### Space Complexity 💾
- **Best Case:** O(max_or_values).
- **Worst Case:** O(max_or_values) for storing DP results.

Space is used for the DP array storing counts for each OR value.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/)

---
{{< youtube _wBj3IMV7tY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
