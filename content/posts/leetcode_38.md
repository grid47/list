
+++
authors = ["Crafted by Me"]
title = "Leetcode 38: Count and Say"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 38: Count and Say in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-and-say/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string tmp = countAndSay(n-1);
        string ans = "";

        for(int i = 0; i < tmp.size(); ) {

            char ch = tmp[i];
            int cnt = 0;

            while(tmp[i] == ch && i < tmp.size()) {
                cnt++;
                i++;
            }

            ans.push_back(cnt+'0');
            ans.push_back(tmp[i-1]);
        }

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/38.md" >}}
---
{{< youtube 4PFCdoSOsiA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #39: Combination Sum](https://grid47.xyz/posts/leetcode_39) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

