
+++
authors = ["grid47"]
title = "Leetcode 2483: Minimum Penalty for a Shop"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2484: Count Palindromic Subsequences](https://grid47.xyz/posts/leetcode-2484-count-palindromic-subsequences-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}