
+++
authors = ["grid47"]
title = "Leetcode 2337: Move Pieces to Obtain a String"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2337: Move Pieces to Obtain a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "Tq2uKuSciOc"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<int, int>> ss, ts;

        for(int i = 0; i < start.size(); i++)
        if(start[i] != '_') ss.push({start[i], i});

        for(int i = 0; i < target.size(); i++)
        if(target[i] != '_') ts.push({target[i], i});

        if(ss.size() != ts.size()) return false;

        while(!ss.empty()) {
            auto s = ss.front();
            auto t = ts.front();
            ss.pop();
            ts.pop();
            if(s.first != t.first) return false;

            if(s.first == 'L' && t.second > s.second)
            return false;
            if(t.first == 'R' && t.second < s.second)
            return false;
        }

        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2337.md" >}}
---
{{< youtube Tq2uKuSciOc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2341: Maximum Number of Pairs in Array](https://grid47.xyz/leetcode/solution-2341-maximum-number-of-pairs-in-array/) |
| --- |
