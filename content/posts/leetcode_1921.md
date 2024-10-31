
+++
authors = ["Crafted by Me"]
title = "Leetcode 1921: Eliminate Maximum Number of Monsters"
date = "2019-07-30"
description = "Solution to Leetcode 1921"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

        int n = dist.size();
        vector<double> res(n, 0);
        for(int i = 0; i < n; i++)
        res[i] = (double(dist[i]) / speed[i]);

        sort(res.begin(), res.end());

        long j = 0, ans = 0;
        for (int i = 0; i < n; i++)
            if(j < res[i]) {
                ans++;
                j++;
            } else break;

        return (int) ans;
    }
};
{{< /highlight >}}


---
{{< youtube 6QQRayzOTD4 >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

