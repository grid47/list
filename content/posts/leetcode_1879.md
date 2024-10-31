
+++
authors = ["Crafted by Me"]
title = "Leetcode 1879: Minimum XOR Sum of Two Arrays"
date = "2019-09-10"
description = "Solution to Leetcode 1879"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> n1, n2;
    
    int memo[15][(1 << 14) - 1];
    
    int dp(int idx, int mask) {
        if(idx == n1.size()) return 0;
        
        if(memo[idx][mask] != -1) return memo[idx][mask];
        int ans = INT_MAX;
        
        for(int i = 0; i < n1.size(); i++) {
            if((mask & (1 << i)) == 0) {
                ans = min(ans, (n1[idx] ^ n2[i]) + dp(idx + 1, mask + (1 << i)));
            }
        }
        
        return memo[idx][mask] = ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        
        memset(memo, -1, sizeof(memo));
        
        return dp(0, 0);
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

