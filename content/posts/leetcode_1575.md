
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1575: Count All Possible Routes"
date = "2020-07-07"
description = "Solution to Leetcode 1575"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-all-possible-routes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int n, mod = (int) 1e9 + 7;
    vector<vector<int>> mem;
    vector<int> loc;
    int countRoutes(vector<int>& loc, int start, int finish, int fuel) {
        n = loc.size();
        this->loc = loc;
        mem.resize(n, vector<int>(fuel + 1, -1));
        return dfs(start, finish, fuel);
    }
    
    int dfs(int st, int ed, int rm) {
        if(rm < 0) return 0;

        if(mem[st][rm] != -1) return mem[st][rm];

        long ans = (st == ed);
        for(int i = 0; i < n ; i++) {
            if(i != st)
            ans = (ans + dfs(i, ed, rm - abs(loc[i] - loc[st]))) % mod;
        }

        return mem[st][rm] = ans;
    }
    
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

