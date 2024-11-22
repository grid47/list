
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### 🚨 Problem Statement

In the "House Robber II" problem, you're a thief working in a neighborhood of houses arranged in a **circle**. Each house contains a certain amount of money, and your task is to determine the maximum amount of money you can rob, following these rules:

1. You **cannot rob two adjacent houses**.
2. Because the houses are arranged in a circle, robbing the **first and last house** together is not allowed.

Your goal is to figure out the best strategy to maximize the loot while respecting these constraints. 🏠💰

---

### 🧠 Approach

This problem can be solved by breaking it into two simpler subproblems: 

1. **Linear vs Circular:**  
   The classic "House Robber I" problem is solved using dynamic programming (DP) with a linear arrangement of houses. But here, since the houses are in a circle, we have an additional challenge: **the first and last houses are adjacent**. So, we need to approach it in two parts:
   - Rob houses excluding the first house.
   - Rob houses excluding the last house.

2. **Dynamic Programming (DP):**  
   In each case, we use dynamic programming to find the optimal solution. For each house `i`, the maximum amount of money you can rob is either:
   - Robbing house `i` (and adding the money from house `i-2`), or
   - Not robbing house `i` and taking the maximum money robbed from house `i-1`.

3. **Two DP Calculations:**  
   Since robbing both the first and last house isn't allowed, we calculate the optimal solution twice:
   - First, we calculate the maximum loot excluding the last house.
   - Second, we calculate it excluding the first house.
   We return the **maximum** of the two results to ensure we get the best possible outcome.

---

### 🔨 Step-by-Step Code Breakdown

Let’s walk through the solution code! 🤓

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();  // Get the number of houses
        if (n == 1) return nums[0];  // If there is only one house, return the value of that house
        
        vector<int> dp(n, 0);  // Initialize a DP array to store maximum robbed values
        
        // Step 1: Rob houses excluding the last house (from 0 to n-2)
        dp[0] = 0;  // Base case: no house to rob
        dp[1] = nums[0];  // Base case: only one house to rob
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        int r1 = dp[n - 1];  // Store the result of robbing houses from 0 to n-2
        
        // Step 2: Rob houses excluding the first house (from 1 to n-1)
        dp.resize(n + 1, 0);  // Resize the DP array for the second case
        dp[1] = 0;  // Base case: no house to rob
        dp[2] = nums[1];  // Base case: only one house to rob
        for (int i = 3; i < n + 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        
        return max(dp[n], r1);  // Return the maximum of the two cases
    }
};
```

---

### 📊 Complexity Analysis

Let’s break down the time and space complexities! 🧮

#### Time Complexity:
- **Building DP arrays:**
  - We process the list of houses twice:
    1. First pass: From house 1 to n-2 (this takes **O(n)**).
    2. Second pass: From house 2 to n-1 (this also takes **O(n)**).
- Thus, the **total time complexity** is **O(n)**, where `n` is the number of houses.

#### Space Complexity:
- We need space to store the `dp` array, which can have at most `n` elements.
- Hence, the **space complexity** is **O(n)**.

---

### 🎯 Conclusion

This approach efficiently solves the "House Robber II" problem by applying **dynamic programming**. By splitting the problem into two subproblems (excluding the first or excluding the last house), we avoid the tricky constraint of robbing two adjacent houses. 🏠💡

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

This solution ensures that we get the maximum loot while respecting all the given constraints. Now you're all set to tackle similar problems involving circular arrays or adjacent constraints! 🚀

---

### 🔑 Key Takeaways:
- Use dynamic programming to optimize decisions based on previous house robbing choices.
- Break the problem into two parts to account for the circular nature of the problem.
- By solving two linear DP problems and taking the maximum, we get the optimal solution!

Happy coding! 👨‍💻✨

[`Link to LeetCode Lab`](https://leetcode.com/problems/house-robber-ii/description/)

---
{{< youtube rWAJCfYYOvM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
