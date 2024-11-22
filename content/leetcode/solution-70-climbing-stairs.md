
+++
authors = ["grid47"]
title = "Leetcode 70: Climbing Stairs"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 70: Climbing Stairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Memoization"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/70.webp"
youtube = "I-R1XsECJu8"
youtube_upload_date="2024-06-01"
youtube_thumbnail="https://i.ytimg.com/vi/I-R1XsECJu8/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/70.webp" 
    alt="A glowing staircase with each step symbolizing progress, slowly leading upwards."
    caption="Solution to LeetCode 70: Climbing Stairs Problem"
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
    int climbStairs(int n) {
        vector<int> dp(n  + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n + 1; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n];
    }
};
{{< /highlight >}}
---

### 🪜 **Climbing Stairs**

The problem is to determine the number of distinct ways to climb a staircase with `n` steps, given that you can take either 1 or 2 steps at a time. For example, if there are 3 steps, you could reach the top by taking 1+1+1 steps, 1+2 steps, or 2+1 steps, which totals three distinct ways. This is a classic dynamic programming problem that builds on smaller solutions to form an efficient approach to counting all possible ways to reach the top.

### 🧠 **Approach**

We can solve this problem efficiently using dynamic programming (DP). The idea is to store the number of ways to reach each step in an array, where each entry is calculated as the sum of the previous two entries. This is because, to reach step `i`, you can either:
- Come from step `i-1` (by taking a single step), or
- Come from step `i-2` (by taking a double step).

#### Detailed Approach:

1. **Define a DP Array**: 
   - We initialize an array `dp` of size `n+1` to store the number of ways to reach each step.
   - `dp[i]` will hold the number of ways to reach the `i`-th step.

2. **Set Base Cases**:
   - `dp[0] = 1`: There is one way to stay at the starting point (step 0).
   - `dp[1] = 1`: There is only one way to reach the first step (by taking a single step).

3. **Fill the DP Array Using a Recurrence Relation**:
   - For each step `i` from 2 to `n`, calculate the number of ways to reach that step as `dp[i] = dp[i-1] + dp[i-2]`.
   - This recurrence is derived from the fact that you can reach step `i` either from `i-1` or `i-2`.

4. **Return the Result**: The final answer is stored in `dp[n]`, which gives the total number of ways to reach the `n`-th step.

### 💻 **Code Breakdown**

#### Step 1: Define the DP Array and Initialize Base Cases

```cpp
vector<int> dp(n + 1, 0);
dp[0] = 1;
dp[1] = 1;
```
- We create a `dp` array of size `n+1` with all elements initialized to 0.
- `dp[0] = 1` and `dp[1] = 1` are the base cases:
  - There's one way to stay at step 0 (no movement).
  - There's one way to reach step 1 (take a single step).

#### Step 2: Populate the DP Array Using the Recurrence Relation

```cpp
for(int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
}
```
- This loop starts from step `i = 2` and goes up to step `n`.
- For each step `i`, the number of ways to reach it is calculated by adding the number of ways to reach the previous step (`dp[i-1]`) and the step before that (`dp[i-2]`).

#### Step 3: Return the Result

```cpp
return dp[n];
```
- After populating the `dp` array, the function returns `dp[n]`, which holds the total number of ways to reach the `n`-th step.

### 📊 **Complexity Analysis**

#### Time Complexity:
- **O(n)**: The algorithm iterates through the steps from `2` to `n`, and each operation inside the loop takes constant time.

#### Space Complexity:
- **O(n)**: We use an array `dp` of size `n+1` to store the number of ways to reach each step, resulting in a space complexity of `O(n)`.

### 🌟 **Conclusion**

This dynamic programming solution efficiently solves the problem of counting the ways to climb a staircase with `n` steps, using only 1 or 2 steps at a time. By breaking the problem down into smaller sub-problems and storing intermediate results, the algorithm avoids redundant calculations, achieving optimal performance with linear time complexity. This approach is a great example of using dynamic programming to solve combinatorial problems that involve overlapping sub-problems.

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/climbing-stairs/description/)

---
{{< youtube I-R1XsECJu8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
