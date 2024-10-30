
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 960: Delete Columns to Make Sorted III"
date = "2022-03-16"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

