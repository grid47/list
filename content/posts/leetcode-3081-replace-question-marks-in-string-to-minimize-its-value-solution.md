
+++
authors = ["grid47"]
title = "Leetcode 3081: Replace Question Marks in String to Minimize Its Value"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3081: Replace Question Marks in String to Minimize Its Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Sorting","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> frq(26, 0), taken;

        int n = s.size();
        for(char c: s) if(c != '?') frq[c - 'a']++;

        for(int i = 0; i < n; i++) {
            if(s[i] != '?') continue;

            int mn = 0;
            for(int j = 0; j < 26; j++)
                if(frq[j] < frq[mn]) mn = j;

            taken.push_back(mn);
            frq[mn]++;
        }

        sort(taken.begin(), taken.end());

        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '?')
            s[i] = taken[idx++] + 'a';
        }

        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3081.md" >}}
---
{{< youtube dYPKJ4Kelxw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3099: Harshad Number](https://grid47.xyz/posts/leetcode-3099-harshad-number-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}