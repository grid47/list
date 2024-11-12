
+++
authors = ["grid47"]
title = "Leetcode 1395: Count Number of Teams"
date = "2024-06-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1395: Count Number of Teams in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Binary Indexed Tree","Segment Tree"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1395.md" >}}
---
{{< youtube zONHzIqCr-o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1396: Design Underground System](https://grid47.xyz/posts/leetcode-1396-design-underground-system-solution/) |
| --- |
