
+++
authors = ["Crafted by Me"]
title = "Leetcode 1690: Stone Game VII"
date = "2019-03-18"
description = "Solution to Leetcode 1690"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-vii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int memo[1001][1001] = {};
    int dp(vector<int>& s, int i, int j, int sum) {
        
        if(i == j) {
            return 0;
        }
        
        
        return memo[i][j] ? memo[i][j] : memo[i][j] = max(sum - s[i] - dp(s, i + 1, j, sum - s[i]),
                                            sum - s[j] - dp(s, i, j - 1, sum - s[j]));
    }
    
    int stoneGameVII(vector<int>& s) {
        int n = s.size();
        return dp(s, 0,n-1, accumulate(begin(s), end(s), 0));
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

