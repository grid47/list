
+++
authors = ["grid47"]
title = "Leetcode 916: Word Subsets"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 916: Word Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/word-subsets/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> frq(26, 0);
        for(auto s: words2) {
            vector<int> tmp(26, 0);
            for(char c: s) {
                tmp[c - 'a']++;
                frq[c - 'a'] = max(frq[c - 'a'], tmp[c-'a']);
            }
        }
        vector<string> res;
        for(auto s: words1) {
            vector<int> tmp(26, 0);
            for(char c: s) tmp[c - 'a']++;
            int flag = true;
            for(int i = 0; i < 26; i++) {
                if(tmp[i] < frq[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) res.push_back(s);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/916.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #918: Maximum Sum Circular Subarray](https://grid47.xyz/posts/leetcode-916-word-subsets-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
