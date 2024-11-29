
+++
authors = ["grid47"]
title = "Leetcode 377: Combination Sum IV"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 377: Combination Sum IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/377.webp"
youtube = "hg_U5GVEM-k"
youtube_upload_date="2023-07-06"
youtube_thumbnail="https://i.ytimg.com/vi/hg_U5GVEM-k/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/377.webp" 
    alt="A glowing set of numbers forming different combinations to meet the target sum, each combination softly glowing."
    caption="Solution to LeetCode 377: Combination Sum IV Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of distinct positive integers `nums` and a target integer `target`, determine the number of possible combinations of elements from `nums` that sum up to `target`. You can use any element of `nums` multiple times in a combination. A combination is considered different if the sequence of numbers is different, even if the same numbers are used.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of distinct integers `nums` and an integer `target`.
- **Example:** `nums = [2, 3, 4], target = 5`
- **Constraints:**
	- 1 <= nums.length <= 200
	- 1 <= nums[i] <= 1000
	- All elements in `nums` are unique.
	- 1 <= target <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of possible combinations of elements from `nums` that add up to `target`.
- **Example:** `Output: 6`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find all possible combinations of numbers that sum up to the target using dynamic programming.

- Create a dynamic programming table `dp` where `dp[i]` represents the number of ways to sum up to `i`.
- Initialize `dp[0] = 1`, since there is one way to reach the target 0 (using no elements).
- For each number in `nums`, update the `dp` array for all target values from that number to the target.
- Return `dp[target]` as the result.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` contains only distinct positive integers.
- The target is a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2, 3, 4], target = 5`  \
  **Explanation:** The possible combinations are: (2, 2, 2), (2, 3), (3, 2), (4).

- **Input:** `nums = [1, 3, 5], target = 8`  \
  **Explanation:** The possible combinations are: (1, 1, 1, 1, 1, 1, 1, 1), (1, 1, 1, 3), (3, 5), etc.

{{< dots >}}
## Approach 🚀
We use dynamic programming to solve the problem efficiently by building a table of subproblems.

### Initial Thoughts 💭
- We can break the problem into smaller subproblems by calculating the number of ways to reach smaller targets.
- The dynamic programming approach is well-suited since we can build solutions iteratively.
{{< dots >}}
### Edge Cases 🌐
- Empty `nums` arrays are not allowed as per the problem constraints.
- The algorithm should handle inputs up to the maximum constraints efficiently.
- Zero or negative values are not allowed as elements of `nums` or as the target.
- Only distinct positive integers are allowed in `nums`.
{{< dots >}}
## Code 💻
```cpp
class Solution {
vector<int> mem;
public:
int combinationSum4(vector<int>& nums, int target) {
    mem.resize(target + 1, -1);
    return dp(nums, target);
}

int dp(vector<int>& nums, int left) {
    
    if(left == 0) return 1;
    if(left < 0) return 0;

    if(mem[left] != -1) return mem[left];

    int res = 0;
    for(int i = 0; i < nums.size(); i++)
        res += dp(nums, left - nums[i]);

    return mem[left] = res;
}
```

This code solves the 'Combination Sum IV' problem using dynamic programming. It uses memoization to optimize the recursive approach to count the number of ways to reach the target sum by using numbers from the input array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	Defines the `Solution` class which will contain the function `combinationSum4` to solve the problem.

2. **Variable Declaration**
	```cpp
	vector<int> mem;
	```
	Declares a vector `mem` that will store the memoized results to avoid redundant calculations in the recursive function.

3. **Access Modifier**
	```cpp
	public:
	```
	Declares the `public` section of the class, indicating that the following methods will be accessible from outside the class.

4. **Function Declaration**
	```cpp
	int combinationSum4(vector<int>& nums, int target) {
	```
	Declares the function `combinationSum4` that takes a vector of integers `nums` and an integer `target` as input and returns the number of combinations that sum to `target`.

5. **Dynamic Programming Initialization**
	```cpp
	    mem.resize(target + 1, -1);
	```
	Initializes the `mem` vector to have a size of `target + 1`, with each value set to -1 to indicate that no subproblems have been solved yet.

6. **Function Call**
	```cpp
	    return dp(nums, target);
	```
	Calls the helper function `dp` to compute the number of combinations that sum up to `target`.

7. **Function Declaration**
	```cpp
	int dp(vector<int>& nums, int left) {
	```
	Declares the helper function `dp`, which uses recursion and memoization to count the number of combinations that sum to `left`.

8. **Base Case (Left == 0)**
	```cpp
	    if(left == 0) return 1;
	```
	Base case of the recursion: If `left` equals 0, it means we have successfully formed a combination that sums to the target, so return 1.

9. **Base Case (Left < 0)**
	```cpp
	    if(left < 0) return 0;
	```
	Base case of the recursion: If `left` becomes negative, it means the current combination is invalid, so return 0.

10. **Memoization Check**
	```cpp
	    if(mem[left] != -1) return mem[left];
	```
	Checks if the result for the current `left` has already been computed and stored in `mem`. If so, it returns the stored result to avoid redundant computations.

11. **Recursive Calculation**
	```cpp
	    int res = 0;
	```
	Declares a variable `res` to accumulate the number of valid combinations that sum to `left`.

12. **Loop Iteration**
	```cpp
	    for(int i = 0; i < nums.size(); i++)
	```
	Iterates over each number in the `nums` array to check if it can be used to form a valid combination that sums to `left`.

13. **Recursive Function Call**
	```cpp
	        res += dp(nums, left - nums[i]);
	```
	Recursively calls `dp` with the updated value `left - nums[i]` and adds the result to `res`. This checks for all combinations that sum to `left`.

14. **Memoization Update**
	```cpp
	    return mem[left] = res;
	```
	Stores the computed result for `left` in the `mem` vector and returns the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(target * nums.size())
- **Average Case:** O(target * nums.size())
- **Worst Case:** O(target * nums.size())

The time complexity is linear with respect to the target and the size of `nums`.

### Space Complexity 💾
- **Best Case:** O(target)
- **Worst Case:** O(target)

The space complexity is O(target) due to the DP array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/combination-sum-iv/description/)

---
{{< youtube hg_U5GVEM-k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
