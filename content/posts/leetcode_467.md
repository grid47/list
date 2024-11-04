
+++
authors = ["Crafted by Me"]
title = "Leetcode 467: Unique Substrings in Wraparound String"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 467: Unique Substrings in Wraparound String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Dynamic Programming","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> len(26, 0);
        int cur = 1;
        len[p[0] - 'a'] = 1;
        for(int i = 1; i < p.size(); i++) {
            if((p[i] + 26 - p[i - 1]) % 26 == 1) cur++;
            else cur = 1;
            len[p[i] - 'a'] = max(len[p[i] - 'a'], cur);
        }
        return accumulate(len.begin(), len.end(), 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/467.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #468: Validate IP Address](https://grid47.xyz/posts/leetcode_468) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

