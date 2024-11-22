
+++
authors = ["grid47"]
title = "Leetcode 279: Perfect Squares"
date = "2024-10-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 279: Perfect Squares in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/279.webp"
youtube = "HLZLwjzIVGo"
youtube_upload_date="2021-05-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HLZLwjzIVGo/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/279.webp" 
    alt="A series of glowing squares being formed from numbers, each square glowing brighter as it becomes perfect."
    caption="Solution to LeetCode 279: Perfect Squares Problem"
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
    int numSquares(int n) {
        vector<long> cnt(n + 1, INT_MAX);

        cnt[0] = 0;

        for(int i = 1; i <= n; i++)
        for(int j = 1; j * j <= i; j++)
            cnt[i] = min(cnt[i], cnt[i - j * j] + 1);

        return cnt[n];

    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

You're tasked with finding the **least number of perfect squares** that sum up to a given number `n`. A **perfect square** is an integer that is the square of another integer. For example, the numbers `1`, `4`, `9`, `16`, `25`, and so on are perfect squares.

Your goal is to determine the minimum number of these perfect squares that add up to `n`. Let's see a couple of examples:
- If `n = 12`, the least number of perfect squares that sum up to `12` is `3`, because `12 = 4 + 4 + 4`.
- If `n = 13`, the least number of perfect squares that sum up to `13` is `2`, because `13 = 9 + 4`.

This is a classic **dynamic programming problem** where we break down the problem into smaller subproblems and use the results of these subproblems to build up to the final solution. Let's dive into how we can approach this!

---

### 🧠 Approach

To tackle this problem, we'll use **dynamic programming (DP)**. The core idea is to build a solution incrementally, solving smaller subproblems and using those solutions to solve the overall problem.

We maintain an array `cnt` where `cnt[i]` will store the minimum number of perfect squares required to sum up to `i`. By considering all perfect squares smaller than or equal to `i`, we can iteratively fill out this array.

---

### 🔨 Step-by-Step Code Breakdown

#### Step 1: Initialize the `cnt` Array
```cpp
vector<long> cnt(n + 1, INT_MAX);
cnt[0] = 0;
```
- We start by creating a `cnt` array of size `n + 1` and initialize it to `INT_MAX` (which represents infinity) because initially, we don't know how to sum up to any number other than `0`.
- We know that no perfect square is needed to sum up to `0`, so `cnt[0] = 0`.

#### Step 2: Iterate Through All Numbers from `1` to `n`
```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j * j <= i; j++) {
        cnt[i] = min(cnt[i], cnt[i - j * j] + 1);
    }
}
```
- Now, we loop through each number `i` from `1` to `n` (outer loop).
- For each number `i`, we check all perfect squares `j * j` that are smaller than or equal to `i` (inner loop).
- We then update `cnt[i]` by comparing its current value with the result of subtracting a square (`cnt[i - j * j]`) and adding `1`. This means we’re considering the square `j * j` and finding the best result for the remaining sum (`i - j * j`).

#### Step 3: Return the Result for `n`
```cpp
return cnt[n];
```
- After completing the iteration, the value `cnt[n]` will contain the minimum number of perfect squares that sum up to `n`.

---

### 📈 Complexity Analysis

#### Time Complexity:
- The outer loop runs from `1` to `n`, so it executes `n` iterations.
- The inner loop iterates over all perfect squares less than or equal to `i`. For each `i`, the number of perfect squares less than or equal to `i` is approximately `sqrt(i)`. So, the inner loop runs at most `O(sqrt(i))` times.
- The time complexity is then the sum of `sqrt(i)` for `i` from `1` to `n`, which can be approximated as **O(n * sqrt(n))**.

#### Space Complexity:
- The space complexity is **O(n)** because we store the minimum number of perfect squares for each number up to `n` in the `cnt` array.

---

### 🏁 Conclusion

This dynamic programming approach is a highly efficient method for solving the problem of finding the least number of perfect squares that sum up to a given number `n`. By breaking down the problem into smaller subproblems, we can solve it iteratively and store intermediate results for later use.

#### Key Points:
- **Time-efficient**: With a time complexity of **O(n * sqrt(n))**, this solution scales well for moderately large values of `n`.
- **Space-efficient**: The space complexity of **O(n)** is manageable and doesn’t require too much memory.

This approach ensures that we can compute the result optimally and handle large inputs effectively. So, whether you're solving coding challenges or just improving your dynamic programming skills, this method is a great example of how to use DP to solve problems efficiently!

---

### 🎯 Takeaway

Dynamic programming is a powerful technique for breaking down complex problems into smaller, manageable pieces. By using the `cnt` array to store intermediate results, we avoid redundant calculations and achieve an optimal solution. Keep practicing, and soon you’ll be solving dynamic programming problems like a pro! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/perfect-squares/description/)

---
{{< youtube HLZLwjzIVGo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
