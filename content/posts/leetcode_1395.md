
+++
authors = ["Crafted by Me"]
title = "Leetcode 1395: Count Number of Teams"
date = "2020-01-07"
description = "Solution to Leetcode 1395"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-teams/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int memo[1001][1001][4];
    vector<int> rate;
    
    int dp(int idx, int prv, int cnt) {
        if(cnt == 3) return 1;
        if(idx == rate.size()) return 0;
        if(memo[idx][prv + 1][cnt] != -1) return memo[idx][prv + 1][cnt];
        int ans = 0;
        if(prv == -1 || rate[idx] > rate[prv]) {
            ans += dp(idx + 1, idx, cnt + 1);
        }
        ans += dp(idx + 1, prv, cnt);
        
        return memo[idx][prv + 1][cnt] = ans;
    }

    int numTeams(vector<int>& rate) {
        this->rate = rate;
        memset(memo, -1, sizeof(memo));
        int res1 = dp(0, -1, 0);

        reverse(this->rate.begin(),this->rate.end());

        memset(memo, -1, sizeof(memo));        
        int res2 = dp(0, -1, 0);

        return res1 + res2;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

