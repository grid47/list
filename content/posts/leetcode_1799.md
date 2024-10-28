
+++
authors = ["Yasir"]
title = "Leetcode 1799: Maximize Score After N Operations"
date = "2019-11-26"
description = "Solution to Leetcode 1799"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximize-score-after-n-operations/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int n;
    vector<int> nums;
    int memo[8][20000] = {};
    
    int dp(int idx, int msk) {
        if(idx == n) return 0;
        
        if(memo[idx][msk] != -1) return memo[idx][msk];
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(((msk >> i) & 1) == 1) continue;
            for(int j = 0; j < nums.size(); j++) {
                if(i == j) continue;
                if(((msk >> j) & 1) == 1) continue;
                msk ^= (1 << i);
                msk ^= (1 << j);
                ans = max(ans, (idx + 1) * __gcd(nums[i], nums[j]) + dp(idx + 1, msk));
                msk ^= (1 << i);
                msk ^= (1 << j);                
            }
        }
        return memo[idx][msk] = ans;
    }
    
    int maxScore(vector<int>& nums) {

        n = nums.size() / 2;
        this->nums = nums;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

