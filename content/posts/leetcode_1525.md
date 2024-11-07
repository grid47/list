
+++
authors = ["Crafted by Me"]
title = "Leetcode 1525: Number of Good Ways to Split a String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1525: Number of Good Ways to Split a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-good-ways-to-split-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSplits(string s) {
        map<char, int> left, right;
        
        int n = s.size();
        for(int i = 0; i < n; i++)
            right[s[i]]++;
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            left[s[i]]++;
            right[s[i]]--;
            if(right[s[i]] == 0) right.erase(s[i]);
            if(left.size() == right.size()) cnt++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1525.md" >}}
---
{{< youtube lRVpVUC5mQ4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1527: Patients With a Condition](https://grid47.xyz/posts/leetcode_1527) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
