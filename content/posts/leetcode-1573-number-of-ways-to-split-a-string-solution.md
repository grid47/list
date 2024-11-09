
+++
authors = ["grid47"]
title = "Leetcode 1573: Number of Ways to Split a String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1573: Number of Ways to Split a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-split-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numWays(string s) {
        
        long n = s.size();
        int one = 0;
        for(char x: s)
            one += (x == '0')? 0: 1;
        
        int mod = (int) 1e9 + 7;
        
        if(one == 0) return (int)((n - 2) * (n - 1) / 2 % mod);
        
            
        if(one % 3 != 0) return 0;
        
        long long waysOfFirstCut = 0, waysOfSecondCut = 0;
        int net = one / 3, tmp = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') tmp++;
            if(tmp == net) waysOfFirstCut++;
            else if(tmp == 2 * net) waysOfSecondCut++;
        }
        
        return (int)(waysOfFirstCut *waysOfSecondCut % mod) ;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1573.md" >}}
---
{{< youtube DVcHb_poT6E >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1575: Count All Possible Routes](https://grid47.xyz/posts/leetcode-1575-count-all-possible-routes-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
