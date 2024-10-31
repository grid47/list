
+++
authors = ["Crafted by Me"]
title = "Leetcode 2611: Mice and Cheese"
date = "2017-09-08"
description = "Solution to Leetcode 2611"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

