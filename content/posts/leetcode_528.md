
+++
authors = ["Crafted by Me"]
title = "Leetcode 528: Random Pick with Weight"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 528: Random Pick with Weight in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search","Prefix Sum","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/random-pick-with-weight/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> wc;
    public:
    Solution(vector<int>& w) {
        int n = w.size();
        for(int i = 1; i < n; i++)
            w[i] += w[i - 1];
        wc = w;
    }
    
    int pickIndex() {
        
        int x = rand() % wc.back()+1;//[(wc.size() - 1)];        
        int l = 0, r = wc.size() - 1;
    
        while(l < r) {

            int mid = l + (r - l) / 2;            
            if(wc[mid] == x) return mid;

            if(wc[mid] < x) l = mid + 1;
            else            r = mid;
        
        }
        
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/528.md" >}}
---
{{< youtube oYjDXfo-mt0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #529: Minesweeper](https://grid47.xyz/posts/leetcode_529) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
