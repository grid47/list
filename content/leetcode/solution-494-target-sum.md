
+++
authors = ["grid47"]
title = "Leetcode 494: Target Sum"
date = "2024-09-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 494: Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/494.webp"
youtube = "Rdie0uPp7e8"
youtube_upload_date="2023-07-19"
youtube_thumbnail="https://i.ytimg.com/vi/Rdie0uPp7e8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/494.webp" 
    alt="A set of numbers being combined to reach a target sum, with each valid combination softly glowing."
    caption="Solution to LeetCode 494: Target Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array nums and an integer target. You must build an expression by adding '+' or '-' before each element in nums and concatenate them to form an expression. Return the number of different expressions that result in the target value.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums and an integer target.
- **Example:** `nums = [1, 2, 3, 4, 5], target = 7`
- **Constraints:**
	- 1 <= nums.length <= 20
	- 0 <= nums[i] <= 1000
	- 0 <= sum(nums[i]) <= 1000
	- -1000 <= target <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct expressions that can be formed, which evaluate to the target value.
- **Example:** `Output: 3`
- **Constraints:**
	- The result will be an integer representing the number of expressions.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the number of expressions whose evaluated result matches the target value.

- 1. Use dynamic programming or memoization to track the number of ways to achieve each sum with the given operations.
- 2. Use recursion to consider both adding and subtracting each number at every step.
- 3. Use a memoization table to store intermediate results for efficient computation.
{{< dots >}}
### Problem Assumptions ✅
- The array will always have at least one element.
- Both operations '+' and '-' can be applied to any element in nums.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 2, 3, 4, 5], target = 7`  \
  **Explanation:** There are 3 ways to form an expression that evaluates to 7: +1 +2 +3 -4 +5, +1 +2 -3 +4 +5, and +1 -2 +3 +4 +5.

- **Input:** `nums = [10, 2, 3], target = 5`  \
  **Explanation:** There is only 1 way to form an expression that evaluates to 5: +10 -2 -3.

{{< dots >}}
## Approach 🚀
The solution involves dynamic programming and memoization to recursively find the number of ways to form the target sum by applying the '+' and '-' operations to each element of nums.

### Initial Thoughts 💭
- The problem can be solved by exploring all possible combinations of '+' and '-' for each element.
- Dynamic programming with memoization should be used to efficiently calculate the number of ways to reach the target sum.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that nums will always contain at least one element.
- The solution must be optimized to handle larger inputs efficiently, up to the constraint limits.
- If the target is 0, we need to count the number of ways to make the sum 0.
- Ensure that the algorithm handles both small and large arrays as specified in the constraints.
{{< dots >}}
## Code 💻
```cpp
map<int, map<int, int>> mp;
vector<int> nums;

int dp(int target, int idx) {
    if(idx == nums.size()) return target == 0;
    
    if(mp.count(target))
        if(mp[target].count(idx)) return mp[target][idx];
    
    int res = dp(target - nums[idx], idx + 1);
    res += dp(target + nums[idx], idx + 1);
    
    return mp[target][idx] = res;
}
int findTargetSumWays(vector<int>& nums, int target) {
    this->nums = nums;
    return dp(target, 0);
}
```

This solution uses dynamic programming and memoization to calculate the number of ways to assign '+' and '-' signs to each element in the array to reach the target sum.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Memoization Structure**
	```cpp
	map<int, map<int, int>> mp;
	```
	Declares a map `mp` which stores the number of ways to achieve a specific target using a given index, enabling memoization for efficient calculation.

2. **Variable Declaration**
	```cpp
	vector<int> nums;
	```
	Declares a vector `nums` to store the input numbers that will be used in the calculations.

3. **Function Definition**
	```cpp
	int dp(int target, int idx) {
	```
	Defines the `dp` function, which is a recursive function that calculates the number of ways to reach a specific target sum starting from a given index.

4. **Base Case**
	```cpp
	    if(idx == nums.size()) return target == 0;
	```
	Base case: If all elements have been processed (i.e., `idx` equals the size of `nums`), return 1 if the target is 0 (meaning we’ve successfully formed the target sum), otherwise return 0.

5. **Memoization Check**
	```cpp
	    if(mp.count(target))
	```
	Checks if the result for the current target has already been calculated for the given index using memoization.

6. **Memoization Lookup**
	```cpp
	        if(mp[target].count(idx)) return mp[target][idx];
	```
	If the result for the current target and index is already stored, return the memoized value to avoid redundant calculations.

7. **Recursive Calls**
	```cpp
	    int res = dp(target - nums[idx], idx + 1);
	```
	Recursively calls `dp` by subtracting the current number (`nums[idx]`) from the target and moving to the next index.

8. **Recursive Calls**
	```cpp
	    res += dp(target + nums[idx], idx + 1);
	```
	Recursively calls `dp` again, but this time by adding the current number (`nums[idx]`) to the target and moving to the next index. Both results are added to account for both possibilities.

9. **Memoization**
	```cpp
	    return mp[target][idx] = res;
	```
	Stores the computed result in the memoization table `mp` for future use, associating it with the current target and index.

10. **Function Definition**
	```cpp
	int findTargetSumWays(vector<int>& nums, int target) {
	```
	Defines the `findTargetSumWays` function, which initializes the memoization structure and calls the recursive `dp` function to calculate the result.

11. **Input Assignment**
	```cpp
	    this->nums = nums;
	```
	Assigns the input vector `nums` to the class-level `nums` variable, so it can be used in the `dp` function.

12. **Return Statement**
	```cpp
	    return dp(target, 0);
	```
	Calls the `dp` function starting from index 0 and the target value, and returns the result, which is the number of ways to achieve the target sum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * target)
- **Average Case:** O(n * target)
- **Worst Case:** O(n * target)

The time complexity is O(n * target) because each subproblem is computed once and memoized.

### Space Complexity 💾
- **Best Case:** O(n * target)
- **Worst Case:** O(n * target)

The space complexity is O(n * target) due to the memoization table storing results for each target and index combination.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/target-sum/description/)

---
{{< youtube Rdie0uPp7e8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
