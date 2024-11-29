
+++
authors = ["grid47"]
title = "Leetcode 213: House Robber II"
date = "2024-10-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 213: House Robber II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/213.webp"
youtube = "rWAJCfYYOvM"
youtube_upload_date="2021-02-19"
youtube_thumbnail="https://i.ytimg.com/vi/rWAJCfYYOvM/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/213.webp" 
    alt="A series of houses arranged in a circle, each glowing with a soft light, showing optimal paths to rob."
    caption="Solution to LeetCode 213: House Robber II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are tasked with designing a strategy to rob houses along a circular street, where no two adjacent houses can be robbed on the same night. The goal is to maximize the total money stolen without triggering security alarms.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers representing the amount of money at each house along the street. The houses are arranged in a circle.
- **Example:** `[3, 5, 1, 6]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 0 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the maximum amount of money that can be robbed without robbing two adjacent houses.
- **Example:** `For input [3, 5, 1, 6], the output is 9.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Design an efficient algorithm that calculates the maximum amount of money that can be stolen, taking into account the circular arrangement of houses.

- Use dynamic programming to solve the problem. Consider two cases: one where the first house is included and one where it is not.
- For each case, use dynamic programming to calculate the maximum money that can be robbed while ensuring adjacent houses are not robbed.
{{< dots >}}
### Problem Assumptions ✅
- The houses are in a circular arrangement.
- Adjacent houses cannot be robbed together.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this example, you can rob houses 1 and 3 to maximize the stolen amount, totaling 9.

- **Input:** `Example 2`  \
  **Explanation:** For this input, robbing houses 1, 3, and 5 gives a total of 12, which is the maximum amount.

{{< dots >}}
## Approach 🚀
We use dynamic programming to solve this problem, considering two possible cases: one where the first house is robbed and one where it is not. We then apply a standard dynamic programming approach to each case.

### Initial Thoughts 💭
- Dynamic programming is a natural fit because we need to decide at each step whether to rob a house or skip it, based on the previous decisions.
- We will break the problem into two smaller subproblems: one where we exclude the first house and one where we include the first house.
{{< dots >}}
### Edge Cases 🌐
- If the input is an empty array, the result should be 0.
- The solution should efficiently handle cases where the number of houses is large (up to 100).
- If all houses contain 0 money, the maximum amount that can be robbed is 0.
- Handle edge cases such as arrays with only one house, or with houses containing no money.
{{< dots >}}
## Code 💻
```cpp
int rob(vector<int>& nums) {
    
    int n = nums.size();
    if(n == 1) return nums[0];
    
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i = 2; i < n; i++)
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        
    int r1 = dp[n - 1];
    
    dp.resize(n + 1, 0);
    dp[1] = 0;
    dp[2] = nums[1];        
    for(int i = 3; i < n + 1; i++)
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);        
    
    return max(dp[n], r1);
}
```

This code defines the 'rob' function, which implements a dynamic programming approach to solve the house robber problem. It uses two different dynamic programming arrays to store intermediate results, ensuring an optimized solution to avoid robbing adjacent houses.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	int rob(vector<int>& nums) {
	```
	The method definition for the 'rob' function, which takes a vector of integers as input.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes a variable 'n' to store the size of the input vector 'nums'.

3. **Conditional Statement**
	```cpp
	    if(n == 1) return nums[0];
	```
	Checks if there's only one house. If so, return its value as it is the only option.

4. **Array Initialization**
	```cpp
	    vector<int> dp(n, 0);
	```
	Initializes a dynamic programming array 'dp' of size 'n' with all elements set to 0.

5. **Assignment**
	```cpp
	    dp[0] = 0;
	```
	Sets the first element of 'dp' to 0, as no money can be robbed from the first house.

6. **Assignment**
	```cpp
	    dp[1] = nums[0];
	```
	Sets the second element of 'dp' to the value of the first house, since it’s the first valid option.

7. **Loop Iteration**
	```cpp
	    for(int i = 2; i < n; i++)
	```
	Begins a loop from index 2 to 'n', iterating over the houses to calculate the maximum money that can be robbed.

8. **Array Manipulation**
	```cpp
	    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
	```
	For each house, we decide whether to rob it (i.e., add its value to the result of robbing up to house 'i-2') or skip it (i.e., keep the value from 'i-1').

9. **Variable Assignment**
	```cpp
	    int r1 = dp[n - 1];
	```
	Stores the final result of the first dynamic programming sequence (up to house 'n-1').

10. **Array Resize**
	```cpp
	    dp.resize(n + 1, 0);
	```
	Resizes the 'dp' array to accommodate one more element and initializes the new values to 0.

11. **Assignment**
	```cpp
	    dp[1] = 0;
	```
	Sets the second element of the resized 'dp' array to 0, representing no money robbed from the first house.

12. **Assignment**
	```cpp
	    dp[2] = nums[1];        
	```
	Sets the third element of 'dp' to the value of the second house.

13. **Loop Iteration**
	```cpp
	    for(int i = 3; i < n + 1; i++)
	```
	Begins another loop, this time starting from house 3 (after resizing the array) to calculate maximum money that can be robbed.

14. **Array Manipulation**
	```cpp
	    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);        
	```
	As before, we update 'dp' based on whether we rob the current house or not.

15. **Return Statement**
	```cpp
	    return max(dp[n], r1);
	```
	Returns the maximum value between the results of the two dynamic programming sequences.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the nums array.
- **Average Case:** O(n), since we iterate over the array twice for the two cases.
- **Worst Case:** O(n), where n is the length of the nums array.

The algorithm processes each element of the array once for each of the two cases, making the time complexity linear in terms of the number of houses.

### Space Complexity 💾
- **Best Case:** O(n), as space is used to store the results of subproblems.
- **Worst Case:** O(n), due to the space used for the dynamic programming table.

The space complexity is linear because we store results for subproblems in an array of size n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/house-robber-ii/description/)

---
{{< youtube rWAJCfYYOvM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
