
+++
authors = ["grid47"]
title = "Leetcode 198: House Robber"
date = "2024-10-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 198: House Robber in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/198.webp"
youtube = "UVNgW5nSoiU"
youtube_upload_date="2023-06-20"
youtube_thumbnail="https://i.ytimg.com/vi/UVNgW5nSoiU/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/198.webp" 
    alt="A series of houses softly glowing, with the optimal path for robbing illuminating."
    caption="Solution to LeetCode 198: House Robber Problem"
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
    int rob(vector<int>& a) {
        int n = a.size();
        if(n == 1) return a[0];
        vector<int> dp(n,0);
        dp[0] = a[0];
        dp[1] = max(a[0], a[1]);
        for(int i = 2; i < n; i++)
            dp[i] = max(dp[i-2]+a[i], dp[i-1]);
        return dp[n-1];
    }
};
{{< /highlight >}}
---

### 🌟 House Robber Problem (Dynamic Programming)

The problem at hand is a classic dynamic programming problem known as the **House Robber** problem. Given a list of non-negative integers representing the amount of money stored in each house, the goal is to determine the maximum amount of money you can rob tonight without alerting the police. The catch is that you cannot rob two adjacent houses on the same night.

#### Example:
- **Input:** `a = [2, 7, 9, 3, 1]`
- **Output:** `12` (Rob the first, third, and fifth house for a total of 12).

### 💡 Approach

We solve this problem using **dynamic programming** by deciding for each house whether to rob it or skip it. The decision at each house depends on the maximum amount we can rob up to that point, considering whether we rob the current house or skip it.

**State Definition:**
- Let `dp[i]` represent the maximum amount of money that can be robbed from the first `i` houses (i.e., from house `0` to house `i`).

**Recurrence Relation:**
- If we rob the `i`-th house, we cannot rob the `(i-1)`-th house, but we can take the money from the `(i-2)`-th house. Therefore, the value will be `dp[i-2] + a[i]`.
- If we skip the `i`-th house, we take the value of `dp[i-1]`.
- Thus, the recurrence relation is:
  \[
  dp[i] = \max(dp[i-1], dp[i-2] + a[i])
  \]
- Base cases:
  - `dp[0] = a[0]`: If there is only one house, we rob it.
  - `dp[1] = max(a[0], a[1])`: If there are two houses, we rob the one with the higher amount of money.

### 🛠 Code Breakdown

#### Step 1: Handle Small Input Sizes
```cpp
if (n == 1) return a[0];
```
- If there is only one house, we can rob it, so we return the value in `a[0]`.

#### Step 2: Initialize the DP Array
```cpp
vector<int> dp(n, 0);
```
- We initialize a vector `dp` of size `n` (the number of houses) to store the maximum money that can be robbed up to each house.

#### Step 3: Set Base Cases
```cpp
dp[0] = a[0];
dp[1] = max(a[0], a[1]);
```
- For the first house (`dp[0]`), the maximum money we can rob is `a[0]`.
- For the second house (`dp[1]`), we choose the house with the higher amount of money: `max(a[0], a[1])`.

#### Step 4: Fill the DP Array for All Other Houses
```cpp
for (int i = 2; i < n; i++)
    dp[i] = max(dp[i-2] + a[i], dp[i-1]);
```
- For each house from the third onward, we update `dp[i]` by choosing the maximum between:
  - Robbing the current house (`dp[i-2] + a[i]`), or
  - Skipping the current house and taking the value of `dp[i-1]`.

#### Step 5: Return the Final Result
```cpp
return dp[n-1];
```
- The final value `dp[n-1]` contains the maximum money that can be robbed, considering all the houses.

### 📊 Complexity Analysis

#### Time Complexity:
- **O(n):** We iterate through the list of houses once, performing constant-time operations for each house (calculating the maximum between two values). Thus, the time complexity is linear in the number of houses, i.e., **O(n)**.

#### Space Complexity:
- **O(n):** We use a dynamic programming array `dp` of size `n` to store intermediate results. Therefore, the space complexity is proportional to the number of houses, i.e., **O(n)**.

### 🚀 Space Complexity Optimization

We can reduce the space complexity to **O(1)** by keeping track of only the last two values in the `dp` array. This is because each state (`dp[i]`) only depends on the previous two states (`dp[i-1]` and `dp[i-2]`).

#### Optimized Code:

```cpp
int rob(vector<int>& a) {
    int n = a.size();
    if (n == 1) return a[0];

    int prev2 = a[0], prev1 = max(a[0], a[1]);
    for (int i = 2; i < n; i++) {
        int current = max(prev2 + a[i], prev1);
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
```
In this optimized version:
- We use two variables, `prev1` and `prev2`, to store the results of the last two houses.
- This reduces the space complexity to **O(1)**, while still maintaining the same time complexity of **O(n)**.

### ✅ Conclusion

The **House Robber** problem is efficiently solved using dynamic programming. The key idea is to make decisions based on previous choices, and the solution can be optimized to use constant space. Here's a recap:

- **Time Complexity:** **O(n)**, where `n` is the number of houses.
- **Space Complexity:** **O(1)** after optimization.

This solution is not only optimal in terms of time and space but also applicable to similar problems that require making decisions based on previous states.

[`Link to LeetCode Lab`](https://leetcode.com/problems/house-robber/description/)

---
{{< youtube UVNgW5nSoiU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
