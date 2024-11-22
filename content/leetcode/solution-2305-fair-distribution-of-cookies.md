
+++
authors = ["grid47"]
title = "Leetcode 2305: Fair Distribution of Cookies"
date = "2024-03-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2305: Fair Distribution of Cookies in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "74-V6AjJ4wg"
youtube_upload_date="2022-06-12"
youtube_thumbnail="https://i.ytimg.com/vi/74-V6AjJ4wg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int k, ans = INT_MAX;
    vector<int> cook, dist;
    
    int dp(int idx) {
        if(idx == cook.size()) {            
            int sol = dist[0];
            for(int i = 0; i < k; i++) {
                sol = max(sol, dist[i]);
            }
            ans = min(ans, sol);
            return sol;
        }

        int ans = INT_MAX;
        for(int i = 0; i < k; i++) {
            dist[i] += cook[idx];
            ans = min(ans, dp(idx + 1));
            dist[i] -= cook[idx];
        }

        return ans;
    }
    
    int distributeCookies(vector<int>& cook, int k) {
        this->k = k;
        dist.resize(k, 0);
        this->cook = cook;
        dp(0);
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement
Given an array `cookies` where each element represents the number of cookies assigned to a person, and an integer `k` representing the number of people, the task is to distribute the cookies in a way that minimizes the maximum number of cookies assigned to any person. The objective is to return the minimum possible value of the maximum number of cookies that any person receives after distributing all the cookies.

### Approach
This problem is a classic example of load balancing, where we need to distribute items (cookies) to groups (people) such that the load (maximum cookies) is minimized. The approach to solve this problem efficiently is using a backtracking algorithm combined with dynamic programming (DP). This solution involves recursive exploration of all possible ways to distribute the cookies and keeping track of the optimal (minimal) maximum load.

### Key Observations:
1. **Base Case**: Once all cookies are distributed, calculate the maximum load (max of cookies distributed to any person).
2. **Recursive Exploration**: Distribute cookies recursively by trying to assign each cookie to each person. After distributing a cookie, move on to the next one and continue exploring the possibilities.
3. **Optimal Substructure**: The problem can be broken down into subproblems where each decision (distributing a cookie to a person) affects the result of subsequent decisions.

### Code Breakdown (Step by Step)

1. **Initialization**:
   - `k`: This stores the number of people.
   - `ans`: This variable keeps track of the minimum possible maximum cookies a person can receive. It starts with `INT_MAX` to ensure that any valid solution will be smaller.
   - `cook`: The array of cookies that need to be distributed.
   - `dist`: A vector that stores the current distribution of cookies among the `k` people.

2. **Recursive Function `dp(idx)`**:
   ```cpp
   int dp(int idx) {
       if(idx == cook.size()) {
           int sol = dist[0];
           for(int i = 0; i < k; i++) {
               sol = max(sol, dist[i]);
           }
           ans = min(ans, sol);
           return sol;
       }

       int ans = INT_MAX;
       for(int i = 0; i < k; i++) {
           dist[i] += cook[idx];
           ans = min(ans, dp(idx + 1));
           dist[i] -= cook[idx];
       }

       return ans;
   }
   ```
   - The function `dp(idx)` is called recursively, where `idx` represents the index of the cookie being distributed.
   - **Base Case**: If `idx == cook.size()`, it means all cookies have been distributed. Now, calculate the maximum load on any person and update the `ans` to the minimum of its current value and this calculated maximum.
   - **Recursive Case**: For each person (from 0 to `k-1`), assign the current cookie (`cook[idx]`) to that person, update the distribution (`dist`), and then recurse by calling `dp(idx + 1)`. After recursion, backtrack by undoing the change (`dist[i] -= cook[idx]`), which allows for exploring other possibilities of cookie distribution.

3. **Main Function `distributeCookies()`**:
   ```cpp
   int distributeCookies(vector<int>& cook, int k) {
       this->k = k;
       dist.resize(k, 0);
       this->cook = cook;
       dp(0);
       return ans;
   }
   ```
   - The `distributeCookies()` function is the main function that initializes the required parameters and calls the recursive `dp()` function to start the distribution from the first cookie (`idx = 0`).
   - It sets up the `dist` vector to store the current load on each person, initially all set to zero.
   - Finally, it returns the value of `ans`, which contains the minimum possible maximum cookies any person can receive after all cookies are distributed.

### Complexity

#### Time Complexity:
- The time complexity of this solution is exponential, specifically `O(k^n)`, where `n` is the number of cookies, and `k` is the number of people. This is because for each cookie (`n` cookies), we try assigning it to each of the `k` people. In the worst case, the algorithm explores all possible distributions of cookies.
- However, this solution benefits from pruning (through the recursive calls), which helps to minimize the search space and avoid redundant calculations.

#### Space Complexity:
- The space complexity is `O(k)`, where `k` is the number of people. This is because the `dist` array has `k` elements, and it is the main data structure used in the recursive function to keep track of the current distribution of cookies.

### Conclusion
This algorithm efficiently solves the problem of distributing cookies to minimize the maximum number of cookies assigned to any person by leveraging recursion and dynamic programming. While the time complexity is exponential due to the need to explore all possible cookie distributions, it is made efficient by carefully updating and backtracking the cookie assignments. This ensures that the solution is optimal for smaller problem sizes. For large inputs, further optimization techniques, such as memoization or dynamic programming, could be considered to reduce the computation time.

[`Link to LeetCode Lab`](https://leetcode.com/problems/fair-distribution-of-cookies/description/)

---
{{< youtube 74-V6AjJ4wg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
