
+++
authors = ["grid47"]
title = "Leetcode 375: Guess Number Higher or Lower II"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 375: Guess Number Higher or Lower II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/375.webp"
youtube = "Gi-FQM3Ez84"
youtube_upload_date="2021-03-28"
youtube_thumbnail="https://i.ytimg.com/vi/Gi-FQM3Ez84/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/375.webp" 
    alt="Similar to the previous idea, but with multiple guesses and a progressively smaller range."
    caption="Solution to LeetCode 375: Guess Number Higher or Lower II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    vector<vector<int>> table;
public:
    int getMoneyAmount(int n) {
        table.resize(n + 1, vector<int>(n + 1));
        return dpf(table, 1, n);
    }

    int dpf(vector<vector<int>> &dp, int s, int e) {
        if(s >= e) return 0;
        if(dp[s][e] > 0) return dp[s][e];
        int res = INT_MAX;
        for(int x = s; x <= e; x++) {
            int tmp = (x + max(dpf(dp, s, x-1), dpf(dp, x + 1, e)));
            res = min(res, tmp);
        }
        return dp[s][e] = res;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

Imagine you're playing a guessing game where you need to determine the minimum cost to guess a number correctly within a given range `[1, n]`. Each guess has a cost, and the goal is to minimize the total cost in the worst-case scenario.

For every guess you make:
- If it's too high, you narrow the range to `[s, guess - 1]`.
- If it's too low, you narrow the range to `[guess + 1, e]`.

The challenge here is to make guesses efficiently so that you minimize the cost of reaching the correct number in the worst case.

---

### 🧠 Approach

This problem is best solved using **Dynamic Programming (DP)**, a technique where we break the problem into smaller subproblems and build up the solution step by step.

#### Key Insight 💡
We can visualize this problem as a decision tree. Each guess splits the current range into two smaller subranges:
1. One where the number is too high.
2. One where the number is too low.

The strategy is to minimize the **worst-case cost**. For each range `[s, e]`, we try every possible guess `x` and calculate the total cost, which is:
- The cost of guessing `x`, which is just `x` itself.
- Plus the maximum cost of the two subranges formed after the guess.

The goal is to choose the guess that minimizes the total cost in the worst-case scenario.

---

### 🔨 Step-by-Step Code Breakdown

Let’s walk through the code and break it down into bite-sized steps:

#### 1. **Initialization of the DP Table** 🛠️

```cpp
vector<vector<int>> table;
public:
int getMoneyAmount(int n) {
    table.resize(n + 1, vector<int>(n + 1)); // Initialize the DP table.
    return dpf(table, 1, n);  // Call the recursive function to solve the problem.
}
```

- We start by defining a table (`table`) to store the minimum cost for each subproblem (range `[s, e]`).
- The `getMoneyAmount` function initializes the table and then calls the `dpf` function to compute the result for the range `[1, n]`.

#### 2. **The Recursive DP Function** 🔄

```cpp
int dpf(vector<vector<int>> &dp, int s, int e) {
    if(s >= e) return 0;  // No cost for invalid or single-number ranges.
    if(dp[s][e] > 0) return dp[s][e];  // If the result is already computed, return it.
    
    int res = INT_MAX;  // Initialize the result to a very large value.
    
    for(int x = s; x <= e; x++) {
        int tmp = (x + max(dpf(dp, s, x-1), dpf(dp, x + 1, e)));
        res = min(res, tmp);  // Minimize the worst-case cost.
    }
    
    return dp[s][e] = res;  // Store the result in the DP table.
}
```

- The `dpf` function is where the magic happens. It computes the minimum cost to guess a number within a given range `[s, e]`.
- If the range is invalid (`s >= e`), the cost is zero (no guesses needed).
- If we’ve already computed the cost for the range `[s, e]`, we return it (memoization).
- We then iterate through all possible guesses `x` and calculate the cost for each guess.
- The result is stored in the DP table to avoid recalculating the same subproblem multiple times.

#### 3. **Main Function** 🏁

```cpp
int getMoneyAmount(int n) {
    table.resize(n + 1, vector<int>(n + 1));  // Initialize the DP table.
    return dpf(table, 1, n);  // Compute and return the result.
}
```

- The `getMoneyAmount` function initializes the DP table and calls `dpf` to compute the minimum cost to guess a number within the range `[1, n]`.

---

### 📈 Complexity Analysis

#### Time Complexity ⏱️
- The time complexity is **O(n³)**. This comes from the fact that we compute the result for every pair of subproblems `[s, e]` (which gives us `O(n²)` subproblems), and for each subproblem, we try every possible guess `x` (which gives us `O(n)` iterations per subproblem).
- Thus, the overall time complexity is **O(n³)**.

#### Space Complexity 💾
- The space complexity is **O(n²)**, as we store the results for each subproblem in a DP table of size `(n+1) x (n+1)`.

---

### 🏁 Conclusion

This dynamic programming solution is an efficient way to solve the problem of determining the minimum cost to guess a number correctly. By breaking the problem into smaller subproblems and using memoization, we avoid redundant calculations and can solve even moderately large inputs.

Although the time complexity is cubic, it’s still feasible for a range of sizes that are typically encountered in competitive programming or real-world applications.

Remember: This approach ensures that we always choose the best possible guess at each step, minimizing the worst-case cost.

Keep practicing, and you’ll soon feel comfortable with dynamic programming problems like this one! 🌟

[`Link to LeetCode Lab`](https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/)

---
{{< youtube Gi-FQM3Ez84 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
