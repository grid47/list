
+++
authors = ["grid47"]
title = "Leetcode 1593: Split a String Into the Max Number of Unique Substrings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1593: Split a String Into the Max Number of Unique Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mx = 1, n;
    string s;
    
    int maxUniqueSplit(string s) {
        set<string> cnt;
        string tmp = "";
        n = s.size();
        this->s = s;
        bt(0, tmp, cnt);
        
        return mx;
    }
    
    void bt(int idx, string tmp, set<string> cnt) {
        if(idx == n) {
            mx = max(mx, (int)cnt.size());
            return;
        }
        
        for(int i = idx; i < n; i++) {
            tmp += s[i];
            if(!cnt.count(tmp)) {
                cnt.insert(tmp);
                bt(i + 1, "", cnt);
                cnt.erase(tmp);
            }
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1593.md" >}}
---
{{< youtube fLjeVALxzjg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1594: Maximum Non Negative Product in a Matrix](https://grid47.xyz/posts/leetcode-1594-maximum-non-negative-product-in-a-matrix-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}