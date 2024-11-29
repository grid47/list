
+++
authors = ["grid47"]
title = "Leetcode 1049: Last Stone Weight II"
date = "2024-07-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1049: Last Stone Weight II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gdXkkmzvR3c"
youtube_upload_date="2023-02-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gdXkkmzvR3c/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers representing the weights of stones. In each turn, you can select two stones, x and y, with x <= y, and smash them together. The result of the smash is as follows: if x equals y, both stones are destroyed, otherwise, the stone with weight x is destroyed, and the stone with weight y becomes y - x. The process continues until there is at most one stone left. Your task is to return the smallest possible weight of the remaining stone, or return 0 if no stones are left.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers representing the weight of each stone.
- **Example:** `Input: stones = [3, 9, 6, 5, 8]`
- **Constraints:**
	- 1 <= stones.length <= 30
	- 1 <= stones[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest possible weight of the remaining stone after all possible smashes.
- **Example:** `Output: 2`
- **Constraints:**
	- The result will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the smallest possible remaining stone weight after all smashes.

- 1. Calculate the total sum of the stones.
- 2. Use dynamic programming to find the largest possible subset sum close to half of the total sum.
- 3. The smallest remaining stone weight will be the difference between the total sum and twice the largest subset sum found.
{{< dots >}}
### Problem Assumptions ✅
- Each stone is represented by a positive integer weight.
- The number of stones is relatively small, so an approach using dynamic programming is feasible.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: stones = [3, 9, 6, 5, 8]`  \
  **Explanation:** In this example, the best we can achieve is a remaining stone with weight 2, after repeatedly smashing stones together and reducing the total weight progressively.

- **Input:** `Input: stones = [4, 6, 7, 2]`  \
  **Explanation:** For these stones, the final remaining stone will have weight 1 after optimal smashes.

{{< dots >}}
## Approach 🚀
To solve this problem, we use dynamic programming to find a subset of stones that sums up to as close as possible to half of the total sum of the stones, which minimizes the remaining stone weight.

### Initial Thoughts 💭
- The game can be interpreted as a problem of partitioning the stones into two subsets such that the difference between the total weights of the two subsets is minimized.
- This is a variation of the knapsack problem where we aim to maximize the subset sum close to half of the total weight of the stones.
{{< dots >}}
### Edge Cases 🌐
- If no stones are provided, the result is 0.
- The dynamic programming approach works within the problem's constraints of 30 stones and stone weights up to 100.
- If all stones have the same weight, the remaining stone weight will be the absolute difference between any two stones.
- The number of stones and their weights are guaranteed to be within the defined limits.
{{< dots >}}
## Code 💻
```cpp
int lastStoneWeightII(vector<int>& stones) {

    int sum = 0;
    for(int x: stones) sum += x;

    int n = stones.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, 0));

    for (int i = 1; i < n + 1  ; i++)
    for (int j = 0; j < sum / 2 + 1; j++) {
        if(j >= stones[i - 1]) 
             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
        else dp[i][j] = dp[i - 1][j];
    }

    return sum - 2 * dp[n][sum / 2];
}
```

This function solves the problem of the last stone weight after performing a series of stone collisions. It uses dynamic programming to compute the closest sum that can be achieved by dividing the stones into two groups.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int lastStoneWeightII(vector<int>& stones) {
	```
	Define the function 'lastStoneWeightII', which takes a vector of integers 'stones' as input and returns the final weight of the last stone after a series of collisions.

2. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	Initialize the variable 'sum' to 0, which will store the total sum of all stones.

3. **Summing Stones**
	```cpp
	    for(int x: stones) sum += x;
	```
	Loop through each stone in the 'stones' vector and add its value to 'sum'.

4. **Calculate Size**
	```cpp
	    int n = stones.size();
	```
	Determine the number of stones by calculating the size of the 'stones' vector and store it in 'n'.

5. **DP Table Initialization**
	```cpp
	    vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, 0));
	```
	Create a dynamic programming (DP) table 'dp' with dimensions (n + 1) x (sum / 2 + 1). Each cell will store the maximum sum achievable with a subset of the stones.

6. **Outer Loop Setup**
	```cpp
	    for (int i = 1; i < n + 1  ; i++)
	```
	Start a loop that iterates through each stone, from the first stone to the nth stone.

7. **Inner Loop Setup**
	```cpp
	    for (int j = 0; j < sum / 2 + 1; j++) {
	```
	Start a nested loop that iterates through possible weight values (from 0 to sum / 2). This loop considers all possible subsets of stones.

8. **Condition Check**
	```cpp
	        if(j >= stones[i - 1]) 
	```
	Check if the current weight 'j' is greater than or equal to the weight of the current stone. If it is, consider adding the stone to the current subset.

9. **DP Table Update**
	```cpp
	             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
	```
	Update the DP table by taking the maximum value between not including the current stone or including it, adding its weight to the existing sum.

10. **DP Table Update (Else Case)**
	```cpp
	        else dp[i][j] = dp[i - 1][j];
	```
	If the current stone's weight is larger than the current weight 'j', simply carry over the previous value from the DP table.

11. **Return Result**
	```cpp
	    return sum - 2 * dp[n][sum / 2];
	```
	Return the result, which is the difference between the total sum of stones and twice the value stored in dp[n][sum / 2]. This gives the minimum possible difference between the two groups of stones.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * sum)
- **Average Case:** O(n * sum)
- **Worst Case:** O(n * sum)

The time complexity is O(n * sum) where n is the number of stones and sum is the total sum of all stones. This is because we need to check all possible subset sums up to half of the total sum.

### Space Complexity 💾
- **Best Case:** O(sum)
- **Worst Case:** O(sum)

The space complexity is O(sum) due to the dynamic programming table used to store the possible subset sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/last-stone-weight-ii/description/)

---
{{< youtube gdXkkmzvR3c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
