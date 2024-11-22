
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> dp(n + 1, 0);
        
        for(int i = 2; i <= n; i++)
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        
        return dp[n];
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given an array `cost` of length `n` where `cost[i]` represents the cost to step on the `i`-th stair. You are tasked with finding the minimum cost to reach the top of the staircase. However, you are allowed to take a step either from stair `i` to stair `i+1` or from stair `i` to stair `i+2`.

The goal is to compute the minimum cost needed to reach the top of the staircase, either by starting from stair 0 or stair 1.

### Example

#### Example 1:
Input: 
```cpp
cost = [10, 15, 20]
```
Output: 
```cpp
15
```
Explanation: The optimal way is to start at stair 1, and then jump to stair 3 (which is the top). The cost is `15`.

#### Example 2:
Input: 
```cpp
cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
```
Output: 
```cpp
6
```
Explanation: The optimal way is to start at stair 0, then jump to stair 2, then to stair 3, and so on, with a minimum cost of `6`.

### Approach

This problem is a classic example of dynamic programming. The idea is to compute the minimum cost of reaching each stair by considering the minimum cost of the two possible ways to get there: either from the previous stair or the stair before that.

The dynamic programming approach can be broken down into the following steps:
1. **Define a DP Array:** We define a `dp` array where `dp[i]` represents the minimum cost to reach stair `i`.
2. **Base Case:** The base case would be the cost of reaching stair 0 or stair 1, which are both initialized to 0 because no step has been made yet.
3. **Recurrence Relation:** The cost of reaching stair `i` can either be from stair `i-1` or stair `i-2`. The formula for computing the minimum cost to reach stair `i` is:
   - `dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])`
4. **Compute Final Result:** Once all the stairs are processed, the final answer will be stored in `dp[n]`, representing the minimum cost to reach the top of the staircase.

### Code Breakdown (Step by Step)

Let's break down the code for a deeper understanding:

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();  // Get the size of the cost array
        
        vector<int> dp(n + 1, 0);  // Create a dp array to store minimum cost to reach each stair

        // Starting from the third stair, we calculate the minimum cost to reach each stair
        for(int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);  // Recurrence relation
        }

        // Return the minimum cost to reach the top of the stairs (either from the last or second-last stair)
        return dp[n];
    }
};
```

#### Step 1: Initialize the DP Array
The array `dp` is initialized with size `n + 1` (to account for the "top" step, which doesn't exist in the cost array but is the destination). Each element of `dp` is initially set to 0.

```cpp
vector<int> dp(n + 1, 0);  // dp[i] will store the minimum cost to reach the i-th stair
```

#### Step 2: Iterate Through the Stairs
We begin the iteration from `i = 2` since the first two steps can be reached without any previous steps, and the first base case is handled implicitly in the initialization of `dp`.

```cpp
for(int i = 2; i <= n; i++) {
    dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
}
```
- For each stair `i`, we compute the minimum cost to reach that stair from either the previous stair (`i-1`) or the stair before it (`i-2`).
- The cost to reach stair `i` from stair `i-1` is `dp[i-1] + cost[i-1]`, while the cost to reach stair `i` from stair `i-2` is `dp[i-2] + cost[i-2]`.
- We take the minimum of these two values and update `dp[i]`.

#### Step 3: Return the Final Result
Once the loop has processed all the stairs, `dp[n]` will contain the minimum cost to reach the top of the staircase.

```cpp
return dp[n];  // Return the minimum cost to reach the top of the stairs
```

### Complexity

#### Time Complexity:
- **O(n)**: We only need a single pass through the `cost` array to fill the `dp` array, which takes linear time. Thus, the time complexity is **O(n)**.

#### Space Complexity:
- **O(n)**: We use an array `dp` of size `n + 1` to store the minimum costs, so the space complexity is **O(n)**.

### Conclusion

This solution efficiently solves the problem of finding the minimum cost to reach the top of the staircase using dynamic programming. By breaking the problem down into smaller subproblems and storing the results, we avoid redundant calculations and achieve an optimal solution with time complexity O(n) and space complexity O(n).

The approach ensures that we calculate the minimum cost to reach each stair step by step, considering the two possible ways to reach each stair. This technique works efficiently even for larger input sizes and provides the correct result with minimal computational overhead.

This solution provides a clear example of how dynamic programming can simplify problems involving optimization, where you need to compute the minimum or maximum of a series of related values.

[`Link to LeetCode Lab`](https://leetcode.com/problems/min-cost-climbing-stairs/description/)

---
{{< youtube fPnQWeFlBCU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
