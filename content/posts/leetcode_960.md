
+++
authors = ["Crafted by Me"]
title = "Leetcode 960: Delete Columns to Make Sorted III"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 960: Delete Columns to Make Sorted III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/delete-columns-to-make-sorted-iii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> strs;
    int memo[101][105], cmem[101][105];    
    bool check(int idx, int prv) {
        if(cmem[idx][prv] != -1) return cmem[idx][prv];
        for(int i = 0; i < strs.size(); i++) {
            if(strs[i][idx] < strs[i][prv])
                return cmem[idx][prv] = false;
        }
        return cmem[idx][prv] = true;
    }

    int dp(int idx, int prv) {
        if(idx == strs[0].size()) return 0;
        
        if(memo[idx][prv + 1] != -1) return memo[idx][prv + 1];
        
        int ans = dp(idx + 1, prv);
        
        if(prv == -1 || check(idx, prv)) {
            ans = max(ans, dp(idx + 1, idx) + 1);
        }
        
        return memo[idx][prv + 1] = ans;
    }
    
    int minDeletionSize(vector<string>& strs) {
        this->strs = strs;
        memset(memo, -1, sizeof(memo));
        memset(cmem, -1, sizeof(cmem));
        return strs[0].size() - dp(0, -1);
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/960.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #961: N-Repeated Element in Size 2N Array](https://grid47.xyz/posts/leetcode_961) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

