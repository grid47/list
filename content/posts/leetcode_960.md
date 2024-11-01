
+++
authors = ["Crafted by Me"]
title = "Leetcode 960: Delete Columns to Make Sorted III"
date = "2022-03-18"
description = "Solution to Leetcode 960"
tags = [
    
]
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
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

