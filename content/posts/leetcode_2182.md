
+++
authors = ["Crafted by Me"]
title = "Leetcode 2182: Construct String With Repeat Limit"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2182: Construct String With Repeat Limit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-string-with-repeat-limit/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for(char ch: s) freq[ch - 'a']++;
        priority_queue<pair<char, int>> pq;

        for(int i = 0; i < 26; i++)
        if(freq[i] > 0) pq.push(make_pair((char) 'a' + i, freq[i]));

        string ans = "";
        while(!pq.empty()) {
            pair<char, int> p = pq.top();
            pq.pop();
            int cnt = p.second;
            for(int i = 0; i < repeatLimit && cnt-- > 0; i++) ans.push_back(p.first);

            if(cnt > 0 && !pq.empty()) {
                pair<char, int> sp = pq.top();
                pq.pop();
                ans.push_back(sp.first);
                if(sp.second > 1) {
                    sp.second--;
                    pq.push(sp);
                }
                p.second = cnt;
                pq.push(p);
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2182.md" >}}
---
{{< youtube PZT5c2SFAYs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2183: Count Array Pairs Divisible by K](https://grid47.xyz/posts/leetcode_2183) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
