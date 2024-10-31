
+++
authors = ["Crafted by Me"]
title = "Leetcode 436: Find Right Interval"
date = "2023-08-23"
description = "Solution to Leetcode 436"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-right-interval/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& iv) {
        map<int, int> mk;
        
        int n = iv.size();
        for(int i = 0; i < n; i++)
            mk[iv[i][0]] = i;
        
        vector<int> ans(n, -1);
        for(int j = 0; j < n; j++) {
            auto i= iv[j];
            if(mk.lower_bound(i[1]) != end(mk))
                ans[j] = mk.lower_bound(i[1])->second;
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/436.md" >}}
---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

