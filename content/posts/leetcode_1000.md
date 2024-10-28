
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1000: Minimum Cost to Merge Stones"
date = "2022-02-02"
description = "Solution to Leetcode 1000"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-to-merge-stones/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> prefix;
    int k;
    long memo[101][101][31];
    
    long dp(int i, int j, int m) {
        if((j - i + 1 - m) % (k - 1))
            return INT_MAX;
        else if(i == j) {
            if(m == 1) {
                return 0;
            } else {
                return INT_MAX;
            }
        }
        if(memo[i][j][m] != -1) return memo[i][j][m];
        if(m == 1)
            return dp(i, j, k) + prefix[j + 1] - prefix[i];
        
        long ans = INT_MAX;
        for(int p = i; p < j; p += k - 1) {
            ans = min(ans, dp(i, p, 1) + dp(p + 1, j, m - 1));
        }
        return memo[i][j][m] = ans;
    }
    
    int mergeStones(vector<int>& stones, int k) {
        this->k = k;
        int n = stones.size();
        prefix.resize(n + 1, 0);
        for(int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];
        
        memset(memo, -1, sizeof(memo));
        int ans = dp(0, n - 1, 1);
        
        return ans >= INT_MAX? -1: ans;
        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

