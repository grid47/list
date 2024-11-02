
+++
authors = ["Crafted by Me"]
title = "Leetcode 2101: Detonate the Maximum Bombs"
date = "2018-01-31"
description = "Solution to Leetcode 2101"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/detonate-the-maximum-bombs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    #define ll long long int
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> gph(n);
        for(int i = 0; i < n; i++) {

            ll x1 = bombs[i][0];
            ll y1 = bombs[i][1];
            ll r1 = bombs[i][2];

            for(int j = 0; j < n; j++) {
                if(i != j) {
                    ll x2 = abs(x1 - bombs[j][0]);
                    ll y2 = abs(y1 - bombs[j][1]);
                    if(x2 * x2 + y2 * y2 <= r1 * r1) {
                        gph[i].push_back(j);
                    }
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int c = 0;
            vector<bool> vistd(n, false);
            dfs(gph, vistd, c, i);
            ans = max(ans, c);
        }
        return ans;
    }

    void dfs(vector<vector<int>> &gph, vector<bool> &vstd, int &c, int i) {
        if(vstd[i]) return;
        vstd[i] = true;
        c++;
        for(int j: gph[i])
            if(!vstd[j])
            dfs(gph, vstd, c, j);
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

