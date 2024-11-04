
+++
authors = ["Crafted by Me"]
title = "Leetcode 522: Longest Uncommon Subsequence II"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 522: Longest Uncommon Subsequence II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        if(strs.empty()) return -1;
        int rst = -1;
        for(auto i = 0; i < strs.size(); i++) {
            int j = 0;
            for(; j < strs.size(); j++) {
                if( i == j ) continue;
                if(LCS(strs[i], strs[j])) break;
            }
            if (j == strs.size())
            rst = max(rst, static_cast<int>(strs[i].size()));
        }
        return rst;
    }
    
    bool LCS(const string& a, const string& b) {
        if(b.size() < a.size()) return false;

        int i = 0;
        for(auto ch : b)
        if (i < a.size() && a[i] == ch) i++;

        return i == a.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/522.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #523: Continuous Subarray Sum](https://grid47.xyz/posts/leetcode_523) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

