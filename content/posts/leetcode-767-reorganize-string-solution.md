
+++
authors = ["grid47"]
title = "Leetcode 767: Reorganize String"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 767: Reorganize String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Sorting","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reorganize-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string reorganizeString(string s) {
        int mfq = 0, i = 0;
        
        vector<int> frq(26, 0);
        for(char c: s)
            if (++frq[c - 'a'] > frq[mfq])
                mfq = c - 'a';
        
        // if mfq over bounds return ""
        if(2 * frq[mfq] - 1 > s.size()) return "";
        /*  dist mfq across
            dist rest across */
        while(frq[mfq]) {
            s[i] = 'a' + mfq;
            i += 2;
            frq[mfq]--;
        }

        for(int j = 0; j < 26; j++) {
            while(frq[j]) {
                if(i >= s.size()) i = 1;
                s[i] = 'a' + j;
                frq[j]--;
                i += 2;
            }
        }
        
        return s;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/767.md" >}}
---
{{< youtube 2g_b1aYTHeg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #769: Max Chunks To Make Sorted](https://grid47.xyz/posts/leetcode-769-max-chunks-to-make-sorted-solution/) |
| --- |
