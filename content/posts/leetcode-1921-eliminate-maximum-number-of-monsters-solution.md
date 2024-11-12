
+++
authors = ["grid47"]
title = "Leetcode 1921: Eliminate Maximum Number of Monsters"
date = "2024-04-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1921: Eliminate Maximum Number of Monsters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1925: Count Square Sum Triples](https://grid47.xyz/posts/leetcode-1925-count-square-sum-triples-solution/) |
| --- |
