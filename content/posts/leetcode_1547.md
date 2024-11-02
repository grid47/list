
+++
authors = ["Crafted by Me"]
title = "Leetcode 1547: Minimum Cost to Cut a Stick"
date = "2019-08-08"
description = "Solution to Leetcode 1547"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> cut;
    int dp[102][102] = {};
    
    int func(int i, int j) {
        
        if(j - i <= 1) return 0; // There are no cut in between, so no expence;
        
        if(!dp[i][j]) {
            dp[i][j] = INT_MAX;
            for(int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], cut[j] - cut[i] + func(i, k) + func(k, j));
            }
        }
        return dp[i][j];
        
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        
        
        sort(cuts.begin(), cuts.end());

        cut = cuts;
        return func(0, cuts.size() - 1);
        
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

