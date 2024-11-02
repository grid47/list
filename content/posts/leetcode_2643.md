
+++
authors = ["Crafted by Me"]
title = "Leetcode 2643: Row With Maximum Ones"
date = "2016-08-07"
description = "Solution to Leetcode 2643"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/row-with-maximum-ones/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int mx = 0, idx = 0;
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++)
                if(mat[i][j]) cnt++;
            if(cnt > mx) {
                idx = i;
                mx = cnt;
            }
        }
        return vector<int>{idx, mx};
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

