
+++
authors = ["grid47"]
title = "Leetcode 983: Minimum Cost For Tickets"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 983: Minimum Cost For Tickets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "akXV67u1pTg"
youtube_upload_date="2023-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/akXV67u1pTg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {

        int d = days.back();
        vector<int>  dp(d + 1, 0);
        vector<bool> td(d + 1, false);

        for(int x : days) td[x] = true;

        for(int i = 1; i < d + 1; i++) {
            if(!td[i]) {
                dp[i] = dp[i - 1];
                continue;
            }
            
            dp[i] = dp[i - 1] + cost[0];
            dp[i] = min(dp[i], cost[1] + dp[max(i - 7, 0)]);
            dp[i] = min(dp[i], cost[2] + dp[max(i - 30, 0)]);            

        }

        return dp[d];
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine the minimum cost required to travel on specific days, where we are given a list of days when travel is required and the costs associated with different types of tickets. There are three types of tickets available:
1. A 1-day ticket which covers travel for a single day.
2. A 7-day ticket which covers travel for seven consecutive days.
3. A 30-day ticket which covers travel for thirty consecutive days.

Given these tickets, the goal is to determine the minimum cost to cover all the travel days in the given list.

### Approach

To solve this problem, we can use dynamic programming (DP). The basic idea is to compute the minimum cost of covering all travel days by considering the different ticket options available for each day and ensuring that we minimize the cost over the possible choices.

#### Key Insights:
1. **Dynamic Programming**:
   - We can define a `dp` array where `dp[i]` represents the minimum cost required to travel from day 1 to day `i`.
   - The main challenge is to choose which ticket to buy on each day to minimize the total cost.
   - For each day `i`, we can either:
     - Use a 1-day ticket, adding `cost[0]` to the cost of the previous day (`dp[i - 1]`).
     - Use a 7-day ticket, adding `cost[1]` to the cost of the day that is 7 days earlier (`dp[i - 7]`).
     - Use a 30-day ticket, adding `cost[2]` to the cost of the day that is 30 days earlier (`dp[i - 30]`).

2. **Using a Helper Array**:
   - To simplify the problem, we use an array `td` where `td[i]` is `true` if day `i` is a travel day (i.e., we need to travel on that day), and `false` otherwise.

3. **Base Case**:
   - We initialize `dp[0]` to `0` since no travel is needed on day 0.

#### Detailed Steps:
- First, we initialize the DP array and a boolean array `td` to mark the days when travel is needed.
- Then, we iterate through all days from 1 to `d` (where `d` is the last day in the list of travel days), and for each day, we compute the minimum cost of travel by considering all three ticket options.
- We use the `min` function to choose the least cost option at each step.
- Finally, after iterating through all days, `dp[d]` will contain the minimum cost to travel on all the required days.

### Code Breakdown (Step by Step)

#### 1. **Initialization**:
```cpp
int d = days.back();
vector<int> dp(d + 1, 0);
vector<bool> td(d + 1, false);
```
- We initialize the variable `d` to the last day in the `days` array, which gives the total number of days.
- We initialize a `dp` array of size `d + 1` to store the minimum costs. Each entry represents the minimum cost for covering all days up to that point.
- We also create a `td` array to mark which days are travel days.

#### 2. **Marking Travel Days**:
```cpp
for(int x : days) td[x] = true;
```
- This loop marks all the days in the `days` array as `true` in the `td` array, indicating that we need to travel on those days.

#### 3. **Filling the DP Array**:
```cpp
for(int i = 1; i < d + 1; i++) {
    if(!td[i]) {
        dp[i] = dp[i - 1];
        continue;
    }
    
    dp[i] = dp[i - 1] + cost[0];
    dp[i] = min(dp[i], cost[1] + dp[max(i - 7, 0)]);
    dp[i] = min(dp[i], cost[2] + dp[max(i - 30, 0)]);
}
```
- We iterate through all the days from 1 to `d` (inclusive).
- For each day `i`, if it is not a travel day (`!td[i]`), the cost is the same as the previous day (`dp[i] = dp[i - 1]`).
- If day `i` is a travel day, we compute the cost for each ticket option:
  - **1-day ticket**: We add the cost of the 1-day ticket (`cost[0]`) to the cost of the previous day (`dp[i - 1]`).
  - **7-day ticket**: We add the cost of the 7-day ticket (`cost[1]`) to the cost of the day 7 days before (`dp[max(i - 7, 0)]`).
  - **30-day ticket**: We add the cost of the 30-day ticket (`cost[2]`) to the cost of the day 30 days before (`dp[max(i - 30, 0)]`).
- After calculating the costs for all three ticket options, we pick the minimum value and update `dp[i]`.

#### 4. **Returning the Final Result**:
```cpp
return dp[d];
```
- After processing all the days, `dp[d]` contains the minimum cost to travel on all the required days, which is the final answer.

### Complexity

#### Time Complexity:
- **Initialization**: Initializing the `dp` and `td` arrays takes **O(d)** time, where `d` is the last day in the `days` array.
- **Filling the DP Array**: The loop iterates through all the days from 1 to `d`. For each day, we perform constant-time operations (checking travel days and updating `dp[i]`). Therefore, this step takes **O(d)** time.
- **Total Time Complexity**: The overall time complexity is **O(d)**.

#### Space Complexity:
- **DP Array**: The `dp` array has a size of `d + 1`, so it takes **O(d)** space.
- **TD Array**: The `td` array also has a size of `d + 1`, so it takes **O(d)** space.
- **Total Space Complexity**: The overall space complexity is **O(d)**.

### Conclusion

The `mincostTickets` function provides an optimal solution to the problem of determining the minimum cost to travel on specific days. By using dynamic programming, the solution efficiently computes the minimum cost by considering each type of ticket option and ensuring that the cost is minimized at each step. The time and space complexities are both linear, making this approach highly scalable for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-cost-for-tickets/description/)

---
{{< youtube akXV67u1pTg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
