
+++
authors = ["grid47"]
title = "Leetcode 2483: Minimum Penalty for a Shop"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2483: Minimum Penalty for a Shop in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-penalty-for-a-shop/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int bestClosingTime(string a) {
        int s = a.size();
        vector<int> y,n;
        y.push_back(0);
        n.push_back(0);
        int cnt = 0;
        for (int i = 0; i < s; i++) {
            if(a[i] == 'N') cnt++;
            n.push_back(cnt);
        }
        cnt = 0;
        for (int i = s -1; i >= 0; i--) {
            if(a[i] == 'Y') cnt++;
            y.push_back(cnt);
        }
        
        reverse (y.begin(), y.end());
        int ans = INT_MAX, ind = 0;
        for(int i = 0; i < s +1; i++) {
            int h = n[i] + y[i];
            if(h<ans) {
                ans = h;
                ind = i;
            }
        }
        return ind;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2483.md" >}}
---
{{< youtube 0d7ShRoOFVE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2485: Find the Pivot Integer](https://grid47.xyz/posts/leetcode-2485-find-the-pivot-integer-solution/) |
| --- |
