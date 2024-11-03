
+++
authors = ["Crafted by Me"]
title = "Leetcode 2611: Mice and Cheese"
date = "2017-09-09"
description = "In-depth solution and explanation for Leetcode 2611: Mice and Cheese in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/mice-and-cheese/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        
        int n = r1.size();

        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            ans.push_back({r1[i] - r2[i], r1[i], r2[i]});
        }
        sort(ans.begin(), ans.end(), greater<vector<int>>());
        
        int res = 0, i = 0;
        while(k--) {
            res += ans[i++][1];
        }
        while(i < n) res += ans[i++][2];
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2612: Minimum Reverse Operations](https://grid47.xyz/posts/leetcode_2612) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

