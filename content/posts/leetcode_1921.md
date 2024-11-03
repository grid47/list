
+++
authors = ["Crafted by Me"]
title = "Leetcode 1921: Eliminate Maximum Number of Monsters"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1921: Eliminate Maximum Number of Monsters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1921.md" >}}
---
{{< youtube 6QQRayzOTD4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1922: Count Good Numbers](https://grid47.xyz/posts/leetcode_1922) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

