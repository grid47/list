
+++
authors = ["grid47"]
title = "Leetcode 2381: Shifting Letters II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2381: Shifting Letters II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shifting-letters-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        int n = s.length();
        vector<int> net(n, 0);
        for(auto &x: sh) {
            int k = x[2] == 1? 1 : -1;
            net[x[0]] += k;
           // net[x[0]] %= 26;
            if(x[1] + 1 < n) {
            net[x[1] + 1] -= k;
           // net[x[1] + 1] %= 26;
                }



        }
        
        partial_sum(net.begin(), net.end(), net.begin());
        
        int i = 0;
        for(char &c : s) {
            
            int res = ((c - 'a') + net[i])% 26;
                     res = (res + 26)%26;
            c = 'a' + res;
            i++;
        }
        
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2381.md" >}}
---
{{< youtube dWp_egpuwbU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2383: Minimum Hours of Training to Win a Competition](https://grid47.xyz/posts/leetcode_2383) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
