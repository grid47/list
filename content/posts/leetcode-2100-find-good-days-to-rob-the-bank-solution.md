
+++
authors = ["grid47"]
title = "Leetcode 2100: Find Good Days to Rob the Bank"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2100: Find Good Days to Rob the Bank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-good-days-to-rob-the-bank/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) {

        int n = sec.size();
        vector<int> pre(n, 0), suf(n, 0);
        pre[0] = 0;
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if(sec[i] <= sec[i - 1])
                cnt++;
            else cnt = 0;
            pre[i] = cnt;
        }
        
        suf[n - 1] = 0;
        cnt = 0;
        for (int i = n - 2; i >= 0; i--) {
            if(sec[i] <= sec[i + 1])
                cnt++;
            else cnt = 0;
            suf[i] = cnt;
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (pre[i] >= time && suf[i] >= time)
                ans.push_back(i);
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2100.md" >}}
---
{{< youtube skEtLRG05RQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2101: Detonate the Maximum Bombs](https://grid47.xyz/posts/leetcode-2101-detonate-the-maximum-bombs-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}