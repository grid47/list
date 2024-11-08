
+++
authors = ["grid47"]
title = "Leetcode 1540: Can Convert String in K Moves"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1540: Can Convert String in K Moves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/can-convert-string-in-k-moves/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        vector<int> cnt(n, 0);
        vector<int> frq(26, 0);
        for(int i = 0; i < n; i++) {
            if(t[i] > s[i]) {
                cnt[i] = t[i] - s[i];
            } else if(t[i] < s[i]) {
                cnt[i] = 26 - (s[i] - t[i]);
            }
            // cout << cnt[i] << " ";
            frq[cnt[i] % 26]++;
        }

        for(int i = 1; i < 26; i++) {
            // cout << frq[i] << " ";
            if(frq[i] == 0) continue;
            long net = (long) (i + (frq[i] - 1)  * 26);
            if( net > k) return false;
        }
        
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1540.md" >}}
---
{{< youtube 3psLUZqiGx0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1541: Minimum Insertions to Balance a Parentheses String](https://grid47.xyz/posts/leetcode_1541) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
