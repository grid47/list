
+++
authors = ["Crafted by Me"]
title = "Leetcode 1542: Find Longest Awesome Substring"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1542: Find Longest Awesome Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-longest-awesome-substring/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestAwesome(string s) {
        map<int, int> mp;
        int msk = 0;
        int n = s.size();
        int j = 0, ans = 1;
        mp[0] = -1;
        for(int i = 0; i < s.size(); i++) {
            msk ^= (1 << (s[i] - '0'));

            if(mp.count(msk)) ans = max(ans, i - mp[msk]);
            for(int j = 0; j < 10; j++) {
                // if((msk & (1 << j)) == 0) continue;
                msk ^= (1 << j);
                if(mp.count(msk)) ans = max(ans, i - mp[msk]);
                msk ^= (1 << j);                
            }

            if(!mp.count(msk)) mp[msk] = i;
        }

        return ans;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1542.md" >}}
---
{{< youtube 0-HJwJLayps >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1545: Find Kth Bit in Nth Binary String](https://grid47.xyz/posts/leetcode_1545) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
