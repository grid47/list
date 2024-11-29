
+++
authors = ["grid47"]
title = "Leetcode 746: Min Cost Climbing Stairs"
date = "2024-08-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 746: Min Cost Climbing Stairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/746.webp"
youtube = "fPnQWeFlBCU"
youtube_upload_date="2024-06-02"
youtube_thumbnail="https://i.ytimg.com/vi/fPnQWeFlBCU/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/746.webp" 
    alt="A staircase where the minimum cost to climb is calculated, with each step glowing softly as it is taken."
    caption="Solution to LeetCode 746: Min Cost Climbing Stairs Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are climbing a staircase with a cost associated with each step. You can either start at the first or second step. At each step, you can either move one step or skip one step. Find the minimum cost to reach the top of the staircase.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `cost`, where `cost[i]` is the cost of the ith step.
- **Example:** `cost = [5, 10, 15, 20]`
- **Constraints:**
	- 2 <= cost.length <= 1000
	- 0 <= cost[i] <= 999

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum cost to reach the top of the staircase.
- **Example:** `For cost = [5, 10, 15, 20], the output is 15.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To minimize the cost, choose whether to move one step or skip one step depending on the given costs.

- Use dynamic programming to calculate the minimum cost of reaching each step.
- For each step, you can either come from the previous step or skip one step, and choose the minimum cost.
{{< dots >}}
### Problem Assumptions ✅
- There will always be at least two steps in the staircase.
{{< dots >}}
## Examples 🧩
- **Input:** `For cost = [5, 10, 15, 20]`  \
  **Explanation:** Starting at step 1 with cost 10, and skipping to step 3 with cost 15. Total cost: 10 + 15 = 15.

- **Input:** `For cost = [1, 20, 10, 5, 30, 10]`  \
  **Explanation:** Starting at step 0 with cost 1, skipping steps, and reaching the top with a total cost of 16.

{{< dots >}}
## Approach 🚀
Use dynamic programming to calculate the minimum cost of reaching each step by considering the previous step and the step before it.

### Initial Thoughts 💭
- The problem is similar to the Fibonacci sequence but with costs associated with each step.
- Dynamic programming allows us to break down the problem and calculate the optimal cost to reach the top step.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that `cost.length` will be at least 2, so empty inputs are not possible.
- The solution should efficiently handle input sizes up to 1000 steps.
- If all costs are the same, the minimum cost will be the same regardless of the steps taken.
- The solution should work within the provided constraints for both time and space efficiency.
{{< dots >}}
## Code 💻
```cpp
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    
    vector<int> dp(n + 1, 0);
    
    for(int i = 2; i <= n; i++)
    dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    
    return dp[n];
}
```

This function calculates the minimum cost to reach the top of the staircase, where each step has a given cost. It uses dynamic programming to find the optimal solution.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minCostClimbingStairs(vector<int>& cost) {
	```
	This line defines the function minCostClimbingStairs that takes a vector of integers (cost) as input and returns an integer representing the minimum cost to reach the top.

2. **Variable Initialization**
	```cpp
	    int n = cost.size();
	```
	The variable 'n' is initialized to the size of the 'cost' vector, representing the number of steps in the staircase.

3. **DP Array Initialization**
	```cpp
	    vector<int> dp(n + 1, 0);
	```
	Initialize a dynamic programming (DP) array 'dp' of size n+1, with all elements set to 0. This array will store the minimum cost to reach each step.

4. **For Loop**
	```cpp
	    for(int i = 2; i <= n; i++)
	```
	Start of the for loop, which iterates from step 2 to step n, calculating the minimum cost for each step.

5. **DP Update**
	```cpp
	    dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
	```
	At each step, the cost to reach step 'i' is calculated by taking the minimum of the cost to reach step 'i-1' and step 'i-2' plus the respective step costs from the 'cost' array.

6. **Return Statement**
	```cpp
	    return dp[n];
	```
	Return the minimum cost to reach the top of the staircase, which is stored in dp[n].

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the `cost` array.
- **Average Case:** O(n), where n is the length of the `cost` array.
- **Worst Case:** O(n), where n is the length of the `cost` array.

The time complexity is O(n) because we iterate over the `cost` array once.

### Space Complexity 💾
- **Best Case:** O(n), the space complexity remains the same for all cases.
- **Worst Case:** O(n), because we use an array `dp` to store the minimum cost at each step.

The space complexity is O(n) because we need an additional array to store the minimum costs.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/min-cost-climbing-stairs/description/)

---
{{< youtube fPnQWeFlBCU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
