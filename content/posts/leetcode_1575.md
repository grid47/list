
+++
authors = ["Crafted by Me"]
title = "Leetcode 1575: Count All Possible Routes"
date = "2020-07-11"
description = "In-depth solution and explanation for Leetcode 1575: Count All Possible Routes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1575.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1576: Replace All ?'s to Avoid Consecutive Repeating Characters](https://grid47.xyz/posts/leetcode_1576) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

