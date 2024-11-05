
+++
authors = ["Crafted by Me"]
title = "Leetcode 1799: Maximize Score After N Operations"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1799: Maximize Score After N Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximize-score-after-n-operations/description/)

---

**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1799.md" >}}
---
{{< youtube W4ruG1rTKw0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1800: Maximum Ascending Subarray Sum](https://grid47.xyz/posts/leetcode_1800) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

